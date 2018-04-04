[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawCaption
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DrawCaption function draws a window caption.
***  


## Code examples:
[Drawing a window caption using the DrawCaption routine](../../samples/sample_238.md)  

## Declaration:
```foxpro  
BOOL DrawCaption(
  HWND hwnd,    // handle to window
  HDC hdc,      // handle to device context
  LPCRECT lprc, // rectangle to draw into
  UINT uFlags   // drawing options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawCaption IN user32;
	INTEGER hwnd,;
	INTEGER hdc,;
	STRING  lprc,;
	INTEGER uFlags  
```  
***  


## Parameters:
hwnd 
[in] Handle to a window that supplies text and an icon for the window caption. 

hdc 
[in] Handle to a device context. The function draws the window caption into this device context. 

lprc 
[in] Pointer to a RECT structure that specifies the bounding rectangle for the window caption.

uFlags 
[in] Specifies drawing options.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

