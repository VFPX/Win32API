<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetHandleInformation
Group: Handle and Object - Library: kernel32    
***  


#### The GetHandleInformation function retrieves certain properties of an object handle.
***  


## Code examples:
[Memory usage info for current VFP session (WinNT only)](../../samples/sample_172.md)  

## Declaration:
```foxpro  
BOOL GetHandleInformation(
  HANDLE hObject,
  LPDWORD lpdwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetHandleInformation IN kernel32;
	INTEGER   hObject,;
	INTEGER @ lpdwFlags  
```  
***  


## Parameters:
```txt  
hObject
[in] Handle to an object whose information is to be retrieved.

lpdwFlags
[out] Pointer to a variable that receives a set of bit flags that specify properties of the object handle.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
You can specify a handle to one of the following types of objects: access token, event, file, file mapping, job, mailslot, mutex, pipe, printer, process, registry key, semaphore, serial communication device, socket, thread, or waitable timer.  
  
See also: SetHandleInformation   
  
***  

