[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UnregisterHotKey
Group: [Keyboard Input](../../functions_group.md#Keyboard_Input)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The UnregisterHotKey function frees a hot key previously registered by the calling thread. 
***  


## Code examples:
[How to block the ALT+TAB shortcut (WinXP)](../../samples/sample_432.md)  
[How to block the PrintScreen key](../../samples/sample_489.md)  

## Declaration:
```foxpro  
BOOL UnregisterHotKey(
	HWND hWnd,
	int id
);  
```  
***  

## FoxPro declaration:
```foxpro  
DECLARE INTEGER UnregisterHotKey IN user32;
	INTEGER hWnd,;
	INTEGER id
  
```  
***  


## Parameters:

hWnd
[in] Handle to the window associated with the hot key to be freed.

id
[in] Specifies the identifier of the hot key to be freed.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [RegisterHotKey](RegisterHotKey.md) function.  
  
***  

