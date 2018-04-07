[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetVersionEx
Group: [System Information](../../functions_group.md#System_Information)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetVersionEx function obtains extended information about the version of the operating system that is currently running
***  


## Code examples:
[Extended OS Version info](../../samples/sample_023.md)  
[How to Start a Process as Another User (NT/XP/2K)](../../samples/sample_426.md)  

## Declaration:
```foxpro  
BOOL GetVersionEx(
    LPOSVERSIONINFO  lpVersionInformation 	
	// points to version information structure
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetVersionEx IN kernel32;
	STRING @ lpVersionInformation
  
```  
***  


## Parameters:
lpVersionInformation
Points to an OSVERSIONINFO data structure that the function fills with operating system version information  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
See also: [GetVersion](../kernel32/GetVersion.md), [GetProductInfo](../kernel32/GetProductInfo.md).  
  
***  

