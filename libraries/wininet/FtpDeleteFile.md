<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FtpDeleteFile
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Deletes a file stored on the FTP server.
***  


## Code examples:
[How to delete file on FTP server](../../samples/sample_071.md)  

## Declaration:
```foxpro  
BOOL FtpDeleteFile(
    HINTERNET hConnect,
    LPCTSTR lpszFileName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpDeleteFile IN wininet;
   	INTEGER hConnect,;
   	STRING  lpszFileName  
```  
***  


## Parameters:
```txt  
hConnect
[in] Valid HINTERNET handle returned by a previous call to InternetConnect using INTERNET_SERVICE_FTP.

lpszFileName
[in] Pointer to a null-terminated string that contains the name of the file to delete on the remote system.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

