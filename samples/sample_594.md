[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Playing WAV files on InteractiveChange

## Before you begin:
This code sample shows how to play a WAV sound on *InteractiveChange* event of *ListBox* control.   

The sound is played *asynchronously*, which does not slow the UI. Separate sounds are played for *odd* and *even* list items.  

See also:

* [Controlling master audio volume](sample_592.md)  
* [Playing WAV sounds simultaneously](sample_523.md)  
* [How to play MIDI notes](sample_537.md)  
* [WAV file player](sample_417.md)  

  
***  


## Code:
```foxpro  
oForm = CREATEOBJECT("TForm")
oForm.Visible = .T.
READ EVENTS
* end of main

DEFINE CLASS TForm as Form
	Caption="Interactive PlaySound"
	Width=250
	Height=350
	Autocenter=.T.
	
	ADD OBJECT List1 as TList WITH;
	Left=5, Top=5, Width=240, Height=320

PROCEDURE Init
	THIS.List1.PopulateList
	
PROCEDURE Destroy
	CLEAR EVENTS

PROCEDURE KeyPress
LPARAMETERS nKeyCode, nShiftAltCtrl
	IF nKeyCode = 27
		THIS.Release
	ENDIF

ENDDEFINE

DEFINE CLASS TList as ListBox
#DEFINE SND_FILENAME 0x20000
#DEFINE SND_ASYNC 1

PROCEDURE Init
	THIS.declare
	
PROCEDURE PopulateList
	LOCAL nIndex
	FOR nIndex=1 TO 100
		THIS.AddItem("Item " +;
			TRANSFORM(nIndex))
	NEXT
	THIS.ListIndex = 1

PROCEDURE InteractiveChange
	THIS.PlayEventSound

PROCEDURE PlayEventSound
* download these sound files or use your own
* http://www.soundjay.com/button/button-20.wav
* http://www.soundjay.com/button/button-33.wav

	* plays separate sounds
	* for odd and even list items
	PlaySound(;
		IIF(MOD(THIS.ListIndex, 2)=0,;
		"sounds\button-20.wav",;
		"sounds\button-33.wav"),;
		0, SND_FILENAME + SND_ASYNC)
	
PROCEDURE declare
	DECLARE INTEGER PlaySound IN winmm;
		STRING pszSound, INTEGER hmod,;
		LONG fdwSound

ENDDEFINE  
```  
***  


## Listed functions:
[PlaySound](../libraries/winmm/PlaySound.md)  

## Comment:
As long as UI sounds stay equally informative and unobtrusive, they certainly can improve end-user experience. For example, your UI may deliver a sound not for every item in a list but for a few chosen ones.  
  
***  

