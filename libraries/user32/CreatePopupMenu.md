[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreatePopupMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The CreatePopupMenu function creates a drop-down menu, submenu, or shortcut menu.

The menu is initially empty. You can insert or append menu items by using the InsertMenuItem function. You can also use the InsertMenu function to insert menu items and the AppendMenu function to append menu items.
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  

## Declaration:
```foxpro  
HMENU CreatePopupMenu(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreatePopupMenu IN user32  
```  
***  


## Parameters:
This function has no parameters.   
***  


## Return value:
If the function succeeds, the return value is a handle to the newly created menu. If the function fails, the return value is NULL.  
***  


## Comments:
Call the DestroyMenu function to free the resource.  
  
***  

