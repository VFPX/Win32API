<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : BlockInput
Group: Keyboard Input - Library: user32    
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
```txt  
fBlockIt
[in] Specifies the function"s purpose. If this parameter is TRUE, keyboard and mouse input events are blocked. If this parameter is FALSE, keyboard and mouse events are unblocked.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Note that only the thread that blocked the input can successfully unblock it.   
  
***  

