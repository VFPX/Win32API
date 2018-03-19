[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading STARTUPINFO structure for the current VFP session

## Before you begin:
See also:

* [Running MSDOS Shell as a child process](sample_477.md)  
* [How to prevent users from accessing the Windows Desktop](sample_492.md)  

  
***  


## Code:
```foxpro  
DO declare

*| typedef struct _STARTUPINFO {
*|   DWORD   cb;                4
*|   LPTSTR  lpReserved;        4
*|   LPTSTR  lpDesktop;         4
*|   LPTSTR  lpTitle;           4
*|   DWORD   dwX;               4
*|   DWORD   dwY;               4
*|   DWORD   dwXSize;           4
*|   DWORD   dwYSize;           4
*|   DWORD   dwXCountChars;     4
*|   DWORD   dwYCountChars;     4
*|   DWORD   dwFillAttribute;   4
*|   DWORD   dwFlags;           4
*|   WORD    wShowWindow;       2
*|   WORD    cbReserved2;       2
*|   LPBYTE  lpReserved2;       4
*|   HANDLE  hStdInput;         4
*|   HANDLE  hStdOutput;        4
*|   HANDLE  hStdError;         4
*| } STARTUPINFO, *LPSTARTUPINFO; total: 68 bytes

LOCAL lcStartupInfo, lnAddr

* do not use SPACE(250) instead; there must be strict zeroes
lcStartupInfo = Repli(Chr(0), 250)

= GetStartupInfo(@lcStartupInfo)

? "Byte size:", buf2dword(SUBSTR(lcStartupInfo, 1,4))
? "lpReserved:", buf2dword(SUBSTR(lcStartupInfo, 5,4))

* WinNT/XP/@K returns a string value; WinMe -- empty string
? "lpDesktop string:", getStr(buf2dword(SUBSTR(lcStartupInfo, 9,4)))

* WinNT/XP/2K: possibly the shortcut to your VFP application
* or a full path to the executable if started directly
* WinMe = empty string
? "lpTitle string:", getStr(buf2dword(SUBSTR(lcStartupInfo, 13,4)))

? "dwX:", buf2dword(SUBSTR(lcStartupInfo, 17,4))
? "dwY:", buf2dword(SUBSTR(lcStartupInfo, 21,4))
? "dwXSize:", buf2dword(SUBSTR(lcStartupInfo, 25,4))
? "dwYSize:", buf2dword(SUBSTR(lcStartupInfo, 29,4))
? "dwXCountChars:", buf2dword(SUBSTR(lcStartupInfo, 33,4))
? "dwYCountChars:", buf2dword(SUBSTR(lcStartupInfo, 37,4))
? "dwFillAttribute:", buf2dword(SUBSTR(lcStartupInfo, 41,4))
? "dwFlags:", buf2dword(SUBSTR(lcStartupInfo, 45,4))
? "wShowWindow:", buf2word(SUBSTR(lcStartupInfo, 49,2))
? "cbReserved2:", buf2word(SUBSTR(lcStartupInfo, 51,2))
? "lpReserved2:", buf2dword(SUBSTR(lcStartupInfo, 53,4))
? "hStdInput:", buf2dword(SUBSTR(lcStartupInfo, 57,4))
? "hStdOutput:", buf2dword(SUBSTR(lcStartupInfo, 61,4))
? "hStdError:", buf2dword(SUBSTR(lcStartupInfo, 65,4))

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION getStr(lnAddr)
	LOCAL lcBuffer
	lcBuffer = Repli(Chr(0), 128)
	= CopyMemory(@lcBuffer, lnAddr, Len(lcBuffer))

	IF AT(Chr(0), lcBuffer) <> 0
		lcBuffer = SUBSTR(lcBuffer, 1, AT(Chr(0), lcBuffer)-1)
	ENDIF
RETURN  lcBuffer

PROCEDURE declare
	DECLARE GetStartupInfo IN kernel32 STRING @lpStartupInfo

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Destination, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[GetStartupInfo](../libraries/kernel32/GetStartupInfo.md)  
