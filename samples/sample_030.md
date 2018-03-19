[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Who is the first in viewing the Clipboard

## Code:
```foxpro  
DO declare

hWindow=GetActiveWindow()
hOwner=GetClipboardViewer()
	
? "Active window: ............", hWindow,;
	"["+GetWinText(hWindow)+"]"

? "_SCREEN.HWnd: .............", _screen.HWnd,;
	"["+GetWinText(_screen.HWnd)+"]"

? "Window viewing clipboard: ..", hOwner,;
	"["+GetWinText(hOwner)+"]"

FUNCTION GetWinText(hWindow)
	LOCAL nBufsize, cBuffer
	nBufsize = 128
	cBuffer = Repli(Chr(0), nBufsize)
	nBufsize = GetWindowText(hWindow, @cBuffer, nBufsize)
RETURN Iif(nBufsize=0, "", Left(cBuffer, nBufsize))

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetClipboardViewer IN user32

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClipboardViewer](../libraries/user32/GetClipboardViewer.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  

## Comment:
As you can see from this example the VFP Main Window is the first application viewing the clipboard - same for GetClipboardOwner  
  
***  

