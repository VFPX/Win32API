[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenService
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The OpenService function opens an existing service.

***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  
[How to delete a service object](../../samples/sample_518.md)  

## Declaration:
```foxpro  
SC_HANDLE OpenService(
  SC_HANDLE hSCManager,
  LPCTSTR lpServiceName,
  DWORD dwDesiredAccess
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenService IN advapi32;
	INTEGER hSCManager,;
	STRING  lpServiceName,;
	LONG    dwDesiredAccess
  
```  
***  


## Parameters:
hSCManager 
[in] Handle to the service control manager database. The OpenSCManager function returns this handle.

lpServiceName 
[in] Pointer to a null-terminated string that specifies the name of the service to open. 

dwDesiredAccess 
[in] Access to the service.   
***  


## Return value:
If the function succeeds, the return value is a handle to the service.
  
***  


## Comments:
Unicode: Implemented as OpenServiceW (Unicode) and OpenServiceA (ANSI).  
  
The returned handle is only valid for the process that called OpenService. It can be closed by calling the CloseServiceHandle function.  
  
See also: [StartService](../advapi32/StartService.md), [ControlService](../advapi32/ControlService.md).  
  
***  

