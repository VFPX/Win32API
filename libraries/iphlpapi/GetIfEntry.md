<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetIfEntry
Group: IP Helper - Library: iphlpapi    
***  


#### The GetIfEntry function retrieves information for the specified interface on the local computer.
***  


## Declaration:
```foxpro  
DWORD GetIfEntry(
  PMIB_IFROW pIfRow  // pointer to interface entry
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetIfEntry IN iphlpapi;
	STRING @ pIfRow  
```  
***  


## Parameters:
```txt  
pIfRow
[in, out] Pointer to a MIB_IFROW structure that, on successful return, receives information for an interface on the local computer.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the function fails, use FormatMessage to obtain the message string for the returned error.  
***  


## Comments:
On input, set the dwIndex member of MIB_IFROW to the index of the interface for which to retrieve information.  
  
***  

