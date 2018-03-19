[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Printing text on the client area of the main VFP window

## Code:
```foxpro  
DO decl

hwnd = GetActiveWindow()
hDC = GetDC (hwnd)

lpString = "Printing text with TextOut"
= TextOut (hDC, 50,80, lpString, Len(lpString)) &&

= ReleaseDC (hwnd, hDC)

PROCEDURE  decl
	DECLARE INTEGER GetDC IN user32 INTEGER hwnd

	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER GetActiveWindow IN user32

	DECLARE INTEGER TextOut IN gdi32;
		INTEGER hdc,;
		INTEGER x,;
		INTEGER y,;
		STRING  lpString,;
		INTEGER nCount  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetDC](../libraries/user32/GetDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[TextOut](../libraries/gdi32/TextOut.md)  

## Comment:
This does not work - no client area is available.   
  
Always use GetWindowDC to access a device context, which can be used for printing and drawing on VFP windows.  
  
***  

