[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to intercept window messages sent to VFP form

## Before you begin:
Before testing this code download [WinProcXT.dll](../downloads/WinProcXT.dll) to a local directory and register it:

```txt
regsvr32 c:\temp\WinProcXT.dll
```


Change "c:\temp" to the name of a directory where you copied the DLL file.  

This is an ActiveX DLL. The VB code is available [here.](../downloads/winproc.zip)

The DLL reassignes the WindowProc address of the VFP form to its own function and sends system messages to a text file. Change in the following program code the "c:\temp\log.txt" to any appropriate file name.  

Every system message has three parameters to be saved: message identifier, first message parameter, second message parameter.  

Run the following code. Right after you close the form a list of system messages saved during its execution appears. Usually this list ends with message identifiers 2 (WM_DESTROY) and 130 (WM_NCDESTROY).  

List of some message identifiers is available [here.](../downloads/wm.dbf)

* * *  
For VFP9 use BINDEVENT() to trap Windows messages.  
  
***  


## Code:
```foxpro  
PUBLIC objForm
objForm = CreateObject("TForm")
objForm.Visible = .T.

DEFINE CLASS TForm As Form
	Width=460
	Height=300
	AutoCenter=.T.
	Caption=" Recording Window Messages"
	KeyPreview=.T.
	recorder=.F.
	hWindow=0
	
PROCEDURE Activate
	IF THIS.hWindow = 0
		DECLARE INTEGER GetFocus IN user32
		THIS.hWindow = GetFocus()

		THIS.recorder = CreateObject("TRecorder",;
			THIS.hWindow, "c:\temp\log.txt")
	ENDIF

PROCEDURE KeyPress
LPARAMETERS nKeyCode, nShiftAltCtrl
	IF nKeyCode = 27
		ThisForm.Release
	ENDIF

ENDDEFINE

DEFINE CLASS TRecorder As Custom
	hWindow=0
	LogFile=""
	ole=.F.

PROCEDURE Init (hWnd, lcFileName)
	THIS.LogFile = lcFileName
	THIS.hWindow = hWnd

	ON ERROR ?? Chr(7)
	THIS.ole = CreateObject("WinProcXT.WinProc")
	ON ERROR
	
	IF TYPE("THIS.ole") <> "O"
		RETURN .F.
	ENDIF

	WITH THIS.ole
		.StartService (THIS.hWindow, THIS.LogFile)
		IF Not .IsRunning
			RETURN .F.
		ENDIF
	ENDWITH

PROCEDURE Destroy
	THIS.ole.StopService
	IF FILE (THIS.LogFile)
		CREATE CURSOR csMessages (msg N(16), wParam N(16), lParam N(16))
		APPEND FROM (THIS.LogFile) TYPE DELIMITED WITH TAB
		GO TOP
		BROWSE NORMAL NOWAIT
	ENDIF
ENDDEFINE  
```  
***  


## Listed functions:
[GetFocus](../libraries/user32/GetFocus.md)  

## Comment:
The WindowProc function is an application-defined function that processes messages sent to a window.  
  
***  

