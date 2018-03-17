<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetPropertyIdList
Group: GDI+ Image - Library: gdiplus    
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
```txt  
img
[in] Handle to Image object

numOfProperty
[in] Integer that specifies the number of elements in the list array. Call the GdipGetPropertyCount to determine this number.

list
[out] Pointer to an array that receives the property identifiers.  
```  
***  


## Return value:
Returns 0 on success.  
***  

