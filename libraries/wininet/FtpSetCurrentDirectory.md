[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpSetCurrentDirectory
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Changes to a different working directory on the FTP server
***  


## Code examples:
[Retrieving list of files on the FTP directory](../../samples/sample_046.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[Reading list of folders and files on FTP server](../../samples/sample_340.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL FtpSetCurrentDirectory(
    HINTERNET hConnect,
    LPCTSTR lpszDirectory
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpSetCurrentDirectory IN wininet;
	INTEGER   hFtpSession,;
	STRING  @ lpszDirectory  
```  
***  


## Parameters:
hConnect
[in] Valid HINTERNET handle to an FTP session.

lpszDirectory
[in] Pointer to a null-terminated string that contains the name of the directory to change to on the remote system  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  


## Comments:
The function is very straightforward, nothing sophisticated. You can pass the directory name by a reference or by a value; it looks like the VFP automatically changes the passing value to a proper format  
  
***  

