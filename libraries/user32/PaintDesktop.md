[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PaintDesktop
Group: [Painting and Drawing](../../functions_group.md#Painting_and_Drawing)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Fills the clipping region in the specified device context with the desktop pattern or wallpaper.
***  


## Declaration:
```foxpro  
BOOL PaintDesktop(
	HDC hdc  // handle to DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PaintDesktop IN user32;
	INTEGER hdc  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
You may call this function from within the Paint event of a form and see what happens to form`s native controls, which controls are windowless by definition.  
  
***  

