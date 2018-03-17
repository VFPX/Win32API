<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ImageList_Destroy
Group: Windows Controls - Library: comctl32    
***  


#### Destroys an image list.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  

## Declaration:
```foxpro  
BOOL ImageList_Destroy(
	HIMAGELIST himl
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImageList_Destroy IN comctl32;
	INTEGER himl  
```  
***  


## Parameters:
```txt  
himl
Handle to the image list to destroy.


  
```  
***  


## Return value:
Returns nonzero if successful, or zero otherwise. 
  
***  


## Comments:
See also: ImageList_Create   
  
***  

