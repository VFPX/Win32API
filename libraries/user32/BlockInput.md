[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : BlockInput
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Blocks keyboard and mouse input events from reaching applications.
***  


## Code examples:
[Disabling mouse and keyboard input for the main VFP window (with the app still running)](../../samples/sample_083.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  

## Declaration:
```foxpro  
BOOL BlockInput(
  BOOL fBlockIt  // block option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER BlockInput IN user32 INTEGER fBlockIt  
```  
***  


## Parameters:
fBlockIt 
[in] Specifies the function"s purpose. If this parameter is TRUE, keyboard and mouse input events are blocked. If this parameter is FALSE, keyboard and mouse events are unblocked.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Note that only the thread that blocked the input can successfully unblock it.   
  
***  

