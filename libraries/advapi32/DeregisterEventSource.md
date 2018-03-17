<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DeregisterEventSource
Group: Event Logging - Library: advapi32    
***  


#### Closes a write handle to the specified event log.
***  


## Code examples:
[Writing entries to custom Event Log](../../samples/sample_564.md)  

## Declaration:
```foxpro  
BOOL DeregisterEventSource(
  HANDLE hEventLog
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeregisterEventSource IN advapi32;
	INTEGER hEventLog  
```  
***  


## Parameters:
```txt  
hEventLog
[in, out] A handle to the event log. This handle is returned by the RegisterEventSource function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

