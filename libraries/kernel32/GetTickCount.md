[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTickCount
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the number of milliseconds that have elapsed since the system was started.
***  


## Code examples:
[Using the GetTempFileName](../../samples/sample_016.md)  
[Retrieving the elapsed time since the system was started](../../samples/sample_066.md)  
[Time in milliseconds represented as string (e.g. 1 hour 24 min 36 sec)](../../samples/sample_105.md)  
[How to put a horizontal text scrolling on the form (a news line, marquee)](../../samples/sample_352.md)  
[Peer-to-peer LAN messenger built with Mailslot API functions](../../samples/sample_410.md)  
[How to play AVI file on the _screen](../../samples/sample_430.md)  
[GDI+: how to make VFP controls visually shake and shudder](../../samples/sample_526.md)  
[GDI+ fun: roach-infested desktop](../../samples/sample_548.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
DWORD GetTickCount(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG GetTickCount IN kernel32  
```  
***  


## Parameters:
This function has no parameters.  
***  


## Return value:
The return value is the number of milliseconds that have elapsed since the system was started.  
***  


## Comments:
DWORD or INTEGER both allow to keep 4 bytes, that means maximum of 4,294,967,295 milliseconds -> 1193 hours -> 49.7103 days.   
  
So after 49 and something days without rebooting the computer, this 32-bit counter overflows.  
  
Use the QueryPerformanceFrequency and QueryPerformanceCounter functions to access the high-resolution performance counter that operates 64-bit values.  
  
Read more about <a href="http://cs-www.bu.edu/groups/realtime/SRMS-NT/event_scheduling.htm">time counters</a>.  
  
* * *  
The GetTickCount64 function is free of the 49.71 limitation, if only one can find a way to return its 8-byte return value back to FoxPro. Unless, of course, this function is called in external library.  
  
* * *  
The timeGetTime function (Winmm.dll) is the absolute twin of the GetTickCount.  
```foxpro
DECLARE LONG timeGetTime IN winmm
```

***  

