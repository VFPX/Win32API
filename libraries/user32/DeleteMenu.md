[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Deletes an item from the specified menu. If the menu item opens a menu or submenu, this function destroys the handle to the menu or submenu and frees the memory used by the menu or submenu.
***  


## Code examples:
[Programmatically removing submenus from VFP main menu](../../samples/sample_258.md)  

## Declaration:
```foxpro  
BOOL WINAPI DeleteMenu(
	__in  HMENU hMenu,
	__in  UINT uPosition,
	__in  UINT uFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteMenu IN user32;
	INTEGER hMenu,;
	INTEGER uPosition,;
	INTEGER uFlags

  
```  
***  


## Parameters:
hMenu [in]
HMENU
A handle to the menu to be changed.

uPosition [in]
UINT
The menu item to be deleted, as determined by the uFlags parameter.

uFlags [in]
UINT
Indicates how the uPosition parameter is interpreted: MF_BYCOMMAND (0), MF_BYPOSITION (0x0400)  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [RemoveMenu](..//RemoveMenu.md), [DestroyMenu](../user32/DestroyMenu.md), [GetMenu](../user32/GetMenu.md).  
  
If you are not into Windows API yet, get yourself a cup of coffee or a drink and start musing about possible functional differences of three Menu API functions with somewhat close names:  
  
* RemoveMenu  
* DeleteMenu  
* DestroyMenu  
  
  
***  

