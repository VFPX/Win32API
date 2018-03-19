[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# The window and its ancestors

## Before you begin:
Call this code in three different ways to compare the results: (a) from the Command window; (b) from an open PRG editor; (c) from a form method.  
  
***  


## Code:
```foxpro  
DO decl

#DEFINE GA_PARENT     1
#DEFINE GA_ROOT       2
#DEFINE GA_ROOTOWNER  3

LOCAL hWindow
hWindow = GetFocus()

ACTI SCREEN
? "*** The window and its ancestors"

= _print ("Source window:", hWindow)
= _print ("Parent window (GetParent):", GetParent (hWindow))
= _print ("Parent window (GetAncestor):", GetAncestor (hWindow, GA_PARENT))
= _print ("Root window:", GetAncestor (hWindow, GA_ROOT))
= _print ("Owned root window:", GetAncestor (hWindow, GA_ROOTOWNER))

ACTI SCREEN
?
? "*** Some other important windows"

= _print ("VFP main window:", GetActiveWindow())
= _print ("Windows desktop:", GetDesktopWindow())

PROCEDURE  _print (lcMemo, hWindow)
	LOCAL lcWintext
	lcWintext = GetWinText(hWindow)
	ACTI SCREEN
	? lcMemo, "|", hWindow, "|", lcWintext

FUNCTION  GetWinText(hWindow)
	LOCAL lnBufsize, lcBuffer
	lnBufsize = 1024
	lcBuffer = Repli(Chr(0), lnBufsize)
	lnBufsize = GetWindowText(hWindow, @lcBuffer, lnBufsize)
RETURN  Iif(lnBufsize=0, "", Left(lcBuffer,lnBufsize))

PROCEDURE  decl
	DECLARE INTEGER GetDesktopWindow IN user32
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetFocus IN user32

	DECLARE INTEGER GetParent IN user32 INTEGER hwnd
	DECLARE INTEGER GetAncestor IN user32;
		INTEGER hwnd, INTEGER gaFlags

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetAncestor](../libraries/user32/GetAncestor.md)  
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetParent](../libraries/user32/GetParent.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
