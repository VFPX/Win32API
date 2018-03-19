[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Memory usage info for current VFP session (WinNT only)

## Before you begin:
See also:

* [Obtaining memory performance information for the system](sample_567.md)  
  
***  


## Code:
```foxpro  
DO decl
*| typedef struct _PROCESS_MEMORY_COUNTERS {
*|     DWORD cb;
*|     DWORD PageFaultCount;
*|     SIZE_T PeakWorkingSetSize;
*|     SIZE_T WorkingSetSize;
*|     SIZE_T QuotaPeakPagedPoolUsage;
*|     SIZE_T QuotaPagedPoolUsage;
*|     SIZE_T QuotaPeakNonPagedPoolUsage;
*|     SIZE_T QuotaNonPagedPoolUsage;
*|     SIZE_T PagefileUsage;
*|     SIZE_T PeakPagefileUsage;
*| } PROCESS_MEMORY_COUNTERS;  4 x 10 = 40 bytes
*| typedef PROCESS_MEMORY_COUNTERS *PPROCESS_MEMORY_COUNTERS
#DEFINE STRU_LENGTH   40
#DEFINE HANDLE_FLAG_INHERIT  1
#DEFINE HANDLE_FLAG_PROTECT_FROM_CLOSE  2

PRIVATE lcBuffer
LOCAL hProcess, nFlags

hProcess = GetCurrentProcess()

nFlags = 0
= GetHandleInformation(hProcess, @nFlags)
? "Object Handle flags:", nFlags
?

lcBuffer = Chr(STRU_LENGTH) + Repli(Chr(0), STRU_LENGTH-1)

IF GetProcessMemoryInfo (hProcess, @lcBuffer, STRU_LENGTH) <> 0
*	= _print ("Size of the structure, in bytes:",  1)
	= _print ("Number of page faults:          ",  5)
	= _print ("Peak working set size:          ",  9)
	= _print ("Current working set size:       ", 13)
	= _print ("Peak paged pool usage:          ", 17)
	= _print ("Current paged pool usage:       ", 21)
	= _print ("Peak nonpaged pool usage:       ", 25)
	= _print ("Current nonpaged pool usage:    ", 29)
	= _print ("Current pagefile usage:         ", 33)
	= _print ("Peak pagefile usage:            ", 37)
ENDIF

PROCEDURE _print (lcCaption, lnOffs)
	LOCAL lnValue
	lnValue = buf2dword(SUBSTR(lcBuffer, lnOffs,4))
	? lcCaption, TRANS(lnValue, "999,999,999,999,999")
RETURN

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE decl
	DECLARE INTEGER GetProcessMemoryInfo IN psapi;
		INTEGER Process, STRING @ppsmemCounters, INTEGER cb

	DECLARE INTEGER GetCurrentProcess IN kernel32

	DECLARE INTEGER GetHandleInformation IN kernel32;
		INTEGER hObject, INTEGER @lpdwFlags  
```  
***  


## Listed functions:
[GetCurrentProcess](../libraries/kernel32/GetCurrentProcess.md)  
[GetHandleInformation](../libraries/kernel32/GetHandleInformation.md)  
[GetProcessMemoryInfo](../libraries/psapi/GetProcessMemoryInfo.md)  

## Comment:
WinNT Performance Monitor  
  
***  

