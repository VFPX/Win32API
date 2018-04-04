[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpCreateDirectory
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Creates a new directory on the FTP server
***  


## Code examples:
[Creating a directory on the FTP](../../samples/sample_047.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL FtpCreateDirectory(
    HINTERNET hConnect,
    LPCTSTR lpszDirectory
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpCreateDirectory IN wininet;
	INTEGER hFtpSession,;
	STRING  lpszDirectory  
```  
***  


## Parameters:
hConnect
[in] Valid HINTERNET handle returned by a previous call to InternetConnect using INTERNET_SERVICE_FTP

lpszDirectory
[in] Pointer to a null-terminated string that contains the name of the directory to create  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
To create a directory you must have sufficient access level to the ftp server.  
  
***  

