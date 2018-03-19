[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using GetNearestColor

## Code:
```foxpro  
DO decl

	* defining a device context for the VFP Main window
	hWnd = GetActiveWindow ()
	hDc = GetDC (hWnd)
	
	crColor = RGB (16, 108, 231)
	matchColor = GetNearestColor (hDc, crColor)
	? LTRIM(STR(crColor)) + " transformed to " + LTRIM(STR(matchColor))

	= ReleaseDC (hwnd, hdc)

PROCEDURE  decl
    DECLARE INTEGER GetDC IN user32 INTEGER hwnd
    DECLARE INTEGER GetActiveWindow IN user32

	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hwnd, INTEGER hdc

    DECLARE INTEGER GetNearestColor IN gdi32;
		INTEGER hdc,;
		INTEGER crColor  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetDC](../libraries/user32/GetDC.md)  
[GetNearestColor](../libraries/gdi32/GetNearestColor.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  

## Comment:
I ran this code with two color resolutions.   
  
With 32-bit True Color the result was:  
15166480 to 15166480  
  
With 256 colors it was:  
15166480 to 8421376  
  
***  

