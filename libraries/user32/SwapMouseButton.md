[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SwapMouseButton
Group: [Mouse Input](../../functions_group.md#Mouse_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SwapMouseButton function reverses or restores the meaning of the left and right mouse buttons
***  


## Declaration:
```foxpro  
BOOL SwapMouseButton(
  BOOL fSwap   // reverse or restore buttons
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SwapMouseButton IN user32 INTEGER bSwap  
```  
***  


## Parameters:
fSwap 
[in] Specifies whether the mouse button meanings are reversed or restored. If this parameter is TRUE, the left button generates right-button messages and the right button generates left-button messages. If this parameter is FALSE, the buttons are restored to their original meanings  
***  


## Return value:
If the meaning of the mouse buttons was reversed previously, before the function was called, the return value is nonzero.

If the meaning of the mouse buttons was not reversed, the return value is zero
  
***  


## Comments:
The usage is simple:  
  
```foxpro
DECLARE INTEGER SwapMouseButton IN user32;  
	INTEGER bSwap  
  
= SwapMouseButton(1)  && swaps  
= SwapMouseButton(0)  && restores defaults
```
Also GetSystemMetrics can read the swap state (SM_SWAPBUTTON).  
  
***  

