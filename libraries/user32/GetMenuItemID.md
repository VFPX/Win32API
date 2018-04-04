[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMenuItemID
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetMenuItemID function retrieves the menu item identifier of a menu item located at the specified position in a menu.
***  


## Code examples:
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  

## Declaration:
```foxpro  
UINT GetMenuItemID(
	HMENU hMenu,
	int nPos
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenuItemID IN user32;
	INTEGER hMenu,;
	INTEGER nPos  
```  
***  


## Parameters:
hMenu
[in] Handle to the menu that contains the item whose identifier is to be retrieved. 

nPos
[in] Specifies the zero-based relative position of the menu item whose identifier is to be retrieved.   
***  


## Return value:
The return value is the identifier of the specified menu item. If the menu item identifier is NULL or if the specified item opens a submenu, the return value is -1.   
***  

