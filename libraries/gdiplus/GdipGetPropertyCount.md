<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipGetPropertyCount
Group: GDI+ Image - Library: gdiplus    
***  


#### Gets the number of properties (pieces of metadata) stored in this Image object. 
***  


## Code examples:
[GDI+: reading and writing metadata in JPEG and TIFF files](../../samples/sample_461.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipGetPropertyCount(
	GpImage *image,
	UINT* numOfProperty
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipGetPropertyCount IN gdiplus;
	INTEGER   img,;
	INTEGER @ numOfProperty
  
```  
***  


## Parameters:
```txt  
img
[in] Handle to Image object

numofproperty
[out] Number of properties stored in this Image object  
```  
***  


## Return value:
Returns 0 on success.  
***  

