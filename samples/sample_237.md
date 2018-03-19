[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining the bounding rectangle for the specified device context

## Code:
```foxpro  
DO decl
#DEFINE DCB_RESET       1
#DEFINE DCB_ACCUMULATE  2
#DEFINE DCB_ENABLE      4
#DEFINE DCB_DISABLE     8
#DEFINE DCB_SET       BitOr(DCB_RESET, DCB_ACCUMULATE)

LOCAL hWindow, hDC, lcRect, lnResult

* retrieving the device context for the main VFP window
hWindow = GetActiveWindow()
hDC = GetWindowDC(hWindow)

* allocating a buffer for the RECT structure
lcRect = Repli(Chr(0), 16) && 4 DWORDs

* obtaining the current accumulated bounding rectangle
* for the device context
lnResult = GetBoundsRect (hDC, @lcRect, 0)

DO CASE
CASE lnResult = 0
	? "The specified device context handle is invalid"
CASE lnResult = DCB_DISABLE
	? "Boundary accumulation is off"
CASE lnResult = DCB_ENABLE
	? "Boundary accumulation is on"
CASE lnResult = DCB_RESET
	? "The bounding rectangle is empty"
CASE lnResult = DCB_SET
* The bounding rectangle is not empty
	? "The bounding rectangle:",;
		buf2dword(SUBSTR(lcRect,  1,4)),;
		buf2dword(SUBSTR(lcRect,  5,4)),;
		buf2dword(SUBSTR(lcRect,  9,4)),;
		buf2dword(SUBSTR(lcRect, 13,4))
ENDCASE

= ReleaseDC(hWindow, hDC)
* end of main

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER GetBoundsRect IN gdi32;
		INTEGER hdc, STRING @lprcBounds, INTEGER flags  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetBoundsRect](../libraries/gdi32/GetBoundsRect.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
