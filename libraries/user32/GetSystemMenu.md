[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSystemMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetSystemMenu function allows the application to access the window menu (also known as the system menu or the control menu) for copying and modifying. 
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  

## Declaration:
```foxpro  
HMENU GetSystemMenu(
  HWND hWnd,    // handle to window
  BOOL bRevert  // reset option
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSystemMenu IN user32;
	INTEGER hWnd,;
	INTEGER bRevert  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window that will own a copy of the window menu. 

bRevert 
[in] Specifies the action to be taken. The FALSE means that GetSystemMenu returns a handle to the copy of the window menu currently in use.   
***  


## Return value:
If the bRevert parameter is FALSE, the return value is a handle to a copy of the window menu. If the bRevert parameter is TRUE, the return value is NULL.   
***  

