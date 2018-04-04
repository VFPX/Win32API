[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : TrackPopupMenuEx
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The TrackPopupMenuEx function displays a shortcut menu at the specified location and tracks the selection of items on the shortcut menu. The shortcut menu can appear anywhere on the screen.
***  


## Code examples:
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  

## Declaration:
```foxpro  
BOOL TrackPopupMenuEx(
	HMENU hmenu,
	UINT fuFlags,
	int x,
	int y,
	HWND hwnd,
	LPTPMPARAMS lptpm
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER TrackPopupMenuEx IN user32;
	LONG hmenu,;
	LONG fuFlags,;
	INTEGER x,;
	INTEGER y,;
	LONG hwnd,;
	INTEGER lptpm
  
```  
***  


## Parameters:
hmenu
[in] Handle to the shortcut menu to be displayed. This handle can be obtained by calling the CreatePopupMenu function to create a new shortcut menu or by calling the GetSubMenu function to retrieve a handle to a submenu associated with an existing menu item. 

fuFlags
[in] Specifies function options: a combination of constants

x
[in] Horizontal location of the shortcut menu, in screen coordinates. 

y
[in] Vertical location of the shortcut menu, in screen coordinates. 

hwnd
[in] Handle to the window that owns the shortcut menu. 

lptpm
[in] This parameter can be NULL.   
***  


## Return value:
If you specify TPM_RETURNCMD in the fuFlags parameter, the return value is the menu-item identifier of the item that the user selected. If the user cancels the menu without making a selection, or if an error occurs, then the return value is zero.

If you do not specify TPM_RETURNCMD in the fuFlags parameter, the return value is nonzero if the function succeeds and zero if it fails. To get extended error information, call GetLastError.
  
***  

