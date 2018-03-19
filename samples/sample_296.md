[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# The original LoadPicture() function in VFP returns valid handles to bitmaps, icons, cursors, and metafiles

## Before you begin:
Provide valid file names when calling this function.  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetObjectType IN gdi32 INTEGER h
#DEFINE OBJ_BITMAP    7
#DEFINE OBJ_METAFILE  9

LOCAL obj

* provide valid file names

= LoadObject("badge.bmp")
= LoadObject("BACKGRND.GIF")
= LoadObject("BD04956_.WMF")
= LoadObject("FILES10.ICO")
= LoadObject("H_POINT.CUR")

PROCEDURE LoadObject (lcFilename)
	LOCAL obj
	? "Filename:", FULLPATH(lcFilename)

	IF FILE(lcFilename)
		obj = LoadPicture (lcFilename)
	ENDIF

	IF TYPE("obj") = "O"
		? "Handle:", obj.handle
		? "Handle type:", GetObjectType(obj.handle)
		? "Width:", obj.width
		? "Height:", obj.height
	ELSE
		?? " -- not accessible"
	ENDIF
	?  
```  
***  


## Listed functions:
[GetObjectType](../libraries/gdi32/GetObjectType.md)  

## Comment:
The LoadPicture() function *(note this is a VFP function, not Win32 one)* loads bitmap files as well as GIF and JPEG files, converting them into memory bitmaps. So after all you get valid bitmap handle -- no need to implement Win32-based algorithms for reading GIFs and JPEGs.  
  
***  

