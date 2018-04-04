[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadBitmap
Group: [Bitmap](../../functions_group.md#Bitmap)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The LoadBitmap function loads the specified bitmap resource from a module"s executable file. This function has been superseded by the LoadImage function. 
***  


## Code examples:
[Drawing Windows predefined bitmaps using the LoadBitmap functions](../../samples/sample_253.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  

## Declaration:
```foxpro  
HBITMAP LoadBitmap(
  HINSTANCE hInstance,  // handle to application instance
  LPCTSTR lpBitmapName  // name of bitmap resource
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadBitmap IN user32;
	INTEGER hInstance,;
	INTEGER lpBitmapName  
```  
***  


## Parameters:
hInstance 
[in] Handle to the instance of the module whose executable file contains the bitmap to be loaded. 

lpBitmapName 
[in] Pointer to a null-terminated string that contains the name of the bitmap resource to be loaded.   
***  


## Return value:
If the function succeeds, the return value is the handle to the specified bitmap. Otherwise, the return value is NULL. 
  
***  


## Comments:
The application must call the DeleteObject function to delete each bitmap handle returned by the LoadBitmap function.   
  
LoadBitmap creates a compatible bitmap of the display, which cannot be selected to a printer. To load a bitmap that you can select to a printer, call LoadImage and specify LR_CREATEDIBSECTION to create a DIB section. A DIB section can be selected to any device.  
  
***  

