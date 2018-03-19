[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining I/O counts for the current process

## Code:
```foxpro  
#DEFINE PROCESS_QUERY_INFORMATION 0x0400
#DEFINE PROCESS_VM_READ 4
DO declare

* retrieve a handle to the current process
hProcess = OpenProcess(;
	BITOR(PROCESS_QUERY_INFORMATION,PROCESS_VM_READ),;
	0, GetCurrentProcessId()) && application.ProcessId

IF hProcess = 0
	? "OpenProcess failed:", GetLastError()
	RETURN
ENDIF

LOCAL cBuffer
cBuffer = REPLICATE(CHR(0), 48)
= GetProcessIoCounters(hProcess, @cBuffer)

? "ReadOperationCount:", buf64ToNum(SUBSTR(cBuffer,1,8))
? "WriteOperationCount:", buf64ToNum(SUBSTR(cBuffer,9,8))
? "OtherOperationCount:", buf64ToNum(SUBSTR(cBuffer,17,8))
? "ReadTransferCount:", buf64ToNum(SUBSTR(cBuffer,25,8))
? "WriteTransferCount:", buf64ToNum(SUBSTR(cBuffer,33,8))
? "OtherTransferCount:", buf64ToNum(SUBSTR(cBuffer,41,8))

= CloseHandle(hProcess)
* end of main

FUNCTION buf64ToNum(cBuffer)
	LOCAL nLo, nHi
	nLo = buf2dword(SUBSTR(cBuffer,1,4))
	nHi = buf2dword(SUBSTR(cBuffer,5,4))
RETURN m.nLo + m.nHi * (0xffffffff+1)

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetCurrentProcessId IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER OpenProcess IN kernel32;
		INTEGER dwDesiredAccess,;
		INTEGER bInheritHandle, INTEGER dwProcId

	DECLARE INTEGER GetProcessIoCounters IN kernel32;
		INTEGER hProcess, STRING @lpIoCounters  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetCurrentProcessId](../libraries/kernel32/GetCurrentProcessId.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProcessIoCounters](../libraries/kernel32/GetProcessIoCounters.md)  
[OpenProcess](../libraries/kernel32/OpenProcess.md)  

## Comment:
The IO_COUNTERS structure contains I/O accounting information for a process or a job object. For a job object, the counters include all operations performed by all processes that have ever been associated with the job, in addition to all processes currently associated with the job.  
  
***  

