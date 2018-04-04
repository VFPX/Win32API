[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PlayEnhMetaFile
Group: [Metafile](../../functions_group.md#Metafile)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The PlayEnhMetaFile function displays the picture stored in the specified enhanced-format metafile.
***  


## Code examples:
[How to display picture stored in enhanced-format metafile (*.emf)](../../samples/sample_403.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  

## Declaration:
```foxpro  
BOOL PlayEnhMetaFile(
  HDC hdc,            // handle to DC
  HENHMETAFILE hemf,  // handle to an enhanced metafile
  CONST RECT *lpRect  // bounding rectangle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PlayEnhMetaFile IN gdi32;
	INTEGER   hdc,;
	INTEGER   hemf,;
	STRING  @ lpRect
  
```  
***  


## Parameters:
hdc 
[in] Handle to the device context for the output device on which the picture will appear. 

hemf 
[in] Handle to the enhanced metafile. 

lpRect 
[in] Pointer to a RECT structure that contains the coordinates of the bounding rectangle used to display the picture. The coordinates are specified in logical units.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
When an application calls the PlayEnhMetaFile function, the system uses the picture frame in the enhanced-metafile header to map the picture onto the rectangle pointed to by the lpRect parameter.   
  
This picture may be sheared or rotated by setting the world transform in the output device before calling PlayEnhMetaFile. Points along the edges of the rectangle are included in the picture.   
  
An enhanced metafile can be embedded in a newly created enhanced metafile by calling PlayEnhMetaFile and playing the source enhanced metafile into the device context for the new enhanced metafile.   
  
***  

