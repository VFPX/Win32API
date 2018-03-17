<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Reading the state of mouse buttons within DO WHILE loop

## Before you begin:
See also:

* [Capturing keyboard activity of another application using the Raw Input API](sample_572.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetAsyncKeyState IN user32 INTEGER vKey
DECLARE INTEGER GetKeyState IN user32 INTEGER vKey
DECLARE INTEGER SetKeyboardState IN user32 STRING @lpKeyState

#DEFINE VK_LBUTTON  1
#DEFINE VK_RBUTTON  2

LOCAL cBuffer, nIndex, lStop
lStop=.F.

* clearing input-state table
cBuffer = REPLICATE(CHR(0), 256)
= SetKeyboardState(@cBuffer)
DOEVENTS

DO WHILE Not lStop
	* simulating time-consuming activity
	CREATE CURSOR cs (num N(10))
	FOR nIndex=1 TO 1000
		INSERT INTO cs VALUES (nIndex)
	ENDFOR

	?? "."
*	DOEVENTS

	* testing if any mouse key has been pressed
	* since previous call to this function
	IF GetKeyState(VK_LBUTTON) <> 0
		? "Left button pressed."
		EXIT
	ENDIF

	IF GetKeyState(VK_RBUTTON) <> 0
		? "Right button pressed."
		EXIT
	ENDIF
ENDDO  
```  
***  


## Listed functions:
[GetAsyncKeyState](../libraries/user32/GetAsyncKeyState.md)  
[GetKeyState](../libraries/user32/GetKeyState.md)  
[SetKeyboardState](../libraries/user32/SetKeyboardState.md)  

## Comment:
Check list of <a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/winui/vkeys_529f.asp">Virtual-Key Codes</a> on the MSDN.  
  
***  

