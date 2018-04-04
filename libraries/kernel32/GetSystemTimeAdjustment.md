[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemTimeAdjustment
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Determines whether the system is applying periodic time adjustments to its time-of-day clock at each clock interrupt, along with the value and period of any such adjustments.
***  


## Code examples:
[Retrieving the System Time adjustment](../../samples/sample_072.md)  

## Declaration:
```foxpro  
BOOL GetSystemTimeAdjustment(
  PDWORD lpTimeAdjustment,       // size of time adjustment
  PDWORD lpTimeIncrement,        // time between adjustments
  PBOOL lpTimeAdjustmentDisabled // disable option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetSystemTimeAdjustment IN kernel32.dll;
	INTEGER @ lpTimeAdjustment,;
	INTEGER @ lpTimeIncrement,;
	SHORT   @ lpTimeAdjustmentDisabled  
```  
***  


## Parameters:
lpTimeAdjustment 
[out] Pointer to a DWORD that the function sets to the number of 100-nanosecond units added to the time-of-day clock at each periodic time adjustment. 

lpTimeIncrement 
[out] Pointer to a DWORD that the function sets to the interval, counted in 100-nanosecond units, between periodic time adjustments. This interval is the time period between a system"s clock interrupts. 

lpTimeAdjustmentDisabled 
[out] Pointer to a BOOL that the function sets to indicate whether periodic time adjustment is in effect.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Under Win9* this function returns the error code 120 -- "This function is not supported on this system".  
  
***  

