[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ClearEventLog
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Clears the specified event log, and optionally saves the current copy of the log to a backup file.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  

## Declaration:
```foxpro  
BOOL ClearEventLog(
  HANDLE hEventLog,
  LPCTSTR lpBackupFileName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ClearEventLog IN advapi32;
	INTEGER hEventLog,;
	STRING lpBackupFileName  
```  
***  


## Parameters:
hEventLog 
[in] A handle to the event log to be cleared. This handle is returned by the OpenEventLog function. 

lpBackupFileName 
[in] The name of the backup file. If this file already exists, the function fails. 
If the lpBackupFileName parameter is NULL, the current event log is not backed up.

  
***  


## Return value:
If the function succeeds, the return value is nonzero.   
***  


## Comments:
The ClearEventLog function fails if the event log is empty or a file already exists with the same name as lpBackupFileName.  
  
After this function returns, any handles that reference the cleared event log cannot be used to read the log.  
  
***  

