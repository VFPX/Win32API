[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CloseEnhMetaFile
Group: [Metafile](../../functions_group.md#Metafile)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The CloseEnhMetaFile function closes an enhanced-metafile device context and returns a handle that identifies an enhanced-format metafile.
***  


## Code examples:
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  

## Declaration:
```foxpro  
HENHMETAFILE CloseEnhMetaFile(
  HDC hdc   // handle to enhanced-metafile DC
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CloseEnhMetaFile IN gdi32;
	INTEGER hdc
  
```  
***  


## Parameters:
hdc 
[in] Handle to an enhanced-metafile device context.   
***  


## Return value:
If the function succeeds, the return value is a handle to an enhanced metafile.  
***  


## Comments:
When the application no longer needs the enhanced metafile handle, it should release the handle by calling the DeleteEnhMetaFile function.   
  
***  

