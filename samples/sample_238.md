[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Drawing a window caption using the DrawCaption routine

## Code:
```foxpro  
DO decl

#DEFINE DC_ACTIVE    1
#DEFINE DC_SMALLCAP  2
#DEFINE DC_ICON      4
#DEFINE DC_TEXT      8
#DEFINE DC_INBUTTON 16
#DEFINE DC_GRADIENT 32

LOCAL hWindowSrc, hWindowTrg, hDC

* the caption of this window is to be drawn
* actually you can supply a handle for any other window
hWindowSrc = GetActiveWindow()

* the target device context - to draw the caption on
hWindowTrg = GetFocus()
hDC = GetWindowDC(hWindowTrg)

* drawing the caption of the source window
* each time with different options

= DrawCaption(hWindowTrg, hDC,;
	GetRect(100, 200, 400, 220), DC_ICON+DC_TEXT)

= DrawCaption(hWindowTrg, hDC,;
	GetRect(100, 222, 400, 242), DC_ACTIVE+DC_ICON+DC_TEXT)

* releasing the target device context
= ReleaseDC(hWindowTrg, hDC)
* end of main

FUNCTION  GetRect (lnLeft, lnTop, lnRight, lnBottom)
* returns the RECT structure (four DWORDs) filled with the values
RETURN num2dword(lnLeft) + num2dword(lnTop) +;
	num2dword(lnRight) + num2dword(lnBottom)

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3 * m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER DrawCaption IN user32;
		INTEGER hwnd, INTEGER hdc,;
		STRING lprc, INTEGER uFlags  
```  
***  


## Listed functions:
[DrawCaption](../libraries/user32/DrawCaption.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
