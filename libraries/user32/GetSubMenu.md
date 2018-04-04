[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSubMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a handle to the drop-down menu or submenu activated by the specified menu item.
***  


## Code examples:
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  

## Declaration:
```foxpro  
HMENU GetSubMenu(
	HMENU hMenu,
	int nPos
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSubMenu IN user32;
	INTEGER hMenu,;
	INTEGER nPos  
```  
***  


## Parameters:
hMenu
[in] Handle to the menu. 

nPos
[in] Specifies the zero-based relative position in the specified menu of an item that activates a drop-down menu or submenu.   
***  


## Return value:
If the function succeeds, the return value is a handle to the drop-down menu or submenu activated by the menu item. If the menu item does not activate a drop-down menu or submenu, the return value is NULL.   
***  

