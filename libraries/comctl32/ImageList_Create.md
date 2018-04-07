[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ImageList_Create
Group: [Windows Controls](../../functions_group.md#Windows_Controls)  -  Library: [comctl32](../../Libraries.md#comctl32)  
***  


#### Creates a new image list.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  

## Declaration:
```foxpro  
HIMAGELIST ImageList_Create(
	int cx,
	int cy,
	UINT flags,
	int cInitial,
	int cGrow
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_Create IN comctl32;
	INTEGER cx,;
	INTEGER cy,;
	LONG listflags,;
	INTEGER cInitial,;
	INTEGER cGrow  
```  
***  


## Parameters:
cx
Width, in pixels, of each image. 

cy
Height, in pixels, of each image. 

flags
Set of bit flags that specify the type of image list to create.

cInitial
Number of images that the image list initially contains.

cGrow
Number of images by which the image list can grow when the system needs to make room for new images.  
***  


## Return value:
Returns the handle to the image list if successful, or NULL otherwise.  
***  


## Comments:
See also: [ImageList_Destroy](../comctl32/ImageList_Destroy.md).  
  
***  

