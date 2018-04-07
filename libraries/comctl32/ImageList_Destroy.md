[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ImageList_Destroy
Group: [Windows Controls](../../functions_group.md#Windows_Controls)  -  Library: [comctl32](../../Libraries.md#comctl32)  
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
himl
Handle to the image list to destroy. 


  
***  


## Return value:
Returns nonzero if successful, or zero otherwise. 
  
***  


## Comments:
See also: [ImageList_Create](../comctl32/ImageList_Create.md).  
  
***  

