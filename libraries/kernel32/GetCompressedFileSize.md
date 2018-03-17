<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetCompressedFileSize
Group: File System - Library: kernel32    
***  


#### Retrieves the actual number of bytes of disk storage used to store a specified file. If the file is located on a volume that supports compression/sparse files, and the file is compressed, the value obtained is the compressed/sparse size of the specified file
***  


## Code examples:
[Using GetCompressedFileSize (WinNT only)](../../samples/sample_192.md)  

## Declaration:
```foxpro  
DWORD GetCompressedFileSize(
  LPCTSTR lpFileName,     // file name
  LPDWORD lpFileSizeHigh  // high-order DWORD of file size
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCompressedFileSize IN kernel32;
	STRING    lpFileName,;
	INTEGER @ lpFileSizeHigh  
```  
***  


## Parameters:
```txt  
lpFileName
[in] Pointer to a null-terminated string that specifies the name of the file.

lpFileSizeHigh
[out] Pointer to a variable that receives the high-order DWORD of the compressed file size.  
```  
***  


## Return value:
If the function succeeds, the return value is the low-order DWORD of the actual number of bytes of disk storage used to store the specified file.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 3.1 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

