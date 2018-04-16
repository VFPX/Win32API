[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# GDI+: Storing DLL icon resources in image files

## Before you begin:
The code is based on [custom GDI+ class](sample_450.md). Download the class module first and save it in **gdiplus.prg** file.   

It shows how to save icon resources in image files (BMP, GIF, PNG, TIF and JPEG).  

See also:

* [Storing DLL icon resources in .ICO files](sample_502.md)  
* [How to view icons stored in executable files (Icon Viewer)](sample_113.md)  
* [GDI+ function](../libraries/gdiplus/GdipCreateBitmapFromHICON.md)  

  
***  


## Code:
```foxpro  
DO declare

* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
PRIVATE gdip As gdiplusinit
gdip = NEWOBJECT("gdiplusinit", "gdiplus.prg")

LOCAL cSourceFile, hModule, nIconIndex, hIcon, cTargetFile
hModule = GetModuleHandle(0)

* use any EXE or DLL file that contains icons
*!*	cSourceFile = "C:\Program Files\Microsoft Visual Studio " +;
*!*		".NET\Common7\IDE\devenv.exe"
cSourceFile = _vfp.ServerName

* enumerating icons in the source file from 0 and on
nIconIndex = 0
DO WHILE .T.
	hIcon = ExtractIcon(hModule, cSourceFile, nIconIndex)

	IF hIcon <> 0
	
		* PNG, TIF
		* BMP, JPG, GIF
		* make sure the target path is valid
		cTargetFile = "c:\temp\appicon" +;
			STRTRAN(STR(nIconIndex,3)," ","0") + ".png"

		LOCAL oBitmap As gdibitmap
		oBitmap = NEWOBJECT("gdibitmap", "gdiplus.prg")

		WITH oBitmap
			.CreateFromHIcon(m.hIcon)
			IF .SaveToFile(cTargetFile)
				? cTargetFile + " saved"
			ELSE
				? cTargetFile + " - error"
			ENDIF
		ENDWITH

		oBitmap=NULL
		= DestroyIcon(hIcon)
		nIconIndex = nIconIndex + 1
	ELSE
		EXIT
	ENDIF
ENDDO

PROCEDURE declare
	DECLARE INTEGER DestroyIcon IN user32 INTEGER hIcon

	DECLARE INTEGER ExtractIcon IN shell32;
		INTEGER hInst, STRING lpszExeFileName,;
		INTEGER lpiIcon

	DECLARE INTEGER GetModuleHandle IN kernel32;
		INTEGER lpModuleName  
```  
***  


## Listed functions:
[DestroyIcon](../libraries/user32/DestroyIcon.md)  
[ExtractIcon](../libraries/shell32/ExtractIcon.md)  
[GetModuleHandle](../libraries/kernel32/GetModuleHandle.md)  

## Comment:
To load the icon data from a .ICO file, not from resource, use this code:  
  
```foxpro
#DEFINE LR_LOADFROMFILE 0x0010  
#DEFINE LR_SHARED 0x8000  
#DEFINE IMAGE_ICON 1  
  
hIcon = LoadImage(0, cIconFile, IMAGE_ICON,;  
	0, 0, BITOR(LR_LOADFROMFILE, LR_SHARED))
```
While Windows imposes no restrictions on the sizes of icons, common sizes include 16, 32, and 48 pixels square.  
  
***  

