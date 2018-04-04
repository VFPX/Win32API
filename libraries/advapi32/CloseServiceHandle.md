[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CloseServiceHandle
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The CloseServiceHandle function closes a handle to a service control manager or service object.
***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  
[How to create a service object](../../samples/sample_517.md)  
[How to delete a service object](../../samples/sample_518.md)  

## Declaration:
```foxpro  
BOOL CloseServiceHandle(
  SC_HANDLE hSCObject
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CloseServiceHandle IN advapi32;
	INTEGER hSCObject  
```  
***  


## Parameters:
hSCObject 
[in] Handle to the service control manager object or the service object to close.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The CloseServiceHandle function does not destroy the service control manager object referred to by the handle. A service control manager object cannot be destroyed. A service object can be destroyed by calling the DeleteService function.  
  
***  

