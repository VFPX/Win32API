[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawFrameControl
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DrawFrameControl function draws a frame control of the specified type and style.
***  


## Code examples:
[Drawing Windows frame controls using the DrawFrameControl function](../../samples/sample_254.md)  

## Declaration:
```foxpro  
BOOL DrawFrameControl(
  HDC hdc,     // handle to device context
  LPRECT lprc, // bounding rectangle
  UINT uType,  // frame-control type
  UINT uState  // frame-control state
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawFrameControl IN user32;
	INTEGER   hdc,;
	STRING  @ lprc,;
	INTEGER   uType,;
	INTEGER   uState  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context of the window in which to draw the control. 

lprc 
[in] Pointer to a RECT structure that contains the logical coordinates of the bounding rectangle for frame control. 

uType 
[in] Specifies the type of frame control to draw. 

[in] Specifies the initial state of the frame control.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
MSDN: note that the use of LoadBitmap to load OEM bitmaps is deprecated and is supported only for backwards compatibility. New applications should use DrawFrameControl to draw system elements.  
  
***  

