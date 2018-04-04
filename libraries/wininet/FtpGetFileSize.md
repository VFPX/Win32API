[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpGetFileSize
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves the file size of the requested FTP resource.
***  


## Code examples:
[How to retrieve the size of a remote file (FTP)](../../samples/sample_069.md)  

## Declaration:
```foxpro  
DWORD FtpGetFileSize(
    HINTERNET hFile,
    LPDWORD lpdwFileSizeHigh
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpGetFileSize IN wininet;
	INTEGER   hFile,;
	INTEGER @ lpdwFileSizeHigh  
```  
***  


## Parameters:
hFile
[in] HINTERNET handle returned from a call to FtpOpenFile.

lpdwFileSizeHigh
[out] Pointer to the high-order unsigned long integer of the file size of the requested FTP resource.  
***  


## Return value:
Returns the low-order unsigned long integer of the file size of the requested FTP resource.  
***  

