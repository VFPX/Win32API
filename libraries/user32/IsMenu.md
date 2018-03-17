<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IsMenu
Group: Menu - Library: user32    
***  


#### The IsMenu function determines whether a handle is a menu handle. 
***  


## Code examples:
[Programmatically removing submenus from VFP main menu](../../samples/sample_258.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[How to control Adobe Reader 9.0 (SDI mode) from VFP application](../../samples/sample_550.md)  

## Declaration:
```foxpro  
BOOL IsMenu(
	HMENU hMenu
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsMenu IN user32;
	INTEGER hMenu  
```  
***  


## Parameters:
```txt  
hMenu
[in] Handle to be tested.
  
```  
***  


## Return value:
If hMenu is a menu handle, the return value is nonzero.   
***  

