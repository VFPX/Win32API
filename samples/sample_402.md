[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Storing screen shot of a form to enhanced metafile (*.emf)

## Before you begin:
Call this code from a VFP form to store its snapshot to a file in EMF format . Make sure that the target file (ccOutput) is a valid filename.  

This code is much more compact and easy to understand comparing to [Storing screen shot of a form to a bitmap file](sample_187.md) code sample.  
  
***  


## Code:
```foxpro  
#DEFINE HORZSIZE 4
#DEFINE VERTSIZE 6
#DEFINE HORZRES  8
#DEFINE VERTRES  10
#DEFINE SRCCOPY  0xCC0020
#DEFINE ccOutput "test.emf"  && output file name
DO decl

* obtaining window handle and DC for a window with a keyboard focus
* GetFocus can be replaced with GetDesktopWindow, GetActiveWindow, FindWindow
* or any valid window handle
hWndSrc = GetFocus()
hDCSrc = GetWindowDC(hWndSrc)

* obtaining size and resolution parameters for the source DC
hsize = GetDeviceCaps(hDCSrc, HORZSIZE) * 100
vsize = GetDeviceCaps(hDCSrc, VERTSIZE) * 100
hres = GetDeviceCaps(hDCSrc, HORZRES)
vres = GetDeviceCaps(hDCSrc, VERTRES)

* calculating width and height for the source DC
rcSrc = Repli(Chr(0),16)
= GetWindowRect(hWndSrc, @rcSrc)
nLeftSrc = buf2dword(SUBSTR(rcSrc,1,4))
nTopSrc = buf2dword(SUBSTR(rcSrc,5,4))
nRightSrc = buf2dword(SUBSTR(rcSrc,9,4))
nBotSrc = buf2dword(SUBSTR(rcSrc,13,4))
nRightSrc = nRightSrc - nLeftSrc
nBotSrc = nBotSrc - nTopSrc
STORE 0 TO nLeftSrc, nTopSrc

* calculating RECT data for a target metafile
nMetaLeft = (nLeftSrc * hsize)/hres
nMetaTop = (nTopSrc * vsize)/vres
nMetaRight = (nRightSrc * hsize)/hres
nMetaBot = (nBotSrc * vsize)/vres
rcMeta = num2dword(nMetaLeft) + num2dword(nMetaTop) +;
	num2dword(nMetaRight) + num2dword(nMetaBot)

* creating a device context for an enhanced metafile
* this device context can be used to store a device-independent picture
hMetaDC = CreateEnhMetaFile(hDCSrc, ccOutput, @rcMeta, Null)

* drawing source image on target metafile device context
= BitBlt(hMetaDC, 0,0, nRightSrc, nBotSrc, hDCSrc, 0,0, SRCCOPY)

* releasing target device context and closing the metafile
hMetaFile = CloseEnhMetaFile(hMetaDC)
= DeleteEnhMetaFile(hMetaFile)

* releasing source DC
= ReleaseDC(hWndSrc, hDCSrc)
* end of main

PROCEDURE decl
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER GetWindowRect IN user32 INTEGER hwnd, STRING @lpRect
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex
	DECLARE INTEGER CloseEnhMetaFile IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteEnhMetaFile IN gdi32 INTEGER hemf
	DECLARE INTEGER GetWindowDC In user32 INTEGER hwnd

	DECLARE INTEGER CreateEnhMetaFile IN gdi32;
		INTEGER hdcRef, STRING lpFilename,;
		STRING @lpRect, STRING lpDescription

	DECLARE INTEGER BitBlt IN gdi32;
		INTEGER hDestDC, INTEGER x, INTEGER y,;
		INTEGER nWidth, INTEGER nHeight, INTEGER hSrcDC,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dwRop

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[BitBlt](../libraries/gdi32/BitBlt.md)  
[CloseEnhMetaFile](../libraries/gdi32/CloseEnhMetaFile.md)  
[CreateEnhMetaFile](../libraries/gdi32/CreateEnhMetaFile.md)  
[DeleteEnhMetaFile](../libraries/gdi32/DeleteEnhMetaFile.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  

 
  
  
***  

