[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ControlService
Group: [Service](../../functions_group.md#Service)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The ControlService function sends a control code to a service.

***  


## Code examples:
[Encapsulating access to the Windows Services in a class](../../samples/sample_476.md)  
[How to delete a service object](../../samples/sample_518.md)  

## Declaration:
```foxpro  
BOOL ControlService(
  SC_HANDLE hService,
  DWORD dwControl,
  LPSERVICE_STATUS lpServiceStatus
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ControlService IN advapi32;
	INTEGER  hService,;
	LONG     dwControl,;
	STRING @ lpServiceStatus
  
```  
***  


## Parameters:
hService 
[in] Handle to the service. This handle is returned by the OpenService or CreateService function. 

dwControl 
[in] This parameter can be one of predefined control codes.

lpServiceStatus 
[out] Pointer to a SERVICE_STATUS structure that receives the latest service status information.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The ControlService function asks the Service Control Manager (SCM) to send the requested control code to the service. The SCM sends the code if the service has specified that it will accept the code, and is in a state in which a control code can be sent to it.  
  
See also: [OpenService](../advapi32/OpenService.md), [StartService](../advapi32/StartService.md).  
  
***  

