[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieveing information about the active window (even if it is not owned by the calling process)

## Code:
```foxpro  
#DEFINE GUI_CARETBLINKING  1
#DEFINE GUI_INMOVESIZE     2
#DEFINE GUI_INMENUMODE     4
#DEFINE GUI_SYSTEMMENUMODE 8
#DEFINE GUI_POPUPMENUMODE  16
#DEFINE GUITHREADINFO_SIZE  48

*|typedef struct tagGUITHREADINFO {
*|    DWORD cbSize;       0:4
*|    DWORD flags;        4:4
*|    HWND hwndActive;    8:4
*|    HWND hwndFocus;     12:4
*|    HWND hwndCapture;   16:4
*|    HWND hwndMenuOwner; 20:4
*|    HWND hwndMoveSize;  24:4
*|    HWND hwndCaret;     28:4
*|    RECT rcCaret;       32:16
*|} GUITHREADINFO, *PGUITHREADINFO; total 48 bytes

DO declare
? "_VFP.HWnd:", TRANSFORM(_VFP.HWnd, "@0")

IF USED("csResult")
	USE IN csResult
ENDIF

LOCAL lnThreaddId
*lnThreadId = GetCurrentThreadId()  && VFP
lnThreadId = _vfp.ThreadId && 0  && the foreground thread

PRIVATE cBuffer, nFlags
cBuffer = Chr(GUITHREADINFO_SIZE) +;
	Repli(Chr(0), GUITHREADINFO_SIZE-1)

IF GetGUIThreadInfo(lnThreadId, @cBuffer) = 0
	? "Error code:", GetLastError()
	RETURN
ENDIF

= ins("Thread ID", LTRIM(STR(lnThreadId)))

nFlags = buf2dword(SUBSTR(cBuffer, 5,4))

= flg(GUI_CARETBLINKING, "The caret is visible")
= flg(GUI_INMOVESIZE, "The thread is in a move or size loop")
= flg(GUI_INMENUMODE, "The thread is in menu mode")
= flg(GUI_SYSTEMMENUMODE, "The thread is in a system menu mode")
= flg(GUI_POPUPMENUMODE, "The thread has an active pop-up menu")

= wnd(9, "Active window within the thread")
= wnd(13, "Window that has the keyboard focus")
= wnd(17, "Window that has captured the mouse")
= wnd(21, "Window that owns any active menus")
= wnd(25, "Window in a move or size loop")
= wnd(29, "Window that is displaying the caret")

GO TOP
BROW NORMAL NOWAIT
* end of main

PROCEDURE flg(lnFlag, lcTitle)
	= ins(lcTitle, Iif(BitAnd(nFlags, lnFlag)=lnFlag, "True","False"))

PROCEDURE wnd(lnOffs, lcTitle)
	hWindow = buf2dword(SUBSTR(cBuffer, lnOffs,4))
	lcCaption = GetWindowCaption(hWindow)
	= ins(lcTitle, TRANSFORM(hWindow, "@0") + ", [" + lcCaption + "]")

PROCEDURE ins(cTitle, cValue)
	IF NOT USED("csResult")
		CREATE CURSOR csResult (ptitle C(50), pvalue C(200))
	ENDIF

	INSERT INTO csResult VALUES (m.cTitle, m.cValue)
RETURN

PROCEDURE declare
	DECLARE INTEGER GetGUIThreadInfo IN user32;
		INTEGER idThread, STRING @lpgui
	DECLARE INTEGER GetCurrentThreadId IN kernel32
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetWindowText IN user32;
			INTEGER hwnd, STRING @lpString, INTEGER cch	

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)), 8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION GetWindowCaption(lnWindow)
	LOCAL lnLength, lcText
	lcText = SPACE(250)
	lnLength = GetWindowText(lnWindow, @lcText, Len(lcText))
RETURN Iif (lnLength>0, Left(lcText, lnLength), "#empty#")  
```  
***  


## Listed functions:
[GetCurrentThreadId](../libraries/kernel32/GetCurrentThreadId.md)  
[GetGUIThreadInfo](../libraries/user32/GetGUIThreadInfo.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
