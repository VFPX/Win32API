[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetWindowPos
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SetWindowPos function changes the size, position, and Z order of a child, pop-up, or top-level window.
***  


## Code examples:
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[Extended MessageBox Class](../../samples/sample_418.md)  
[Using Video Capture: displaying on FoxPro form frames and previewing video obtained from a digital camera](../../samples/sample_437.md)  
[How to position the GETPRINTER() dialog](../../samples/sample_482.md)  
[Displaying hypertext links with the SysLink control (VFP9, Comctl32.dll)](../../samples/sample_559.md)  
[Using Month Calendar Control (VFP9, Comctl32.dll)](../../samples/sample_560.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
BOOL SetWindowPos(
  HWND hWnd,             // handle to window
  HWND hWndInsertAfter,  // placement-order handle
  int X,                 // horizontal position
  int Y,                 // vertical position
  int cx,                // width
  int cy,                // height
  UINT uFlags            // window-positioning options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetWindowPos IN user32;
	INTEGER hwnd,;
	INTEGER hWndInsertAfter,;
	INTEGER x,;
	INTEGER y,;
	INTEGER cx,;
	INTEGER cy,;
	INTEGER wFlags
  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window. 

hWndInsertAfter 
[in] Handle to the window to precede the positioned window in the Z order. 

X 
[in] Specifies the new position of the left side of the window, in client coordinates. 

Y 
[in] Specifies the new position of the top of the window, in client coordinates. 

cx 
[in] Specifies the new width of the window, in pixels. 

cy 
[in] Specifies the new height of the window, in pixels. 

uFlags 
[in] Specifies the window sizing and positioning flags.

  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

