***************************
* ApiViewer
***************************
**********************************************************
* AM  2005.Dec.21 Module created
**********************************************************

SET RESOURCE OFF
SET TALK OFF
SET EXCLUSIVE OFF
SET CENTURY ON
_screen.Visible=.F.

#INCLUDE apiviewer.h
SET PROCEDURE TO genlib ADDITIVE

LOCAL oMsg
oMsg = NEWOBJECT("msgbox", "apiviewer")
WITH oMsg
	.SetCaption("Please wait...")
	.Visible=.T.
	.SetMessage(PRODUCT_NAME + CRLF + CRLF +;
		COPYRIGHT_TEXT + CRLF +;
		CONTACT_PERSON + CRLF +;
		CONTACT_PHONE + CRLF +;
		CONTACT_ADDRESS;
		)
ENDWITH

DO FORM ApiViewer NOSHOW
RELEASE oMsg

DECLARE INTEGER SetForegroundWindow IN user32 INTEGER hWindow
= SetForegroundWindow(ApiViewer.HWND)

READ EVENTS

DO OnExit
* end of main

PROCEDURE OnExit
	IF _vfp.StartMode = 0
		CLOSE DATABASES
		CLOSE TABLES ALL
		SET PROCEDURE TO
		SET TALK ON
		SET RESOURCE ON
		_screen.Visible = .T.
	ELSE
		QUIT
	ENDIF
