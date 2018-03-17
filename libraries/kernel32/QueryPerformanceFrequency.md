<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : QueryPerformanceFrequency
Group: Time - Library: kernel32    
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
```txt  
lpFrequency
[out] Pointer to a variable that receives the current performance-counter frequency, in counts per second.  
```  
***  


## Return value:
If the installed hardware supports a high-resolution performance counter, the return value is nonzero.  
***  


## Comments:
Note that the frequency of the high-resolution performance counter is not the processor speed.  
See GetTickCount function.  
  
***  

