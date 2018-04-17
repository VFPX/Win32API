[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file

## Before you begin:
The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.   

Related code samples:  
* [GDI+: Storing content of the Clipboard to a bitmap file](sample_475.md)  
* [Copying picture of the active form to the Clipboard using Bitmap API functions](sample_091.md)  
* [Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](sample_404.md)  
* [Storing content of the Clipboard to a bitmap file](sample_189.md)  
* [Storing screen shot of a form to a bitmap file](sample_187.md)  

  
***  


## Code:
```foxpro  
SET PROCEDURE TO gdiplus ADDITIVE
DO decl

* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
PRIVATE gdiplus
gdiplus = CREATEOBJECT("gdiplusinit")

= FormToClip(GetFocus())
*= FileToClip("c:\windows\forest.bmp")
* end of main

PROCEDURE FormToClip(hwindow)
#DEFINE SRCCOPY  0x00CC0020
	LOCAL hdc, bmp, nWidth, nHeight
	hdc = GetWindowDC(hwindow)
	STORE 0 TO nWidth, nHeight
	= GetWinRect(hwindow, @nWidth, @nHeight)

	bmp = CREATEOBJECT("gdibitmap", m.nWidth, m.nHeight)
	WITH bmp
		.graphics.GetDC
		= BitBlt(.graphics.hdc, 0,0, .imgwidth, .imgheight,;
			m.hdc, 0,0, SRCCOPY)
		.graphics.ReleaseDC
	ENDWITH
	= ReleaseDC(m.hwindow, m.hdc)

	IF NOT img2clip(bmp)
		? "Error code:", bmp.errorcode
	ENDIF

PROCEDURE FileToClip(cFilename)
	LOCAL img, nResult
	img = CREATEOBJECT("gdiimage", cFilename)

	IF NOT img2clip(img)
		? "Error code:", img.errorcode
	ENDIF

FUNCTION img2clip(img)
* sends gdi+ image or bitmap object to the Clipboard
#DEFINE CF_BITMAP  2
	IF img.GetHBITMAP() <> 0
		= OpenClipboard(0)
		= EmptyClipboard()
		= SetClipboardData(CF_BITMAP, img.hbitmap)
		= CloseClipboard()
		= LockClipboardData()
	ENDIF
RETURN (img.errorcode=0)

PROCEDURE LockClipboardData
* the shortest way of locking clipboard data I have found;
* otherwise it does not survive beyond the lifetime of its parent gdi+ object
	= OpenClipboard(0)
	LOCAL nIndex, hData
	nIndex = 0
	DO WHILE .T.
		nIndex = EnumClipboardFormats(nIndex)
		IF nIndex = 0
			EXIT
		ELSE
			hData = GetClipboardData(nIndex)
		ENDIF
	ENDDO
	= CloseClipboard()

PROCEDURE GetWinRect(hwindow, nWidth, nHeight)
#DEFINE maxDword  0xffffffff
	LOCAL lpRect, nLeft, nTop, nRight, nBottom
	lpRect = REPLI (Chr(0), 16)
	= GetWindowRect (hwindow, @lpRect)
	nRight  = buf2dword(SUBSTR(lpRect, 9,4))
	nBottom = buf2dword(SUBSTR(lpRect, 13,4))

	nLeft = buf2dword(SUBSTR(lpRect, 1,4))
	IF nLeft > nRight
		nLeft = nLeft - maxDword
	ENDIF
	nTop = buf2dword(SUBSTR(lpRect, 5,4))
	IF nTop > nBottom
		nTop = nTop - maxDword
	ENDIF
	nWidth = nRight - nLeft
	nHeight = nBottom - nTop
RETURN

PROCEDURE decl
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER EmptyClipboard  IN user32
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER GetClipboardData IN user32 INTEGER uFormat
	DECLARE INTEGER EnumClipboardFormats IN user32 INTEGER wFormat

	DECLARE INTEGER SetClipboardData IN user32;
		INTEGER wFormat, INTEGER hMem

	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwindow
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwindow, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[EmptyClipboard](../libraries/user32/EmptyClipboard.md)  
[EnumClipboardFormats](../libraries/user32/EnumClipboardFormats.md)  
[GetClipboardData](../libraries/user32/GetClipboardData.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SetClipboardData](../libraries/user32/SetClipboardData.md)  

## Comment:
Call the *FormToClip* function from a method or event of a FoxPro form when that form is active, i.e. posesses the keyboard focus.  
  
For the *FileToClip* make sure the source file name is valid. The source file can be in any of graphics formats supported by the GDI+: BMP, GIF, JPG, TIF, EMF...  
  
The *LockClipboardData* function is kind of a lazy way to avoid complexities of locking data on the Clipboard. The SetClipboardData in the code above creates three sets of data on the Clipboard:  
  
* Bitmap handle (2)  
* BITMAPINFO structure (8)  
* BITMAPV5HEADER structure (17)*  
  
The last two, if not locked properly, are getting wiped out as soon as gdi+ *img* object is out of scope or released.   
  
Even if this works on WinXP and Win2K computers, this behaviour of the GetClipboardData looks rather undocumented. As soon as I come with another solution (short enough) I will post it here.  
  
* * *  
An article [How To Copy the Screen or Active Window to the Clipboard from Visual Basic](https://support.microsoft.com/en-us/help/240653/how-to-copy-the-screen-or-active-window-to-the-clipboard-from-visual-b) published on Microsoft Help and Support page describes a different approach -- the picture of the whole screen is sent to the clipboard by virtually pressing (through the keybd_event call) PrtScr key.  

***  

