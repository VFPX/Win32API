[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)

## Before you begin:
![](../)  

Note that the code sample below just displays the names of files dropped on VFP form in ListBox control. It does not copy or move these files, so the testing is absolutely safe.  

See also:

* [Tracking mouse movement to detect when to start dragging](sample_281.md)  
* [How to drag a Form not using its Titlebar or Caption](sample_195.md)  
  
***  


## Code:
```foxpro  
LOCAL oForm As TForm
oForm = CREATEOBJECT("TForm")
oForm.Visible=.T.
READ EVENTS
* end of main

DEFINE CLASS TForm As Form
#DEFINE WM_DROPFILES 0x0233
#DEFINE GWL_WNDPROC -4
#DEFINE MAX_PATH 260

PROTECTED hWindow, hOrigProc
	hWindow=0
	hOrigProc=0
	Width=350
	Height=200
	MinButton=.F.
	MaxButton=.F.
	Caption=" Dropping files on the form"
	ShowWindow=2
	Autocenter=.T.

	ADD OBJECT ch As CheckBox WITH;
	Left=10, Top=10, Autosize=.T., BackStyle=0,;
	Caption="Accept dropped files", Value=0
	
	ADD OBJECT lst As ListBox WITH;
	Left=5, Top=40, Width=340, Height=130
	
	ADD OBJECT lbl As Label WITH;
	Left=10, Top=176, Autosize=.T., BackStyle=0,;
	Caption="Drag files from an Explorer window and drop on the listbox"

PROCEDURE Init
	THIS.declare

PROCEDURE Destroy
	THIS.ReleaseAccept
	CLEAR EVENTS

PROCEDURE ch.InteractiveChange
	IF THIS.Value = 1
		ThisForm.SetAccept
	ELSE
		ThisForm.ReleaseAccept
	ENDIF

PROCEDURE SetAccept
	THIS.hWindow = GetFocus()
	THIS.hOrigProc = GetWindowLong(THIS.hWindow, GWL_WNDPROC)

	IF VERSION(5) >= 900
		= BINDEVENT(THIS.hWindow, WM_DROPFILES,;
			THIS, "OnFilesDropped")
	ENDIF
	= DragAcceptFiles(THIS.hWindow, 1)

PROCEDURE ReleaseAccept
	= UNBINDEVENTS(THIS)

	IF THIS.hWindow <> 0
		= DragAcceptFiles(THIS.hWindow, 0)
		THIS.hWindow=0
	ENDIF

PROCEDURE OnFilesDropped(hWindow as Integer,;
	nMsgID as Integer, wParam as Integer, lParam as Integer)
* requires VFP9, otherwise ignored
* note that input parameters are predefined and should not be changed
* see WindowProc function for details

	LOCAL nReturn
	nReturn=0
	
	DO CASE
	CASE nMsgID=WM_DROPFILES
		THIS.ProcessDroppedFiles(wParam)
		
	OTHERWISE
	* pass control to the original window procedure
		nReturn = CallWindowProc(THIS.hOrigProc, THIS.hWindow,;
			m.nMsgID, m.wParam, m.lParam)
	ENDCASE
RETURN nReturn

PROTECTED PROCEDURE ProcessDroppedFiles(hDrop)
	LOCAL cPoint, nX, nY

	cPoint = REPLICATE(CHR(0),8)  && POINT buffer
	= DragQueryPoint(hDrop, @cPoint)

	nX = buf2dword(SUBSTR(cPoint,1,4))
	nY = buf2dword(SUBSTR(cPoint,5,4))
	
	* only if clicked inside the listbox
	WITH THIS.lst
		IF NOT (BETWEEN(nX, .Left, .Left+.Width-1);
			AND BETWEEN(nY, .Top, .Top+.Height-1))
			RETURN
			= DragFinish(hDrop)
		ENDIF
	ENDWITH
	
	THIS.lst.Clear
	
	LOCAL nFilecount, nIndex, cBuffer, nLength
	nFilecount = DragQueryFile(hDrop, 0xFFFFFFFF, Null, 0)
	
	FOR nIndex=0 TO nFilecount-1
		cBuffer = REPLICATE(CHR(0), MAX_PATH)
		nLength = DragQueryFile(hDrop, nIndex, @cBuffer, MAX_PATH)
		cBuffer = SUBSTR(cBuffer, 1, nLength)
		THIS.lst.AddItem(cBuffer)
	NEXT

	= DragFinish(hDrop)

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetFocus IN user32
	DECLARE DragFinish IN shell32 INTEGER hDrop

	DECLARE DragAcceptFiles IN Shell32;
		INTEGER hWindow, INTEGER fAccept

	DECLARE INTEGER DragQueryFile IN shell32;
		INTEGER hDrop, INTEGER iFile,;
		STRING @lpszFile, INTEGER cch

	DECLARE INTEGER DragQueryPoint IN shell32;
		INTEGER hDrop, STRING @lppt

	DECLARE INTEGER CallWindowProc IN user32;
		INTEGER lpPrevWndFunc, INTEGER hWindow, LONG Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex

ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[CallWindowProc](../libraries/user32/CallWindowProc.md)  
[DragAcceptFiles](../libraries/user32/DragAcceptFiles.md)  
[DragFinish](../libraries/shell32/DragFinish.md)  
[DragQueryFile](../libraries/shell32/DragQueryFile.md)  
[DragQueryPoint](../libraries/shell32/DragQueryPoint.md)  
[GetFocus](../libraries/user32/GetFocus.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[WindowProc](../libraries/kernel32/WindowProc.md)  

## Comment:
[WM_DROPFILES](http://msdn.microsoft.com/en-us/library/windows/desktop/bb774303(v=vs.85).aspx) window message -- sent when the user drops a file on the window of an application that has registered itself as a recipient of dropped files.  
  
[DragAcceptFiles](http://msdn.microsoft.com/en-us/library/windows/desktop/bb776406(v=vs.85).aspx) function -- registers whether a window accepts dropped files.  
  
A good reading on the subject, Andrew MacNeill's [Using Drag and Drop in your Applications](http://www.aksel.com/whitepapers/dragdrop.htm). The article explains the basics and the more of using FoxPro native OLEDragOver and OLEDragDrop events for dragging and dropping files from Explorer and Outlook windows.  
  
***  

