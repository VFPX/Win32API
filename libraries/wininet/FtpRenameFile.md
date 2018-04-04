[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpRenameFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Renames a file stored on the FTP server.
***  


## Code examples:
[Uploading local file to FTP server with FtpPutFile](../../samples/sample_061.md)  

## Declaration:
```foxpro  
BOOL FtpRenameFile(
    HINTERNET hConnect,
    LPCTSTR lpszExisting,
    LPCTSTR lpszNew
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpRenameFile IN wininet;
	INTEGER hConnect,;
	STRING  lpszExisting,;
	STRING  lpszNew  
```  
***  


## Parameters:
hConnect
[in] Valid HINTERNET handle to an FTP session.

lpszExisting
[in] Pointer to a null-terminated string that contains the name of the file that will have its name changed on the remote FTP server.

lpszNew
[in] Pointer to a null-terminated string that contains the new name for the remote file.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
If the file with the target name already exists, most probably it would be overwritten with new one during the renaming. At least my FTP server acts like this.  
  
***  

