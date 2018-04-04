[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CopyImage
Group: [Resource](../../functions_group.md#Resource)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Creates a new image (icon, cursor, or bitmap) and copies the attributes of the specified image to the new one. If necessary, the function stretches the bits to fit the desired size of the new image.
***  


## Declaration:
```foxpro  
HANDLE CopyImage(
	HANDLE hImage,
	UINT uType,
	int cxDesired,
	int cyDesired,
	UINT fuFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CopyImage IN user32;
	INTEGER hImage,;
	INTEGER uType,;
	INTEGER cxDesired,;
	INTEGER cyDesired,;
	INTEGER fuFlags;
  
```  
***  


## Parameters:
hImage
[in] Handle to the image to be copied. 

uType
[in] Specifies the type of image to be copied. 

cxDesired
[in] Specifies the desired width, in pixels, of the image. 

cyDesired
[in] Specifies the desired height, in pixels, of the image.

fuFlags
[in] This parameter can be one or more of the predefined values.   
***  


## Return value:
If the function succeeds, the return value is the handle to the newly created image.  
***  


## Comments:
When you are finished using the resource, you can release its associated memory by calling one of the functions: DeleteObject, DestroyCursor, DestroyIcon -- depending on the type of the object.  
  
***  

