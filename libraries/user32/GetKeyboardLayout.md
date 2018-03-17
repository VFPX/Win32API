<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetKeyboardLayout
Group: Keyboard Input - Library: user32    
***  


#### The GetKeyboardLayout function retrieves the active input locale identifier (formerly called the keyboard layout) for the specified thread. If the idThread parameter is zero, the input locale identifier for the active thread is returned.
***  


## Code examples:
[Switching between keyboard layouts](../../samples/sample_275.md)  

## Declaration:
```foxpro  
HKL GetKeyboardLayout(
  DWORD idThread  // thread identifier
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyboardLayout IN user32;
	INTEGER idThread  
```  
***  


## Parameters:
```txt  
idThread
[in] Identifies the thread to query or is zero for the current thread.  
```  
***  


## Return value:
The return value is the input locale identifier for the thread. The low word contains a language identifier for the input language and the high word contains a device handle for the physical layout of the keyboard.  
***  

