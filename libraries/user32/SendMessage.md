[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SendMessage
Group: [Message and Message Queue](../../functions_group.md#Message_and_Message_Queue)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Sends the specified message to a window or windows. It calls the window procedure for the specified window and does not return until the window procedure has processed the message. 
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[System Image List Viewer](../../samples/sample_021.md)  
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[How to drag a Form not using its Titlebar or Caption](../../samples/sample_195.md)  
[How to start the screen saver and how to find whether the screen saver is active](../../samples/sample_196.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[How to change the name and the size of the font in the MessageBox dialog](../../samples/sample_434.md)  
[Using Video Capture: displaying on FoxPro form frames and previewing video obtained from a digital camera](../../samples/sample_437.md)  
[How to disable the Windows Clipboard (VFP9)](../../samples/sample_488.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[Using WM_COPYDATA for interprocess communication (VFP9)](../../samples/sample_536.md)  
[How to view system icons for the classes installed on the local machine](../../samples/sample_544.md)  
[Enumerating devices installed on the local machine](../../samples/sample_545.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  
[Displaying hypertext links with the SysLink control (VFP9, Comctl32.dll)](../../samples/sample_559.md)  
[Using Month Calendar Control (VFP9, Comctl32.dll)](../../samples/sample_560.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  
[Controlling master audio volume by sending WM_APPCOMMAND messages](../../samples/sample_592.md)  

## Declaration:
```foxpro  
LRESULT SendMessage(
  HWND hWnd,      // handle to destination window
  UINT Msg,       // message
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SendMessage IN user32;
	INTEGER hWnd,;
	INTEGER Msg,;
	INTEGER wParam,;
	INTEGER lParam
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose window procedure will receive the message. 

Msg 
[in] Specifies the message to be sent. 

wParam 
[in] Specifies additional message-specific information. 

lParam 
[in] Specifies additional message-specific information.   
***  


## Return value:
The return value specifies the result of the message processing; it depends on the message sent.   
***  


## Comments:
To send a message and return immediately, use the SendMessageCallback or SendNotifyMessage function. To post a message to the message queue of a thread and return immediately, use the PostMessage or PostThreadMessage function.   
  
***  

