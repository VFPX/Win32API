[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Simulating DOEVENTS

## Code:
```foxpro  
PUBLIC frm
frm = CreateObject ("Tform")
frm.Visible = .T.

DEFINE CLASS Tform As Form
	Width=500
	Height=200
	Caption="Simulating DOEVENTS"
	AutoCenter=.T.
	
	ADD OBJECT sh As Shape WITH;
		Left=20, Width=0,;
		Top=100, Height=70, BackColor=Rgb(192,192,250),;
		BorderStyle=0

	ADD OBJECT cmdStart As CommandButton WITH;
		Left=10, Top=10, Height=25, Width=80,;
		Caption="Start"

	ADD OBJECT cmdStop As CommandButton WITH;
		Left=THIS.cmdStart.Left+THIS.cmdStart.Width+2,;
		Top=THIS.cmdStart.Top, Height=25, Width=80,;
		Caption="Stop"

	LoopState = .F.

PROCEDURE  Init
	DECLARE INTEGER GetQueueStatus IN user32 INTEGER flags
	ThisForm.stopLoop
ENDPROC

PROCEDURE  startLoop
* this method emulates a time-consuming process
	THIS.LoopState = .T.
	LOCAL ii
	CREATE CURSOR cs (dt T)
	DO WHILE THIS.LoopState
		WITH ThisForm.sh
			.Width = .Width + 10
			IF .Width > ThisForm.Width - .Left*2
				.Width = 0
			ENDIF
		ENDWITH

		FOR ii=1 TO 10000
			INSERT INTO cs VALUES (datetime())

		* this line makes a difference
		* allowing VFP to take a breath and analyze the user input
		* though it slows the process down
			ThisForm._doEvents()
		* ----------------------------
		ENDFOR
	ENDDO
ENDPROC

PROCEDURE  stopLoop
	ThisForm.LoopState = .F.
ENDPROC

PROCEDURE  cmdStart.Click
	ThisForm.startLoop
ENDPROC

PROCEDURE  cmdStop.Click
* actually there is no need to call StopLoop from this event
ENDPROC

PROCEDURE  _doEvents
#DEFINE QS_MOUSEBUTTON  4
#DEFINE QS_MOUSEMOVE    2
#DEFINE QS_MOUSE        6  && QS_MOUSEMOVE Or QS_MOUSEBUTTON

	* catching mouse messages
	IF GetQueueStatus(QS_MOUSEBUTTON) <> 0
	* if mouse button pressed -- we are here inside
		LOCAL obj

		* obtaining a reference to the object
		* that is under the current mouse position
		obj = SYS(1270)

		* if this particular button is clicked,
		* then we stop the process
		IF obj.Name = "CMDSTOP"
			ThisForm.stopLoop
		ENDIF
		
		* there is another way -- getting mouse cursor position
		* and testing it against the button rectangle
		* possibly it would work faster than SYS function
		* and no undocumented functionality would be involved -- try
	ENDIF
ENDDEFINE  
```  
***  


## Listed functions:
[GetQueueStatus](../libraries/user32/GetQueueStatus.md)  

## Comment:
This example shows how to track user input while executing time-consuming process. This technique is especially useful for VFP3, because this version has no DOEVENTS function implemented.  
  
***  

