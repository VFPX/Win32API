[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InsertMenuItem
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The InsertMenuItem function inserts a new menu item at the specified position in a menu.
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  

## Declaration:
```foxpro  
BOOL InsertMenuItem(
  HMENU hMenu,           // handle to menu
  UINT uItem,            // identifier or position
  BOOL fByPosition,      // meaning of uItem
  LPCMENUITEMINFO lpmii  // menu item information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InsertMenuItem IN user32;
	INTEGER   hMenu,;
	INTEGER   uItem,;
	INTEGER   fByPosition,;
	STRING  @ lpmii
  
```  
***  


## Parameters:
hMenu 
[in] Handle to the menu in which the new menu item is inserted. 

uItem 
[in] Identifier or position of the menu item before which to insert the new item. The meaning of this parameter depends on the value of fByPosition. 

fByPosition 
[in] Value specifying the meaning of uItem. If this parameter is FALSE, uItem is a menu item identifier. Otherwise, it is a menu item position. 

lpmii 
[in] Pointer to a MENUITEMINFO structure that contains information about the new menu item.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  

