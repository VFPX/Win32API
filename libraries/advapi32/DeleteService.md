[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteService
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Marks the specified service for deletion from the service control manager database.
***  


## Code examples:
[How to delete a service object](../../samples/sample_518.md)  

## Declaration:
```foxpro  
BOOL WINAPI DeleteService(
	SC_HANDLE hService
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteService IN advapi32;
	INTEGER hService
  
```  
***  


## Parameters:
hService 
[in] Handle to the service.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This handle is returned by the OpenService or CreateService function, and it must have the DELETE access right.  
  
The DeleteService function marks a service for deletion from the service control manager database. The database entry is not removed until all open handles to the service have been closed by calls to the CloseServiceHandle function, and the service is not running.   
  
A running service is stopped by a call to the ControlService function with the SERVICE_CONTROL_STOP control code. If the service cannot be stopped, the database entry is removed when the system is restarted.  
  
The service control manager deletes the service by deleting the service key and its subkeys from the registry.  
  
1072=ERROR_SERVICE_MARKED_FOR_DELETE  
1062=ERROR_SERVICE_NOT_ACTIVE  
  
***  

