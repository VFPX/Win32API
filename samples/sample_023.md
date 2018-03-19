[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Extended OS Version info

## Before you begin:
See also:

* [OS version and revision](sample_022.md)  
  
***  


## Code:
```foxpro  
*| typedef struct _OSVERSIONINFO{
*|   DWORD dwOSVersionInfoSize;  0 | 4
*|   DWORD dwMajorVersion;       4 | 4
*|   DWORD dwMinorVersion;       8 | 4
*|   DWORD dwBuildNumber;       12 | 4
*|   DWORD dwPlatformId;        16 | 4
*|   TCHAR szCSDVersion[ 128 ]; 20 | 128 = 148 bytes
*| } OSVERSIONINFO;

*| typedef struct _OSVERSIONINFOEX {
*|   DWORD dwOSVersionInfoSize;  0 | 4
*|   DWORD dwMajorVersion;       4 | 4
*|   DWORD dwMinorVersion;       8 | 4
*|   DWORD dwBuildNumber;       12 | 4
*|   DWORD dwPlatformId;        16 | 4
*|   TCHAR szCSDVersion[ 128 ]; 20 | 128
*|   WORD wServicePackMajor;   148 | 2
*|   WORD wServicePackMinor;   150 | 2
*|   WORD wSuiteMask;          152 | 2
*|   BYTE wProductType;        154 | 1
*|   BYTE wReserved;           155 | 1 = 156 bytes
*| } OSVERSIONINFOEX, *POSVERSIONINFOEX, *LPOSVERSIONINFOEX;

DECLARE INTEGER GetVersionEx IN kernel32;
    STRING @ lpVersionInformation

* set dwOSVersionInfoSize to 148 (OSVERSIONINFO)
* or 156 (OSVERSIONINFOEX) bytes
lcInfo = Chr(156) + REPLI (Chr(0), 300)  && some loose space

nResult = GetVersionEx (@lcInfo)

? "Major Version: ", buf2dword(SUBSTR(lcInfo,  5,4))
? "Minor Version: ", buf2dword(SUBSTR(lcInfo,  9,4))
? "Build Number:  ", buf2dword(SUBSTR(lcInfo, 13,4))
? "szCSDVersion:  ", "["+STRTRAN(SUBSTR(lcInfo, 21,128), Chr(0),"")+"]"
?
? "Major Service Pack: ", buf2word(SUBSTR(lcInfo,  149,2))
? "Minor Service Pack: ", buf2word(SUBSTR(lcInfo,  151,2))
? "Suite Bit Flags:    ", buf2word(SUBSTR(lcInfo,  153,2))
? "Product Type:       ", Asc(SUBSTR(lcInfo,155,1))
? "Reserved Byte:      ", Asc(SUBSTR(lcInfo,156,1))

FUNCTION  buf2dword (lcBuffer)
RETURN;
	Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216
ENDFUNC

FUNCTION  buf2word (lcBuffer)
RETURN;
	Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256
ENDFUNC  
```  
***  


## Listed functions:
[GetVersionEx](../libraries/kernel32/GetVersionEx.md)  
