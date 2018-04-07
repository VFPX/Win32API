[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowLong
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves information about the specified window. The function also retrieves the 32-bit (long) value at the specified offset into the extra window memory.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[System Image List Viewer](../../samples/sample_021.md)  
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Retrieving information about the main VFP window](../../samples/sample_111.md)  
[Setting properties of the window: caption and user-defined value](../../samples/sample_182.md)  
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Placing a button on the VFP form as a new child window](../../samples/sample_274.md)  
[Switching between keyboard layouts](../../samples/sample_275.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[Locking the workstation](../../samples/sample_300.md)  
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[Semi-transparent Form](../../samples/sample_453.md)  
[How to disable the Windows Clipboard (VFP9)](../../samples/sample_488.md)  
[How to block the PrintScreen key](../../samples/sample_489.md)  
[Transparent Menu Class (requires VFP9)](../../samples/sample_496.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  
[How to hot-track menu item selection in top-level form (requires VFP9)](../../samples/sample_521.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[Using WM_COPYDATA for interprocess communication (VFP9)](../../samples/sample_536.md)  
[Displaying hypertext links with the SysLink control (VFP9, Comctl32.dll)](../../samples/sample_559.md)  
[Using Month Calendar Control (VFP9, Comctl32.dll)](../../samples/sample_560.md)  
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  
[Customizing the frame of top-level form: removing the standard frame (VFP9, Vista)](../../samples/sample_574.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  
[Monitoring clipboard content changes (VFP9)](../../samples/sample_601.md)  

## Declaration:
```foxpro  
LONG GetWindowLong(
  HWND hWnd,  // handle to window
  int nIndex  // offset of value to retrieve
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowLong IN user32;
	INTEGER hWnd, INTEGER nIndex
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window and, indirectly, the class to which the window belongs. 

nIndex 
[in] Specifies the zero-based offset to the value to be retrieved. 

  
***  


## Return value:
If the function succeeds, the return value is the requested 32-bit value.
If the function fails, the return value is zero. 
  
***  


## Comments:
This function, as well as GetModuleHandle, retrieves a handle to the application instance; but not only.  
  
See also: [SetWindowLong](../user32/SetWindowLong.md).  
  
***  

