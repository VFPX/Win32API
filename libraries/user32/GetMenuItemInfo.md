[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMenuItemInfo
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetMenuItemInfo function retrieves information about a menu item.
***  


## Code examples:
[Reading the structure of VFP main menu](../../samples/sample_337.md)  

## Declaration:
```foxpro  
BOOL GetMenuItemInfo(
	HMENU hMenu,
	UINT uItem,
	BOOL fByPosition,
	LPMENUITEMINFO lpmii
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenuItemInfo IN user32;
	INTEGER   hMenu,;
	INTEGER   uItem,;
	INTEGER   fByPosition,;
	STRING  @ lpmii
  
```  
***  


## Parameters:
hMenu
[in] Handle to the menu that contains the menu item. 

uItem
[in] Identifier or position of the menu item to get information about. The meaning of this parameter depends on the value of fByPosition. 

fByPosition
[in] Specifies the meaning of uItem. If this parameter is FALSE, uItem is a menu item identifier. Otherwise, it is a menu item position. 

lpmii
[in, out] Pointer to a MENUITEMINFO structure that specifies the information to retrieve and receives information about the menu item.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

