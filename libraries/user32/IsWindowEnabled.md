
## Function name : IsWindowEnabled
Group: Keyboard Input - Library: user32    
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

