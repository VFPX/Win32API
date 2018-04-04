[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CloseEventLog
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Closes a read handle to the specified event log.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  

## Declaration:
```foxpro  
BOOL CloseEventLog(
 	HANDLE hEventLog
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CloseEventLog IN advapi32;
	INTEGER hEventLog
  
```  
***  


## Parameters:
hEventLog 
[in, out] A handle to the event log to be closed. This handle is returned by the OpenEventLog or OpenBackupEventLog function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

