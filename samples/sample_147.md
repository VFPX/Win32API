[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the Semaphore object to allow only one instance of VFP application running

## Before you begin:
The best way to test this sample is to create a project with the code below and compile it in an executable file. Though whichever way you choose: an executable, an application, or another VFP instance -- this code works fine.  

See also:

* [Using shared memory to exchange data between two FoxPro applications](sample_498.md)  
* [How to prevent users from accessing the Windows Desktop and from switching to other applications](sample_492.md)  
  
***  


## Code:
```foxpro  
#DEFINE WAIT_OBJECT_0     0
#DEFINE STATUS_TIMEOUT  258

#DEFINE STANDARD_RIGHTS_REQUIRED 0xf0000
#DEFINE SYNCHRONIZE              0x100000

*| STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 3
#DEFINE SEMAPHORE_ALL_ACCESS     0x1f0003

DO decl

	LOCAL hSmp, lcSmp
	lcSmp = "TestSmp"
	
	* trying to open a semaphore named TestSmp
	hSmp = OpenSemaphore (STANDARD_RIGHTS_REQUIRED, 0, lcSmp)

	IF hSmp = 0
	* no Semaphore object found
	* new Semaphore object to be created
		hSmp = CreateSemaphore (0, 1, 1, lcSmp)
		IF hSmp = 0
			= MessageB("Unable to create required Semaphore object.   " +;
			Chr(13)+ "Error code: " +;
			LTRIM(STR(GetLastError())))
			RETURN
		ENDIF
		
		= MessageB("New Semaphore object has been created:   " + Chr(13) +;
			"name=" + lcSmp + ", handle=" + LTRIM(STR(hSmp)))

		* launch your application here
		* ...
	ELSE
	* the Semaphore object with this name already exists
	* that means the process is already running
		= MessageB("The process is already running.   ")
	ENDIF

	* The system closes the handle automatically
	* when the process terminates
	* so the following line is mostly redundant
	= CloseHandle(hSmp)

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER CreateSemaphore IN kernel32;
		INTEGER lcSmAttr, INTEGER lInitialCount,;
		INTEGER lMaximumCount, STRING lpName

	DECLARE INTEGER OpenSemaphore IN kernel32;
		INTEGER dwDesiredAccess,;
		INTEGER bInheritHandle, STRING lpName  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateSemaphore](../libraries/kernel32/CreateSemaphore.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[OpenSemaphore](../libraries/kernel32/OpenSemaphore.md)  

## Comment:
A combination of two functions -- Create... and Open... -- is used, and it is not the only Semaphore object good for this task.   
  
Same can be done with **Mutex** object (**Mut**ually**Ex**clusive), or **Event** object. First you try to open the named object. If it already exists, that means another VFP application instance is running. Otherwise you create the object within this instance.  
  
***  

