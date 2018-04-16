[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetNumberOfEventLogRecords
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves the number of records in the specified event log.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  
[Writing entries to custom Event Log](../../samples/sample_564.md)  

## Declaration:
```foxpro  
BOOL GetNumberOfEventLogRecords(
	HANDLE hEventLog,
	PDWORD NumberOfRecords
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNumberOfEventLogRecords IN advapi32;
	INTEGER hEventLog,;
	LONG @NumberOfRecords  
```  
***  


## Parameters:
hEventLog
[in] A handle to the open event log. This handle is returned by the OpenEventLog or OpenBackupEventLog function. 

NumberOfRecords
[out] A pointer to a variable that receives the number of records in the specified event log.   
***  


## Return value:
If the function succeeds, the return value is nonzero.   
***  


## Comments:
```foxpro
hLog = OpenEventLog(NULL, "Application")  
  
IF hLog <> 0  
	STORE 0 TO nReccount, nRecno  
  
	= GetNumberOfEventLogRecords(m.hLog, @nReccount)  
	= GetOldestEventLogRecord(m.hLog, @nRecno)  
  
	? nReccount, nRecno  
  
	= CloseEventLog(hLog)  
ENDIF
```

***  

