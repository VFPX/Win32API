[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the current system date and time. The system time is expressed in Coordinated Universal Time (UTC).
***  


## Code examples:
[System and Local Time values](../../samples/sample_064.md)  
[Setting the date and time that a file was created](../../samples/sample_065.md)  
[Winsock: sending email messages (SMTP, port 25)](../../samples/sample_385.md)  
[GDI+: custom Clock Control](../../samples/sample_597.md)  

## Declaration:
```foxpro  
VOID GetSystemTime(
  LPSYSTEMTIME lpSystemTime   // system time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE GetSystemTime IN kernel32;
	STRING @ lpSystemTime  
```  
***  


## Parameters:
lpSystemTime 
[out] Pointer to a SYSTEMTIME structure to receive the current system date and time. 
  
***  


## Return value:
This function does not return a value.  
***  


## Comments:
If time settings on your computer is different from the UTC (Coordinated Universal Time) then you can notice the difference between results of DATETIME() -- which is GetLocalTime wrapper -- and this function.  
  
***  

