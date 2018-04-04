[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumServicesStatus
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The EnumServicesStatus function enumerates services in the specified service control manager database.
***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  

## Declaration:
```foxpro  
BOOL EnumServicesStatus(
  SC_HANDLE hSCManager,
  DWORD dwServiceType,
  DWORD dwServiceState,
  LPENUM_SERVICE_STATUS lpServices,
  DWORD cbBufSize,
  LPDWORD pcbBytesNeeded,
  LPDWORD lpServicesReturned,
  LPDWORD lpResumeHandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumServicesStatus IN advapi32;
	INTEGER hSCManager,;
	LONG    dwServiceType,;
	LONG    dwServiceState,;
	INTEGER lpServices,;
	LONG    cbBufSize,;
	LONG  @ pcbBytesNeeded,;
	LONG  @ lpServicesReturned,;
	LONG  @ lpResumeHandle
  
```  
***  


## Parameters:
hSCManager 
[in] Handle to the service control manager database.

dwServiceType 
[in] Type of services to enumerate.

dwServiceState 
[in] State of the services to be enumerated.

lpServices 
[out] Pointer to a buffer that contains an array of ENUM_SERVICE_STATUS structures that receive the name and service status information for each service in the database.

cbBufSize 
[in] Size of the buffer pointed to by the lpServices parameter, in bytes. 

pcbBytesNeeded 
[out] Pointer to a variable that receives the number of bytes needed to return the remaining service entries, if the buffer is too small. 

lpServicesReturned 
[out] Pointer to a variable that receives the number of service entries returned. 

lpResumeHandle 
[in, out] Pointer to a variable that, on input, specifies the starting point of enumeration.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The <Em>hSCManager</Em> handle is returned by the OpenSCManager function, and must have the SC_MANAGER_ENUMERATE_SERVICE access right.  
  
Set the value of <Em>lpResumeHandle</Em> to zero the first time this function is called.  
  
***  

