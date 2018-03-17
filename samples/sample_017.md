<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Using the GetLogicalDriveStrings

## Code:
```foxpro  
DECLARE INTEGER GetDriveType IN kernel32 STRING nDrive

DECLARE INTEGER GetLogicalDriveStrings IN kernel32;
	INTEGER nBufferLength, STRING @lpBuffer

LOCAL cBuffer, nBufsize, cName, ch
cBuffer = REPLICATE(CHR(0), 250)
	
nBufsize = GetLogicalDriveStrings(Len(cBuffer), @cBuffer)
cBuffer = PADR(cBuffer, nBufsize)
? cBuffer
	
cName = ""
FOR nBufsize=1 TO Len(cBuffer)
	ch = SUBSTR(cBuffer, nBufsize,1)
	IF ch = Chr(0)
		? cName, GetDriveType(cName)
		cName = ""
	ELSE
		cName = cName + ch
	ENDIF
ENDFOR  
```  
***  


## Listed functions:
[GetDriveType](../libraries/kernel32/GetDriveType.md)  
[GetLogicalDriveStrings](../libraries/kernel32/GetLogicalDriveStrings.md)  
