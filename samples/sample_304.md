[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using Font and Text functions

## Code:
```foxpro  
DO decl
#DEFINE TRANSPARENT  1
#DEFINE OPAQUE       2

#DEFINE TA_LEFT      0
#DEFINE TA_CENTER    6
#DEFINE TA_RIGHT     2

	PRIVATE hWindow, hDC
	hWindow = GetActiveWindow()
	hDC = GetWindowDC(hWindow)
	
	= SetBkMode (hDC, TRANSPARENT)

	DO PrintText WITH Rgb(192,  0,  0), 600, 100, 0, 0
	DO PrintText WITH Rgb(  0,192,  0), 600, 120, 6, 1
	DO PrintText WITH Rgb(  0,  0,192), 600, 140, 2, 2
	DO PrintText WITH Rgb(192,  0,192), 600, 160, 2, 3
	DO PrintText WITH Rgb(192,192,  0), 600, 180, 0, 1
	DO PrintText WITH Rgb(  0,192,192), 600, 200, 6, 0

	= ReleaseDC(hWindow, hDC)

PROCEDURE PrintText (lnColor, lnX, lnY, lnAlign, lnInterChar)
	LOCAL lcText, lcFont, lnBufsize
	
	lcFont = SPACE(250)
	lnBufsize = GetTextFace(hDC, Len(lcFont), @lcFont)
	lcFont = LEFT(lcFont, lnBufsize)

	= SetTextAlign (hDC, lnALign)
	= SetTextCharacterExtra (hDC, lnInterChar)
	= SetTextColor (hDC, lnColor)

	lcText = "Font: " + lcFont + ", color: " + LTRIM(STR(GetTextColor(hDC))) +;
		", align: " + LTRIM(STR(GetTextAlign(hDC))) +;
		", interchar: " + LTRIM(STR(GetTextCharacterExtra(hDC)))

	= TextOut (hDC, lnX, lnY, lcText, Len(lcText))

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWnd, INTEGER hDC
	DECLARE INTEGER GetTextAlign IN gdi32 INTEGER hdc
	DECLARE INTEGER SetTextAlign IN gdi32 INTEGER hdc, INTEGER fMode
	DECLARE INTEGER SetTextCharacterExtra IN gdi32 INTEGER hdc, INTEGER nCharExtra
	DECLARE INTEGER GetTextCharacterExtra IN gdi32 INTEGER hdc
	DECLARE INTEGER GetTextColor IN gdi32 INTEGER hdc
	DECLARE INTEGER SetTextColor IN gdi32 INTEGER hdc, INTEGER crColor
	DECLARE INTEGER SetBkMode IN gdi32 INTEGER hdc, INTEGER iBkMode

	DECLARE INTEGER TextOut IN gdi32;
		INTEGER hdc, INTEGER x, INTEGER y,;
		STRING lpString, INTEGER nCount

	DECLARE INTEGER GetTextFace IN gdi32;
		INTEGER hdc, INTEGER nCount, STRING @lpFaceName  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetTextAlign](../libraries/gdi32/GetTextAlign.md)  
[GetTextCharacterExtra](../libraries/gdi32/GetTextCharacterExtra.md)  
[GetTextColor](../libraries/gdi32/GetTextColor.md)  
[GetTextFace](../libraries/gdi32/GetTextFace.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SetBkMode](../libraries/gdi32/SetBkMode.md)  
[SetTextAlign](../libraries/gdi32/SetTextAlign.md)  
[SetTextCharacterExtra](../libraries/gdi32/SetTextCharacterExtra.md)  
[SetTextColor](../libraries/gdi32/SetTextColor.md)  
[TextOut](../libraries/gdi32/TextOut.md)  
