[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadImage
Group: [Resource](../../functions_group.md#Resource)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The LoadImage function loads an icon, cursor, animated cursor, or bitmap.
***  


## Code examples:
[Using the LoadImage function to have a bitmap file loaded and displayed on VFP main window](../../samples/sample_210.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Displaying bitmap using the AlphaBlend function](../../samples/sample_293.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[Displaying animated images on FoxPro form with BitBlt and StretchBlt functions](../../samples/sample_355.md)  
[How to convert a bitmap file to monochrome format (1 bpp)](../../samples/sample_493.md)  

## Declaration:
```foxpro  
HANDLE LoadImage(
  HINSTANCE hinst,   // handle to instance
  LPCTSTR lpszName,  // image to load
  UINT uType,        // image type
  int cxDesired,     // desired width
  int cyDesired,     // desired height
  UINT fuLoad        // load options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadImage IN user32;
	INTEGER hinst,;
	STRING  lpszName,;
	INTEGER uType,;
	INTEGER cxDesired,;
	INTEGER cyDesired,;
	INTEGER fuLoad  
```  
***  


## Parameters:
hinst 
[in] Handle to an instance of the module that contains the image to be loaded. To load an OEM image, set this parameter to zero. 

lpszName 
[in] Specifies the image to load. 

uType 
[in] Specifies the type of image to be loaded. 

cxDesired 
[in] Specifies the width, in pixels, of the icon or cursor. 

cyDesired 
[in] Specifies the height, in pixels, of the icon or cursor. 

fuLoad 
[in] This parameter can be one or more of the predefined values.   
***  


## Return value:
If the function succeeds, the return value is the handle of the newly loaded image. If the function fails, the return value is NULL.  
***  

