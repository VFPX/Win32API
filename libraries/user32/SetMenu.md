[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SetMenu function assigns a new menu to the specified window.
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  

## Declaration:
```foxpro  
BOOL SetMenu(
  HWND hWnd,  // handle to window
  HMENU hMenu // handle to menu
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetMenu IN user32;
	INTEGER hWnd,;
	INTEGER hMenu  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window to which the menu is to be assigned. 

hMenu 
[in] Handle to the new menu. If this parameter is NULL, the window"s current menu is removed.  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
A menu can be assigned to any window that is not a child window. For the VFP forms it means that only those with ShowWindow property equal to 2 (top-level windows) can accept the menu.  
  
The SetMenu function replaces the previous menu, if any, but it does not destroy it. An application should call the DestroyMenu function to accomplish this task.   
  
***  

