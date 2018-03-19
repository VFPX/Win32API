[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Printing text with the Escape function

## Before you begin:
This code allows printed pages with controlled fonts, colours, positioning. You can even insert pictures using StretchBlt function.  

This approach can be good for printing labels, ad-hoc reports, invoices, bank cheques etc. Of course it should not be another Report Designer, one is already enough.  
  
***  


## Code:
```foxpro  
* constants for using with the Escape function
#DEFINE NEWFRAME  1
#DEFINE STARTDOC  10
#DEFINE ENDDOC    11

* CreateFont constants
#DEFINE FW_NORMAL           400
#DEFINE FW_BOLD             700
#DEFINE ANSI_CHARSET        0
#DEFINE OUT_OUTLINE_PRECIS  8
#DEFINE CLIP_STROKE_PRECIS  2
#DEFINE PROOF_QUALITY       2
#DEFINE DEFAULT_PITCH       0

#DEFINE LOGPIXELSX           88
#DEFINE LOGPIXELSY           90
#DEFINE PHYSICALOFFSETX     112
#DEFINE PHYSICALOFFSETY     113

#DEFINE cnFontSize 16

DO decl

PRIVATE hPrnDC, prnOffsX, prnOffsY, xScale, yScale
STORE 0 TO hPrnDC, xScale, yScale

IF Not GetPrinterDC()
	? "Unable to access default printer"
	RETURN
ENDIF

DO GetScale

* creating printer fonts
DIMEN hFont[3]
hFont[1] = CreateFont(xScale*cnFontSize, 0, 0,0, FW_BOLD, 0,0,0,;
	ANSI_CHARSET, OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
	PROOF_QUALITY, DEFAULT_PITCH, "Times New Roman")

hFont[2] = CreateFont(xScale*cnFontSize, 0, 0,0, FW_NORMAL, 0,0,0,;
	ANSI_CHARSET, OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
	PROOF_QUALITY, DEFAULT_PITCH, "Verdana")

hFont[3] = CreateFont(xScale*cnFontSize, 0, 0,0, FW_NORMAL, 0,0,0,;
	ANSI_CHARSET, OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
	PROOF_QUALITY, DEFAULT_PITCH, "Courier New")

STORE 70 TO prnOffsX, prnOffsY

* informs a printer driver that a new print job is starting.
= Escape(hPrnDC, STARTDOC, 0, 0, 0)

= SelectObject(hPrnDC, hFont[1])
= SetTextColor(hPrnDC, Rgb(192,0,0))

= prn("Escape")
= prn("")

= SelectObject(hPrnDC, hFont[2])
= SetTextColor(hPrnDC, 0)

= prn("The Escape function enables applications to access capabilities of a particular device ")
= prn("not directly available through GDI. Escape calls made by an application are translated ")
= prn("and sent to the driver. ")
= prn("")

= SelectObject(hPrnDC, hFont[3])
= SetTextColor(hPrnDC, Rgb(0,0,128))

= prn("int Escape(")
= prn("  HDC hdc,           // handle to DC")
= prn("  int nEscape,       // escape function")
= prn("  int cbInput,       // size of input structure")
= prn("  LPCSTR lpvInData,  // input structure")
= prn("  LPVOID lpvOutData  // output structure")
= prn(");")
= prn("")

* informs the printer that the application has finished writing to a page.
= Escape(hPrnDC, NEWFRAME, 0,0,0)

* ends a print job started by the STARTDOC escape.
= Escape(hPrnDC, ENDDOC, 0,0,0)

* releasing system resources
= DeleteObject(hFont[3])
= DeleteObject(hFont[2])
= DeleteObject(hFont[1])
= DeleteDC(hPrnDC)
* end of main

FUNCTION GetPrinterDC
* returns device context for default printer
	LOCAL lcBuffer, lcPrinter, lcDriver, lcPort
	lcBuffer = Repli(Chr(0), 120)

	* retrieving the printer, printer driver, and output-port names
	= GetProfileString("Windows", "Device", ",,,", @lcBuffer, Len(lcBuffer))
	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")

	DIMEN arrPos[3]
	arrPos[1] = AT(",", lcBuffer, 1)
	arrPos[2] = AT(",", lcBuffer, 2)
	arrPos[3] = Len(lcBuffer)

	lcPrinter = SUBSTR(lcBuffer, 1, arrPos[1]-1)
	lcDriver = SUBSTR(lcBuffer, arrPos[1]+1, arrPos[2]-arrPos[1]-1)
	lcPort = SUBSTR(lcBuffer, arrPos[2]+1, arrPos[3]-arrPos[2])

	* creating device context for the printer
	hPrnDC = CreateDC(lcDriver, lcPrinter, lcPort, 0)
RETURN (hPrnDC <> 0)

PROCEDURE prn(lcText)
	= TextOut(hPrnDC, prnOffsX, prnOffsY, lcText, Len(lcText))
	prnOffsY = prnOffsY + xScale*cnFontSize*1.2

FUNCTION GetScale
* retrieve scaling factor values from screen to printer
	DECLARE INTEGER GetDesktopWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hwnd, INTEGER hdc

	LOCAL hWindow, hDC
	hWindow = GetDesktopWindow()
	hDC = GetWindowDC(hWindow)
	xScale = GetDeviceCaps(hPrnDC, LOGPIXELSX)/GetDeviceCaps(hDC, LOGPIXELSX)
	yScale = GetDeviceCaps(hPrnDC, LOGPIXELSY)/GetDeviceCaps(hDC, LOGPIXELSY)
	= ReleaseDC(hWindow, hDC)
RETURN xScale

PROCEDURE decl
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER SelectObject IN gdi32 INTEGER hdc, INTEGER hObject
	DECLARE INTEGER SetTextColor IN gdi32 INTEGER hdc, INTEGER crColor
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

    DECLARE INTEGER CreateDC IN gdi32;
		STRING lpszDriver, STRING lpszDevice,;
		STRING lpszOutput, INTEGER lpInitData

	DECLARE INTEGER Escape IN gdi32;
		INTEGER hdc, INTEGER nEscape, INTEGER cbInput,;
		INTEGER lpvInData, INTEGER lpvOutData

	DECLARE INTEGER TextOut IN gdi32;
	    INTEGER hdc, INTEGER x, INTEGER y,;
	    STRING lpString, INTEGER nCount

	DECLARE INTEGER CreateFont IN gdi32;
		INTEGER nHeight, INTEGER nWidth, INTEGER nEscapement,;
		INTEGER nOrientation, INTEGER fnWeight, INTEGER fdwItalic,;
		INTEGER fdwUnderline, INTEGER fdwStrikeOut, INTEGER fdwCharSet,;
		INTEGER fdwOutputPrec, INTEGER fdwClipPrec, INTEGER fdwQuality,;
		INTEGER fdwPitchAndFamily, STRING lpszFace  
```  
***  


## Listed functions:
[CreateDC](../libraries/gdi32/CreateDC.md)  
[CreateFont](../libraries/gdi32/CreateFont.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[Escape](../libraries/gdi32/Escape.md)  
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetTextColor](../libraries/gdi32/SetTextColor.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[TextOut](../libraries/gdi32/TextOut.md)  
