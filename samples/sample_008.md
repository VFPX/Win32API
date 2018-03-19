[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the Semaphore object

## Before you begin:
See also:

* [Using the Semaphore object to allow only one instance of VFP application running](sample_147.md)  
  
***  


## Code:
```foxpro  
#DEFINE WAIT_OBJECT_0 0
#DEFINE STATUS_TIMEOUT 0x0102

DO declare

LOCAL hSmp, lnInc

lnInc = 3
hSmp = CreateSemaphore(0, lnInc, lnInc, "TestSmp")

IF hSmp = 0
* 87 = ERROR_INVALID_PARAMETER
	? "Error:", GetLastError()
	RETURN
ENDIF

? "Semaphore handle:", hSmp
? "Initial count:", lnInc
?
? "Decrementing the count..."
FOR ii=1 TO 10
	dwWaitResult = WaitForSingleObject(hSmp, 0)
	? "dwWaitResult:", _status(dwWaitResult)
ENDFOR

?
lnInc = 2
? "Incrementing the count by " + LTRIM(STR(lnInc))
= ReleaseSemaphore(hSmp, lnInc, 0)

?
? "Decrementing the count..."
FOR ii=1 TO 5
	dwWaitResult = WaitForSingleObject(hSmp, 0)
	? "dwWaitResult:", _status(dwWaitResult)
ENDFOR

= CloseHandle(hSmp)
* end of main

FUNCTION _status(lnWaitResult)
	DO CASE
	CASE lnWaitResult = WAIT_OBJECT_0
		RETURN "WAIT_OBJECT_0"
	CASE lnWaitResult = STATUS_TIMEOUT
		RETURN "STATUS_TIMEOUT"
	OTHER
		RETURN "Unknown type: " + LTRIM(STR(lnWaitResult))
	ENDCASE

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER CreateSemaphore IN kernel32;
		INTEGER lcSmAttr, INTEGER lInitialCount,;
		INTEGER lMaximumCount, STRING lpName

	DECLARE INTEGER OpenSemaphore IN kernel32;
		INTEGER dwDesiredAccess, INTEGER bInheritHandle,;
		STRING lpName

	DECLARE INTEGER ReleaseSemaphore IN kernel32;
		INTEGER hSemaphore, INTEGER lReleaseCount,;
		INTEGER @ lpPreviousCount

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateSemaphore](../libraries/kernel32/CreateSemaphore.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[OpenSemaphore](../libraries/kernel32/OpenSemaphore.md)  
[ReleaseSemaphore](../libraries/kernel32/ReleaseSemaphore.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  

## Comment:
A semaphore object is a synchronization object that maintains a count between zero and a specified maximum value.   
  
The count is decremented each time a thread completes a wait for the semaphore object and incremented each time a thread releases the semaphore  
  
When the count reaches zero, no more threads can successfully wait for the semaphore object state to become signaled.  
  
The state of a semaphore is set to signaled when its count is greater than zero, and nonsignaled when its count is zero.   
  
***  

