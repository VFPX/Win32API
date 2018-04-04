[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ReadEventLog
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Reads a whole number of entries from the specified event log. The function can be used to read log entries in chronological or reverse chronological order.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  

## Declaration:
```foxpro  
BOOL ReadEventLog(
	HANDLE hEventLog,
	DWORD dwReadFlags,
	DWORD dwRecordOffset,
	LPVOID lpBuffer,
	DWORD nNumberOfBytesToRead,
	DWORD* pnBytesRead,
	DWORD* pnMinNumberOfBytesNeeded
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ReadEventLog IN advapi32;
	INTEGER hEventLog,;
	LONG dwReadFlags,;
	LONG dwRecordOffset,;
	INTEGER lpBuffer,;
	LONG nNumberOfBytesToRead,;
	LONG @pnBytesRead,;
	LONG @pnMinNumberOfBytesNeeded  
```  
***  


## Parameters:
hEventLog 
[in] A handle to the event log to be read. This handle is returned by the OpenEventLog function. 

dwReadFlags 
[in] The options for how the read operation is to proceed.

dwRecordOffset 
[in] The number of the log-entry record at which the read operation should start. 

lpBuffer 
[out] A pointer to a buffer for the data read from the event log. 

nNumberOfBytesToRead 
[in] The size of the buffer, in bytes. This function will read as many whole log entries as will fit in the buffer.

pnBytesRead 
[out] A pointer to a variable that receives the number of bytes read by the function. 

pnMinNumberOfBytesNeeded
[out] A pointer to a variable that receives the number of bytes required for the next log entry.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
When this function returns successfully, the read position in the event log is adjusted by the number of records read. Only a whole number of event log records will be returned.  
  
***  

