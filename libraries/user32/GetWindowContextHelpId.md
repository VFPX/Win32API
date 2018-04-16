[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowContextHelpId
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetWindowContextHelpId function retrieves the help context identifier, if any, associated with the specified window.

Windows NT only
***  


## Code examples:
[Retrieving window and menu help context identifiers](../../samples/sample_025.md)  

## Declaration:
```foxpro  
DWORD GetWindowContextHelpId(
    HWND  hWnd	
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowContextHelpId IN user32;
	INTEGER hWnd
  
```  
***  


## Parameters:
hWnd
Handle to the window for which the help context identifier is to be retrieved  
***  


## Return value:
Returns the help context identifier if the window has one or zero otherwise  
***  


## Comments:
See also [SetWindowContextHelpId](SetWindowContextHelpId.md) and [GetMenuContextHelpId](GetMenuContextHelpId.md) functions.  
  
***  

