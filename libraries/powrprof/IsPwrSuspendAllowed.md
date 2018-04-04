[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsPwrSuspendAllowed
Group: [Power Management](../../functions_group.md#Power_Management)  -  Library: [powrprof](../../Libraries.md#powrprof)  
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
This function has no parameters.  
***  


## Return value:
If the computer supports the sleep states (S1, S2, and S3), the function returns TRUE. Otherwise, the function returns FALSE (0).  
***  

