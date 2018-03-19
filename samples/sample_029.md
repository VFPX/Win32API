[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Who owns the Windows Clipboard

## Code:
```foxpro  
DO declare

hWindow=GetActiveWindow()
hOwner=GetClipboardOwner()
	
? "Active window: ............", hWindow,;
	"["+GetWinText(hWindow)+"]"

? "_SCREEN.HWnd: .............", _screen.HWnd,;
	"["+GetWinText(_screen.HWnd)+"]"

? "Window owning clipboard: ..", hOwner,;
	"["+GetWinText(hOwner)+"]"

FUNCTION GetWinText(hWindow)
	LOCAL nBufsize, cBuffer
	nBufsize = 128
	cBuffer = Repli(Chr(0), nBufsize)
	nBufsize = GetWindowText(hWindow, @cBuffer, nBufsize)
RETURN Iif(nBufsize=0, "", Left(cBuffer, nBufsize))

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetClipboardOwner IN user32

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClipboardOwner](../libraries/user32/GetClipboardOwner.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
