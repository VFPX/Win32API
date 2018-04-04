[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCursorPos
Group: [Cursor](../../functions_group.md#Cursor)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the cursor"s position, in screen coordinates.
***  


## Code examples:
[Clipping mouse cursor area](../../samples/sample_080.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[Tracking mouse movement to detect when to start dragging](../../samples/sample_281.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Form Magnifier](../../samples/sample_414.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
BOOL GetCursorPos(
  LPPOINT lpPoint   // cursor position
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetCursorPos IN user32 STRING @ lpPoint  
```  
***  


## Parameters:
lpPoint 
[out] Pointer to a POINT structure that receives the screen coordinates of the cursor.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This function returns an absolute screen position.   
  
Position the cursor with MOUSE AT <y>, <x>; where x and y are local coordinates of VFP main window. After that read the cursor position with GetCursorPos function. That gives you a difference between local and global coordinates.  
  
Put = INKEY(0.1) or any other delay between setting and reading the cursor position. It seems that without such delay VFP does not have enough time to inform the OS about mouse cursor repositioning.  
  
***  

