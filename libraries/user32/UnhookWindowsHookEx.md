[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UnhookWindowsHookEx
Group: [Hook](../../functions_group.md#Hook)  -  Library: [user32](../../Libraries.md#user32)  
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
hhk
[in] Handle to the hook to be removed.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
To be called from FLL or DLL rather then declared in VFP code.  
  
See also: [SetWindowsHookEx](../user32/SetWindowsHookEx.md).  
  
***  

