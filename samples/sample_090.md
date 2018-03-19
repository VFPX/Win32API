[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GetFocus returns a HWND value

## Code:
```foxpro  
PUBLIC frm
frm = CreateObject ("Tform")
frm.Visible = .T.

DEFINE CLASS Tform As form
	caption = " Testing the GetFocus API"
	width = 500
	height = 350
	autocenter = .T.
	colwidth = 100
	rowheight = 20
	DIMEN colnames [3]
	DIMEN rownames [7]
	
FUNCTION  Init
	THIS.colnames [1] = "VFP main"
	THIS.colnames [2] = "GetFocus"
	THIS.colnames [3] = "ThisForm"
	
	THIS.rownames [1] = "HWND:"
	THIS.rownames [2] = "left:"
	THIS.rownames [3] = "top:"
	THIS.rownames [4] = "right:"
	THIS.rownames [5] = "bottom:"
	THIS.rownames [6] = "width:"
	THIS.rownames [7] = "height:"

	THIS.addLabels
ENDFUNC

PROCEDURE  activate
	THIS._showAll
ENDPROC

PROCEDURE  moved
	THIS._showAll
ENDPROC

PROCEDURE  resize
	THIS._showAll
ENDPROC

PROCEDURE  load
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE SHORT GetWindowRect IN user32 INTEGER hwnd, STRING @ lpRect
ENDPROC

PROCEDURE  addLabels
	LOCAL lnRow, lnCol, lcName, lbl
	FOR lnCol=1 TO 3
		lcName = "colname" + LTRIM(STR(lnCol))
		THIS.addObject (lcName, "Theader")
		lbl = EVAL ("THIS." + lcName)
		lnLeft = 80 + THIS.colwidth*(lnCol-1)
		WITH lbl
			.top = 10
			.left = lnLeft
			.caption = THIS.colnames [lnCol]
			.visible = .T.
		ENDWITH

		FOR lnRow=1 TO 7
			lnTop = THIS.rowheight*(lnRow+1)
			IF lnCol = 1
				lcName = "rowname" + LTRIM(STR(lnRow))
				THIS.addObject (lcName, "Theader")
				lbl = EVAL ("THIS." + lcName)
				WITH lbl
					.top = lnTop
					.left = 10
					.caption = THIS.rownames [lnRow]
					.visible = .T.
				ENDWITH
			ENDIF

			lcName = THIS.getLabelName(lnCol, lnRow)
			THIS.addObject (lcName, "Tinfo")
			lbl = EVAL ("THIS." + lcName)
			WITH lbl
				.top = lnTop
				.left = lnLeft
				.caption = lcName
				.visible = .T.
			ENDWITH
		ENDFOR
	ENDFOR
ENDPROC

FUNCTION  getLabelName (lnCol, lnRow)
RETURN  "lbl" + LTRIM(STR(lnCol)) + LTRIM(STR(lnRow))

PROCEDURE  _showAll
	THIS._showHwnd (1, GetActiveWindow())
	THIS._showHwnd (2, GetFocus())
	THIS._showThis
ENDPROC

PROCEDURE  _showThis
	lnCol = 3
	THIS._show (lnCol, 1,;
		Iif(VERSION(5)>600, THIS.hwnd, "-"))
	THIS._show (lnCol, 2, THIS.left)
	THIS._show (lnCol, 3, THIS.top)
	THIS._show (lnCol, 4, THIS.left + THIS.width - 1)
	THIS._show (lnCol, 5, THIS.top + THIS.height - 1)
	THIS._show (lnCol, 6, THIS.width)
	THIS._show (lnCol, 7, THIS.height)
ENDPROC

PROCEDURE  _showHwnd (lnCol, hwnd)
	LOCAL lpRect
	lpRect = REPLI (Chr(0), 16)
	= GetWindowRect (hwnd, @lpRect)

	lnWinLeft   = buf2dword(SUBSTR(lpRect, 1,4))
	lnWinTop    = buf2dword(SUBSTR(lpRect, 5,4))
	lnWinRight  = buf2dword(SUBSTR(lpRect, 9,4))
	lnWinBottom = buf2dword(SUBSTR(lpRect,13,4))
	lnWinWidth  = lnWinRight - lnWinLeft + 1
	lnWinHeight = lnWinBottom - lnWinTop + 1

	THIS._show (lnCol, 1, hwnd)
	THIS._show (lnCol, 2, lnWinLeft)
	THIS._show (lnCol, 3, lnWinTop)
	THIS._show (lnCol, 4, lnWinRight)
	THIS._show (lnCol, 5, lnWinBottom)
	THIS._show (lnCol, 6, lnWinWidth)
	THIS._show (lnCol, 7, lnWinHeight)
ENDPROC

PROCEDURE  _show (lnCol, lnRow, lvValue)
	LOCAL obj
	obj = EVAL ("THIS." + THIS.getLabelName (lnCol, lnRow))
	DO CASE
	CASE TYPE ("lvValue") = "C"
		obj.Caption = lvValue
	CASE TYPE ("lvValue") = "N"
		obj.Caption = LTRIM(STR(lvValue))
	ENDCASE
ENDPROC
ENDDEFINE

DEFINE CLASS Theader As Tlabel
	FontName = "arial"
	FontBold = .T.
ENDDEFINE

DEFINE CLASS Tinfo As Tlabel
	FontName = "Courier"
ENDDEFINE

DEFINE CLASS Tlabel As Label
	autosize = .T.
	backstyle = 1
	FontSize = 10
ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowRect](../libraries/user32/GetWindowRect.md)  

## Comment:
The form in this example displays geometrical parameters of itself and of two windows presented by their HWNDs: (1) main VFP window retrieving from GetActiveWindow, and the window that has the keyboard focus. Its HWND is returned by GetFocus function.  
  
Move and resize this form, and see how all these parameters change.  
  
***  

