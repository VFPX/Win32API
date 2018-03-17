<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetEvent
Group: Synchronization - Library: kernel32    
***  


#### The SetEvent function sets the specified event object to the signaled state.
***  


## Code examples:
[Using an Event Object. Part A: running an application that creates an Event object](../../samples/sample_148.md)  

## Declaration:
```foxpro  
BOOL SetEvent(
  HANDLE hEvent   // handle to event
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetEvent IN kernel32;
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

