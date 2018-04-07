[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InitiateShutdown
Group: [System Shutdown](../../functions_group.md#System_Shutdown)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Initiates a shutdown and restart of the specified computer, and restarts any applications that have been registered for restart.
***  


## Declaration:
```foxpro  
DWORD WINAPI InitiateShutdown(
  __in_opt  LPTSTR lpMachineName,
  __in_opt  LPTSTR lpMessage,
  __in      DWORD dwGracePeriod,
  __in      DWORD dwShutdownFlags,
  __in      DWORD dwReason
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InitiateShutdown IN Advapi32;
	STRING lpMachineName,;
	STRING lpMessage,;
	LONG dwGracePeriod,;
	LONG dwShutdownFlags,;
	LONG dwReason  
```  
***  


## Parameters:
lpMachineName [in, optional]
The name of the computer to be shut down. If the value of this parameter is NULL, the local computer is shut down.

lpMessage [in, optional]
The message to be displayed in the interactive shutdown dialog box.

dwGracePeriod [in]
The number of seconds to wait before shutting down the computer.

dwShutdownFlags [in]
One or more bit flags that specify options for the shutdown.

dwReason [in]
The reason for initiating the shutdown. This parameter must be one of the system shutdown reason codes.  
***  


## Return value:
If the function succeeds, it returns ERROR_SUCCESS (0).  
***  


## Comments:
To shut down the local computer, the calling thread must have the SE_SHUTDOWN_NAME privilege.   
  
To shut down a remote computer, the calling thread must have the SE_REMOTE_SHUTDOWN_NAME privilege on the remote computer.  
  
Minimum supported client: Windows Vista  
  
See also: [InitiateSystemShutdown](../advapi32/InitiateSystemShutdown.md).  
  
***  

