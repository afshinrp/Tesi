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
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)
#define ID_TEXT_0  (GUI_ID_USER + 0x02)
#define ID_RADIO_0  (GUI_ID_USER + 0x03)
#define ID_TEXT_1  (GUI_ID_USER + 0x04)
#define ID_TEXT_2  (GUI_ID_USER + 0x05)
#define ID_TEXT_3  (GUI_ID_USER + 0x07)
#define ID_TEXT_4  (GUI_ID_USER + 0x09)
#define ID_TEXT_5  (GUI_ID_USER + 0x0A)
#define ID_BUTTON_0  (GUI_ID_USER + 0x0C)
#define ID_LISTVIEW_0  (GUI_ID_USER + 0x0D)
#define ID_CHECKBOX_0  (GUI_ID_USER + 0x0E)
#define ID_LISTVIEW_1  (GUI_ID_USER + 0x10)
#define ID_BUTTON_1  (GUI_ID_USER + 0x20)
#define ID_SPINBOX_0  (GUI_ID_USER + 0x21)
#define ID_SPINBOX_1  (GUI_ID_USER + 0x22)
#define ID_SPINBOX_2  (GUI_ID_USER + 0x23)
#define ID_SPINBOX_3  (GUI_ID_USER + 0x24)


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
  { FRAMEWIN_CreateIndirect, "Modbus_Master_testWindow", ID_FRAMEWIN_0, 0, 0, 640, 480, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "id_text", ID_TEXT_0, 30, 27, 80, 20, 0, 0x64, 0 },
  { RADIO_CreateIndirect, "function_radio", ID_RADIO_0, 138, 32, 143, 84, 0, 0x1404, 0 },
  { TEXT_CreateIndirect, "multiple_text", ID_TEXT_1, 30, 160, 161, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "from_text", ID_TEXT_2, 30, 192, 34, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "to_text", ID_TEXT_3, 30, 229, 31, 21, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "single_text", ID_TEXT_4, 30, 290, 143, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "number_text", ID_TEXT_5, 30, 322, 51, 20, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "send_button", ID_BUTTON_0, 87, 383, 106, 35, 0, 0x0, 0 },
  { LISTVIEW_CreateIndirect, "response_view", ID_LISTVIEW_0, 406, 0, 223, 466, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "loop_check", ID_CHECKBOX_0, 230, 401, 121, 24, 0, 0x0, 0 },
  { LISTVIEW_CreateIndirect, "status_view", ID_LISTVIEW_1, 245, 190, 104, 35, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "exit_button", ID_BUTTON_1, 0, 0, 25, 21, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "slave_id_spinbox", ID_SPINBOX_0, 30, 45, 49, 26, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "from_spinbox", ID_SPINBOX_1, 90, 188, 80, 26, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "to_spinbox", ID_SPINBOX_2, 90, 225, 80, 26, 0, 0x0, 0 },
  { SPINBOX_CreateIndirect, "number_spinbox", ID_SPINBOX_3, 90, 318, 80, 26, 0, 0x0, 0 },
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
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'id_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetText(hItem, "slave id:");
    //
    // Initialization of 'function_radio'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_RADIO_0);
    RADIO_SetText(hItem, "read holding registers", 0);
    RADIO_SetText(hItem, "write holding registers", 1);
    RADIO_SetText(hItem, "read single coil", 2);
    RADIO_SetText(hItem, "write single coil", 3);
    //
    // Initialization of 'multiple_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetText(hItem, "MULTIPLE REGISTER REQUEST");
    //
    // Initialization of 'from_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetText(hItem, "from:");
    //
    // Initialization of 'to_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
    TEXT_SetText(hItem, "to:");
    //
    // Initialization of 'single_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
    TEXT_SetText(hItem, "SINGLE REGISTER REQUEST");
    //
    // Initialization of 'number_text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
    TEXT_SetText(hItem, "number:");
    //
    // Initialization of 'send_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "SEND");
    //
    // Initialization of 'response_view'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_0);
    LISTVIEW_AddColumn(hItem, 60, "address", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 80, "slave 1", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 80, "slave 2", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddRow(hItem, NULL);
    LISTVIEW_SetGridVis(hItem, 1);
    LISTVIEW_AddColumn(hItem, 30, "Col", GUI_TA_LEFT | GUI_TA_VCENTER);
    LISTVIEW_SetAutoScrollV(hItem, 1);
    //
    // Initialization of 'loop_check'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "send continuously");
    //
    // Initialization of 'status_view'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_1);
    LISTVIEW_AddColumn(hItem, 100, "status", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_SetGridVis(hItem, 1);
    LISTVIEW_SetItemText(hItem, 0, 0, "0");
    LISTVIEW_SetItemText(hItem, 0, 0, "0");
    //
    // Initialization of 'exit_button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetText(hItem, " X");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_RADIO_0: // Notifications sent by 'function_radio'
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
    case ID_BUTTON_0: // Notifications sent by 'send_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_LISTVIEW_0: // Notifications sent by 'response_view'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_0: // Notifications sent by 'loop_check'
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
    case ID_LISTVIEW_1: // Notifications sent by 'status_view'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'exit_button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_SPINBOX_0: // Notifications sent by 'slave_id_spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
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
    case ID_SPINBOX_1: // Notifications sent by 'from_spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
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
    case ID_SPINBOX_2: // Notifications sent by 'to_spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
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
    case ID_SPINBOX_3: // Notifications sent by 'number_spinbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
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
*       CreateModbus_Master_testWindow
*/
WM_HWIN CreateModbus_Master_testWindow(void);
WM_HWIN CreateModbus_Master_testWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
