[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : QueryPerformanceCounter
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The QueryPerformanceCounter function retrieves the current value of the high-resolution performance counter.
***  


## Code examples:
[Using the GetTempFileName](../../samples/sample_016.md)  
[Using the high-resolution performance counter](../../samples/sample_262.md)  

## Declaration:
```foxpro  
BOOL QueryPerformanceCounter(
  LARGE_INTEGER *lpPerformanceCount   // counter value
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER QueryPerformanceCounter IN kernel32;
	STRING @lpPerformanceCount  
```  
***  


## Parameters:
lpPerformanceCount 
[out] Pointer to a variable that receives the current performance-counter value, in counts.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See functions QueryPerformanceFrequency, and GetTickCount.  
  
Check <a href="http://cs-www.bu.edu/groups/realtime/SRMS-NT/event_scheduling.htm">the link</a> for more information on time counters.  
  
***  

