[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSEnumerateProcesses
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
***  


#### Retrieves information about the active processes on a specified terminal server.
***  


## Code examples:
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  

## Declaration:
```foxpro  
BOOL WTSEnumerateProcesses(
	HANDLE hServer,
	DWORD Reserved,
	WORD Version,
	PWTS_PROCESS_INFO* ppProcessInfo,
	DWORD* pCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSEnumerateProcesses IN Wtsapi32;
	INTEGER hServer,;
	LONG Reserved,;
	LONG RqVersion,;
	LONG @ppProcessInfo,;
	LONG @PICount  
```  
***  


## Parameters:
hServer 
[in] Handle to a terminal server. Specify a handle opened by the WTSOpenServer function, or specify WTS_CURRENT_SERVER_HANDLE to indicate the terminal server on which your application is running. 

Reserved 
Reserved; must be zero. 

Version 
[in] Specifies the version of the enumeration request. Must be 1. 

ppProcessInfo 
[out] Pointer to a variable that receives a pointer to an array of WTS_PROCESS_INFO structures. 

[out] Pointer to a variable that receives the number of WTS_PROCESS_INFO structures returned in the ppProcessInfo buffer.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
To free <Em>ppProcessInfo</Em>, call the WTSFreeMemory function.   
  
See also: [WTSEnumerateSessions](../wtsapi32/WTSEnumerateSessions.md), [WTSEnumerateServers](../wtsapi32/WTSEnumerateServers.md).  
  
***  

