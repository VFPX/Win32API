[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemTimeAsFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetSystemTimeAsFileTime function retrieves the current system date and time. The information is in Coordinated Universal Time (UTC) format.
***  


## Code examples:
[Setting the date and time that a file was created](../../samples/sample_065.md)  

## Declaration:
```foxpro  
void GetSystemTimeAsFileTime(
  LPFILETIME lpSystemTimeAsFileTime
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetSystemTimeAsFileTime IN kernel32;
	STRING @lpSystemTimeAsFileTime
  
```  
***  


## Parameters:
lpSystemTimeAsFileTime 
[out] Pointer to a FILETIME structure to receive the current system date and time in UTC format.  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
This function is useful when you need to set a file time using current system time. Otherwise you would use a succession of GetSystemTime and SystemTimeToFileTime functions.  
  
***  

