/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.20                          *
*        Compiled Mar 19 2013, 15:01:00                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
#include "GUI.h"
#include "port.h"
#include "datamodel.h"
#include "modbus.h"
#include "UEZ.h"
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0     (GUI_ID_USER + 0x00)
#define ID_BUTTON_0     (GUI_ID_USER + 0x01)
#define ID_SLIDER_0     (GUI_ID_USER + 0x04)
#define ID_TEXT_0     (GUI_ID_USER + 0x05)
#define ID_EDIT_0     (GUI_ID_USER + 0x06)
#define ID_TEXT_1     (GUI_ID_USER + 0x07)
#define ID_TEXT_2     (GUI_ID_USER + 0x08)
#define ID_EDIT_1     (GUI_ID_USER + 0x09)
#define ID_TEXT_3     (GUI_ID_USER + 0x0A)
#define ID_EDIT_2     (GUI_ID_USER + 0x0B)
#define ID_TEXT_4     (GUI_ID_USER + 0x0C)
#define ID_EDIT_3     (GUI_ID_USER + 0x0D)
#define ID_TEXT_5     (GUI_ID_USER + 0x0E)
#define ID_EDIT_4     (GUI_ID_USER + 0x0F)
#define ID_TEXT_6     (GUI_ID_USER + 0x10)
#define ID_EDIT_5     (GUI_ID_USER + 0x11)
#define ID_TEXT_7     (GUI_ID_USER + 0x12)
#define ID_EDIT_6     (GUI_ID_USER + 0x13)
#define ID_CHECKBOX_0     (GUI_ID_USER + 0x14)
#define ID_CHECKBOX_1     (GUI_ID_USER + 0x15)
#define ID_CHECKBOX_2     (GUI_ID_USER + 0x16)
#define ID_SPINBOX_0     (GUI_ID_USER + 0x17)
#define ID_TEXT_8     (GUI_ID_USER + 0x18)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "SensorsControl", ID_FRAMEWIN_0, 0, 0, 640, 480, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "exit_button", ID_BUTTON_0, 0, 0, 25, 25, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "refresh_slider", ID_SLIDER_0, 57, 369, 149, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "refresh_text", ID_TEXT_0, 86, 336, 112, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "temperature_edit", ID_EDIT_0, 160, 70, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "temp_text", ID_TEXT_1, 75, 72, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "hum_text", ID_TEXT_2, 75, 128, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "humidity_edit", ID_EDIT_1, 160, 126, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "sound_text", ID_TEXT_3, 330, 72, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "sound_edit", ID_EDIT_2, 395, 70, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "distance_text", ID_TEXT_4, 330, 128, 56, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "distance_edit", ID_EDIT_3, 395, 126, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "pres_text", ID_TEXT_5, 75, 180, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "presence_edit", ID_EDIT_4, 160, 177, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "vibro_text", ID_TEXT_6, 330, 180, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "vibration_edit", ID_EDIT_5, 395, 177, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "light_text", ID_TEXT_7, 75, 229, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "light_edit", ID_EDIT_6, 160, 228, 80, 20, 0, 0x64, 0 },
  { CHECKBOX_CreateIndirect, "light_check", ID_CHECKBOX_0, 318, 364, 268, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "alarm_check", ID_CHECKBOX_1, 318, 400, 237, 32, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "temp_check", ID_CHECKBOX_2, 318, 329, 203, 20, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "Spinbox", ID_SPINBOX_0, 418, 277, 80, 30, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "max_temp_text", ID_TEXT_8, 318, 284, 95, 20, 0, 0x64, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)

//handler al task modbus
T_uezTask poll_sensor_t;
int delay_from_slider = 500;

extern T_uezTaskFunction poll_sensor_check (T_uezTask aTask, void *aParameters);

extern _modbus_rx modbus_rx;

// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
	
	int i;
	char temperature[3] = {'\0'};
	char humidity[3] = {'\0'};
	
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'SensorsControl'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetText(hItem, "Sensors Control");
    //
    // Initialization of 'exit_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, " X");
    //
    // Initialization of 'refresh_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "delay of refresh:");
    //
    // Initialization of 'temperature_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem, "0");
    //
    // Initialization of 'temp_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetText(hItem, "teperature:");
    //
    // Initialization of 'hum_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetText(hItem, "humidity:");
    //
    // Initialization of 'humidity_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
    EDIT_SetText(hItem, "0");
    //
    // Initialization of 'sound_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetText(hItem, "sound:");
    //
    // Initialization of 'sound_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_2);
    EDIT_SetText(hItem, "SILENCE");
    //
    // Initialization of 'distance_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetText(hItem, "distance:");
    //
    // Initialization of 'distance_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_3);
    EDIT_SetText(hItem, "FAR");
    //
    // Initialization of 'pres_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
    TEXT_SetText(hItem, "presence:");
    //
    // Initialization of 'presence_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
    EDIT_SetText(hItem, "NO");
    //
    // Initialization of 'vibro_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
    TEXT_SetText(hItem, "vibration:");
    //
    // Initialization of 'vibration_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_5);
    EDIT_SetText(hItem, "NO");
    //
    // Initialization of 'light_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
    TEXT_SetText(hItem, "light:");
    //
    // Initialization of 'light_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_6);
    EDIT_SetText(hItem, "NO");
    //
    // Initialization of 'light_check'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "turn on all leds when there is no light in the area");
    //
    // Initialization of 'alarm_check'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
    CHECKBOX_SetText(hItem, "activate alarm on presence");
    //
    // Initialization of 'temp_check'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_2);
    CHECKBOX_SetText(hItem, "activate alarm on temperature");
    //
    // Initialization of 'max_temp_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_8);
    TEXT_SetText(hItem, "max temperature:");
    // USER START (Optionally insert additional code for further widget initialization)

		//aggiorno i valori, cio� faccio partire il messaggio di richiesta
		//UEZTaskCreate((T_uezTaskFunction)poll_sensor_check, "_sensor_check", 512,(void *) pMsg->hWin , UEZ_PRIORITY_LOW, &poll_sensor_t);				


		// USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'exit_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
			  PlayAudio(600, 20);				
        PlayAudio(600, 20);				
        PlayAudio(200, 20);				
 
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)

				PlayAudio(900, 20);				
        PlayAudio(1000, 20);				
        PlayAudio(1100, 20);				

				UEZTaskDelete(poll_sensor_t);

        hItem = pMsg->hWin;
        GUI_EndDialog(hItem, 0);

        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SLIDER_0: // Notifications sent by 'refresh_slider'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
			
			PlayAudio(180, 30);				

			hItem = WM_GetDialogItem(pMsg->hWin, ID_SLIDER_0 );
			delay_from_slider = 500 + SLIDER_GetValue(hItem);
			
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_0: // Notifications sent by 'temperature_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_1: // Notifications sent by 'humidity_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_2: // Notifications sent by 'sound_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_3: // Notifications sent by 'distance_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_4: // Notifications sent by 'presence_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_5: // Notifications sent by 'vibration_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_6: // Notifications sent by 'light_edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_0: // Notifications sent by 'light_check'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_1: // Notifications sent by 'alarm_check'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_2: // Notifications sent by 'temp_check'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_0: // Notifications sent by 'Spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_MOVED_OUT:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
		
	case MB_MSG_SENSOR:

		//GESTISCO L'AGGIORNAMENTO DEI LABEL DEI SENSORI
	
		/** 
	i sensori sono stati mappati cos�:
	
	*(usRegHoldingBuf     ) = (USHORT *) &sensors.distance1;
	*(usRegHoldingBuf + 1 ) = (USHORT *) &sensors.distance2;
	*(usRegHoldingBuf + 2 ) = (USHORT *) &sensors.lumino;
	*(usRegHoldingBuf + 3 ) = (USHORT *) &sensors.mic;
	*(usRegHoldingBuf + 4 ) = (USHORT *) &sensors.vibro;
	*(usRegHoldingBuf + 5 ) = (USHORT *) &actual_DHT11.humidity;
	*(usRegHoldingBuf + 6 ) = (USHORT *) &actual_DHT11.temperature;

	
  "temperature_edit", ID_EDIT_0
  "humidity_edit", ID_EDIT_1
  "sound_edit", ID_EDIT_2
  "distance_edit", ID_EDIT_3
  "presence_edit", ID_EDIT_4
  "vibration_edit", ID_EDIT_5
  "light_edit", ID_EDIT_6

			*/
	
		//estrazione della temperatura
		sprintf("%d", temperature, modbus_rx.data_converted[6]);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
		EDIT_SetText(hItem, temperature);

		//estrazione dell'umidita'
		sprintf("%d", humidity, modbus_rx.data_converted[5]);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
		EDIT_SetText(hItem, humidity);

		//estrazione suono
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_2);
		if( modbus_rx.data_converted[3] != 0 )
			EDIT_SetText(hItem, "NOISE");
		else
			EDIT_SetText(hItem, "SILENCE");
		
		//estrazione distanza
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_3);
		if( modbus_rx.data_converted[0] != 0 )
			EDIT_SetText(hItem, "NEAR");
		else
			EDIT_SetText(hItem, "FAR");
		
		//estrazione presenza
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
		if( modbus_rx.data_converted[0] != 0 )
			EDIT_SetText(hItem, "YES");
		else
			EDIT_SetText(hItem, "NO");

		
		//estrazione vibrazione
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_5);
		if( modbus_rx.data_converted[4] != 0 )
			EDIT_SetText(hItem, "YES");
		else
			EDIT_SetText(hItem, "NO");

		
		//estrazione luce
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_6);
		if( modbus_rx.data_converted[2] != 0 )
			EDIT_SetText(hItem, "LIGHT");
		else
			EDIT_SetText(hItem, "DARK");
		
		
	break;
	
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateSensorsControl
*/
WM_HWIN CreateSensorsControl(void);
WM_HWIN CreateSensorsControl(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)


void modify_label_sensors(WM_MESSAGE *msg){
	
	_cbDialog(msg);
	
}


WM_HWIN ExecSensor_Control(void);
WM_HWIN ExecSensor_Control(void) {
  WM_HWIN hWin;

  hWin = GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}


// USER END

/*************************** End of file ****************************/
