
## Function name : ImageList_Add
Group: Windows Controls - Library: comctl32    
***  


#### Adds an image or images to an image list.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  

## Declaration:
```foxpro  
int ImageList_Add(
	HIMAGELIST himl,
	HBITMAP hbmImage,
	HBITMAP hbmMask
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_Add IN comctl32;
	INTEGER himl,;
	INTEGER hbmImage,;
	INTEGER hbmMask  
```  
***  


## Parameters:
himl
Handle to the image list. 

hbmImage
Handle to the bitmap that contains the image or images. The number of images is inferred from the width of the bitmap. 

hbmMask
Handle to the bitmap that contains the mask. If no mask is used with the image list, this parameter is ignored. 

  
***  


## Return value:
Returns the index of the first new image if successful, or -1 otherwise. 
  
***  


## Comments:
The Usage shows how the image from an icon resource can be added to an Image List specified by its HIMAGELIST handle, THIS.himl.  
  
See also: ImageList_Remove, ImageList_GetImageCount, LoadIcon, ExtractIcon, GetIconInfo, LoadImage    
  
***  

