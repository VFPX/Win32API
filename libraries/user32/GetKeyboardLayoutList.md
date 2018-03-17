<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetKeyboardLayoutList
Group: Keyboard Input - Library: user32    
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
```txt  
nBuff
[in] Specifies the maximum number of handles that the buffer can hold.

lpList
[out] Pointer to the buffer that receives the array of input locale identifiers.  
```  
***  


## Return value:
If the function succeeds, the return value is the number of input locale identifiers copied to the buffer.  
***  

