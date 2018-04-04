[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : MoveWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The MoveWindow function changes the position and dimensions of the specified window.
***  


## Code examples:
[Splash Screen for the VFP application](../../samples/sample_294.md)  

## Declaration:
```foxpro  
BOOL MoveWindow(
  HWND hWnd,      // handle to window
  int X,          // horizontal position
  int Y,          // vertical position
  int nWidth,     // width
  int nHeight,    // height
  BOOL bRepaint   // repaint option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER MoveWindow IN user32;
	INTEGER hWnd,;
	INTEGER X,;
	INTEGER Y,;
	INTEGER nWidth,;
	INTEGER nHeight,;
	INTEGER bRepaint  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window. 

X 
[in] Specifies the new position of the left side of the window. 

Y 
[in] Specifies the new position of the top of the window. 

nWidth 
[in] Specifies the new width of the window. 

nHeight 
[in] Specifies the new height of the window. 

bRepaint 
[in] Specifies whether the window is to be repainted. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

