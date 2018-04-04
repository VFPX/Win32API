[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DestroyIcon
Group: [Icon](../../functions_group.md#Icon)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Destroys an icon and frees any memory the icon occupied.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[System Image List Viewer](../../samples/sample_021.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Retrieving information about the specified icon](../../samples/sample_206.md)  
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[GDI+: Storing DLL icon resources in image files](../../samples/sample_501.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  
[GDI+: custom Clock Control](../../samples/sample_597.md)  

## Declaration:
```foxpro  
BOOL DestroyIcon(
  HICON hIcon   // handle to icon
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT DestroyIcon IN user32 INTEGER hIcon  
```  
***  


## Parameters:
hIcon 
[in] Handle to the icon to be destroyed. The icon must not be in use.  
***  


## Return value:
If the function fails, the return value is zero.  
***  


## Comments:
It is only necessary to call DestroyIcon for icons and cursors created with the CreateIconIndirect and the CopyIcon functions.   
  
Do not use this function to destroy a shared icon. A shared icon is valid as long as the module from which it was loaded remains in memory. The following functions obtain a shared icon:   
	- LoadIcon   
	- LoadImage (if you use the LR_SHARED flag)   
	- CopyImage (if you use the LR_COPYRETURNORG flag and the hImage parameter is a shared icon)  
  
***  

