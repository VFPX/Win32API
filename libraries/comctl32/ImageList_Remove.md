[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ImageList_Remove
Group: [Windows Controls](../../functions_group.md#Windows_Controls)  -  Library: [comctl32](../../Libraries.md#comctl32)  
***  


#### Removes an image from an image list.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  

## Declaration:
```foxpro  
BOOL ImageList_Remove(
	HIMAGELIST himl,
	int i
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_Remove IN comctl32;
	INTEGER himl,;
	INTEGER imageindex  
```  
***  


## Parameters:
himl
Handle to the image list. 

i
Index of the image to remove. If this parameter is -1, the function removes all images.   
***  


## Return value:
Returns nonzero if successful, or zero otherwise.  
***  


## Comments:
See also: [ImageList_Add](../comctl32/ImageList_Add.md), [ImageList_GetImageCount](../comctl32/ImageList_GetImageCount.md).  
  
***  

