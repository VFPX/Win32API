[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to delete a service object

## Before you begin:
This code sample shows how to delete the service object created in [How to create a service object code](sample_517.md) sample.  

See also:

* [Encapsulating access to the Windows Services in a class](sample_476.md)  
  
***  


## Code:
```foxpro  
#DEFINE SC_MANAGER_ALL_ACCESS 0xF003F
#DEFINE DELETE_SERVICE 0x00010000
#DEFINE SERVICE_STOP 0x20
#DEFINE SERVICE_CONTROL_STOP 1
#DEFINE SERVICE_STATUS_SIZE 36
DO declare

DO DeleteWinService WITH "FriendlyService"

FUNCTION DeleteWinService(cServiceName)
	LOCAL hManager, hService
	hManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS)

	IF m.hManager = 0
		? "Call to OpenSCManager failed."
		RETURN .F.
	ENDIF

	hService = OpenService(hManager, m.cServiceName,;
		BITOR(DELETE_SERVICE, SERVICE_STOP))

	IF hService = 0
		? "Failed to obtain the handle to the service."
	ELSE
		* stop service if it is running
		LOCAL cStatusInfo
		cStatusInfo = REPLICATE(CHR(0), SERVICE_STATUS_SIZE)
		= ControlService(m.hService, SERVICE_CONTROL_STOP, @cStatusInfo)

		IF DeleteService(m.hService) = 0
			? "DeleteService failed with error code", GetLastError()
		ENDIF
		= CloseServiceHandle(m.hService)
	ENDIF

	= CloseServiceHandle(m.hManager)
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER CloseServiceHandle IN advapi32 INTEGER hSCObject

	DECLARE INTEGER OpenSCManager IN advapi32;
		STRING lpMachineName, STRING lpDatabaseName,;
		LONG dwDesiredAccess

	DECLARE INTEGER OpenService IN advapi32;
		INTEGER hSCManager, STRING lpServiceName,;
		LONG dwDesiredAccess

	DECLARE INTEGER DeleteService IN advapi32 INTEGER hService

	DECLARE INTEGER ControlService IN advapi32;
		INTEGER hService, LONG dwControl,;
		STRING @lpServiceStatus  
```  
***  


## Listed functions:
[CloseServiceHandle](../libraries/advapi32/CloseServiceHandle.md)  
[ControlService](../libraries/advapi32/ControlService.md)  
[DeleteService](../libraries/advapi32/DeleteService.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[OpenSCManager](../libraries/advapi32/OpenSCManager.md)  
[OpenService](../libraries/advapi32/OpenService.md)  
