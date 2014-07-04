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
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_0  (GUI_ID_USER + 0x01)
#define ID_BUTTON_1  (GUI_ID_USER + 0x02)
#define ID_BUTTON_2  (GUI_ID_USER + 0x03)
#define ID_BUTTON_3  (GUI_ID_USER + 0x04)
#define ID_BUTTON_4  (GUI_ID_USER + 0x05)
#define ID_BUTTON_5  (GUI_ID_USER + 0x06)
#define ID_BUTTON_6  (GUI_ID_USER + 0x07)
#define ID_EDIT_0  (GUI_ID_USER + 0x0A)
#define ID_EDIT_1  (GUI_ID_USER + 0x0B)
#define ID_EDIT_2  (GUI_ID_USER + 0x0C)
#define ID_EDIT_3  (GUI_ID_USER + 0x0D)
#define ID_EDIT_4  (GUI_ID_USER + 0x0E)
#define ID_EDIT_5  (GUI_ID_USER + 0x0F)


// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)

extern _modbus_rx modbus_rx;
BOOL led_status[7] = {FALSE};

BOOL exit_thread_led_control;

BOOL changed;

// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "LedControl", ID_FRAMEWIN_0, 0, 0, 640, 480, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "exit_button", ID_BUTTON_0, 0, 0, 25, 25, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "led1_button", ID_BUTTON_1, 140, 95, 100, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "led2_button", ID_BUTTON_2, 370, 95, 100, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "led3_button", ID_BUTTON_3, 140, 205, 100, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "led4_button", ID_BUTTON_4, 370, 205, 100, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "led5_button", ID_BUTTON_5, 140, 315, 100, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "led6_button", ID_BUTTON_6, 370, 315, 100, 40, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "led1_edit", ID_EDIT_0, 172, 140, 32, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "led2_edit", ID_EDIT_1, 402, 140, 32, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "led3_edit", ID_EDIT_2, 172, 250, 32, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "led4_edit", ID_EDIT_3, 404, 250, 32, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "led5_edit", ID_EDIT_4, 172, 360, 32, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "led6_edit", ID_EDIT_5, 404, 360, 32, 20, 0, 0x64, 0 },
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


extern T_uezTaskFunction poll_led_check (T_uezTask aTask, void *aParameters);



void change_led_status(WM_HWIN *hItem, WM_MESSAGE *pMsg, int led){
	
	//invio il messaggio allo slave di on/off rele'
	modbus_led_task(led, led_status[led]);
	
	led_status[led] = !led_status[led];
			
	if(led_status[led]){
		*hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + led - 1);
		EDIT_SetText(*hItem, " 0N");						
		}
	else{
		*hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + led - 1);
		EDIT_SetText(*hItem, " 0FF");						
		}	

}


void autochange_led_status(WM_HWIN *hItem, WM_MESSAGE *pMsg, int led, BOOL value){
	
	led_status[led] = value;
			
	if(!exit_thread_led_control){
		if(led_status[led]){
			*hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + led - 1);
			EDIT_SetText(*hItem, " 0N");						
			}
		else{
			*hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + led - 1);
			EDIT_SetText(*hItem, " 0FF");						
			}	
		}

}


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
	int pos_led;
	BOOL value;
	
	//Led_control_data led_control_data;
	T_uezTask poll_led_t;

  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'LedControl'
    //
    hItem = pMsg->hWin;
	
    FRAMEWIN_SetText(hItem, "Led Control");
    //
    // Initialization of 'exit_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "X");
    //
    // Initialization of 'led1_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetText(hItem, "LED1");
    //
    // Initialization of 'led2_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetText(hItem, "LED2");
    //
    // Initialization of 'led3_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetText(hItem, "LED3");
    //
    // Initialization of 'led4_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetText(hItem, "LED4");
    //
    // Initialization of 'led5_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
    BUTTON_SetText(hItem, "LED5");
    //
    // Initialization of 'led6_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
    BUTTON_SetText(hItem, "LED6");
    //
    // Initialization of 'led1_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0);
    EDIT_SetText(hItem, " 0FF");
    //
    // Initialization of 'led2_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_1);
    EDIT_SetText(hItem, " 0FF");
    //
    // Initialization of 'led3_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_2);
    EDIT_SetText(hItem, " 0FF");
    //
    // Initialization of 'led4_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_3);
    EDIT_SetText(hItem, " 0FF");
    //
    // Initialization of 'led5_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_4);
    EDIT_SetText(hItem, " 0FF");
    //
    // Initialization of 'led6_edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_5);
    EDIT_SetText(hItem, " 0FF");
    // USER START (Optionally insert additional code for further widget initialization)
				
				//all'inizio chiedo allo slave il valore dei coil
				
				modbus_led_check();
				for(i = 0; i < 7; i++)
					if(bit_test(modbus_rx.data_converted[0],i)){
						    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + i);
								EDIT_SetText(hItem, " 0N");
								led_status[i+1] = TRUE;
					}
					else{
						    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_0 + i);
								EDIT_SetText(hItem, " 0FF");
								led_status[i+1] = FALSE;
						
					}
		
			exit_thread_led_control = FALSE;
			UEZTaskCreate((T_uezTaskFunction)poll_led_check, "poll_led_check", 512,(void *) pMsg->hWin , UEZ_PRIORITY_LOW, &poll_led_t);				
				
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
			
			  exit_thread_led_control = TRUE;
			
			  PlayAudio(900, 20);				
        PlayAudio(1000, 20);				
        PlayAudio(1100, 20);							
			  
        hItem = pMsg->hWin;
        GUI_EndDialog(hItem, 0);

        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'led1_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
			        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
			
				change_led_status(&hItem, pMsg, 1);
			
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'led2_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
 			
				change_led_status(&hItem, pMsg, 2);
			
       // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by 'led3_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
 			
				change_led_status(&hItem, pMsg, 3);
			
       // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by 'led4_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
			
				change_led_status(&hItem, pMsg, 4);
			
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_5: // Notifications sent by 'led5_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
 			
				change_led_status(&hItem, pMsg, 5);
			
       // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_6: // Notifications sent by 'led6_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
						        PlayAudio(180, 30);				

        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
			
				change_led_status(&hItem, pMsg, 6);
			
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_0: // Notifications sent by 'led1_edit'
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
    case ID_EDIT_1: // Notifications sent by 'led2_edit'
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
    case ID_EDIT_2: // Notifications sent by 'led3_edit'
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
    case ID_EDIT_3: // Notifications sent by 'led4_edit'
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
    case ID_EDIT_4: // Notifications sent by 'led5_edit'
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
    case ID_EDIT_5: // Notifications sent by 'led6_edit'
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
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
		
	case MB_MSG_COIL:

	//ottengo i valori ricevuti da modbus (numero pi� a sinistra: posizione del led
	//																		 numero pi� a destra: valore del led)
		pos_led = pMsg->Data.v/10;
		if(pMsg->Data.v%10 == 1)
			value = TRUE;
		else
			value = FALSE;
	
	  autochange_led_status(&hItem, pMsg, pos_led, value);
	
		
	
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
*       CreateLedControl
*/
WM_HWIN CreateLedControl(void);
WM_HWIN CreateLedControl(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)

void modify_label(WM_MESSAGE *msg){
	
	_cbDialog(msg);
	
}


WM_HWIN ExecLedControl(void);
WM_HWIN ExecLedControl(void) {

  WM_HWIN hWin = GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER END
/*************************** End of file ****************************/
