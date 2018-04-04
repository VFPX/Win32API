[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FlashWindow
Group: [Error Handling](../../functions_group.md#Error_Handling)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Flashes the specified window one time. It does not change the active state of the window
***  


## Code examples:
[How to make the caption of a VFP application flashing in the Windows task bar](../../samples/sample_228.md)  

## Declaration:
```foxpro  
BOOL FlashWindow(
  HWND hWnd,     // handle to window
  BOOL bInvert   // flash status
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FlashWindow IN user32;
	INTEGER hWnd,;
	INTEGER bInvert  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window to be flashed. The window can be either open or minimized. 

bInvert 
[in] Specifies whether the window is to be flashed or returned to its original state.   
***  


## Return value:
The return value specifies the window"s state before the call to the FlashWindow function.   
***  

