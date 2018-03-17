<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnhookWindowsHookEx
Group: Hook - Library: user32    
***  


#### Removes a hook procedure installed in a hook chain by the SetWindowsHookEx function. 
***  


## Declaration:
```foxpro  
BOOL UnhookWindowsHookEx(
	HHOOK hhk
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UnhookWindowsHookEx IN user32;
	INTEGER hhk  
```  
***  


## Parameters:
```txt  
hhk
[in] Handle to the hook to be removed.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
To be called from FLL or DLL rather then declared in VFP code.  
  
See also: SetWindowsHookEx   
  
***  

