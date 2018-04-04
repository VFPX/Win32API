[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DeleteEnhMetaFile
Group: [Metafile](../../functions_group.md#Metafile)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The DeleteEnhMetaFile function deletes an enhanced-format metafile or an enhanced-format metafile handle. 
***  


## Code examples:
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[How to display picture stored in enhanced-format metafile (*.emf)](../../samples/sample_403.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  

## Declaration:
```foxpro  
BOOL DeleteEnhMetaFile(
  HENHMETAFILE hemf   // handle to an enhanced metafile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DeleteEnhMetaFile IN gdi32;
	INTEGER hemf  
```  
***  


## Parameters:
hemf 
[in] Handle to an enhanced metafile.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If the <Strong>hemf</Strong> parameter identifies an enhanced metafile stored in memory, the DeleteEnhMetaFile function deletes the metafile.   
  
If <Strong>hemf</Strong> identifies a metafile stored on a disk, the function deletes the metafile handle but does not destroy the actual metafile. An application can retrieve the file by calling the GetEnhMetaFile function.   
  
***  

