<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnregisterHotKey
Group: Keyboard Input - Library: user32    
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
```txt  
hWnd
[in] Handle to the window associated with the hot key to be freed.

id
[in] Specifies the identifier of the hot key to be freed.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also RegisterHotKey function.  
  
***  

