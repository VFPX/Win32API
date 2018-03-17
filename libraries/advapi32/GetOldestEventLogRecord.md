<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetOldestEventLogRecord
Group: Event Logging - Library: advapi32    
***  


#### Retrieves the absolute record number of the oldest record in the specified event log.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  

## Declaration:
```foxpro  
BOOL GetOldestEventLogRecord(
	HANDLE hEventLog,
	PDWORD OldestRecord
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetOldestEventLogRecord IN advapi32;
	INTEGER hEventLog,;
	LONG @OldestRecord  
```  
***  


## Parameters:
```txt  
hEventLog
[in] A handle to the open event log. This handle is returned by the OpenEventLog or OpenBackupEventLog function.

OldestRecord
[out] A pointer to a variable that receives the absolute record number of the oldest record in the specified event log.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The oldest record in an event log is not necessarily record number 1.  
  
<div class="precode">hLog = OpenEventLog(NULL, "Application")  
  
IF hLog <> 0  
	STORE 0 TO nReccount, nRecno  
  
	= GetNumberOfEventLogRecords(m.hLog, @nReccount)  
	= GetOldestEventLogRecord(m.hLog, @nRecno)  
  
	? nReccount, nRecno  
  
	= CloseEventLog(hLog)  
ENDIF  
</div>  
  
***  

