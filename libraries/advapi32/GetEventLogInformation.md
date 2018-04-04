[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetEventLogInformation
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves information about the specified event log.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  

## Declaration:
```foxpro  
BOOL GetEventLogInformation(
  HANDLE hEventLog,
  DWORD dwInfoLevel,
  LPVOID lpBuffer,
  DWORD cbBufSize,
  LPDWORD pcbBytesNeeded
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetEventLogInformation IN advapi32;
	INTEGER hEventLog,;
	LONG dwInfoLevel,;
	LONG @lpBuffer,;
	LONG cbBufSize,;
	LONG @pcbBytesNeeded  
```  
***  


## Parameters:
hEventLog 
[in] A handle to the event log. This handle is returned by the OpenEventLog or RegisterEventSource function. 

dwInfoLevel 
[in] The level of event log information to be returned. Use EVENTLOG_FULL_INFO (0) to find out if the specified log is full.

lpBuffer 
[out] A pointer to a buffer for the event log information. The format of this data depends on the value of the dwInfoLevel parameter. 

cbBufSize 
[in] The size of the buffer, in bytes. 

pcbBytesNeeded 
[out] A pointer to a variable that receives the number of bytes required for the requested information, regardless of whether the function succeeds. This parameter cannot be NULL.   
***  


## Return value:
If the function succeeds, the return value is nonzero.   
***  


## Comments:
At this point, the EVENTLOG_FULL_INFORMATION contains only one member, which indicates whether the log is full.  
  
***  

