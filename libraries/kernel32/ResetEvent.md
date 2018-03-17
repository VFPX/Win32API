<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ResetEvent
Group: Synchronization - Library: kernel32    
***  


#### The ResetEvent function sets the specified event object to the nonsignaled state.
***  


## Code examples:
[Using an Event Object. Part B: running an application responding to events](../../samples/sample_149.md)  

## Declaration:
```foxpro  
BOOL ResetEvent(
  HANDLE hEvent   // handle to event
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ResetEvent IN kernel32;
	INTEGER hEvent  
```  
***  


## Parameters:
```txt  
hEvent
[in] Handle to the event object. The CreateEvent or OpenEvent function returns this handle.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

