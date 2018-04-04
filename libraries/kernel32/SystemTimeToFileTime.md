[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SystemTimeToFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The SystemTimeToFileTime function converts a system time to a file time.
***  


## Code examples:
[Setting the date and time that a file was created](../../samples/sample_065.md)  
[A procedure for setting file times](../../samples/sample_128.md)  
[How to suspend or hibernate your system](../../samples/sample_395.md)  
[How to set Creation Date/Time for a folder (WinNT)](../../samples/sample_399.md)  

## Declaration:
```foxpro  
BOOL SystemTimeToFileTime(
  CONST SYSTEMTIME *lpSystemTime,  // system time
  LPFILETIME lpFileTime            // file time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SystemTimeToFileTime IN kernel32;
	STRING  lpSYSTEMTIME,;
	STRING  @ FILETIME  
```  
***  


## Parameters:
lpSystemTime 
[in] Pointer to a SYSTEMTIME structure that contains the time to be converted. 
The wDayOfWeek member of the SYSTEMTIME structure is ignored. 

lpFileTime 
[out] Pointer to a FILETIME structure to receive the converted system time.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  

