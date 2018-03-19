[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving information about the specified icon

## Code:
```foxpro  
DO declare

*| typedef struct _ICONINFO {
*|   BOOL    fIcon;      0:4
*|   DWORD   xHotspot;   4:4
*|   DWORD   yHotspot;   8:4
*|   HBITMAP hbmMask;   12:4
*|   HBITMAP hbmColor;  16:4
*| } ICONINFO; total bytes = 20
#DEFINE ICONINFO_SIZE  20

LOCAL lcModule, lnIndex, hIcon, lcBuffer

lcModule = GetModuleName()
lnIndex = 0   && icon index

* retrieving an icon handle
hIcon = ExtractAssociatedIcon(0, lcModule, @lnIndex)

lcBuffer = REPLICATE(Chr(0), ICONINFO_SIZE)
= GetIconInfo(hIcon, @lcBuffer)

? "Module name:", lcModule
? "Icon handle:", hIcon
?
? "*** Icon info"
? "Icon=1, Cursor=0:", buf2dword(SUBSTR(lcBuffer,1,4))
? "X hotspot:", buf2dword(SUBSTR(lcBuffer,5,4))
? "Y hotspot:", buf2dword(SUBSTR(lcBuffer,9,4))
? "Bitmask Bitmap:", buf2dword(SUBSTR(lcBuffer,13,4))
? "Color Bitmap:", buf2dword(SUBSTR(lcBuffer,17,4))

= DestroyIcon(hIcon)
* end of main

FUNCTION GetModuleName
#DEFINE BUF_SIZE 250
	LOCAL lcFilename, lnLen
	lcFilename = SPACE(BUF_SIZE)
	lnLen = GetModuleFileName(0, @lcFilename, BUF_SIZE)
RETURN  Left(lcFilename, lnLen)

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE SHORT DestroyIcon IN user32 INTEGER hIcon

	DECLARE INTEGER GetModuleFileName IN kernel32;
		INTEGER hModule, STRING @lpFilename, INTEGER nSize

	DECLARE INTEGER ExtractAssociatedIcon IN shell32;
		INTEGER hInst, STRING lpIconPath, INTEGER @lpiIcon

	DECLARE INTEGER GetIconInfo IN user32;
		INTEGER hIcon, STRING @piconinfo  
```  
***  


## Listed functions:
[DestroyIcon](../libraries/user32/DestroyIcon.md)  
[ExtractAssociatedIcon](../libraries/shell32/ExtractAssociatedIcon.md)  
[GetIconInfo](../libraries/user32/GetIconInfo.md)  
[GetModuleFileName](../libraries/kernel32/GetModuleFileName.md)  

## Comment:
First this code retrieves the handle to the icon (index=0) for the VFP executable module. Then it uses the GetIconInfo function to obtain some of this icon`s properties.  
  
***  

