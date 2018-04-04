[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LockWindowUpdate
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
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
hWndLock 
[in] Specifies the window in which drawing will be disabled. If this parameter is NULL, drawing in the locked window is enabled.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero, indicating that an error occurred or another window was already locked.   
***  

