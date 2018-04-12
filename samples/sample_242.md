[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving file information for the VFP executable running

## Before you begin:
API calls GetModuleFileName and GetFileInformationByHandle are used to obtain information about the file behind the current process.   
The latter returns populated BY_HANDLE_FILE_INFORMATION structure.  

See also:

* [How to retrieve version information for the specified file](sample_480.md)  
* [Showing the Properties dialog box for a file (ShellExecuteEx)](sample_320.md)  
* [Basic Volume Information](sample_098.md)  
  
***  


## Code:
```foxpro  
DO decl

*| typedef struct _BY_HANDLE_FILE_INFORMATION {
*|   DWORD    dwFileAttributes;       0:4
*|   FILETIME ftCreationTime;         4:8
*|   FILETIME ftLastAccessTime;      12:8
*|   FILETIME ftLastWriteTime;       20:8
*|   DWORD    dwVolumeSerialNumber;  28:4
*|   DWORD    nFileSizeHigh;         32:4
*|   DWORD    nFileSizeLow;          36:4
*|   DWORD    nNumberOfLinks;        40:4
*|   DWORD    nFileIndexHigh;        44:4
*|   DWORD    nFileIndexLow;         48:4 total 52 bytes
*| } BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION

#DEFINE FILEINFO_SIZE       52
#DEFINE OF_READ              0
#DEFINE OF_SHARE_DENY_NONE  64
#DEFINE HFILE_ERROR         -1

* file type constants
#DEFINE FILE_TYPE_UNKNOWN 0
#DEFINE FILE_TYPE_DISK 1
#DEFINE FILE_TYPE_CHAR 2
#DEFINE FILE_TYPE_PIPE 3
#DEFINE FILE_TYPE_REMOTE 0x8000

LOCAL lcFilename, lcFileInfo, lcReopenBuf, hFile,;
	lnFiletype, lnResult

lcReopenBuf = Repli(Chr(0), 250)
lcFilename = GetModuleName()

hFile = OpenFile(lcFilename,;
	@lcReopenBuf, OF_READ+OF_SHARE_DENY_NONE)

IF hFile = HFILE_ERROR
	? "Error opening file"
	RETURN
ENDIF

lcFileInfo = Repli(Chr(0), FILEINFO_SIZE)

lnResult = GetFileInformationByHandle(hFile, @lcFileInfo)
lnFiletype = GetFileType(hFile)
= CloseHandle(hFile)

IF lnResult <> 0
	? "Target file:", lcFilename
	? "File type:", lnFiletype
	? "File attributes: ", buf2dword(SUBSTR(lcFileInfo, 1,4))

	* the serial number of the volume that contains the file
	? "Volume serial number:", buf2dword(SUBSTR(lcFileInfo, 29,4))

	? "File size high:", buf2dword(SUBSTR(lcFileInfo, 33,4))
	? "File size low:", buf2dword(SUBSTR(lcFileInfo, 37,4))

	* the number of links to this file
	* for the FAT file system this member is always 1
	? "Number of links:", buf2dword(SUBSTR(lcFileInfo, 41,4))
	
	* FileIndex: this identifier and the volume serial number
	* uniquely identify a file.

	* An application can use this identifier and the volume
	* serial number to determine whether two handles refer
	* to the same file.

	? "File index high:", buf2dword(SUBSTR(lcFileInfo, 45,4))
	? "File index low:", buf2dword(SUBSTR(lcFileInfo, 49,4))
ENDIF

FUNCTION  GetModuleName
* retrieves the full path and file name
* for the VFP executable running
	LOCAL lcBuffer, lnLen
	lcBuffer = SPACE(512)
	lnLen = GetModuleFileName(0, @lcBuffer, Len(lcBuffer))
RETURN  Left(lcBuffer, lnLen)

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER GetFileInformationByHandle IN kernel32;
		INTEGER hFile, STRING @lpFileInformation

	DECLARE INTEGER OpenFile IN kernel32;
		STRING lpFileName, STRING @lpReOpenBuff, INTEGER wStyle

	DECLARE INTEGER GetModuleFileName IN kernel32;
		INTEGER hModule, STRING @lpFilename, INTEGER nSize

	DECLARE INTEGER GetFileType IN kernel32 INTEGER hFile  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetFileInformationByHandle](../libraries/kernel32/GetFileInformationByHandle.md)  
[GetFileType](../libraries/kernel32/GetFileType.md)  
[GetModuleFileName](../libraries/kernel32/GetModuleFileName.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  

## Comment:
The *Volume Serial Number* value obtained through this code is more accurate comparing to this example: [Basic Volume Information ](sample_98.md). Since the result of the latter is often interpreted by the VFP as a signed integer.  
  
***  

