[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsWindowEnabled
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The IsWindowEnabled function determines whether the specified window is enabled for mouse and keyboard input. 
***  


## Code examples:
[Using the IsWindowEnabled function](../../samples/sample_306.md)  

## Declaration:
```foxpro  
BOOL IsWindowEnabled(
  HWND hWnd   // handle to window
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsWindowEnabled IN user32;
	INTEGER hwnd  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window to test.   
***  


## Return value:
If the window is enabled, the return value is nonzero.  
***  

