<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : AppendMenu
Group: Menu - Library: user32    
***  


#### The AppendMenu function appends a new item to the end of the specified menu bar, drop-down menu, submenu, or shortcut menu.
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  

## Declaration:
```foxpro  
BOOL AppendMenu(
  HMENU hMenu,         // handle to menu
  UINT uFlags,         // menu-item options
  UINT_PTR uIDNewItem, // identifier, menu, or submenu
  LPCTSTR lpNewItem    // menu-item content
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AppendMenu IN user32;
	INTEGER   hMenu,;
	INTEGER   uFlags,;
	INTEGER   uIDNewItem,;
	STRING  @ lpNewItem  
```  
***  


## Parameters:
```txt  
hMenu
[in] Handle to the menu bar, drop-down menu, submenu, or shortcut menu to be changed.
uFlags
[in] Specifies flags to control the appearance and behavior of the new menu item.

uIDNewItem
[in] Specifies either the identifier of the new menu item or, if the uFlags parameter is set to MF_POPUP, a handle to the drop-down menu or submenu.

lpNewItem
[in] Specifies the content of the new menu item.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.   
***  


## Comments:
MSDN: the AppendMenu function has been superseded by the InsertMenuItem function. You can still use AppendMenu, however, if you do not need any of the extended features of InsertMenuItem.  
  
***  

