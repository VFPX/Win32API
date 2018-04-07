[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMenuBarInfo
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves information about the specified menu bar.
***  


## Declaration:
```foxpro  
BOOL GetMenuBarInfo(
	HWND hwnd,
	LONG idObject,
	LONG idItem,
	PMENUBARINFO pmbi
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenuBarInfo IN user32;
	INTEGER hWindow,;
	LONG idObject,;
	LONG idItem,;
	INTEGER pmbi  
```  
***  


## Parameters:
hwnd
[in] Handle to the window (menu bar) whose information is to be retrieved. 

idObject
[in] Specifies the menu object. This parameter can be one of the following values: OBJID_CLIENT, OBJID_MENU, OBJID_SYSMENU.

idItem
[in] Specifies the item for which to retrieve information.

pmbi
[out] Pointer to a MENUBARINFO structure that receives the information.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Note that you must set MENUBARINFO.cbSize to sizeof(MENUBARINFO) before calling this function.   
  
See also: [GetMenuItemInfo](../user32/GetMenuItemInfo.md), [GetSystemMenu](../user32/GetSystemMenu.md).  
  
***  

