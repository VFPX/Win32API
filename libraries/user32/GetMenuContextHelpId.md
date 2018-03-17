<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetMenuContextHelpId
Group: Shell Functions - Library: user32    
***  


#### Retrieves the Help context identifier associated with the specified menu.
***  


## Code examples:
[Retrieving window and menu help context identifiers](../../samples/sample_025.md)  

## Declaration:
```foxpro  
DWORD GetMenuContextHelpId(
	HMENU hmenu
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetMenuContextHelpId IN user32;
	INTEGER hmenu  
```  
***  


## Parameters:
```txt  
hmenu
Handle to the menu for which the Help context identifier is to be retrieved.  
```  
***  


## Return value:
Returns the Help context identifier if the menu has one, or zero otherwise.  
***  


## Comments:
See also SetMenuContextHelpId and GetWindowContextHelpId functions.  
  
***  

