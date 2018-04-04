[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DestroyMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DestroyMenu function destroys the specified menu and frees any memory that the menu occupies.
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  

## Declaration:
```foxpro  
BOOL DestroyMenu(
  HMENU hMenu  // handle to menu
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DestroyMenu IN user32;
	INTEGER hMenu  
```  
***  


## Parameters:
hMenu 
[in] Handle to the menu to be destroyed.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
DestroyMenu is recursive, that is, it will destroy the menu and all its submenus.  
  
***  

