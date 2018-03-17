<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GdipSetPropertyItem
Group: GDI+ Image - Library: gdiplus    
***  


#### Sets a property item (piece of metadata) for this Image object.
***  


## Code examples:
[GDI+: reading and writing metadata in JPEG and TIFF files](../../samples/sample_461.md)  

## Declaration:
```foxpro  
GpStatus WINGDIPAPI GdipSetPropertyItem(
	GpImage *image,
	GDIPCONST PropertyItem* item
)
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GdipSetPropertyItem IN gdiplus;
	INTEGER  img,;
	STRING @ itm
  
```  
***  


## Parameters:
```txt  
img
[in] Handle to Image Object

item
[in] Pointer to a PropertyItem object that specifies the property item to be set.  
```  
***  


## Return value:
Returns GpStatus value, 0 means success.  
***  


## Comments:
If the item already exists, then its contents are updated; otherwise, a new item is added. Certain image formats (for example, ICON and EMF) do not support properties.  
<code>  
struct PropertyItem {   
&nbsp;&nbsp;LONG id;       //type of metadata  
&nbsp;&nbsp;ULONG length;  // size in bytes of the value array  
&nbsp;&nbsp;WORD type;     // data type  
&nbsp;&nbsp;LPVOID value;  // pointer to array of values  
};</code>  
  
***  

