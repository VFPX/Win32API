[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetNumberOfInterfaces
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Returns the number of network interfaces on the local computer, including the loopback interface. 
***  


## Declaration:
```foxpro  
DWORD GetNumberOfInterfaces(
  PDWORD pdwNumIf  // pointer to number of interfaces
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNumberOfInterfaces IN iphlpapi;
	INTEGER @ pdwNumIf  
```  
***  


## Parameters:
pdwNumIf 
[out] Pointer to a DWORD variable that receives the number of interfaces on the local computer.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the function fails, use FormatMessage to obtain the message string for the returned error.  
***  


## Comments:
The number of network interfaces returned by this function is one more ( that is the loopback interface ) than the number of adapters returned by the GetAdaptersInfo and GetInterfaceInfo functions.  
  
See also: [if_indextoname](../iphlpapi/if_indextoname.md), [if_nametoindex](../iphlpapi/if_nametoindex.md).  
  
***  

