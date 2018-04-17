[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Accessing a CD device (cdaudio) with Multimedia Command Strings

## Before you begin:
With this code you can open and close the device door, retrieve some parameters for the device and for the media inside, even play selected tracks.   

Some commands may not work properly because of variety of CD devices.  
  
***  


## Code:
```foxpro  
PUBLIC objForm
objForm = CreateObject("TForm")
objForm.Visible = .T.

DEFINE CLASS TForm As Form
	Caption="CD"
	Width=420
	Height=240
	Autocenter=.T.
	
	ADD OBJECT cmdOpen As CommandButton WITH;
	Caption="Open", Left=7, Top=7, Width=60, Height=29

	ADD OBJECT cmdClose As CommandButton WITH;
	Caption="Close", Left=7, Top=40, Width=60, Height=29
	
	ADD OBJECT cmdTest As CommandButton WITH;
	Caption="Test", ForeColor=Rgb(0,0,128), Left=350, Top=7,;
	Width=60, Height=29
	
	ADD OBJECT lst As ListBox WITH;
	Left=80, Width=260, Top=7, Height=180

	ADD OBJECT lbl As Label WITH;
	Caption="", Left=7, Width=400, Height=45,;
	WordWrap=.T., Top=200, Fontname="Arial", Fontsize=8
	
PROCEDURE Init
	ThisForm.OpenDevice

PROCEDURE Destroy
	ThisForm.CloseDevice

PROCEDURE cmdOpen.Click
	ThisForm.OpenDoor

PROCEDURE cmdClose.Click
	ThisForm.CloseDoor
	
PROCEDURE cmdTest.Click
	ThisForm.TestCmd

PROCEDURE lst.Init
	THIS.AddItem("capability cdaudio can eject")
	THIS.AddItem("capability cdaudio can play")
	THIS.AddItem("capability cdaudio can record")
	THIS.AddItem("capability cdaudio can save")
	THIS.AddItem("capability cdaudio compound device")
	THIS.AddItem("-")
	THIS.AddItem("info cdaudio identity")
	THIS.AddItem("info cdaudio upc")
	THIS.AddItem("-")
	THIS.AddItem("status cdaudio current track")
	THIS.AddItem("status cdaudio length")
	THIS.AddItem("status cdaudio media present")
	THIS.AddItem("status cdaudio mode")
	THIS.AddItem("-")
	THIS.AddItem("spin cdaudio down")
	THIS.AddItem("spin cdaudio up")
	THIS.AddItem("-")
	THIS.AddItem("play cdaudio from 2")
	THIS.AddItem("pause cdaudio wait")
	THIS.AddItem("resume cdaudio wait")
	THIS.AddItem("stop cdaudio wait")

	THIS.ListIndex = 1

PROCEDURE lst.InteractiveChange
	ThisForm.lbl.Caption = ""

PROCEDURE TestCmd
	ThisForm.cmd(ThisForm.lst.Value)

PROCEDURE lst.DblClick
	ThisForm.cmd(ThisForm.lst.Value)

PROCEDURE OpenDoor
	ThisForm.cmd("set cdaudio door open wait")

PROCEDURE CloseDoor
	ThisForm.cmd("set cdaudio door closed wait")

PROCEDURE OpenDevice
	THIS.cmd("open cdaudio shareable")

PROCEDURE CloseDevice
	THIS.cmd("stop cdaudio wait")
	THIS.cmd("close cdaudio")

PROCEDURE cmd(lcCommand)
	DECLARE INTEGER mciSendString IN winmm;
		STRING lpszCommand, STRING @lpszReturnString,;
		INTEGER cchReturn, INTEGER hwndCallback

	LOCAL lnError
	STORE SPACE(250) TO lcReturn, lcError
	lnError = mciSendString(lcCommand, @lcReturn, Len(lcReturn), 0)

	IF lnError <> 0
		WITH THIS.lbl
			.Caption = THIS.GetErr(lnError)
			.ForeColor = Rgb(196,0,0)
		ENDWITH
	ELSE
		WITH THIS.lbl
			.Caption = ALLTRIM(STRTRAN(lcReturn, Chr(0),""))
			.ForeColor = Rgb(0,0,0)
		ENDWITH
	ENDIF

FUNCTION GetErr(lnError)
	DECLARE INTEGER mciGetErrorString IN winmm;
		INTEGER fdwError, STRING @lpszErrorText,;
		INTEGER cchErrorText

	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), 250)
	= mciGetErrorString(lnError, @lcBuffer, Len(lcBuffer))
RETURN SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)
ENDDEFINE  
```  
***  


## Listed functions:
[mciGetErrorString](../libraries/winmm/mciGetErrorString.md)  
[mciSendString](../libraries/winmm/mciSendString.md)  

## Comment:
Check this MSDN link:  
 
* [Multimedia Command Strings](https://msdn.microsoft.com/en-us/library/dd743572(v=vs.85).aspx)  
  
***  

