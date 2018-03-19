[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the DrawText function

## Code:
```foxpro  
DO decl
#DEFINE TRANSPARENT  1
#DEFINE OPAQUE       2

#DEFINE DT_LEFT      0
#DEFINE DT_CENTER    1
#DEFINE DT_TOP       0
#DEFINE DT_RIGHT     2
#DEFINE DT_WORDBREAK 16

	LOCAL hWindow, hDC, lcRect, lcText
	hWindow = GetActiveWindow()
	hDC = GetWindowDC(hWindow)
	
	_screen.BackColor = Rgb(238,238,255)
	
	lcText = "The DrawText function draws formatted text " +;
		"in the specified rectangle. It formats the text " +;
		"according to the specified method (expanding tabs, " +;
		"justifying characters, breaking lines, and so forth)."

	* left, top, right, bottom
	lcRect = n2dw(100) + n2dw(100) + n2dw(300) + n2dw(260)
	= DrawText (hDC, lcText, Len(lcText),;
		@lcRect, DT_WORDBREAK+DT_RIGHT)

	* changing background mode and color
	= SetBkMode (hDC, TRANSPARENT)

	= SetTextColor (hDC, Rgb(216,216,248))
	lcRect = n2dw(105) + n2dw(303) + n2dw(405) + n2dw(603)
	= DrawText (hDC, lcText, Len(lcText), @lcRect, DT_WORDBREAK)

	= SetTextColor (hDC, Rgb(0,80,192))
	lcRect = n2dw(100) + n2dw(300) + n2dw(400) + n2dw(600)
	= DrawText (hDC, lcText, Len(lcText), @lcRect, DT_WORDBREAK)

	= ReleaseDC(hWindow, hDC)

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hWnd, INTEGER hDC
	DECLARE INTEGER SetBkMode IN gdi32 INTEGER hdc, INTEGER iBkMode
	DECLARE INTEGER SetTextColor IN gdi32 INTEGER hdc, INTEGER crColor

	DECLARE INTEGER DrawText IN user32;
		INTEGER hDC, STRING lpString, INTEGER nCount,;
		STRING @lpRect, INTEGER uFormat

FUNCTION  n2dw (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[DrawText](../libraries/user32/DrawText.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SetBkMode](../libraries/gdi32/SetBkMode.md)  
[SetTextColor](../libraries/gdi32/SetTextColor.md)  
