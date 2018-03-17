<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMenuBarInfo
Group: Menu - Library: user32    
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
```txt  
hwnd
[in] Handle to the window (menu bar) whose information is to be retrieved.

idObject
[in] Specifies the menu object. This parameter can be one of the following values: OBJID_CLIENT, OBJID_MENU, OBJID_SYSMENU.

idItem
[in] Specifies the item for which to retrieve information.

pmbi
[out] Pointer to a MENUBARINFO structure that receives the information.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Note that you must set MENUBARINFO.cbSize to sizeof(MENUBARINFO) before calling this function.   
  
See also: GetMenuItemInfo, GetSystemMenu.  
  
***  

