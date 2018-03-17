<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FtpGetFileSize
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
hFile
[in] HINTERNET handle returned from a call to FtpOpenFile.

lpdwFileSizeHigh
[out] Pointer to the high-order unsigned long integer of the file size of the requested FTP resource.  
```  
***  


## Return value:
Returns the low-order unsigned long integer of the file size of the requested FTP resource.  
***  

