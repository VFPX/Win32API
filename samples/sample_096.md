[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Current System information

## Code:
```foxpro  
DECLARE GetSystemInfo IN kernel32 STRING @lpSystemInfo
	
*| typedef struct _SYSTEM_INFO {
*|   union {
*|     DWORD  dwOemId;
*|     struct {
*|       WORD wProcessorArchitecture;
*|       WORD wReserved;
*|     };
*|   };
*|   DWORD  dwPageSize;
*|   LPVOID lpMinimumApplicationAddress;
*|   LPVOID lpMaximumApplicationAddress;
*|   DWORD_PTR dwActiveProcessorMask;
*|   DWORD dwNumberOfProcessors;
*|   DWORD dwProcessorType;
*|   DWORD dwAllocationGranularity;
*|   WORD wProcessorLevel;
*|   WORD wProcessorRevision;
*| } SYSTEM_INFO;

PRIVATE cSysInfo, nOffs
	
cSysInfo = Repli(Chr(0), 1024)
= GetSystemInfo(@cSysInfo)

CREATE CURSOR cs (varname C(24), prm N(12), descr C(100))
nOffs = 1

= AddParam("dwOemId",;
"Used for compatibility with Windows NT 3.5 and earlier", 4)

= AddParam("wProcessorArchitecture",;
"Specifies the system processor architecture", 2)

= AddParam("wReserved", "Reserved for future use", 2)

= AddParam("dwPageSize",;
"Page size and the granularity of page protection and commitment", 4)

= AddParam("lpMinimumApplicationAddress",;
"Pointer to the lowest memory address accessible to apps and DLLs", 2)

= AddParam("lpMaximumApplicationAddress",;
"Pointer to the highest memory address accessible to apps and DLLs", 2)

= AddParam("dwActiveProcessorMask",;
"Bit 0 is processor 0; bit 31 is processor 31", 4)

= AddParam("dwNumberOfProcessors",;
"Number of processors in the system", 4)

= AddParam("dwProcessorType",;
"An obsolete member", 4)

= AddParam("dwAllocationGranularity",;
"Virtual memory granularity", 4)

= AddParam("wProcessorLevel",;
"Valid for Windows NT/2000 or later", 2)

= AddParam("wProcessorRevision",;
"Valid for Windows NT/2000 or later", 2)

SELECT cs
GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE AddParam(cVarname, cDescr, nLen)
	IF nLen = 2
		nParam = buf2word(SUBSTR(cSysInfo, nOffs, 2))
		nOffs = nOffs + 2
	ELSE
		nParam = buf2dword(SUBSTR(cSysInfo, nOffs, 4))
		nOffs = nOffs + 4
	ENDIF
	INSERT INTO cs VALUES (cVarname, nParam, cDescr)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[GetSystemInfo](../libraries/kernel32/GetSystemInfo.md)  
