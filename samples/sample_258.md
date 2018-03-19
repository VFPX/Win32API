[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Programmatically removing submenus from VFP main menu

## Before you begin:
The following code removes all but the last submenus from VFP main menu.  

To restore the system menu type SET SYSMENU TO DEFAULT  

  
***  


## Code:
```foxpro  
#DEFINE MF_BYPOSITION 0x00000400
DO declare

LOCAL hWindow, hMainMenu

hWindow = _vfp.hWnd

* retrieves a handle to the menu
* assigned to the specified window
hMainMenu = GetMenu( m.hWindow )

IF IsMenu(hMainMenu) = 0
	RETURN
ENDIF

LOCAL nItemCount, nItemIndex

* determines the number of items in the specified menu
nItemCount = GetMenuItemCount(hMainMenu)

* deletes all menu items but the last one
FOR nItemIndex=1 TO nItemCount-1

	* deletes 1st menu item
	DeleteMenu( hMainMenu, 0, MF_BYPOSITION )
	
	* application must call the DrawMenuBar
	* whenever a menu changes
	DrawMenuBar( m.hWindow )
NEXT
* end of main

PROCEDURE declare
	DECLARE INTEGER GetMenu IN user32 INTEGER hWindow
	DECLARE INTEGER IsMenu IN user32 INTEGER hMenu
	DECLARE INTEGER GetMenuItemCount IN user32 INTEGER hMenu
	DECLARE INTEGER DrawMenuBar IN user32 INTEGER hWindow

	DECLARE INTEGER DeleteMenu IN user32;
		INTEGER hMenu, INTEGER uPosition,;
		INTEGER uFlags  
```  
***  


## Listed functions:
[DeleteMenu](../libraries/user32/DeleteMenu.md)  
[DrawMenuBar](../libraries/user32/DrawMenuBar.md)  
[GetMenu](../libraries/user32/GetMenu.md)  
[GetMenuItemCount](../libraries/user32/GetMenuItemCount.md)  
[IsMenu](../libraries/user32/IsMenu.md)  
