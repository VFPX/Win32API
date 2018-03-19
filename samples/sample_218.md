[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading and setting the priority class values for the current process and thread

## Before you begin:
The priority of each thread is determined by the following criteria:  
* The priority class of its process   
* The priority level of the thread within the priority class of its process   

The priority class and priority level are combined to form the base priority of a thread. The priority levels range from zero (lowest priority) to 31 (highest priority).   
  
***  


## Code:
```foxpro  
#DEFINE PROCESS_QUERY_INFORMATION  1024
#DEFINE PROCESS_VM_READ            4
#DEFINE NORMAL_PRIORITY_CLASS      32
#DEFINE IDLE_PRIORITY_CLASS        64
#DEFINE HIGH_PRIORITY_CLASS        128
#DEFINE REALTIME_PRIORITY_CLASS    256
#DEFINE THREAD_BASE_PRIORITY_MAX   2

DO declare

LOCAL hProcess, hThread

* retrieve a handle to the current process
hProcess = OpenProcess(;
	BITOR(PROCESS_QUERY_INFORMATION,PROCESS_VM_READ),;
	0, GetCurrentProcessId())

* retrieve a handle (pseudo) to the current thread
* no need to release this handle through the CloseHandle function
hThread = GetCurrentThread()

IF hProcess <> 0
	? "Current process priority:", GetPriorityClass (hProcess)
	? "Current thread priority:", GetThreadPriority(hThread)

	? "Attempting to change the priority class for the current process:",;
		SetPriorityClass(hProcess, HIGH_PRIORITY_CLASS)

	? "Attempting to change the priority class for the current thread:",;
		SetThreadPriority(hThread, THREAD_BASE_PRIORITY_MAX)

	? "Changed process priority:", GetPriorityClass (hProcess)
	? "Changed thread priority:", GetThreadPriority(hThread)

	= CloseHandle(hProcess)
ENDIF

PROCEDURE declare
	DECLARE INTEGER GetCurrentThread IN kernel32
	DECLARE INTEGER GetCurrentProcessId IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetThreadPriority IN kernel32 INTEGER hThread
	DECLARE INTEGER GetPriorityClass IN kernel32 INTEGER hProcess

	DECLARE INTEGER SetThreadPriority IN kernel32;
		INTEGER hThread, INTEGER nPriority

	DECLARE INTEGER OpenProcess IN kernel32;
		INTEGER dwDesiredAccess,;
		INTEGER bInheritHandle, INTEGER dwProcId

	DECLARE INTEGER SetPriorityClass IN kernel32;
		INTEGER hProcess, INTEGER dwPriorityClass  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetCurrentProcessId](../libraries/kernel32/GetCurrentProcessId.md)  
[GetCurrentThread](../libraries/kernel32/GetCurrentThread.md)  
[GetPriorityClass](../libraries/kernel32/GetPriorityClass.md)  
[GetThreadPriority](../libraries/kernel32/GetThreadPriority.md)  
[OpenProcess](../libraries/kernel32/OpenProcess.md)  
[SetPriorityClass](../libraries/kernel32/SetPriorityClass.md)  
[SetThreadPriority](../libraries/kernel32/SetThreadPriority.md)  

## Comment:
A handle to the current process is retrieved through the OpenProcess function.   
  
Another option available is using the GetCurrentProcess function. This function returns not exactly a handle, but rather a pseudo-handle. Which can be used same way as the real one, saving the CloseHandle call.  
  
***  

