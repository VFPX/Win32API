<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetVersionEx
Group: System Information - Library: kernel32    
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
```txt  
lpVersionInformation
Points to an OSVERSIONINFO data structure that the function fills with operating system version information  
```  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
See also: GetVersion, GetProductInfo   
  
***  

