[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeregisterEventSource
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
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
hEventLog 
[in, out] A handle to the event log. This handle is returned by the RegisterEventSource function.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

