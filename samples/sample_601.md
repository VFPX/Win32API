[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Monitoring clipboard content changes (VFP9)

## Before you begin:
After a VFP form (ThisForm.hWnd) is added to the *clipboard format listener list*, it receives WM_CLIPBOARDUPDATE message whenever the contents of the clipboard changes.  

![](../images/clipboardlistener.png)  

See also:

* [Enumerating data formats currently available on the clipboard](sample_032.md)  
* [How to disable the Windows Clipboard](sample_488.md)  
* [Capturing keyboard activity of another application with the Raw Input API](sample_572.md)  

  
***  


## Code:
```foxpro  
LOCAL oForm as TForm
oForm = CREATEOBJECT("TForm")
oForm.Visible = .T.
READ EVENTS

DEFINE CLASS TForm as Form
#DEFINE CRLF CHR(13)+CHR(10)
	Caption="Clipboard Listener"
	Width=500
	Height=500
	AutoCenter=.T.
	MaxButton=.F.
	MinButton=.F.
	
	ADD OBJECT CFListener As ClipboardListener
	
	ADD OBJECT Button1 as CommandButton WITH;
	Left=10, Top=10, Width=120, Height=27,;
	Caption="Start listening"
	
	ADD OBJECT Edit1 as EditBox WITH;
	Left=10, Top=50, Width=480, Height=420,;
	MaxLength=0

PROCEDURE Destroy
	CLEAR EVENTS

PROCEDURE Button1.Click
	IF ThisForm.CFListener.IsListening()
		ThisForm.CFListener.StopListening
		THIS.Caption = "Start listening"
	ELSE
		IF ThisForm.CFListener.StartListening(ThisForm.HWnd)
			THIS.Caption = "Stop listening"
		ENDIF
	ENDIF

PROCEDURE CFListener.OnUdfMessage
PARAMETERS wParam As Integer, lParam As Integer
	DODEFAULT()
	
	LOCAL cValue
	cValue = ThisForm.Edit1.Value
	
	ThisForm.Edit1.Value = m.cValue +;
		TRANSFORM(DATETIME()) + CRLF +;
		"Formats: " + THIS.GetCFInfo() + CRLF + CRLF
	
ENDDEFINE

DEFINE CLASS ClipboardListener as Control
#DEFINE GWL_WNDPROC -4
#DEFINE WM_CLIPBOARDUPDATE 0x031D

* some of standard clipboard formats
#DEFINE CF_BITMAP            2
#DEFINE CF_DIB               8
#DEFINE CF_DIBV5            17
#DEFINE CF_DIF               5
#DEFINE CF_DSPBITMAP       130
#DEFINE CF_DSPENHMETAFILE  142
#DEFINE CF_DSPMETAFILEPICT 131
#DEFINE CF_DSPTEXT         129
#DEFINE CF_ENHMETAFILE      14
#DEFINE CF_GDIOBJFIRST     768
#DEFINE CF_GDIOBJLAST     1023
#DEFINE CF_HDROP            15
#DEFINE CF_LOCALE           16
#DEFINE CF_METAFILEPICT      3
#DEFINE CF_OEMTEXT           7
#DEFINE CF_OWNERDISPLAY    128
#DEFINE CF_PALETTE           9
#DEFINE CF_PENDATA          10
#DEFINE CF_PRIVATEFIRST    512
#DEFINE CF_PRIVATELAST     767
#DEFINE CF_RIFF             11
#DEFINE CF_SYLK              4
#DEFINE CF_TEXT              1
#DEFINE CF_WAVE             12
#DEFINE CF_TIFF              6
#DEFINE CF_UNICODETEXT      13

PROTECTED ListeningOn
	hWindow=0
	hOrigProc=0
	ListeningOn=.F.
	Visible=.F.

PROCEDURE Init
	THIS.declare
	THIS.hOrigProc = GetWindowLong(THIS.hWindow, GWL_WNDPROC)

PROCEDURE Destroy
	THIS.StopListening
	= CloseClipboard()

FUNCTION IsListening() as Boolean
RETURN THIS.ListeningOn

PROCEDURE StartListening(hWindow as Number)
* starts listening on clipboard changes
	THIS.StopListening

	LOCAL nResult
	nResult = AddClipboardFormatListener(m.hWindow)

	IF nResult = 0
		* 1400 = ERROR_INVALID_WINDOW_HANDLE
		ACTIVATE SCREEN
		? "AddClipboardFormatListener failed:", GetLastError(), m.hWindow
		RETURN .F.
	ENDIF

	THIS.hWindow = m.hWindow

	IF VERSION(5) >= 900  && VFP9+
		= BINDEVENT(THIS.hWindow, WM_CLIPBOARDUPDATE,;
			THIS, "WindowProc")
	ENDIF
	
	THIS.ListeningOn = .T.
RETURN .T.

PROCEDURE StopListening
* stops listening on clipboard changes
	THIS.ListeningOn = .F.
	IF THIS.hWindow = 0
		RETURN
	ENDIF

	IF VERSION(5) >= 900  && VFP9+
		UNBINDEVENTS(THIS.hWindow)
	ENDIF

	RemoveClipboardFormatListener(THIS.hWindow)
	THIS.hWindow = 0

PROCEDURE WindowProc(hWindow as Integer,;
	nMsgID as Integer, wParam as Integer, lParam as Integer)
* requires VFP9, otherwise ignored

	LOCAL nReturn
	nReturn=0
	
	DO CASE
	CASE nMsgID = WM_CLIPBOARDUPDATE
		THIS.OnUdfMessage(wParam, lParam)

	OTHERWISE
	* pass control to the original window procedure
		nReturn = CallWindowProc(THIS.hOrigProc, THIS.hWindow,;
			m.nMsgID, m.wParam, m.lParam)
	ENDCASE

RETURN nReturn

PROCEDURE OnUdfMessage(wParam As Integer, lParam As Integer)
* a placeholder, override

FUNCTION GetCFInfo() as String
* returns list of formats currently on the clipboard
	LOCAL nIndex, cResult
	cResult=""
	nIndex = 0

	= OpenClipboard(THIS.hWindow)

	TRY
		DO WHILE .T.
			nIndex = EnumClipboardFormats(m.nIndex)
			IF m.nIndex = 0
				EXIT
			ENDIF
			
			cResult = m.cResult + IIF(EMPTY(m.cResult), "", ", ") +;
				THIS.GetCFName(m.nIndex)
		ENDDO
	CATCH
	FINALLY
		= CloseClipboard()
	ENDTRY

RETURN m.cResult

FUNCTION GetCFName(nIndex) as String
* returns the name for a specified clipboard format
#DEFINE cmBufsize 250
	LOCAL cBuffer, nResult
	cBuffer = REPLICATE(CHR(0), cmBufsize)
	nResult = GetClipboardFormatName(nIndex, @cBuffer, cmBufsize)

RETURN IIF(nResult=0,;
	"[" + TRANSFORM(m.nIndex) + "]",;
	LEFT(cBuffer, nResult))

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER AddClipboardFormatListener IN user32;
		INTEGER hWindow

	DECLARE INTEGER RemoveClipboardFormatListener IN user32;
		INTEGER hWindow

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex

	DECLARE INTEGER CallWindowProc IN user32;
		INTEGER lpPrevWndFunc, INTEGER hWindow, LONG Msg,;
		INTEGER wParam, INTEGER lParam

	DECLARE INTEGER GetClipboardFormatName IN user32;
		INTEGER fmt, STRING @lpszFmtName, INTEGER cchMaxCount

	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER EnumClipboardFormats IN user32 INTEGER wFormat

ENDDEFINE  
```  
***  


## Listed functions:
[AddClipboardFormatListener](../libraries/user32/AddClipboardFormatListener.md)  
[CallWindowProc](../libraries/user32/CallWindowProc.md)  
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[EnumClipboardFormats](../libraries/user32/EnumClipboardFormats.md)  
[GetClipboardFormatName](../libraries/user32/GetClipboardFormatName.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[RemoveClipboardFormatListener](../libraries/user32/RemoveClipboardFormatListener.md)  

## Comment:
```txt
#define WM_CLIPBOARDUPDATE 0x031D
```
  
See also:

[GetClipboardSequenceNumber](../libraries/user32/GetClipboardSequenceNumber.md)
   
The result returned by this API function increments whenever the content of the clipboard changes, including emptying the clipboard. For example, a single copy-paste operation in Excel, first clears the clipboard, and then adds data to it in N different formats. So before-and-after difference will be N+1.  
  
***  

