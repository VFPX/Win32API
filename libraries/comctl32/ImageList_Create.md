<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ImageList_Create
Group: Windows Controls - Library: comctl32    
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
```txt  
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
```  
***  


## Return value:
Returns the handle to the image list if successful, or NULL otherwise.  
***  


## Comments:
See also: ImageList_Destroy   
  
***  

