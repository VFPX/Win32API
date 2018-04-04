[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetWindowLong
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Changes an attribute of the specified window. The function also sets the 32-bit (long) value at the specified offset into the extra window memory.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[System Image List Viewer](../../samples/sample_021.md)  
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Setting properties of the window: caption and user-defined value](../../samples/sample_182.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Semi-transparent Form](../../samples/sample_453.md)  
[Transparent Menu Class (requires VFP9)](../../samples/sample_496.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  

## Declaration:
```foxpro  
LONG SetWindowLong(
  HWND hWnd,       // handle to window
  int nIndex,      // offset of value to set
  LONG dwNewLong   // new value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetWindowLong IN user32;
	INTEGER hWnd,;
	INTEGER nIndex,;
	INTEGER dwNewLong  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window and, indirectly, the class to which the window belongs. 

nIndex 
[in] Specifies the zero-based offset to the value to be set. 

dwNewLong 
[in] Specifies the replacement value.   
***  


## Return value:
If the function succeeds, the return value is the previous value of the specified 32-bit integer.  
***  

