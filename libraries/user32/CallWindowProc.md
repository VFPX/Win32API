[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CallWindowProc
Group: [Window Procedure](../../functions_group.md#Window_Procedure)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The CallWindowProc function passes message information to the specified window procedure.
***  


## Code examples:
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Switching between keyboard layouts](../../samples/sample_275.md)  
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[How to disable the Windows Clipboard (VFP9)](../../samples/sample_488.md)  
[How to block the PrintScreen key](../../samples/sample_489.md)  
[Transparent Menu Class (requires VFP9)](../../samples/sample_496.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  
[How to hot-track menu item selection in top-level form (requires VFP9)](../../samples/sample_521.md)  
[Using WM_COPYDATA for interprocess communication (VFP9)](../../samples/sample_536.md)  
[Displaying hypertext links with the SysLink control (VFP9, Comctl32.dll)](../../samples/sample_559.md)  
[Using Month Calendar Control (VFP9, Comctl32.dll)](../../samples/sample_560.md)  
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  
[Customizing the frame of top-level form: removing the standard frame (VFP9, Vista)](../../samples/sample_574.md)  
[Monitoring clipboard content changes (VFP9)](../../samples/sample_601.md)  

## Declaration:
```foxpro  
LRESULT CallWindowProc(
	WNDPROC lpPrevWndFunc,
	HWND hWnd,
	UINT Msg,
	WPARAM wParam,
	LPARAM lParam
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CallWindowProc IN user32;
	LONG lpPrevWndFunc,;
	LONG hWnd,;
	LONG Msg,;
	INTEGER wParam,;
	INTEGER lParam  
```  
***  


## Parameters:
lpPrevWndFunc
[in] Pointer to the previous window procedure. This value can be obtained by calling the GetWindowLong function with the nIndex parameter set to GWL_WNDPROC or DWL_DLGPROC

hWnd
[in] Handle to the window procedure to receive the message. 

Msg
[in] Specifies the message. 

wParam
[in] Specifies additional message-specific information.

lParam
[in] Specifies additional message-specific information.  
***  


## Return value:
The return value specifies the result of the message processing and depends on the message sent.  
***  


## Comments:
You hardly could have a reason to call this frunction directly from VFP code.  
  
***  

