[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetEnhMetaFile
Group: [Metafile](../../functions_group.md#Metafile)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetEnhMetaFile function creates a handle that identifies the enhanced-format metafile stored in the specified file.
***  


## Code examples:
[How to display picture stored in enhanced-format metafile (*.emf)](../../samples/sample_403.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  

## Declaration:
```foxpro  
HENHMETAFILE GetEnhMetaFile(
  LPCTSTR lpszMetaFile   // file name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetEnhMetaFile IN gdi32;
	STRING lpszMetaFile  
```  
***  


## Parameters:
lpszMetaFile 
[in] Pointer to a null-terminated string that specifies the name of an enhanced metafile.   
***  


## Return value:
If the function succeeds, the return value is a handle to the enhanced metafile.  
***  


## Comments:
When the application no longer needs an enhanced-metafile handle, it should delete the handle by calling the DeleteEnhMetaFile function.   
  
***  

