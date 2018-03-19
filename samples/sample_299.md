[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining Shell32.dll version

## Code:
```foxpro  
DECLARE INTEGER DllGetVersion IN shell32 STRING @pdvi

*|typedef struct _DllVersionInfo {
*|    DWORD  cbSize;            0:4
*|    DWORD  dwMajorVersion;    4:4
*|    DWORD  dwMinorVersion;    8:4
*|    DWORD  dwBuildNumber;    12:4
*|    DWORD  dwPlatformID;     16:4
*|} DLLVERSIONINFO; total bytes = 20

#DEFINE NOERROR  0
#DEFINE DLLVER_PLATFORM_WINDOWS  1
#DEFINE DLLVER_PLATFORM_NT       2

LOCAL lcBuffer
lcBuffer = Chr(20) + Repli(Chr(0), 19)

IF DllGetVersion (@lcBuffer) = NOERROR
	? "*** Shell32.dll"
	? "Major version:", buf2dword(SUBSTR(lcBuffer, 5,4))
	? "Minor version:", buf2dword(SUBSTR(lcBuffer, 9,4))
	? "Build number: ", buf2dword(SUBSTR(lcBuffer, 13,4))
	? "Platform:     ", Iif(buf2dword(SUBSTR(lcBuffer, 17,4))=1,;
		"Windows", "WinNT")
ENDIF

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[DllGetVersion](../libraries/shell32/DllGetVersion.md)  
