<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RegisterEventSource
Group: Event Logging - Library: advapi32    
***  


#### Retrieves a registered handle to the specified event log.
***  


## Declaration:
```foxpro  
HANDLE RegisterEventSource(
  LPCTSTR lpUNCServerName,
  LPCTSTR lpSourceName
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegisterEventSource IN advapi32;
	STRING lpUNCServerName,;
	STRING lpSourceName  
```  
***  


## Parameters:
```txt  
lpUNCServerName
[in] The Universal Naming Convention (UNC) name of the server on which this operation is to be performed. If this parameter is NULL, the operation is performed on the local computer.

lpSourceName
[in] The name of the event source whose handle is to be retrieved. The source name must be a subkey of a log under the Eventlog registry key.
However, the Security log is for system use only.
  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the event log. 
If the function fails, the return value is NULL.
  
***  


## Comments:
To close the handle to the event log, use the DeregisterEventSource function.  
  
***  

