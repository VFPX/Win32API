<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CloseEventLog
Group: Event Logging - Library: advapi32    
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
```txt  
hEventLog
[in, out] A handle to the event log to be closed. This handle is returned by the OpenEventLog or OpenBackupEventLog function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

