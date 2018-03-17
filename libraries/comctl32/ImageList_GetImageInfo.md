<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ImageList_GetImageInfo
Group: Windows Controls - Library: comctl32    
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
```txt  
himl
A handle to the image list.
i
The index of the image.

pImageInfo
A pointer to an IMAGEINFO structure that receives information about the image.  
```  
***  


## Return value:
Returns nonzero if successful, or zero otherwise.
  
***  

