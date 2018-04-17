[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using an Event Object. Part A: running an application that creates an Event object

## Before you begin:
Compile this code into a separate executable and test with an executable created from the [Part B](sample_149.md) of this example.   
This is the name of the Event Object, that links two parts.  

Start Part A executable prior to the Part B.  
  
***  

## Code:
```foxpro  
PUBLIC frm, lcEventName
lcEventName = "TimeToGoHomeNotice"

frm = CreateObject ("Tform", lcEventName)
IF TYPE ("frm") = "O"
	frm.Visible = .T.
	READ EVENTS
ENDIF

DEFINE CLASS Tform As Form
	Width=300
	Height=150
	BackColor=Rgb(230,230,250)
	Caption="Firing events"
	AutoCenter=.T.
	hEvent=0
	
	ADD OBJECT cmd As CommandButton WITH;
		Height=25, Width=80, Caption="\<Fire!",;
		Left=10, Top=10

PROCEDURE  Init (lcName)
	_SCREEN.WindowState = 2
	_SCREEN.Caption = "Push the button to set an event"
	
	DO decl
	IF Not THIS.createEvent(lcName)
		RETURN .F.
	ENDIF

PROCEDURE  Destroy
	QUIT
	
PROCEDURE  createEvent (lcName)
	THIS.hEvent = CreateEvent (0, 1, 0, lcName)
	IF THIS.hEvent = 0
		= MessageB ("Unable to create an Event object" + Chr(13) +;
			"with this name")
		RETURN .F.
	ENDIF
RETURN .T.

PROCEDURE  fire
	= SetEvent (THIS.hEvent)

PROCEDURE  cmd.Click
	ThisForm.fire
ENDDEFINE

PROCEDURE  decl
	DECLARE INTEGER CreateEvent IN kernel32;
		INTEGER lpEventAttributes, INTEGER bManualReset,;
		INTEGER bInitialState, STRING lpName

	DECLARE INTEGER SetEvent IN kernel32 INTEGER hEvent  
```  
***  


## Listed functions:
[CreateEvent](../libraries/kernel32/CreateEvent.md)  
[SetEvent](../libraries/kernel32/SetEvent.md)  

## Comment:
This code creates an Event object.   
  
Pushing the button on the form you set this Event object, signalling that an event has occured. Another application ([Part B](sample_149.md)) uses Timer to watch the state of the Event object. When the Part B application discovers the event occured it runs some code attached.  
  
***  

