[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ImageList_GetIconSize
Group: [Windows Controls](../../functions_group.md#Windows_Controls)  -  Library: [comctl32](../../Libraries.md#comctl32)  
***  


#### Retrieves the dimensions of images in an image list. All images in an image list have the same dimensions.
***  


## Code examples:
[System Image List Viewer](../../samples/sample_021.md)  

## Declaration:
```foxpro  
BOOL ImageList_GetIconSize(
	HIMAGELIST himl,
	int *cx,
	int *cy
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_GetIconSize IN comctl32;
	INTEGER himl,;
	INTEGER @cx,;
	INTEGER @cy  
```  
***  


## Parameters:
himl
A handle to the image list. 

cx
A pointer to an integer variable that receives the width, in pixels, of each image. 

cy
A pointer to an integer variable that receives the height, in pixels, of each image.  
***  


## Return value:
Returns nonzero if successful, or zero otherwise.
  
***  


## Comments:
See also: [ImageList_GetImageInfo](../comctl32/ImageList_GetImageInfo.md).  
  
***  

