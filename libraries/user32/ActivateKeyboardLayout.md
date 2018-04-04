[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ActivateKeyboardLayout
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
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
hkl 
[in] Input locale identifier to be activated. 

Flags 
[in] Specifies how the input locale identifier is to be activated.   
***  


## Return value:
If the function succeeds, the return value is the previous input locale identifier. Otherwise, it is zero.  
***  


## Comments:
Windows 2000/XP: Activates the specified locale identifier for the entire process and sends the WM_INPUTLANGCHANGE message to the current thread`s Focus or Active window.  
  
***  

