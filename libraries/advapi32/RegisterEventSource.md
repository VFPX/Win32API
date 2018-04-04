[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegisterEventSource
Group: [Event Logging](../../functions_group.md#Event_Logging)  -  Library: [advapi32](../../Libraries.md#advapi32)  
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
lpUNCServerName 
[in] The Universal Naming Convention (UNC) name of the server on which this operation is to be performed. If this parameter is NULL, the operation is performed on the local computer. 

lpSourceName 
[in] The name of the event source whose handle is to be retrieved. The source name must be a subkey of a log under the Eventlog registry key. 
However, the Security log is for system use only.
  
***  


## Return value:
If the function succeeds, the return value is a handle to the event log. 
If the function fails, the return value is NULL.
  
***  


## Comments:
To close the handle to the event log, use the DeregisterEventSource function.  
  
***  

