[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetAsyncKeyState
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetAsyncKeyState function determines whether a key is up or down at the time the function is called, and whether the key was pressed after a previous call to GetAsyncKeyState. 
***  


## Code examples:
[Reading the state of mouse buttons within DO WHILE loop](../../samples/sample_280.md)  
[GDI+: Implementing image scrolling with inertia](../../samples/sample_595.md)  

## Declaration:
```foxpro  
SHORT GetAsyncKeyState(
  int vKey   // virtual-key code
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetAsyncKeyState IN user32;
	INTEGER vKey  
```  
***  


## Parameters:
vKey 
[in] Specifies one of 256 possible virtual-key codes. 
 
  
***  


## Return value:
If the function succeeds, the return value specifies whether the key was pressed since the last call to GetAsyncKeyState, and whether the key is currently up or down.  
***  


## Comments:
Check list of [Virtual-Key Codes](https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx) on the MSDN.   
  
***  

