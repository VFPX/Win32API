<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : OpenEventLog
Group: Event Logging - Library: advapi32    
***  


#### Opens a handle to the specified event log.
***  


## Code examples:
[Reading entries from Event logs](../../samples/sample_524.md)  

## Declaration:
```foxpro  
HANDLE OpenEventLog(
	LPCTSTR lpUNCServerName,
	LPCTSTR lpSourceName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenEventLog IN advapi32;
	STRING lpUNCServerName,;
	STRING lpSourceName
  
```  
***  


## Parameters:
```txt  
lpUNCServerName
[in] The Universal Naming Convention (UNC) name of the server on which the event log is to be opened.

lpSourceName
[in] The name of the log.
If a custom log cannot be found, the event logging service opens the Application log; however, there will be no associated message or category string file.
  
```  
***  


## Return value:
If the function succeeds, the return value is the handle to an event log.  
***  


## Comments:
To close the handle to the event log, use the CloseEventLog function.  
  
With Event Viewer, users can monitor events recorded in the Application, Security, and System logs.  
  
<img src="images/eventviewer.png" width=549 height=323>  
  
***  

