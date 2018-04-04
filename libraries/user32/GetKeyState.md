[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetKeyState
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetKeyState function retrieves the status of the specified virtual key. The status specifies whether the key is up, down, or toggled (on, off—alternating each time the key is pressed). 
***  


## Code examples:
[Reading the state of mouse buttons within DO WHILE loop](../../samples/sample_280.md)  

## Declaration:
```foxpro  
SHORT GetKeyState(
	int nVirtKey
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetKeyState IN user32;
	INTEGER vKey  
```  
***  


## Parameters:
nVirtKey
[in] Specifies a virtual key.

If the desired virtual key is a letter or digit (A through Z, a through z, or 0 through 9), nVirtKey must be set to the ASCII value of that character. For other keys, it must be a virtual-key code.   
***  


## Return value:
The return value specifies the status of the specified virtual key.  
***  


## Comments:
The key status returned from this function changes as a thread reads key messages from its message queue. The status does not reflect the interrupt-level state associated with the hardware. Use the GetAsyncKeyState function to retrieve that information.  
  
To retrieve state information for all the virtual keys, use the GetKeyboardState function.   
  
***  

