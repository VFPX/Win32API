[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading virtual key status values and key names

## Code:
```foxpro  
DO GetKeyStates
DO GetKeyNames
* end of main

PROCEDURE GetKeyStates
	DECLARE INTEGER GetKeyboardState IN user32 STRING @lpKeyState

	LOCAL cBuffer, nIndex

	cBuffer = Repli(Chr(0), 256)
	= GetKeyboardState (@cBuffer)

	CREATE CURSOR csResult (index N(3), asc N(3))
	FOR nIndex=1 TO Len(cBuffer)
		INSERT INTO csResult VALUES (;
			nIndex-1, Asc(SUBSTR(cBuffer, nIndex,1)))
	ENDFOR
	SELECT csResult
	GO TOP
	BROWSE NORMAL

PROCEDURE GetKeyNames
	DECLARE INTEGER GetKeyNameText IN user32;
		INTEGER lParam, STRING @lpString, INTEGER nSize

	CREATE CURSOR cs (scancode I, keyname C(32))
	FOR nIndex=0 TO 255
		= SaveKeycode(nIndex)
	ENDFOR
	SELECT cs
	GO TOP
	BROWSE NORMAL NOWAIT

PROCEDURE SaveKeycode(nKeyindex)
	LOCAL nKeycode, cKeyname

	nKeycode = BITLSHIFT(m.nKeyindex, 16)
	cKeyname = GetKeyName(m.nKeycode)

	IF NOT EMPTY(m.cKeyname)
		INSERT INTO cs VALUES (m.nKeyindex, m.cKeyname)
	ENDIF
	
FUNCTION GetKeyName(num)
	LOCAL cBuffer, nBufsize
	nBufsize=64
	cBuffer = REPLICATE(CHR(0), nBufsize)
	nBufsize = GetKeyNameText(num, @cBuffer, nBufsize)
RETURN SUBSTR(cBuffer, 1, nBufsize)  
```  
***  


## Listed functions:
[GetKeyNameText](../libraries/user32/GetKeyNameText.md)  
[GetKeyboardState](../libraries/user32/GetKeyboardState.md)  
