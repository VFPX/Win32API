[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using GetFileSize

## Before you begin:
See also:

* [How to retrieve the size of a remote file (FTP)](sample_069.md)  
* [Basic volume information](sample_098.md)  
* [Using GetCompressedFileSize](sample_192.md)  
  
***  


## Code:
```foxpro  
DO declare
? GetFileSizeAPI(_vfp.ServerName)

FUNCTION GetFileSizeAPI(lcFilename)
#DEFINE OF_SHARE_DENY_NONE 64
#DEFINE HFILE_ERROR -1
#DEFINE MAX_DWORD 0xffffffff

	LOCAL lpReOpenBuff, hFile, lnSizeLo, lnSizeHi

	lpReOpenBuff = REPLICATE(Chr(0), 250)
	hFile = OpenFile(lcFilename, @lpReOpenBuff, OF_SHARE_DENY_NONE)

	IF hFile <> HFILE_ERROR
		lnSizeHi = 0
		lnSizeLo = GetFileSize(hFile, @lnSizeHi)
		= CloseHandle(hFile)
		RETURN lnSizeHi * (MAX_DWORD + 1) + lnSizeLo
	ELSE
		RETURN 0
	ENDIF

PROCEDURE declare
	DECLARE INTEGER GetFileSize IN kernel32;
		INTEGER hFile, INTEGER @lpFileSizeHigh

	DECLARE INTEGER OpenFile IN kernel32;
		STRING lpFileName,;
		STRING @lpReOpenBuff,;
		INTEGER wStyle

	DECLARE INTEGER CloseHandle IN kernel32;
		INTEGER hObject  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[GetFileSize](../libraries/kernel32/GetFileSize.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  

## Comment:
The GetFileSize returns the result stored in two 32-bit unsigned integers. This is quite a size for any file or device.  
  
Had it return only one 32-bit value -- the maximum of  4,294,967,296 Bytes is not a high-end capacity these days.  
  
***  

