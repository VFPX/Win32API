[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : StartService
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The StartService function starts a service.

***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  

## Declaration:
```foxpro  
BOOL StartService(
  SC_HANDLE hService,
  DWORD dwNumServiceArgs,
  LPCTSTR* lpServiceArgVectors
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER StartService IN advapi32;
	INTEGER hService,;
	LONG    dwNumServiceArgs,;
	INTEGER lpServiceArgVectors
  
```  
***  


## Parameters:
hService 
[in] Handle to the service. This handle is returned by the OpenService or CreateService function, and it must have the SERVICE_START access right.

dwNumServiceArgs 
[in] Number of strings in the lpServiceArgVectors array. If lpServiceArgVectors is NULL, this parameter can be zero.

lpServiceArgVectors 
[in] Pointer to an array of pointers to null-terminated strings to be passed to a service as arguments.   
***  


## Return value:
If the function succeeds, the return value is nonzero.
  
***  


## Comments:
A call to the StartService function to start a service in a locked database fails.  
  
See also: [ControlService](../advapi32/ControlService.md), [CreateService](../advapi32/CreateService.md), [OpenService](../advapi32/OpenService.md), [UnlockServiceDatabase](../advapi32/UnlockServiceDatabase.md).  
  
***  

