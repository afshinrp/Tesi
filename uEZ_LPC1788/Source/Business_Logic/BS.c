#include <BS.h>
#include <modbus.h>
#include <datamodel.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <tcp.h>

//defines
#define ID_EDIT_0_LEDS  				(GUI_ID_USER + 0x0A)
#define ID_EDIT_0_SENSORS   		(GUI_ID_USER + 0x06)
#define ID_EDIT_1_SENSORS   		(GUI_ID_USER + 0x09)
#define ID_EDIT_2_SENSORS   		(GUI_ID_USER + 0x0B)
#define ID_EDIT_3_SENSORS   		(GUI_ID_USER + 0x0D)
#define ID_EDIT_4_SENSORS   		(GUI_ID_USER + 0x0F)
#define ID_EDIT_5_SENSORS   		(GUI_ID_USER + 0x11)
#define ID_EDIT_6_SENSORS   		(GUI_ID_USER + 0x13)
#define ID_CHECKBOX_0_LIGHT     (GUI_ID_USER + 0x14)
#define ID_CHECKBOX_1_ALARM     (GUI_ID_USER + 0x15)
#define ID_CHECKBOX_2_TEMP    	(GUI_ID_USER + 0x16)
#define ID_SLIDER_0_DELAY				(GUI_ID_USER + 0x04)
#define ID_SPINBOX_0_THRTEMP    (GUI_ID_USER + 0x17)


//Executor
void BS_exec(void (*f_for_tcp)(void), void (*f_for_gui)(WM_MESSAGE *), WM_MESSAGE *obj);
void BS_pre_exec(void (*f)(void *), void *obj);
void BS_post_exec(void (*f)(void *), void *obj);
void BS_notify(void (*f_for_tcp)(void *), void (*f_for_gui)(void *), void *obj);

//Internal private functions
void switch_context_to_leds_controller();
void switch_context_to_leds_window();
void switch_context_to_sensors_controller();
void switch_context_to_sensors_window();
void switch_context_to_debug_modbus_controller();
void switch_context_to_debug_modbus_window();
void exit_controller();

void init_leds_controller();
void init_leds_window();
void init_leds_window_subtask();
void init_sensors_controller();
void init_sensors_window();
void activate_leds_subtask();
void activate_sensors_subtask();
void stop_subtask();
void exit_window(WM_MESSAGE *pMsg);
void change_led_status_modbus_task();
void update_led_status_controller();
void update_led_status_window(WM_MESSAGE *pMsg);
void autoupdate_leds_status_controller();
void autoupdate_leds_status_window(WM_MESSAGE *pMsg);
void update_sensors_status_controller();
void update_sensors_status_window();
void init_leds();
void update_led_status();

void notify_change_delay_to_controller(void *delay);
void notify_change_delay_to_window(void *delay);
void notify_change_alarm_temperature_sensor_to_controller();
void notify_change_alarm_sensor_to_controller();
void notify_change_alarm_no_light_sensor_to_controller();
void notify_change_max_temperature_threshold_to_controller(void *new_threshold);
void notify_change_max_temperature_threshold_to_window(void *new_threshold);
void notify_change_alarm_temperature_sensor_to_window();
void notify_change_alarm_sensor_to_window();
void notify_change_alarm_no_light_sensor_to_window();

//GUI Interfaces
extern WM_HWIN ExecLedControl(void);
extern WM_HWIN ExecSensor_Control(void);
extern WM_HWIN ExecModbus_Master_testWindow(void);

//external functions
extern void modbus_led_check();
extern void modbus_sensor_check();
extern T_uezTaskFunction poll_led_check (T_uezTask aTask, void *aParameters);
extern T_uezTaskFunction poll_sensor_check (T_uezTask aTask, void *aParameters);

extern void modify_label(WM_MESSAGE *msg);
extern void modify_label_sensors(WM_MESSAGE *msg);
extern void modify_edit_text(int led, BOOL status, char *string);

extern void write_from_BS(char *string);

//external variables
extern _modbus_rx modbus_rx;
extern Sensors sensors;

//internal variabiles
BOOL led_status[7] = {FALSE};
BOOL exit_subtask_control;
BOOL changed;
int led;
int led_value;
WM_HWIN actual_hWin = NULL;
T_uezSemaphore semaphore_actual_hWin;
T_uezError err;


//handler al task modbus
T_uezTask poll_subtask_t;


void BS_wrapper(command signal, recipient rec, void *obj){

	int i;

	switch(rec){

		//chiamate interne (modifica interfaccia, valori, ecc)
		case INTERNAL:
			switch(signal){
				case EXIT:
					break;
				
				//MENU'
				case SWITCH_CONTEXT_TO_LEDS_CONTROLLER:
					BS_exec(switch_context_to_leds_controller, switch_context_to_leds_window, NULL);
					BS_wrapper(INIT_LEDS_CONTROLLER, EXTERNAL, NULL);
					break;
				
				case SWITCH_CONTEXT_TO_SENSORS_CONTROLLER:
					BS_exec(switch_context_to_sensors_controller, switch_context_to_sensors_window, NULL);
					BS_wrapper(INIT_SENSORS_CONTROLLER, EXTERNAL, NULL);
					break;

				case SWITCH_CONTEXT_TO_DEBUG_MODBUS_CONTROLLER:
					BS_exec(switch_context_to_debug_modbus_controller, switch_context_to_debug_modbus_window, NULL);
					break;
				
				//LEDS CONTROL				
				case EXIT_CONTROLLER:
					BS_pre_exec(stop_subtask, NULL);
					BS_exec(exit_controller, exit_window, (WM_MESSAGE *)obj);
					break;

				case CHANGE_LED_STATUS_1:
					led = 1;
					BS_pre_exec(change_led_status_modbus_task, NULL);
					BS_pre_exec(update_led_status, NULL);
					BS_exec(update_led_status_controller, update_led_status_window, (WM_MESSAGE *)obj);
					break;

				case CHANGE_LED_STATUS_2:
					led = 2;
					BS_pre_exec(change_led_status_modbus_task, NULL);
					BS_exec(update_led_status_controller, update_led_status_window, (WM_MESSAGE *)obj);
					break;

				case CHANGE_LED_STATUS_3:
					led = 3;
					BS_pre_exec(change_led_status_modbus_task, NULL);
					BS_exec(update_led_status_controller, update_led_status_window, (WM_MESSAGE *)obj);
					break;

				case CHANGE_LED_STATUS_4:
					led = 4;
					BS_pre_exec(change_led_status_modbus_task, NULL);
					BS_exec(update_led_status_controller, update_led_status_window, (WM_MESSAGE *)obj);
					break;

				case CHANGE_LED_STATUS_5:
					led = 5;
					BS_pre_exec(change_led_status_modbus_task, NULL);
					BS_exec(update_led_status_controller, update_led_status_window, (WM_MESSAGE *)obj);
					break;

				case CHANGE_LED_STATUS_6:
					led = 6;
					BS_pre_exec(change_led_status_modbus_task, NULL);
					BS_exec(update_led_status_controller, update_led_status_window, (WM_MESSAGE *)obj);
					break;
				
				//UNKNOWN
				default:
					break;
			}
			break;
			
		//chiamate esterne (invio di valori)
		case EXTERNAL:
			switch(signal){
				//LEDS CONTROL
				case INIT_LEDS_CONTROLLER:
					err = UEZSemaphoreCreateBinary(&semaphore_actual_hWin);
					UEZSemaphoreGrab(semaphore_actual_hWin, 1000);
					BS_pre_exec(modbus_led_check, NULL);
					BS_pre_exec(init_leds, NULL);
					//BS_exec(init_leds_controller, init_leds_window, NULL);
					BS_post_exec(activate_leds_subtask, obj);
					break;
				
				case UPDATE_LEDS_STATUS:
					BS_exec(autoupdate_leds_status_controller, autoupdate_leds_status_window, (WM_MESSAGE *)obj);
					break;
				
				//SENSORS CONTROL
				case CHANGE_DELAY_QUERY_FROM_WINDOW:
					BS_notify(notify_change_delay_to_controller, NULL, obj);
					break;

				case CHANGE_DELAY_QUERY_FROM_CONTROLLER:
					BS_notify(NULL, notify_change_delay_to_window, obj);
					break;
				
				case NOTIFY_ALARM_TEMPERATURE_SENSOR_CHANGED_FROM_WINDOW:
					BS_notify(notify_change_alarm_temperature_sensor_to_controller, NULL, obj);
					break;
				
				case NOTIFY_ALARM_PRESENCE_SENSOR_CHANGED_FROM_WINDOW:
					BS_notify(notify_change_alarm_sensor_to_controller, NULL, obj);
					break;

				case NOTIFY_NO_LIGHT_SENSOR_CHANGED_FROM_WINDOW:
					BS_notify(notify_change_alarm_no_light_sensor_to_controller, NULL, obj);					
					break;
				
				case NOTIFY_ALARM_TEMPERATURE_SENSOR_CHANGED_FROM_CONTROLLER:
					BS_notify(NULL, notify_change_alarm_temperature_sensor_to_window, obj);
					break;

				case NOTIFY_NO_LIGHT_SENSOR_CHANGED_FROM_CONTROLLER:
					BS_notify(NULL, notify_change_alarm_no_light_sensor_to_window, obj);					
					break;
				
				case NOTIFY_ALARM_PRESENCE_SENSOR_CHANGED_FROM_CONTROLLER:
					BS_notify(NULL, notify_change_alarm_sensor_to_window, obj);
					break;
				
				case NOTIFY_MAX_TEMPERATURE_THRESHOLD_FROM_WINDOW:
					BS_notify(notify_change_max_temperature_threshold_to_controller, NULL, obj);
					break;

				case NOTIFY_MAX_TEMPERATURE_THRESHOLD_FROM_CONTROLLER:
					BS_notify(NULL, notify_change_max_temperature_threshold_to_window, obj);
					break;
				
				case INIT_SENSORS_CONTROLLER:
					err = UEZSemaphoreCreateBinary(&semaphore_actual_hWin);
					UEZSemaphoreGrab(semaphore_actual_hWin, 1000);
					BS_pre_exec(modbus_sensor_check, NULL);
					BS_exec(init_sensors_controller, init_sensors_window, NULL);
					BS_post_exec(activate_sensors_subtask, obj);
					break;
				
				case UPDATE_SENSORS_STATUS:
					BS_exec(update_sensors_status_controller, update_sensors_status_window, NULL);	
				
			}
			break;
		
		default:
			//chiamata anomala
			break;
	}

}



//FUNCTIONS

void BS_exec(void (*f_for_tcp)(void), void (*f_for_gui)(WM_MESSAGE *), WM_MESSAGE *obj){
	if(*f_for_tcp != NULL)
		(*f_for_tcp)();
	
	if(*f_for_gui != NULL)
		(*f_for_gui)(obj);
}

void BS_pre_exec(void (*f)(void *), void *obj){
	(*f)(obj);
}

void BS_post_exec(void (*f)(void *), void *obj){
	(*f)(obj);
}

void BS_notify(void (*f_for_tcp)(void *), void (*f_for_gui)(void *), void *obj){
	unsigned short check1;
	unsigned short check2;
	
	if(*f_for_tcp != NULL)
		check1 = 1;
	else
		check1 = NULL;
	
	if(*f_for_gui != NULL)
		check2 = 1;
	else
		check2 = NULL;
	
	if(check1 != NULL)
		(*f_for_tcp)(obj);

	if(check2 != NULL)
		(*f_for_gui)(obj);	
}



void switch_context_to_leds_controller(){
	write_from_BS("{\"command\" :\"context\", \"value\": \"leds\"}\r\n");
}

void switch_context_to_leds_window(){

		if (UEZTaskCreate(ExecLedControl, "ExecLedControl", UEZ_TASK_STACK_BYTES(2048), (void *)0, UEZ_PRIORITY_NORMAL, 0))
			; //anomalia
}

void switch_context_to_sensors_controller(){
	write_from_BS("{\"command\" :\"context\", \"value\": \"sensors\"}\r\n");
}

void switch_context_to_sensors_window(){

	if (UEZTaskCreate(ExecSensor_Control, "ExecSensor_Control", UEZ_TASK_STACK_BYTES(2048), (void *)0, UEZ_PRIORITY_NORMAL, 0))
			; //anomalia

}

void switch_context_to_debug_modbus_controller(){
		;
}

void switch_context_to_debug_modbus_window(){

	if (UEZTaskCreate(ExecModbus_Master_testWindow, "ExecModbus_Master_testWindow", UEZ_TASK_STACK_BYTES(2048), (void *)0, UEZ_PRIORITY_NORMAL, 0))
			; //anomalia
	
}

void init_leds(){
	if (UEZTaskCreate(init_leds_window_subtask, "init_leds_window_subtask", UEZ_TASK_STACK_BYTES(2048), (void *)0, UEZ_PRIORITY_NORMAL, 0))
			; //anomalia	
}

void init_leds_controller(){

	int i;
	char res[120];

	sprintf(res, "{\"command\" : \"update_leds\", \"value\" : [\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\"]}\r\n",
		led_status[1]==1?"ON":"OFF", led_status[2]==1?"ON":"OFF", led_status[3]==1?"ON":"OFF", led_status[4]==1?"ON":"OFF", 
		led_status[5]==1?"ON":"OFF", led_status[6]==1?"ON":"OFF");
	
	write_from_BS(res);
	
}

void init_leds_window(){

	WM_HWIN hItem;
	int i;

	for(i = 0; i < 7; i++)
	if(bit_test(modbus_rx.data_converted[0],i)){
				hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_0_LEDS + i);
				EDIT_SetText(hItem, " 0N");
				led_status[i+1] = TRUE;
	}
	else{
				hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_0_LEDS + i);
				EDIT_SetText(hItem, " 0FF");
				led_status[i+1] = FALSE;
	}
	
}

void init_leds_window_subtask(){
		
	UEZSemaphoreGrab(semaphore_actual_hWin, 10000);
	UEZSemaphoreDelete(semaphore_actual_hWin);

	init_leds_window();
	init_leds_controller();

}

void init_sensors_controller(){
	
}

void init_sensors_window(){

}

void activate_leds_subtask(){
	exit_subtask_control = FALSE;
	UEZTaskCreate((T_uezTaskFunction)poll_led_check, "_poll_led_check", 512,(void *) NULL , UEZ_PRIORITY_LOW, &poll_subtask_t);					
}

void stop_subtask(){
	UEZTaskDelete(poll_subtask_t);
	exit_subtask_control = TRUE;
}

void exit_controller(){
	write_from_BS("{\"command\" :\"context\", \"value\": \"menu\"}\r\n");
}

void exit_window(WM_MESSAGE *pMsg){
	GUI_EndDialog(actual_hWin, 0);	
	actual_hWin = NULL;
}

void change_led_status_modbus_task(){
		modbus_led_task(led, led_status[led]);
}

void update_led_status(){

	led_status[led] = !led_status[led];
	
}

void update_led_status_controller(){
	char res[120];
	sprintf(res, "{\"command\" : \"update_led\", \"value\" : {\"led\": %d, \"value\" : \"%s\"}}\r\n", led, led_status[led] == TRUE? "ON" : "OFF");
	write_from_BS(res);
}

void update_led_status_window(WM_MESSAGE *pMsg){
	WM_HWIN hItem;
	
	if(led_status[led]){
		hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_0_LEDS + led - 1);
		EDIT_SetText(hItem, " 0N");						
		}
	else{
		hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_0_LEDS + led - 1);
		EDIT_SetText(hItem, " 0FF");						
		}		
}

void autoupdate_leds_status_window(WM_MESSAGE *pMsg){
	int pos_led;
	WM_HWIN hItem;
	BOOL value;

	pos_led = pMsg->Data.v/10;
	if(pMsg->Data.v%10 == 1)
		value = TRUE;
	else
		value = FALSE;

	led_status[led] = led_value;
			
	if(!exit_subtask_control){
		if(led_status[led]){
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0_LEDS + led - 1);
			EDIT_SetText(hItem, " 0N");						
		}
		else{
			hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0_LEDS + led - 1);
			EDIT_SetText(hItem, " 0FF");						
		}
	}		
}


void autoupdate_leds_status_controller(){
	char res[120];
	sprintf(res, "{\"command\" : \"update_led\", \"value\" : {\"led\": %d, \"value\" : \"%s\"}}\r\n", led, led_status[led] == TRUE? "ON" : "OFF");
	write_from_BS(res);
}


void notify_change_delay_to_controller(void *delay){
	char str[120];
	sprintf(str, "{\"command\" :\"update_widget\", \"value\": \"slider_delay\", \"w_val\" : %d}\r\n", *(int *)delay);
	write_from_BS(str);
}

void notify_change_delay_to_window(void *delay){
	WM_HWIN hItem;
	int value = *(int *) delay;
	hItem = WM_GetDialogItem(actual_hWin, ID_SLIDER_0_DELAY);
	SLIDER_SetValue(hItem, value);
}


void notify_change_alarm_temperature_sensor_to_controller(){
	write_from_BS("{\"command\" :\"update_widget\", \"value\": \"check_alarm_temp\"}\r\n");
}

void notify_change_alarm_temperature_sensor_to_window(){
	WM_HWIN hItem;
	int value;
	hItem = WM_GetDialogItem(actual_hWin, ID_CHECKBOX_2_TEMP);
	value = CHECKBOX_GetState(hItem);
	CHECKBOX_SetState(hItem, !value);						
}

void notify_change_alarm_no_light_sensor_to_controller(){
	write_from_BS("{\"command\" :\"update_widget\", \"value\": \"check_no_light\"}\r\n");
}

void notify_change_alarm_no_light_sensor_to_window(){
	WM_HWIN hItem;
	int value;
	hItem = WM_GetDialogItem(actual_hWin, ID_CHECKBOX_0_LIGHT);
	value = CHECKBOX_GetState(hItem);
	CHECKBOX_SetState(hItem, !value);						
}


void notify_change_alarm_sensor_to_controller(){
	write_from_BS("{\"command\" :\"update_widget\", \"value\": \"check_sensor\"}\r\n");
}

void notify_change_alarm_sensor_to_window(){
	WM_HWIN hItem;
	int value;
	hItem = WM_GetDialogItem(actual_hWin, ID_CHECKBOX_1_ALARM);
	value = CHECKBOX_GetState(hItem);
	CHECKBOX_SetState(hItem, !value);						
}

void notify_change_max_temperature_threshold_to_controller(void *new_threshold){
	char str[50];
	sprintf(str, "{\"command\" :\"update_widget\", \"value\": \"spin_temp_threshold\", \"w_val\" : %d}\r\n", *(int *)new_threshold);
	write_from_BS(str);
}

void notify_change_max_temperature_threshold_to_window(void *new_threshold){
	WM_HWIN hItem;
	int value = *(int *) new_threshold;
	hItem = WM_GetDialogItem(actual_hWin, ID_SPINBOX_0_THRTEMP);
	SPINBOX_SetValue(hItem, value);
}

void activate_sensors_subtask(){
		UEZTaskCreate((T_uezTaskFunction)poll_sensor_check, "_sensor_check", 512,(void *) NULL , UEZ_PRIORITY_LOW, &poll_subtask_t);				
}

void update_sensors_status_controller(){

	int i;
	char res[120];
	char perc = '%';

	sprintf(res, "{\"command\" : \"update_sensors\", \"value\" : [\"%d�\", \"%d%c\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\"]}\r\n",
		((sensors.temperature==0||sensors.temperature==10)?20:sensors.temperature), (sensors.humidity==0?13:sensors.humidity), perc, 
		(sensors.mic!=0?"NOISE":"SILENCE"), (sensors.distance!=0?"FAR":"NEAR"), (sensors.presence!=0?"NO":"YES"), 
		(sensors.vibration!=0?"NO":"YES"), (sensors.light!=0?"LIGHT":"DARK"));
	
	write_from_BS(res);
}

void update_sensors_status_window(){

	WM_HWIN hItem;
	char temperature[3] = {'\0'};
	char humidity[3] = {'\0'};
	char perc = '%';

	if(sensors.temperature != 666){
		if(sensors.temperature == 0 || sensors.temperature == 10)
				sensors.temperature = 20;
		sprintf( temperature, "%d�", sensors.temperature);
		hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_0_SENSORS);
		EDIT_SetText(hItem, temperature);
	}
	//estrazione dell'umidita'
	if(sensors.humidity != 666){
		if(sensors.humidity == 0)
			sensors.humidity = 13;
		sprintf( humidity, "%d%c", sensors.humidity, perc);
		hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_1_SENSORS);
		EDIT_SetText(hItem, humidity);
	}

	//estrazione suono
	hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_2_SENSORS);
	if( sensors.mic != 0 )
		EDIT_SetText(hItem, "NOISE");
	else
		EDIT_SetText(hItem, "SILENCE");

	//estrazione distanza
	hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_3_SENSORS);
	if( sensors.distance != 0 )
		EDIT_SetText(hItem, "FAR");
	else
		EDIT_SetText(hItem, "NEAR");

	//estrazione presenza
	hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_4_SENSORS);
	if( sensors.presence != 0 )
		EDIT_SetText(hItem, "NO");
	else
		EDIT_SetText(hItem, "YES");


	//estrazione vibrazione
	hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_5_SENSORS);
	if( sensors.vibration != 0 )
		EDIT_SetText(hItem, "NO");
	else
		EDIT_SetText(hItem, "YES");


	//estrazione luce
	hItem = WM_GetDialogItem(actual_hWin, ID_EDIT_6_SENSORS);
	if( sensors.light != 0 )
		EDIT_SetText(hItem, "LIGHT");
	else
		EDIT_SetText(hItem, "DARK");

}