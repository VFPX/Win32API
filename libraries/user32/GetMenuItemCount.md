<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMenuItemCount
Group: Menu - Library: user32    
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
```txt  
hMenu
[in] Handle to the menu to be examined.  
```  
***  


## Return value:
If the function succeeds, the return value specifies the number of items in the menu.  
***  

