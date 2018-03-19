[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to find when the application started

## Before you begin:
The GetProcessTimes function among other output parameters returns the creation time of the process.  
  
***  


## Code:
```foxpro  
#DEFINE PROCESS_QUERY_INFORMATION 0x0400
#DEFINE PROCESS_VM_READ 4
DO declare

* obtain a handle for the current process
hProcess = OpenProcess(;
	BITOR(PROCESS_QUERY_INFORMATION,PROCESS_VM_READ),;
	0, GetCurrentProcessId()) && can also use Application.ProcessId

IF hProcess = 0
* 5=ACCESS_DENIED
* 6=INVALID_HANDLE
	? "OpenProcess failed:", GetLastError()
	RETURN
ENDIF

LOCAL cCreationTime, cExitTime, cKernelTime, cUserTime
STORE REPLICATE(CHR(0),8) TO;
	cCreationTime, cExitTime, cKernelTime, cUserTime

IF GetProcessTimes(hProcess, @cCreationTime, @cExitTime,;
	@cKernelTime, @cUserTime) = 0
	? "GetProcessTimes failed:", GetLastError()
ELSE
	? "Process created, UTC:",;
		FiletimeToDatetime(cCreationTime)

	? "Kernel mode time, sec.:",;
		FiletimeToSeconds(cKernelTime)

	? "User mode time, sec.:",;
		FiletimeToSeconds(cUserTime)
ENDIF

= CloseHandle(hProcess)
* end of main

FUNCTION FiletimeToSeconds(cFiletime)
	LOCAL nLow, nHigh, nResult
	nLow = buf2dword(SUBSTR(cFiletime,1,4))
	nHigh = buf2dword(SUBSTR(cFiletime,5))
RETURN (nLow + m.nHigh * (0xffffffff+1)) * 10e-8

FUNCTION FiletimeToDatetime(cFiletime)
	LOCAL cSystime, nYear, nMonth, nDay,;
		nHours, nMinutes, nSeconds

	cSystime = REPLICATE(CHR(0), 16)
	= FileTimeToSystemTime(cFiletime, @cSystime)

	nYear = buf2word(SUBSTR(cSystime, 1,2))
	nMonth = buf2word(SUBSTR(cSystime, 3,2))
	nDay = buf2word(SUBSTR(cSystime, 7,2))
	nHours = buf2word(SUBSTR(cSystime, 9,2))
	nMinutes = buf2word(SUBSTR(cSystime, 11,2))
	nSeconds = buf2word(SUBSTR(cSystime, 13,2))
	
RETURN DTOT(DATE(nYear, nMonth, nDay)) +;
	nHours*3600 + nMinutes*60 + nSeconds

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetCurrentProcessId IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER GetProcessTimes IN kernel32;
		INTEGER hProcess, STRING @lpCreationTime, STRING @lpExitTime,;
		STRING @lpKernelTime, STRING @lpUserTime

	DECLARE INTEGER OpenProcess IN kernel32;
		INTEGER dwDesiredAccess,;
		INTEGER bInheritHandle, INTEGER dwProcId

	DECLARE INTEGER FileTimeToSystemTime IN kernel32;
		STRING lpFileTime, STRING @lpSystemTime  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[FileTimeToSystemTime](../libraries/kernel32/FileTimeToSystemTime.md)  
[GetCurrentProcessId](../libraries/kernel32/GetCurrentProcessId.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProcessTimes](../libraries/kernel32/GetProcessTimes.md)  
[OpenProcess](../libraries/kernel32/OpenProcess.md)  

## Comment:
The Kernel Mode and User Mode times put together are equival to the CPU Time value displayed for the process in the Task Manager.  
  
***  

