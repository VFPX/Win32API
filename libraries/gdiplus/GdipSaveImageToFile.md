[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GdipSaveImageToFile
Group: [GDI+ Image](../../functions_group.md#GDIplus_Image)  -  Library: [gdiplus](../../Libraries.md#gdiplus)  
***  


#### Saves this image to a file.
***  


## Code examples:
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSaveImageToFile(
	GpImage *image,
	GDIPCONST WCHAR* filename,
	GDIPCONST CLSID* clsidEncoder,
	GDIPCONST EncoderParameters* encoderParams
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSaveImageToFile IN gdiplus;
	INTEGER img,;
	STRING  filename,;
	STRING  clsidEncoder,;
	INTEGER encoderParams
  
```  
***  


## Parameters:
img
[in] Handle to Image Object

filename
[in] Pointer to a null-terminated string that specifies the path name for the saved image. 

clsidEncoder
[in] Pointer to a CLSID that specifies the encoder to use to save the image. 

encoderParams
[in] Optional. Pointer to an EncoderParameters object that holds parameters used by the encoder. The default value is NULL.   
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
The technique of constructing a Graphics object based on an image works only for certain image formats. For example, you cannot construct a Graphics object based on an image that has a color depth of 4 bits per pixel.  
  
GDI+ does not allow you to save an image to the same file that you used to construct the image.   
  
***  

