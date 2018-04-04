[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetWindowRgn
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Sets the window region of a window. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region
***  


## Code examples:
[Creating irregularly shaped FoxPro form using transparency color key](../../samples/sample_033.md)  
[Setting the Window Region for a form](../../samples/sample_120.md)  
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[Round FoxPro form](../../samples/sample_143.md)  
[Creating a clipping region from the path selected into the device context of a form](../../samples/sample_144.md)  
[How to draw custom Window Caption on FoxPro form](../../samples/sample_499.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
int SetWindowRgn(
  HWND hWnd,     // handle to window
  HRGN hRgn,     // handle to region
  BOOL bRedraw   // window redraw option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SetWindowRgn IN user32;
	INTEGER hWnd,;
	INTEGER hRgn,;
	SHORT   bRedraw  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window whose window region is to be set. 

hRgn 
[in] Handle to a region. The function sets the window region of the window to this region. 
If hRgn is NULL, the function sets the window region to NULL. 

bRedraw 
[in] Specifies whether the system redraws the window after setting the window region. If bRedraw is TRUE, the system does so; otherwise, it does not. Typically, you set bRedraw to TRUE if the window is visible. 

  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  


## Comments:
After a successful call to SetWindowRgn, the system owns the region specified by the region handle hRgn. The system does not make a copy of the region. Thus, you should not make any further function calls with this region handle. In particular, do not delete this region handle. The system deletes the region handle when it no longer needed.  
  
To obtain the window region of a window, call the GetWindowRgn function.  
  
***  

