[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipGetPropertyIdList
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Gets a list of the property identifiers used in the metadata of this Image object.
***  


## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPropertyIdList(
	GpImage *image,
	UINT numOfProperty,
	PROPID* list
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPropertyIdList IN gdiplus;
	INTEGER   img,;
	INTEGER   numOfProperty,;
	STRING  @ lst  
```  
***  


## Parameters:
img
[in] Handle to Image object
 
numOfProperty
[in] Integer that specifies the number of elements in the list array. Call the GdipGetPropertyCount to determine this number. 

list
[out] Pointer to an array that receives the property identifiers.   
***  


## Return value:
Returns 0 on success.  
***  

