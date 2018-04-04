[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetMenuItemCount
Group: [Menu](../../functions_group.md#Menu)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetMenuItemCount function determines the number of items in the specified menu. 
***  


## Code examples:
[Programmatically removing submenus from VFP main menu](../../samples/sample_258.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  

## Declaration:
```foxpro  
int GetMenuItemCount(
	HMENU hMenu
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenuItemCount IN user32;
	INTEGER hMenu
  
```  
***  


## Parameters:
hMenu
[in] Handle to the menu to be examined.   
***  


## Return value:
If the function succeeds, the return value specifies the number of items in the menu.  
***  

