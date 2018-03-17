<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsPwrSuspendAllowed
Group: Power Management - Library: powrprof    
***  


#### Determines whether the computer supports the sleep states.
***  


## Code examples:
[How to suspend or hibernate your system](../../samples/sample_395.md)  

## Declaration:
```foxpro  
BOOLEAN IsPwrSuspendAllowed(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsPwrSuspendAllowed IN powrprof  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
If the computer supports the sleep states (S1, S2, and S3), the function returns TRUE. Otherwise, the function returns FALSE (0).  
***  

