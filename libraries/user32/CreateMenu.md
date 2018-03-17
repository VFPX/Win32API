<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CreateMenu
Group: Menu - Library: user32    
***  


#### The CreateMenu function creates a menu. The menu is initially empty, but it can be filled with menu items by using the InsertMenuItem, AppendMenu, and InsertMenu functions.
***  


## Code examples:
[Attaching menu to a top-level form](../../samples/sample_208.md)  
[Shortcut Menu Class](../../samples/sample_419.md)  

## Declaration:
```foxpro  
HMENU CreateMenu(VOID);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateMenu IN user32  
```  
***  


## Parameters:
```txt  
This function has no parameters.   
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the newly created menu. If the function fails, the return value is NULL.  
***  


## Comments:
Call the DestroyMenu function to free the resource.  
  
***  

