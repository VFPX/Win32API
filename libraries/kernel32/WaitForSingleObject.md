[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WaitForSingleObject
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The WaitForSingleObject function returns when the specified object is in the signaled state or when the time-out interval elapses
***  


## Code examples:
[Using the Semaphore object](../../samples/sample_008.md)  
[Monitoring changes in a directory](../../samples/sample_117.md)  
[Using an Event Object. Part B: running an application responding to events](../../samples/sample_149.md)  
[Starting external program from VFP and waiting for its termination](../../samples/sample_377.md)  
[Pocket PC: base class](../../samples/sample_440.md)  
[Pocket PC: custom RAPI class for operating with the System Registry](../../samples/sample_441.md)  
[Pocket PC: custom RAPI class for operating with files and folders on mobile device](../../samples/sample_448.md)  
[PocketPC: custom RAPI class for executing routines on remote Windows CE device](../../samples/sample_466.md)  
[Using Change Notification Objects to monitor changes to the printer or print server](../../samples/sample_485.md)  
[How to prevent users from accessing the Windows Desktop and from switching to other applications](../../samples/sample_492.md)  
[Using shared memory to exchange data between applications (processes)](../../samples/sample_498.md)  

## Declaration:
```foxpro  
DWORD WaitForSingleObject(
    HANDLE  hObject,	// handle of object to wait for
    DWORD  dwTimeout 	// time-out interval in milliseconds
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WaitForSingleObject IN kernel32;
	INTEGER hHandle,;
	INTEGER dwMilliseconds
  
```  
***  


## Parameters:
hObject
Identifies the object

dwTimeout
Specifies the time-out interval, in milliseconds  
***  


## Return value:
If the function succeeds, the return value indicates the event that caused the function to return  
***  

