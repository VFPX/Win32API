[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetWaitableTimer
Group: [Synchronization](../../functions_group.md#Synchronization)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Activates the specified waitable timer. When the due time arrives, the timer is signaled and the thread that set the timer calls the optional completion routine.
***  


## Code examples:
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
BOOL WINAPI SetWaitableTimer(
	HANDLE hTimer,
	const LARGE_INTEGER* pDueTime,
	LONG lPeriod,
	PTIMERAPCROUTINE pfnCompletionRoutine,
	LPVOID lpArgToCompletionRoutine,
	BOOL fResume
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetWaitableTimer IN kernel32;
	INTEGER hTimer,;
	STRING @pDueTime,;
	LONG lPeriod,;
	INTEGER pfnCompletionRoutine,;
	INTEGER lpArgToCompletionRoutine,;
	INTEGER fResume  
```  
***  


## Parameters:
hTimer 
[in] Handle to the timer object. The CreateWaitableTimer or OpenWaitableTimer function returns this handle. 

pDueTime 
[in] Time after which the state of the timer is to be set to signaled, in 100 nanosecond intervals. Use the format described by the FILETIME structure.

lPeriod 
[in] Period of the timer, in milliseconds. If lPeriod is zero, the timer is signaled once. If lPeriod is greater than zero, the timer is periodic.

pfnCompletionRoutine 
[in] Pointer to an optional completion routine. 

lpArgToCompletionRoutine 
[in] Pointer to a structure that is passed to the completion routine. 

fResume 
[in] If this parameter is TRUE, restores a system in suspended power conservation mode when the timer state is set to signaled.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Timers are initially inactive. To activate a timer, call SetWaitableTimer. If the timer is already active when you call SetWaitableTimer, the timer is stopped, then it is reactivated. Stopping the timer in this manner does not set the timer state to signaled, so threads blocked in a wait operation on the timer remain blocked.  
  
For <Em>pDueTime</Em> use the format described by the FILETIME structure. Positive values indicate absolute time. Be sure to use a UTC-based absolute time, as the system uses UTC-based time internally. Negative values indicate relative time.  
  
***  

