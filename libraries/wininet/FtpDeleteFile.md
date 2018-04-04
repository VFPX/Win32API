[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpDeleteFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
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
hConnect
[in] Valid HINTERNET handle returned by a previous call to InternetConnect using INTERNET_SERVICE_FTP.

lpszFileName
[in] Pointer to a null-terminated string that contains the name of the file to delete on the remote system.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

