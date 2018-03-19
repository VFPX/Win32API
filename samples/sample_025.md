[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving window and menu help context identifiers

## Code:
```foxpro  
DO decl

LOCAL hWindow, hMenu
hWindow = GetFocus()
hMenu = GetMenu(hWindow)

ACTI SCREEN
? "Window handle:", hWindow
? "Window Help Context ID:", GetWindowContextHelpId(hWindow)

IF hMenu <> 0
	? "Menu handle:", hMenu
	? "Menu Help Context ID:", GetMenuContextHelpId(hMenu)
ELSE
	? "No menu attached to this window"
ENDIF

PROCEDURE decl
	DECLARE INTEGER GetWindowContextHelpId IN user32 INTEGER hWnd
	DECLARE INTEGER GetMenuContextHelpId IN user32 INTEGER hmenu
	DECLARE INTEGER GetFocus IN user32
	DECLARE INTEGER GetMenu IN user32 INTEGER hWnd  
```  
***  


## Listed functions:
[GetFocus](../libraries/user32/GetFocus.md)  
[GetMenu](../libraries/user32/GetMenu.md)  
[GetMenuContextHelpId](../libraries/user32/GetMenuContextHelpId.md)  
[GetWindowContextHelpId](../libraries/user32/GetWindowContextHelpId.md)  
