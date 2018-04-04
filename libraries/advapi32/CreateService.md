[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateService
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Creates a service object and adds it to the specified service control manager database.
***  


## Code examples:
[How to create a service object](../../samples/sample_517.md)  

## Declaration:
```foxpro  
SC_HANDLE WINAPI CreateService(
	SC_HANDLE hSCManager,
	LPCTSTR lpServiceName,
	LPCTSTR lpDisplayName,
	DWORD dwDesiredAccess,
	DWORD dwServiceType,
	DWORD dwStartType,
	DWORD dwErrorControl,
	LPCTSTR lpBinaryPathName,
	LPCTSTR lpLoadOrderGroup,
	LPDWORD lpdwTagId,
	LPCTSTR lpDependencies,
	LPCTSTR lpServiceStartName,
	LPCTSTR lpPassword
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateService IN advapi32;
	INTEGER hSCManager,;
	STRING lpServiceName,;
	STRING lpDisplayName,;
	LONG dwDesiredAccess,;
	LONG dwServiceType,;
	LONG dwStartType,;
	LONG dwErrorControl,;
	STRING lpBinaryPathName,;
	STRING lpLoadOrderGroup,;
	LONG lpdwTagId,;
	STRING lpDependencies,;
	STRING lpServiceStartName,;
	STRING lpPassword  
```  
***  


## Parameters:
hSCManager 
[in] Handle to the service control manager database. This handle is returned by the OpenSCManager function and must have the SC_MANAGER_CREATE_SERVICE access right. 

lpServiceName 
[in] Pointer to a null-terminated string that specifies the name of the service to install. 

lpDisplayName 
[in] Pointer to a null-terminated string that contains the display name to be used by user interface programs to identify the service.

dwDesiredAccess 
[in] Access to the service.

dwServiceType 
[in] Service types, example SERVICE_WIN32_OWN_PROCESS.

dwStartType 
[in] Service start options, example SERVICE_DEMAND_START.

dwErrorControl 
[in] Severity of the error, and action taken, if this service fails to start, example SERVICE_ERROR_NORMAL.

lpBinaryPathName 
[in] Pointer to a null-terminated string that contains the fully qualified path to the service binary file.

lpLoadOrderGroup 
[in] Pointer to a null-terminated string that names the load ordering group of which this service is a member. Can be NULL.

lpdwTagId 
[out] Pointer to a variable that receives a tag value that is unique in the group specified in the lpLoadOrderGroup parameter. Can be NULL.

lpDependencies 
[in] Pointer to a double null-terminated array of null-separated names of services or load ordering groups that the system must start before this service. Can be NULL.

lpServiceStartName 
[in] Pointer to a null-terminated string that specifies the name of the account under which the service should run. Set to NULL for LocalSystem account.

lpPassword 
[in] Pointer to a null-terminated string that contains the password to the account name specified by the lpServiceStartName parameter.   
***  


## Return value:
If the function succeeds, the return value is a handle to the service.  
***  


## Comments:
The returned handle is only valid for the process that called CreateService. It can be closed by calling the CloseServiceHandle function.  
  
***  

