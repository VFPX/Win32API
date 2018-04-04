[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawAnimatedRects
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DrawAnimatedRects function draws a wire-frame rectangle and animates it to indicate the opening of an icon or the minimizing or maximizing of a window.
***  


## Code examples:
[Animating a transition of the VFP form (a wire-frame rectangle)](../../samples/sample_255.md)  

## Declaration:
```foxpro  
BOOL DrawAnimatedRects(
  HWND hwnd,            // handle to clipping window
  int idAni,            // type of animation
  CONST RECT *lprcFrom, // rectangle coordinates (minimized)
  CONST RECT *lprcTo    // rectangle coordinates (restored)
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawAnimatedRects IN user32;
	INTEGER   hwnd,;
	INTEGER   idAni,;
	STRING  @ lprcFrom,;
	STRING  @ lprcTo  
```  
***  


## Parameters:
hwnd 
[in] Handle to the window to which the rectangle is clipped. If this parameter is NULL, the working area of the screen is used. 

idAni 
[in] Specifies the type of animation. If you specify IDANI_CAPTION, the window caption will animate from the position specified by lprcFrom to the position specified by lprcTo. 

lprcFrom 
[in] Pointer to a RECT structure specifying the location and size of the icon or minimized window. Coordinates are relative to the clipping window hwnd. 

lprcTo 
[in] Pointer to a RECT structure specifying the location and size of the restored window. Coordinates are relative to the clipping window hwnd.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

