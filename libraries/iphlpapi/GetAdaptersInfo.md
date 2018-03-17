<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetAdaptersInfo
Group: IP Helper - Library: iphlpapi    
***  


#### The GetAdaptersInfo function retrieves adapter information for the local computer.
***  


## Code examples:
[How to retrieve adapter information for the local computer (including MAC address)](../../samples/sample_347.md)  

## Declaration:
```foxpro  
DWORD GetAdaptersInfo(
	PIP_ADAPTER_INFO pAdapterInfo,
	PULONG pOutBufLen
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetAdaptersInfo IN iphlpapi;
	STRING @ pAdapterInfo,;
	LONG   @ pOutBufLen
  
```  
***  


## Parameters:
```txt  
pAdapterInfo
[out] Pointer to a buffer that receives a linked list of IP_ADAPTER_INFO structures.

pOutBufLen
[in] Pointer to a ULONG variable that specifies the size of the buffer pointed to by the pAdapterInfo parameter.  
```  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS. If the function fails, the return value is one of predefined error codes.
  
***  


## Comments:
Windows Server 2003 and Windows XP: Use the GetAdaptersAddresses function instead of GetAdaptersInfo.  
  
***  

