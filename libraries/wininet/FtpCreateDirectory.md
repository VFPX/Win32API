<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FtpCreateDirectory
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
hConnect
[in] Valid HINTERNET handle returned by a previous call to InternetConnect using INTERNET_SERVICE_FTP

lpszDirectory
[in] Pointer to a null-terminated string that contains the name of the directory to create  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
To create a directory you must have sufficient access level to the ftp server.  
  
***  

