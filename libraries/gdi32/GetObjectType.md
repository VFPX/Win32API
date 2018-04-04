[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetObjectType
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetObjectType retrieves the type of the specified object.
***  


## Code examples:
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[The original LoadPicture() function in VFP returns valid handles to bitmaps, icons, cursors, and metafiles](../../samples/sample_296.md)  
[Reading the structure of VFP main menu](../../samples/sample_337.md)  
[Custom GDI+ class](../../samples/sample_450.md)  

## Declaration:
```foxpro  
DWORD GetObjectType(
  HGDIOBJ h   // handle to graphics object
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetObjectType IN gdi32;
	INTEGER h  
```  
***  


## Parameters:
h 
[in] Handle to the graphics object.  
***  


## Return value:
If the function fails, the return value is zero.   
***  

