[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetKeyboardLayoutList
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetKeyboardLayoutList function retrieves the input locale identifiers (formerly called keyboard layout handles) corresponding to the current set of input locales in the system. 
***  


## Code examples:
[Switching between keyboard layouts](../../samples/sample_275.md)  

## Declaration:
```foxpro  
UINT GetKeyboardLayoutList(
  int nBuff,       // size of array
  HKL FAR *lpList  // array of input locale identifiers
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyboardLayoutList IN user32;
	INTEGER   nBuff,;
	STRING  @ lpList  
```  
***  


## Parameters:
nBuff 
[in] Specifies the maximum number of handles that the buffer can hold. 

lpList 
[out] Pointer to the buffer that receives the array of input locale identifiers.   
***  


## Return value:
If the function succeeds, the return value is the number of input locale identifiers copied to the buffer.  
***  

