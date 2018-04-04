[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetLocalTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the current local date and time.
***  


## Code examples:
[System and Local Time values](../../samples/sample_064.md)  
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
VOID GetLocalTime(
  LPSYSTEMTIME lpSystemTime   // system time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetLocalTime IN kernel32;
	STRING @ lpSystemTime  
```  
***  


## Parameters:
lpSystemTime 
[out] Pointer to a SYSTEMTIME structure to receive the current local date and time.  
***  


## Return value:
This function does not return a value.  
***  

