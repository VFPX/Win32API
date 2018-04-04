[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenSCManager
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The OpenSCManager function establishes a connection to the service control manager on the specified computer and opens the specified service control manager database.

***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  
[How to create a service object](../../samples/sample_517.md)  
[How to delete a service object](../../samples/sample_518.md)  

## Declaration:
```foxpro  
SC_HANDLE OpenSCManager(
  LPCTSTR lpMachineName,
  LPCTSTR lpDatabaseName,
  DWORD dwDesiredAccess
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenSCManager IN advapi32;
	STRING lpMachineName,;
	STRING lpDatabaseName,;
	LONG   dwDesiredAccess
  
```  
***  


## Parameters:
lpMachineName 
[in] Pointer to a null-terminated string that specifies the name of the target computer.

lpDatabaseName 
[in] Pointer to a null-terminated string that specifies the name of the service control manager database to open.

dwDesiredAccess 
[in] Access to the service control manager.  
***  


## Return value:
If the function succeeds, the return value is a handle to the specified service control manager database.  
***  


## Comments:
The returned handle is only valid for the process that called the OpenSCManager function. It can be closed by calling the CloseServiceHandle function.  
  
***  

