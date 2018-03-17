<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Using GetCompressedFileSize (WinNT only)

## Before you begin:
See also:

* [How to retrieve the size of a local file](sample_114.md)  
* [Basic volume information](sample_098.md)  
* [How to retrieve the size of a remote file (FTP)](sample_069.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetCompressedFileSize IN kernel32;
	STRING lpFileName, INTEGER @lpFileSizeHigh

LOCAL lcFilename, lnSizeLo, lnSizeHi, lnSizeActual

lcFilename = "c:\Program Files\Microsoft Office\Office\Winword.exe"
STORE 0 TO lnSizeLo, lnSizeHi

lnSizeLo = GetCompressedFileSize (lcFilename, @lnSizeHi)
? "LO and HI values of actual size:", lnSizeLo, lnSizeHi  
```  
***  


## Listed functions:
[GetCompressedFileSize](../libraries/kernel32/GetCompressedFileSize.md)  

## Comment:
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

