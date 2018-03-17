<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LockWindowUpdate
Group: Painting and Drawing - Library: user32    
***  


#### The LockWindowUpdate function disables or enables drawing in the specified window. Only one window can be locked at a time.
***  


## Code examples:
[Disabling drawing in the VFP form](../../samples/sample_257.md)  
[How to position the GETPRINTER() dialog](../../samples/sample_482.md)  

## Declaration:
```foxpro  
BOOL LockWindowUpdate(
  HWND hWndLock   // handle to window
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LockWindowUpdate IN user32;
	INTEGER hWndLock  
```  
***  


## Parameters:
```txt  
hWndLock
[in] Specifies the window in which drawing will be disabled. If this parameter is NULL, drawing in the locked window is enabled.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero, indicating that an error occurred or another window was already locked.   
***  

