[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Storing the environment strings in cursor

## Before you begin:
![](../images/envstrings.png)  

See also:

* [One more way to retrieve environment strings](sample_132.md)  
* [Creating INI file and adding strings to it](sample_137.md)  
* [Reading and setting Environment variables](sample_152.md)  

  
***  


## Code:
```foxpro  
DO declare
LOCAL nProcAddr, cBuffer, nBufsize

* get the address of the environment block of the current process
nProcAddr = GetEnvironmentStrings()
IF nProcAddr = 0
	RETURN
ENDIF

* allocate sufficient buffer
nBufsize = GlobalSize(nProcAddr)
nBufsize = Iif(nBufsize=0, 4096, nBufsize)
cBuffer = Repli(Chr(0), nBufsize)
	
* copy memory block to the buffer
= CopyMemory(@cBuffer, nProcAddr, Len(cBuffer))

* the zero word marks the end of the environment block
cBuffer = Left(cBuffer, AT(Chr(0)+Chr(0), cBuffer))

* target cursor
CREATE CURSOR cs (envname C(30), sz I, envvalue C(250))

LOCAL nIndex, ss, ch, lnPos, lcName, lcValue
ss = ""
FOR nIndex=1 TO Len(cBuffer)
	ch = SUBSTR(cBuffer, nIndex, 1)
	IF ch = Chr(0)
		lnPos = AT("=", ss)
		lcName = LEFT(ss, lnPos-1)
		lcValue = SUBSTR(ss, lnPos+1)
		INSERT INTO cs VALUES (lcName, Len(lcValue), lcValue)
		ss = ""
	ELSE
		ss = ss + ch
	ENDIF
ENDFOR

* release the environment block
= FreeEnvironmentStrings(nProcAddr)

SELECT cs
GO TOP
BROW NORMAL NOWAIT
* end of main

PROCEDURE declare
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
	DECLARE INTEGER GetEnvironmentStrings IN kernel32

	DECLARE INTEGER FreeEnvironmentStrings IN kernel32;
		INTEGER lpszEnvBlock

  	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Dest, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[FreeEnvironmentStrings](../libraries/kernel32/FreeEnvironmentStrings.md)  
[GetEnvironmentStrings](../libraries/kernel32/GetEnvironmentStrings.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  

## Comment:
This way you get all environment variables, so you dont need to provide their names as with the GetEnv() function.  
  
***  

