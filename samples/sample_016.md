[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the GetTempFileName

## Code:
```foxpro  
#DEFINE MAX_PATH 260
DO decl

LOCAL cTmpPath, nIndex
cTmpPath = GetTmpPath()

FOR nIndex=0 TO 10
	? GetTmpName(cTmpPath, "vrl", .F.)
ENDFOR

FUNCTION GetTmpName(cTmpPath, cPrefix, lCreate)
	LOCAL nUnique, cTmpFile

	IF lCreate
	* the GetTempFileName creates a temporary file and closes it
	* truly unique name is returned based on the current system time
		nUnique = 0
	ELSE
	* file name is generated, though the GetTempFileName does not
	* check if this name is truly unique
*		nUnique = SECONDS()  && easily creates duplicates
*		nUnique = GetTickCount() && easily creates duplicates
		nUnique = GetCounter()  && the most reliable option
	ENDIF

	cTmpFile = Repli(Chr(0), 250)
	= GetTempFileName(cTmpPath, cPrefix, nUnique, @cTmpFile)
	cTmpFile = STRTRAN(cTmpFile, Chr(0), "")
RETURN cTmpFile

FUNCTION GetTmpPath
	LOCAL cShort, cLong
	STORE Repli(Chr(0), 512) TO cShort, cLong
	= GetTempPath(Len(cShort), @cShort)
	cShort = STRTRAN(cShort, Chr(0), "")
	= GetLongPathName(cShort, @cLong, Len(cLong))
RETURN STRTRAN(cLong, Chr(0), "")

FUNCTION GetCounter
	LOCAL cBuffer
	cBuffer = Repli(Chr(0), 8)
	= QueryPerformanceCounter(@cBuffer)
RETURN LargeInt(cBuffer)

FUNCTION LargeInt(cBuffer)
#DEFINE MAX_DWORD 0x100000000
RETURN buf2dword(SUBSTR(cBuffer, 1,4)) +;
	buf2dword(SUBSTR(cBuffer, 5,4)) * MAX_DWORD

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE decl
	DECLARE INTEGER GetTempFileName IN kernel32;
		STRING lpszPath, STRING lpPrefixString,;
		INTEGER wUnique, STRING @lpTempFileName

	DECLARE INTEGER GetTempPath IN kernel32;
		INTEGER nBufferLength, STRING @lpBuffer

	DECLARE INTEGER GetLongPathName IN kernel32;
	    STRING lpszShort, STRING @lpszLong, INTEGER cchBuffer

	DECLARE INTEGER GetTickCount IN kernel32

	DECLARE INTEGER QueryPerformanceCounter IN kernel32;
	    STRING @lpPerformanceCount  
```  
***  


## Listed functions:
[GetLongPathName](../libraries/kernel32/GetLongPathName.md)  
[GetTempFileName](../libraries/kernel32/GetTempFileName.md)  
[GetTempPath](../libraries/kernel32/GetTempPath.md)  
[GetTickCount](../libraries/kernel32/GetTickCount.md)  
[QueryPerformanceCounter](../libraries/kernel32/QueryPerformanceCounter.md)  
