
## Function name : DrawMenuBar
Group: Menu - Library: user32    
***  


#### Redraws the menu bar of the specified window. If the menu bar changes after the system has created the window, this function must be called to draw the changed menu bar.
***  


## Code examples:
[Programmatically removing submenus from VFP main menu](../../samples/sample_258.md)  

## Declaration:
```foxpro  
BOOL WINAPI DrawMenuBar(
	__in  HWND hWnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawMenuBar IN user32;
	INTEGER hWindow  
```  
***  


## Parameters:
hWnd [in]
HWND
A handle to the window whose menu bar is to be redrawn.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: DeleteMenu, RemoveMenu   
  
***  

