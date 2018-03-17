<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetNumberOfInterfaces
Group: IP Helper - Library: iphlpapi    
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
```txt  
pdwNumIf
[out] Pointer to a DWORD variable that receives the number of interfaces on the local computer.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0). If the function fails, use FormatMessage to obtain the message string for the returned error.  
***  


## Comments:
The number of network interfaces returned by this function is one more ( that is the loopback interface ) than the number of adapters returned by the GetAdaptersInfo and GetInterfaceInfo functions.  
  
See also: if_indextoname, if_nametoindex   
  
***  

