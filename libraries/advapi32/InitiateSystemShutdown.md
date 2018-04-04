[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InitiateSystemShutdown
Group: [System Shutdown](../../functions_group.md#System_Shutdown)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Initiates a shutdown and optional restart of the specified computer.
***  


## Code examples:
[How to initiate System shutdown](../../samples/sample_122.md)  

## Declaration:
```foxpro  
BOOL InitiateSystemShutdown(
  LPTSTR lpMachineName,      // computer name
  LPTSTR lpMessage,          // message to display
  DWORD dwTimeout,           // length of time to display
  BOOL bForceAppsClosed,     // force closed option
  BOOL bRebootAfterShutdown  // reboot option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT InitiateSystemShutdown IN advapi32;
	STRING  lpMachineName,;
	STRING  lpMessage,;
	INTEGER dwTimeout,;
	SHORT   bForceAppsClosed,;
	SHORT   bRebootAfterShutdown  
```  
***  


## Parameters:
lpMachineName 
[in] Pointer to the null-terminated string that specifies the network name of the computer to shut down. If lpMachineName is NULL or an empty string, the function shuts down the local computer. 

lpMessage 
[in] Pointer to a null-terminated string that specifies a message to display in the shutdown dialog box. This parameter can be NULL if no message is required. 

dwTimeout 
[in] Specifies the time (in seconds) that the shutdown dialog box should be displayed. 

bForceAppsClosed 
[in] Specifies whether applications with unsaved changes are to be forcibly closed. 

bRebootAfterShutdown 
[in] Specifies whether the computer is to restart immediately after shutting down. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  


## Comments:
Windows NT/2000 or later: Requires Windows NT 3.1 or later.   
Windows 95/98/Me: Unsupported.  
  
To shut down the local computer, the calling thread must have the SE_SHUTDOWN_NAME privilege. To shut down a remote computer, the calling thread must have the SE_REMOTE_SHUTDOWN_NAME privilege on the remote computer.   
  
* * *  
The InitiateSystemShutdownEx initiates a shutdown and optional restart of the specified computer, and optionally records the reason for the shutdown.  
  
***  

