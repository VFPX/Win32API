[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : QueryPerformanceFrequency
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The QueryPerformanceFrequency function retrieves the frequency of the high-resolution performance counter, if one exists. The frequency cannot change while the system is running.
***  


## Code examples:
[Using the high-resolution performance counter](../../samples/sample_262.md)  

## Declaration:
```foxpro  
BOOL QueryPerformanceFrequency(
  LARGE_INTEGER *lpFrequency   // current frequency
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER QueryPerformanceFrequency IN kernel32;
	STRING @lpFrequency  
```  
***  


## Parameters:
lpFrequency 
[out] Pointer to a variable that receives the current performance-counter frequency, in counts per second.   
***  


## Return value:
If the installed hardware supports a high-resolution performance counter, the return value is nonzero.  
***  


## Comments:
Note that the frequency of the high-resolution performance counter is not the processor speed.  
See GetTickCount function.  
  
***  

