[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WTSEnumerateSessions
Group: [Terminal Services](../../functions_group.md#Terminal_Services)  -  Library: [wtsapi32](../../Libraries.md#wtsapi32)  
***  


#### Retrieves a list of sessions on a specified terminal server.
***  


## Code examples:
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  

## Declaration:
```foxpro  
BOOL WTSEnumerateSessions(
	HANDLE hServer,
	DWORD Reserved,
	DWORD Version,
	PWTS_SESSION_INFO* ppSessionInfo,
	DWORD* pCount
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WTSEnumerateSessions IN Wtsapi32;
	INTEGER hServer,;
	LONG Reserved,;
	LONG RqVersion,;
	LONG @ppSessionInfo,;
	LONG @SICount
  
```  
***  


## Parameters:
hServer 
[in] Handle to a terminal server. Specify a handle opened by the WTSOpenServer function, or specify WTS_CURRENT_SERVER_HANDLE to indicate the terminal server on which your application is running. 

Reserved 
Reserved; must be zero. 

Version 
[in] Specifies the version of the enumeration request. Must be 1.

ppSessionInfo 
[out] Pointer to a variable that receives a pointer to an array of WTS_SESSION_INFO structures.

pCount 
[out] Pointer to the variable that receives the number of WTS_SESSION_INFO structures returned in the ppSessionInfo buffer.   
***  


## Return value:
If the function succeeds, the return value is a nonzero value.  
***  


## Comments:
To free <Em>ppSessionInfo</Em>, call the WTSFreeMemory function.   
  
See also: [WTSEnumerateProcesses](../wtsapi32/WTSEnumerateProcesses.md), [WTSEnumerateServers](../wtsapi32/WTSEnumerateServers.md).  
  
***  

