<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : StartService
Group: Service - Library: advapi32    
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
```txt  
hService
[in] Handle to the service. This handle is returned by the OpenService or CreateService function, and it must have the SERVICE_START access right.

dwNumServiceArgs
[in] Number of strings in the lpServiceArgVectors array. If lpServiceArgVectors is NULL, this parameter can be zero.

lpServiceArgVectors
[in] Pointer to an array of pointers to null-terminated strings to be passed to a service as arguments.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.
  
***  


## Comments:
A call to the StartService function to start a service in a locked database fails.  
  
See also: ControlService, CreateService, OpenService, UnlockServiceDatabase.  
  
***  

