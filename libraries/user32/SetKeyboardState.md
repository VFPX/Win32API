<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetKeyboardState
Group: Keyboard Input - Library: user32    
***  


#### The SetKeyboardState function copies a 256-byte array of keyboard key states into the calling thread"s keyboard input-state table. 
***  


## Code examples:
[Reading the state of mouse buttons within DO WHILE loop](../../samples/sample_280.md)  

## Declaration:
```foxpro  
BOOL SetKeyboardState(
	LPBYTE lpKeyState
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetKeyboardState IN user32;
	STRING @ lpKeyState  
```  
***  


## Parameters:
```txt  
lpKeyState
[in] Pointer to a 256-byte array that contains keyboard key states.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
This is the same table accessed by the GetKeyboardState and GetKeyState functions. Changes made to this table do not affect keyboard input to any other thread.   
  
Because the SetKeyboardState function alters the input state of the calling thread and not the global input state of the system, an application cannot use SetKeyboardState to set the NUM LOCK, CAPS LOCK, or SCROLL LOCK (or the Japanese KANA) indicator lights on the keyboard. These can be set or cleared using SendInput to simulate keystrokes.  
  
***  

