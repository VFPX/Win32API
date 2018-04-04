[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateEnhMetaFile
Group: [Metafile](../../functions_group.md#Metafile)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The CreateEnhMetaFile function creates a device context for an enhanced-format metafile. This device context can be used to store a device-independent picture.
***  


## Code examples:
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  

## Declaration:
```foxpro  
HDC CreateEnhMetaFile(
  HDC hdcRef,            // handle to reference DC
  LPCTSTR lpFilename,    // file name
  CONST RECT* lpRect,    // bounding rectangle
  LPCTSTR lpDescription  // description string
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateEnhMetaFile IN gdi32;
	INTEGER  hdcRef,;
	STRING   lpFilename,;
	STRING @ lpRect,;
	STRING   lpDescription
  
```  
***  


## Parameters:
hdcRef 
[in] Handle to a reference device for the enhanced metafile. 

lpFilename 
[in] Pointer to the file name for the enhanced metafile to be created.

lpRect 
[in] Pointer to a RECT structure that specifies the dimensions (in .01-millimeter units) of the picture to be stored in the enhanced metafile. 

lpDescription 
[in] Pointer to a string that specifies the name of the application that created the picture, as well as the picture"s title.   
***  


## Return value:
If the function succeeds, the return value is a handle to the device context for the enhanced metafile.  
***  


## Comments:
MSDN: The left and top members of the RECT structure pointed to by the lpRect parameter must be less than the right and bottom members, respectively. Points along the edges of the rectangle are included in the picture.   
  
If lpRect is NULL, the graphics device interface (GDI) computes the dimensions of the smallest rectangle that surrounds the picture drawn by the application. The lpRect parameter should be provided where possible.  
  
***  

