[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading metrics for the currently selected font

## Code:
```foxpro  
DO decl

*|typedef struct tagTEXTMETRIC {
*|  LONG tmHeight;             0:4
*|  LONG tmAscent;             4:4
*|  LONG tmDescent;            8:4
*|  LONG tmInternalLeading;    12:4
*|  LONG tmExternalLeading;    16:4
*|  LONG tmAveCharWidth;       20:4
*|  LONG tmMaxCharWidth;       24:4
*|  LONG tmWeight;             28:4
*|  LONG tmOverhang;           32:4
*|  LONG tmDigitizedAspectX;   36:4
*|  LONG tmDigitizedAspectY;   40:4
*|  TCHAR tmFirstChar;         44:1
*|  TCHAR tmLastChar;          45:1
*|  TCHAR tmDefaultChar;       46:1
*|  TCHAR tmBreakChar;         47:1
*|  BYTE tmItalic;             48:1
*|  BYTE tmUnderlined;         49:1
*|  BYTE tmStruckOut;          50:1
*|  BYTE tmPitchAndFamily;     51:1
*|  BYTE tmCharSet;            52:1
*|} TEXTMETRIC, *PTEXTMETRIC;

	LOCAL lcBuffer, hWindow, hDC
	lcBuffer = Repli(Chr(0), 250)
	hWindow = GetActiveWindow()
	hDC = GetWindowDC(hWindow)
	
	= GetTextMetrics(hDC, @lcBuffer)
	
	= _add("Height (ascent + descent)",;
		b2d(SUBS(lcBuffer, 1,4)))

	= _add("Ascent (units above the base line)";
		 b2d(SUBS(lcBuffer, 5,4)))

	= _add("Descent (units below the base line)",;
		b2d(SUBS(lcBuffer, 9,4)))

	= _add("Leading inside the bounds...",;
		b2d(SUBS(lcBuffer, 13,4)))

	= _add("Extra leading added between rows",;
		b2d(SUBS(lcBuffer, 17,4)))

	= _add("Avg width of characters",;
		b2d(SUBS(lcBuffer, 21,4)))

	= _add("Width of the widest character",;
		b2d(SUBS(lcBuffer, 25,4)))

	= _add("Weight of the font",;
		b2d(SUBS(lcBuffer, 29,4)))

	= _add("Extra width per string", b2d(SUBS(lcBuffer, 33,4)))

	= _add("Optimal horiz aspect", b2d(SUBS(lcBuffer, 37,4)))

	= _add("Optimal vert aspect", b2d(SUBS(lcBuffer, 41,4)))
	
	= _add("First character defined", Asc(SUBS(lcBuffer, 45,1)))

	= _add("Last character defined", Asc(SUBS(lcBuffer, 46,1)))

	= _add("Substitute if char not found", Asc(SUBS(lcBuffer, 47,1)))

	= _add("Char for word breaks", Asc(SUBS(lcBuffer, 48,1)))
	
	= _add("Italic", Asc(SUBS(lcBuffer, 49,1)))
	= _add("Underlined", Asc(SUBS(lcBuffer, 50,1)))
	= _add("Strikeout", Asc(SUBS(lcBuffer, 51,1)))

	= _add("Font pitch", BitAnd(15,Asc(SUBS(lcBuffer, 52,1))))
	= _add("Font family", BitAnd(240,Asc(SUBS(lcBuffer, 52,1))))

	= _add("Font Character Set", Asc(SUBS(lcBuffer, 53,1)))

	ReleaseDC(hWindow, hDC)
	GO TOP
	BROW NORMAL NOWAIT
* end of main

PROCEDURE _add(lcName, lnValue)
	IF Not USED("csResult")
		CREATE CURSOR csResult (paramname C(35), paramvalue C(50))
	ENDIF
	INSERT INTO csResult VALUES (m.lcName, LTRIM(STR(m.lnValue)))

PROCEDURE decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd

	DECLARE INTEGER ReleaseDC IN user32 ;
		INTEGER hwnd,  INTEGER hdc

	DECLARE INTEGER GetTextMetrics IN gdi32;
		INTEGER hdc, STRING @lptm

FUNCTION  b2d(lcBuffer)
RETURN Asc(SUBS(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBS(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBS(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBS(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetTextMetrics](../libraries/gdi32/GetTextMetrics.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
