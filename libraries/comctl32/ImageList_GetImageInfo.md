[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ImageList_GetImageInfo
Group: [Windows Controls](../../functions_group.md#Windows_Controls)  -  Library: [comctl32](../../Libraries.md#comctl32)  
***  


#### Retrieves information about an image in the image list. 
***  


## Code examples:
[System Image List Viewer](../../samples/sample_021.md)  

## Declaration:
```foxpro  
BOOL ImageList_GetImageInfo(
	HIMAGELIST himl,
	int i,
	IMAGEINFO *pImageInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_GetImageInfo IN comctl32;
	INTEGER himl,;
	INTEGER i,;
	STRING @pImageInfo  
```  
***  


## Parameters:
himl
A handle to the image list. 
i
The index of the image. 

pImageInfo
A pointer to an IMAGEINFO structure that receives information about the image.  
***  


## Return value:
Returns nonzero if successful, or zero otherwise.
  
***  

