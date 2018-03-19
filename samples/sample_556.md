[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to find which fonts Windows uses for drawing captions, menus and message boxes

## Short description:
Calling SystemParametersInfo with SPI_GETNONCLIENTMETRICS input parameter populates the NONCLIENTMETRICS structure. This structure contains the metrics associated with the nonclient area of a nonminimized window. Among the metrics included are the settings for 5 fonts, the OS uses for drawing captions, small captions, menus, status bars and message boxes.  
***  


## Before you begin:
Calling SystemParametersInfo with SPI_GETNONCLIENTMETRICS input parameter populates the NONCLIENTMETRICS structure.  

This structure contains the metrics associated with the *nonclient area* of a nonminimized window. Among the metrics included are the settings for 5 fonts (LOGFONT structures), the OS uses for drawing captions, small captions, menus, status bars and message boxes.  

See also:

* [Displaying icons and descriptions associated with files and folders](sample_530.md)  
  
***  


## Code:
```foxpro  
#DEFINE SPI_GETNONCLIENTMETRICS 0x0029
#DEFINE NONCLIENTMETRICS_SIZE 0x0154
#DEFINE LOGFONT_SIZE 0x003c
#DEFINE LOGPIXELSY 0x005a

DO declare

LOCAL cNonClientMetrics, cLogFont

* populating NONCLIENTMETRICS structure
* the size of the structure occupies first 4 bytes
cNonClientMetrics=num2dword(NONCLIENTMETRICS_SIZE)

* padding the structure to the required size
cNonClientMetrics=PADR(cNonClientMetrics,;
	NONCLIENTMETRICS_SIZE, CHR(0))

* retrieving the metrics associated with the nonclient area
* of nonminimized windows
IF SystemParametersInfo(SPI_GETNONCLIENTMETRICS,;
	NONCLIENTMETRICS_SIZE, @cNonClientMetrics, 0) = 0

	? "SystemParametersInfo call failed:", GetLastError()
	RETURN
ENDIF

* among other metrics, populated NONCLIENTMETRICS structure
* contains data for 5 fonts used for drawing:
* captions, small captions, menus, status bar and message boxes
LOCAL oCaptionFont As clsLogFont, oSmCaptionFont As clsLogFont,;
	oMenuFont As clsLogFont, oStatusFont As clsLogFont,;
	oMessageFont As clsLogFont

oCaptionFont = CREATEOBJECT("clsLogFont",;
	SUBSTR(cNonClientMetrics, 25, LOGFONT_SIZE))

oSmCaptionFont = CREATEOBJECT("clsLogFont",;
	SUBSTR(cNonClientMetrics, 93, LOGFONT_SIZE))

oMenuFont = CREATEOBJECT("clsLogFont",;
	SUBSTR(cNonClientMetrics, 161, LOGFONT_SIZE))

oStatusFont = CREATEOBJECT("clsLogFont",;
	SUBSTR(cNonClientMetrics, 221, LOGFONT_SIZE))

oMessageFont = CREATEOBJECT("clsLogFont",;
	SUBSTR(cNonClientMetrics, 281, LOGFONT_SIZE))

* Vista: Segoe UI, 9, N, 1
* WinXP: Tahoma, 9, N, 1
? oMessageFont.GetFontDesc()
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWindow

	DECLARE INTEGER SystemParametersInfo IN user32;
		INTEGER uiAction, INTEGER uiParam,;
		STRING @pvParam, INTEGER fWinIni

	DECLARE INTEGER GetDeviceCaps IN gdi32;
		INTEGER hdc, INTEGER nIndex

	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hWindow, INTEGER hDC

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

DEFINE CLASS clsLogFont As Relation
* implements LOGFONT structure
	lfHeight=0
	lfWidth=0
	lfEscapement=0
	lfOrientation=0
	lfWeight=0
	lfItalic=.F.
	lfUnderline=.F.
	lfStrikeOut=.F.
	lfCharSet=0
	lfOutPrecision=0
	lfClipPrecision=0
	lfQuality=0
	lfPitchAndFamily=0
	lfFaceName=""

PROCEDURE Init(cBuf As String)
	WITH THIS
		.lfHeight=buf2dword(SUBSTR(cBuf,1,4))
		.lfWidth=buf2dword(SUBSTR(cBuf,5,4))
		.lfEscapement=buf2dword(SUBSTR(cBuf,9,4))
		.lfOrientation=buf2dword(SUBSTR(cBuf,13,4))
		.lfWeight=buf2dword(SUBSTR(cBuf,17,4))
		.lfItalic = (ASC(SUBSTR(cBuf,21,1)) <> 0)
		.lfUnderline = (ASC(SUBSTR(cBuf,22,1)) <> 0)
		.lfStrikeOut = (ASC(SUBSTR(cBuf,23,1)) <> 0)
		.lfCharSet=ASC(SUBSTR(cBuf,24,1))
		.lfOutPrecision=ASC(SUBSTR(cBuf,25,1))
		.lfClipPrecision=ASC(SUBSTR(cBuf,26,1))
		.lfQuality=ASC(SUBSTR(cBuf,27,1))
		.lfPitchAndFamily=ASC(SUBSTR(cBuf,28,1))
		.lfFaceName=STRTRAN(SUBSTR(cBuf,29,32), CHR(0),"")
	ENDWITH

PROCEDURE GetFontDesc() As String
* returns GETFONT() style description for the font:
* cFontName, nFontSize, cFontStyle, nFontCharSet
WITH THIS
	LOCAL cFontStyle, nFontSize
	cFontStyle=""
	cFontStyle=cFontStyle+IIF(.lfWeight > 400, "B", "")
	cFontStyle=cFontStyle+IIF(.lfItalic, "I", "")
	cFontStyle=cFontStyle+IIF(.lfUnderline, "U", "")
	cFontStyle=cFontStyle+IIF(.lfStrikeOut, "S", "")
	cFontStyle=IIF(EMPTY(cFontStyle), "N", cFontStyle)

	RETURN .lfFaceName + ", " +;
		TRANSFORM(.GetFontSize()) + ", " +;
		m.cFontStyle + ", " + TRANSFORM(.lfCharSet)
		
ENDWITH

FUNCTION GetFontSize() As Number
* converts the font height to font size;
* note that in this particular case the font height is a negative value
	LOCAL hWindow, hDC, nPxPerInchY
	hWindow=_screen.HWnd
	hDC=GetWindowDC(hWindow)
	nPxPerInchY = GetDeviceCaps(hDC, LOGPIXELSY)
	ReleaseDC(hWindow, hDC)
RETURN ROUND((ABS(THIS.lfHeight) * 72) / nPxPerInchY, 0)

ENDDEFINE  
```  
***  


## Listed functions:
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SystemParametersInfo](../libraries/user32/SystemParametersInfo.md)  

## Comment:
Normally all 5 fonts have identical settings.  
Vista: *Segoe UI, 9, N, 1*  
WinXP: *Tahoma, 9, N, 1*  
  
***  

