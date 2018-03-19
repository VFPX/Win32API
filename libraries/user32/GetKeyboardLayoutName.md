
## Function name : GetKeyboardLayoutName
Group: Keyboard Input - Library: user32    
***  


#### The GetKeyboardLayoutName function retrieves the name of the active input locale identifier (formerly called the keyboard layout). 
***  


## Code examples:
[Switching between keyboard layouts](../../samples/sample_275.md)  

## Declaration:
```foxpro  
BOOL GetKeyboardLayoutName(
  LPTSTR pwszKLID   // input locale identifier name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyboardLayoutName IN user32;
	STRING @pwszKLID  
```  
***  


## Parameters:
pwszKLID 
[out] Pointer to the buffer (of at least KL_NAMELENGTH characters in length) that receives the name of the input locale identifier  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

