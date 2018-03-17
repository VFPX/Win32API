<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetLocalTime
Group: Time - Library: kernel32    
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
```txt  
lpSystemTime
[out] Pointer to a SYSTEMTIME structure to receive the current local date and time.  
```  
***  


## Return value:
This function does not return a value.  
***  

