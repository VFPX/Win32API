<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Using Video Capture: enumerating installed capture drivers

## Code:
```foxpro  
DECLARE INTEGER capGetDriverDescription IN avicap32;
	INTEGER wDriverIndex, STRING @lpszName,;
	INTEGER cbName, STRING @lpszVer, INTEGER cbVer

LOCAL nIndex, cDriver, cVersion, nResult

CREATE CURSOR cs (drindex I, drname C(50), drver C(50))
FOR nIndex=0 TO 9
	STORE Repli(Chr(0), 250) TO cDriver, cVersion

	nResult = capGetDriverDescription(nIndex,;
		@cDriver, Len(cDriver), @cVersion, Len(cVersion))

	IF nResult <> 0
		cDriver = STRTRAN(cDriver, Chr(0), "")
		cVersion = STRTRAN(cVersion, Chr(0), "")
		INSERT INTO cs VALUES (nIndex, cDriver, cVersion)
	ENDIF
ENDFOR

SELECT cs
BROWSE NORMAL NOWAIT  
```  
***  


## Listed functions:
[capGetDriverDescription](../libraries/avicap32/capGetDriverDescription.md)  
