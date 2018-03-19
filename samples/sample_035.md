[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Printing text on the main VFP window

## Code:
```foxpro  
#DEFINE ANSI_CHARSET          0
#DEFINE OUT_DEFAULT_PRECIS    0
#DEFINE OUT_DEVICE_PRECIS     5
#DEFINE OUT_OUTLINE_PRECIS    8

#DEFINE CLIP_DEFAULT_PRECIS   0
#DEFINE CLIP_STROKE_PRECIS    2

#DEFINE DEFAULT_QUALITY       0
#DEFINE PROOF_QUALITY         2

#DEFINE DEFAULT_PITCH         0
#DEFINE FW_BOLD             700

#DEFINE TRANSPARENT           1
#DEFINE OPAQUE                2

	DO decl
	
	lcText = "Printing Text"
	FOR ii=200 TO 1 STEP-1
		lnColor = Rgb(Max(0,255-ii), Max(0,128-ii*5), Min(255,128+ii*10))
		= _print (lcText, lnColor, -ii)

		ii = ii - 30
		= _print (lcText, Rgb(80,80,80), -ii)
	ENDFOR
	= _print (lcText, Rgb(164,0,0), 0)

PROCEDURE  _print (lcText, lnColor, lnAngle)
	hFont = CreateFont (;
		100,0, lnAngle,lnAngle, FW_BOLD, 0,0,0, ANSI_CHARSET,;
		OUT_OUTLINE_PRECIS, CLIP_STROKE_PRECIS,;
		PROOF_QUALITY, DEFAULT_PITCH, "Times New Roman")

	hwnd = GetActiveWindow()
	hdc = GetWindowDC (hwnd)

	* select new font into the device context
	* and delete the old one
	= DeleteObject (SelectObject (hdc, hFont))

	* set text color on a transparent background
	= SetTextColor (hdc, lnColor)
	= SetBkMode (hdc, TRANSPARENT)

	* the printing
	= TextOut (hdc, 50, 100, lcText, Len(lcText))

	* release system resources
	= DeleteObject (hFont)
	= ReleaseDC (hwnd, hdc)

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd

	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER SetTextColor IN gdi32;
		INTEGER hdc, INTEGER crColor

	DECLARE INTEGER SelectObject IN gdi32;
		INTEGER hdc, INTEGER hObject

	DECLARE INTEGER TextOut IN gdi32;
		INTEGER hdc, INTEGER x, INTEGER y,;
		STRING  lpString, INTEGER nCount

	DECLARE INTEGER SetBkMode IN gdi32;
		INTEGER hdc, INTEGER iBkMode

	DECLARE INTEGER CreateFont IN gdi32;
		INTEGER nHeight, INTEGER nWidth,;
		INTEGER nEscapement, INTEGER nOrientation,;
		INTEGER fnWeight, INTEGER fdwItalic,;
		INTEGER fdwUnderline, INTEGER fdwStrikeOut,;
		INTEGER fdwCharSet,;
		INTEGER fdwOutputPrecision,;
		INTEGER fdwClipPrecision,;
		INTEGER fdwQuality,;
		INTEGER fdwPitchAndFamily,;
		STRING  lpszFace  
```  
***  


## Listed functions:
[CreateFont](../libraries/gdi32/CreateFont.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
[SelectObject](../libraries/gdi32/SelectObject.md)  
[SetBkMode](../libraries/gdi32/SetBkMode.md)  
[SetTextColor](../libraries/gdi32/SetTextColor.md)  
[TextOut](../libraries/gdi32/TextOut.md)  

## Comment:
Any output from FoxPro command like CLEAR and ?/?? wipes the image produced by this code. Curiously CLEAR command even standing above the TextOut in a source code sometimes removes any printing produced by the TextOut.  
  
***  

