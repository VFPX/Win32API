<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SHGetFileInfo
Group: Shell Functions - Library: shell32    
***  


#### Retrieves information about an object in the file system, such as a file, a folder, a directory, or a drive root.

***  


## Code examples:
[System Image List Viewer](../../samples/sample_021.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  
[Browsing Windows Known Folders (Special Folders)](../../samples/sample_576.md)  

## Declaration:
```foxpro  
DWORD_PTR SHGetFileInfo(
	LPCTSTR pszPath,
	DWORD dwFileAttributes,
	SHFILEINFO *psfi,
	UINT cbFileInfo,
	UINT uFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHGetFileInfo IN shell32;
	STRING pszPath,;
	LONG dwFileAttributes,;
	STRING @psfi,;
	LONG cbFileInfo,;
	LONG uFlags  
```  
***  


## Parameters:
```txt  
pszPath
[in] Pointer to a null-terminated string of maximum length MAX_PATH that contains the path and file name.

dwFileAttributes
[in] Combination of one or more file attribute flags.

psfi
[out] Address of a SHFILEINFO structure to receive the file information.

cbFileInfo
[in] Size, in bytes, of the SHFILEINFO structure pointed to by the psfi parameter.

uFlags
[in] Flags that specify the file information to retrieve.  
```  
***  


## Return value:
Returns a value whose meaning depends on the uFlags parameter.  
***  


## Comments:
If SHGetFileInfo returns an icon handle (HICON) in the hIcon member of the SHFILEINFO structure pointed to by psfi.   
  
Not so many applications in Visual FoxPro for this HICON handle I can think of. But there are two I am pretty sure about: displaying an icon in the <a href="?example=235">System Tray</a>, and displaying an icon <a href="?example=500">inside the MessageBox dialog window</a>.  
  
The application is responsible for freeing the icon handle with DestroyIcon when it is no longer needed.  
  
* * *  
It seems that this function makes an addition to the system image list (aka Shell Icon Cache, HIMAGELIST), if the list has no element for the specified file type.  
  
<div class="precode">#DEFINE SHGFI_ICON 0x000000100  
#DEFINE SHGFI_TYPENAME 0x000000400  
#DEFINE SHGFI_USEFILEATTRIBUTES 0x000000010  
#DEFINE FILE_ATTRIBUTE_NORMAL 0x00000080  
  
<span style="color:#00a000;">*!*typedef struct _SHFILEINFO {  
*!*	HICON hIcon;  
*!*	int iIcon;  
*!*	DWORD dwAttributes;  
*!*	TCHAR szDisplayName[MAX_PATH];  
*!*	TCHAR szTypeName[80];  
*!*} SHFILEINFO;</span>  
  
LOCAL cFilename, nBufsize, cBuffer, nFlags,;  
	nResult, hIcon  
  
cFilename = ".xml"  
nBufsize=1024  
cBuffer = REPLICATE(CHR(0), nBufsize)  
nFlags = BITOR(SHGFI_ICON,;  
	SHGFI_TYPENAME, SHGFI_USEFILEATTRIBUTES)  
  
nResult = SHGetFileInfo(cFilename, FILE_ATTRIBUTE_NORMAL,;  
	@cBuffer, nBufsize, nFlags)  
  
hIcon = buf2dword(SUBSTR(cBuffer, 1, 4))  
IF hIcon <> 0  
	= DestroyIcon(hIcon)  
ENDIF  
</div>  
All system icons can be accessed through this function and drawn, for example, on ListView ActiveX control:  
  
<img src="images/sysimagelist.png" width=507 height=338>  
  
* * *  
As MSDN suggests, the SHGetFileInfo may not be the best way, even if the simplest, to retrieve an object`s icon. A more flexible and efficient way is to use <a href="http://msdn.microsoft.com/en-us/library/bb761854(v=vs.85).aspx">IExtractIcon Interface</a>. The Shell uses IExtractIcon to retrieve icons when it displays the contents of a folder.  
  
***  

