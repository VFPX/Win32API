<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetObjectType
Group: Device Context - Library: gdi32    
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
```txt  
h
[in] Handle to the graphics object.  
```  
***  


## Return value:
If the function fails, the return value is zero.   
***  

