[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMenu
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetMenu function retrieves a handle to the menu assigned to the specified window. 
***  


## Code examples:
[Retrieving window and menu help context identifiers](../../samples/sample_025.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Programmatically removing submenus from VFP main menu](../../samples/sample_258.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  

## Declaration:
```foxpro  
HMENU GetMenu(
	HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenu IN user32;
	INTEGER hWnd  
```  
***  


## Parameters:
hWnd
[in] Handle to the window whose menu handle is to be retrieved.   
***  


## Return value:
The return value is a handle to the menu. If the specified window has no menu, the return value is NULL. If the window is a child window, the return value is undefined.  
***  

