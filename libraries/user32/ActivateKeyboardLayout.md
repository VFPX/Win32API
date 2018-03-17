<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ActivateKeyboardLayout
Group: Keyboard Input - Library: user32    
***  


#### The ActivateKeyboardLayout function sets the input locale identifier (formerly called the keyboard layout handle) for the calling thread or the current process. The input locale identifier specifies a locale as well as the physical layout of the keyboard.
***  


## Code examples:
[Switching between keyboard layouts](../../samples/sample_275.md)  

## Declaration:
```foxpro  
HKL ActivateKeyboardLayout(
  HKL hkl,     // input locale identifier
  UINT Flags   // input locale identifier options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ActivateKeyboardLayout IN user32;
	INTEGER hkl,;
	INTEGER Flags  
```  
***  


## Parameters:
```txt  
hkl
[in] Input locale identifier to be activated.

Flags
[in] Specifies how the input locale identifier is to be activated.  
```  
***  


## Return value:
If the function succeeds, the return value is the previous input locale identifier. Otherwise, it is zero.  
***  


## Comments:
Windows 2000/XP: Activates the specified locale identifier for the entire process and sends the WM_INPUTLANGCHANGE message to the current thread`s Focus or Active window.  
  
***  

