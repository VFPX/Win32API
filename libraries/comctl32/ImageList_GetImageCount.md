
## Function name : ImageList_GetImageCount
Group: Windows Controls - Library: comctl32    
***  


#### Retrieves the number of images in an image list. 
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[System Image List Viewer](../../samples/sample_021.md)  
[How to view system icons for the classes installed on the local machine](../../samples/sample_544.md)  

## Declaration:
```foxpro  
int ImageList_GetImageCount(
	HIMAGELIST himl
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_GetImageCount IN comctl32;
	INTEGER himl  
```  
***  


## Parameters:
himl
A handle to the image list.  
***  


## Return value:
Returns the number of images.
  
***  


## Comments:
<div class="precode">nImageCount = ImageList_GetImageCount(THIS.imagelist32.himl)  
</div>  
See also: ImageList_Add, ImageList_Remove   
  
***  

