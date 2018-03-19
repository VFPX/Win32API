[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to initiate System shutdown

## Before you begin:
See also: 

* [Closing Windows](sample_036.md)  
* [Restarting Windows](sample_361.md)  
* [How to suspend or hibernate your system](sample_395.md)  
* [Enabling the SE_SHUTDOWN_NAME privilege for the application](sample_552.md)  

  
***  


## Code:
```foxpro  
DO declare

LOCAL cMachineName, nResult
cMachineName=""

nResult=InitiateSystemShutdown(cMachineName,;
	"System Shutdown initiated...", 10, 0, 1)

IF nResult = 0
* Common reasons for failure include an invalid
* or inaccessible computer name or insufficient privilege.
	*   5 = ERROR_ACCESS_DENIED
	*  53 = ERROR_BAD_NETPATH
	* 120 = ERROR_CALL_NOT_IMPLEMENTED -- not supported in Win9*
	? "Error code:", GetLastError()
ENDIF

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER InitiateSystemShutdownA IN advapi32;
	AS InitiateSystemShutdown ;
		STRING lpMachineName, STRING lpMessage,;
		INTEGER dwTimeout, SHORT bForceAppsClosed,;
		SHORT bRebootAfterShutdown  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[InitiateSystemShutdown](../libraries/advapi32/InitiateSystemShutdown.md)  

## Comment:
To shut down the local computer, the calling thread must have the SE_SHUTDOWN_NAME privilege.  
  
The InitiateSystemShutdownEx initiates a shutdown and optional restart of the specified computer, and optionally records the reason for the shutdown.  
  
***  

