[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetEvent
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hEvent 
[in] Handle to the event object. The CreateEvent or OpenEvent function returns this handle.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

