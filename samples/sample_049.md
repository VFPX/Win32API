[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining window class name for the main VFP window

## Code:
```foxpro  
DO declare

LOCAL hWindow
hWindow = GetActiveWindow()

? "GetActiveWindow():", hWindow
? "Window Class:", GetWindowClass(hWindow)
? "Window Caption:", GetWindowCaption(hWindow)
?
? "_vfp.hWnd:", _vfp.hWnd
? "_screen.hWnd:", _screen.hWnd
? "_SCREEN.Caption:", _screen.Caption

FUNCTION GetWindowClass(lnWindow)
	LOCAL lnLength, lcText

	lcText = SPACE(250)
	lnLength = RealGetWindowClass(lnWindow,;
		@lcText, Len(lcText))

RETURN IIF(lnLength > 0,;
	Left(lcText, lnLength), "#empty#")

FUNCTION GetWindowCaption(lnWindow)
	LOCAL lnLength, lcText

	lcText = SPACE(250)
	lnLength = GetWindowText(lnWindow,;
		@lcText, Len(lcText))

RETURN IIF(lnLength > 0,;
	Left(lcText, lnLength), "#empty#")

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32

	DECLARE INTEGER RealGetWindowClass IN user32;
		INTEGER hWindow, STRING @ pszType,;
		INTEGER cchType

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hWindow,;
		STRING @lpString, INTEGER cch  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[RealGetWindowClass](../libraries/user32/RealGetWindowClass.md)  

## Comment:
Compare the results when:  
\- running this code using DO in the Command Window;  
\- running from an open Program Edit window using Ctrl+E  
  
***  

