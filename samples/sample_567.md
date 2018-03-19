[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining OS memory performance information

## Before you begin:
Memory performance information is available from the memory manager through the system performance counters and through functions such as GetPerformanceInfo, GetProcessMemoryInfo, and GlobalMemoryStatusEx.  

See also:

* [Memory usage info for current VFP session](sample_172.md)  
* [Enumerating processes](sample_162.md)  

  
***  


## Code:
```foxpro  
*!*	typedef struct _PERFORMANCE_INFORMATION {
*!*	  DWORD  cb;                 0:4
*!*	  SIZE_T CommitTotal;        4:4
*!*	  SIZE_T CommitLimit;        8:4
*!*	  SIZE_T CommitPeak;        12:4
*!*	  SIZE_T PhysicalTotal;     16:4
*!*	  SIZE_T PhysicalAvailable; 20:4
*!*	  SIZE_T SystemCache;       24:4
*!*	  SIZE_T KernelTotal;       28:4
*!*	  SIZE_T KernelPaged;       32:4
*!*	  SIZE_T KernelNonpaged;    36:4
*!*	  SIZE_T PageSize;          40:4
*!*	  DWORD  HandleCount;       44:4
*!*	  DWORD  ProcessCount;      48:4
*!*	  DWORD  ThreadCount;       52:4
*!*	} PERFORMANCE_INFORMATION,
*!*		*PPERFORMANCE_INFORMATION;

#DEFINE PERFORMANCE_INFORMATION_SIZE 56

DECLARE INTEGER GetPerformanceInfo in psapi;
	STRING @pPerfInfo, INTEGER cb
	
LOCAL cBuffer, nPageSize
cBuffer = PADR(CHR(PERFORMANCE_INFORMATION_SIZE),;
	PERFORMANCE_INFORMATION_SIZE, CHR(0))
	
= GetPerformanceInfo(@cBuffer,;
	PERFORMANCE_INFORMATION_SIZE)

nPageSize = buf2dword(SUBSTR(cBuffer, 41, 4))
	
? "Physical Total (Bytes):",;
	TRANSFORM(buf2dword(SUBSTR(cBuffer, 17, 4)) *;
	nPageSize, "999,999,999,999")

? "Physical Available (Bytes):",;
	TRANSFORM(buf2dword(SUBSTR(cBuffer, 21, 4)) *;
	nPageSize, "999,999,999,999")

? "Handle Count:",;
	buf2dword(SUBSTR(cBuffer, 45, 4))

? "Process Count:",;
	buf2dword(SUBSTR(cBuffer, 49, 4))

? "Thread Count:",;
	buf2dword(SUBSTR(cBuffer, 53, 4))

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetPerformanceInfo](../libraries/psapi/GetPerformanceInfo.md)  

## Comment:
System information obtained through call to GetPerformanceInfo, includes counts for running processes and threads, handles, amount of available and allocated memory.  
  
***  

