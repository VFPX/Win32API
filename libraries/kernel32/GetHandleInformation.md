[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetHandleInformation
Group: [Handle and Object](../../functions_group.md#Handle_and_Object)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hObject 
[in] Handle to an object whose information is to be retrieved.

lpdwFlags 
[out] Pointer to a variable that receives a set of bit flags that specify properties of the object handle.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
You can specify a handle to one of the following types of objects: access token, event, file, file mapping, job, mailslot, mutex, pipe, printer, process, registry key, semaphore, serial communication device, socket, thread, or waitable timer.  
  
See also: [SetHandleInformation](../kernel32/SetHandleInformation.md).  
  
***  

