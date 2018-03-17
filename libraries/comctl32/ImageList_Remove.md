<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ImageList_Remove
Group: Windows Controls - Library: comctl32    
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
```txt  
himl
Handle to the image list.

i
Index of the image to remove. If this parameter is -1, the function removes all images.  
```  
***  


## Return value:
Returns nonzero if successful, or zero otherwise.  
***  


## Comments:
See also: ImageList_Add, ImageList_GetImageCount   
  
***  

