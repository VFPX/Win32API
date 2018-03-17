<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetKeyboardState
Group: Keyboard Input - Library: user32    
***  


#### The GetKeyboardState function copies the status of the 256 virtual keys to the specified buffer.
***  


## Code examples:
[Reading virtual key status values and key names](../../samples/sample_305.md)  
[Capturing keyboard activity of another application with the Raw Input API (VFP9)](../../samples/sample_572.md)  

## Declaration:
```foxpro  
BOOL GetKeyboardState(
  PBYTE lpKeyState   // array of status data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyboardState IN user32;
	STRING @lpKeyState  
```  
***  


## Parameters:
```txt  
lpKeyState
[in] Pointer to the 256-byte array that will receive the status data for each virtual key.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

