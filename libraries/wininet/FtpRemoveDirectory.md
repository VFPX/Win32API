[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpRemoveDirectory
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Removes the specified directory on the FTP server.
***  


## Code examples:
[How to remove FTP directory](../../samples/sample_070.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL FtpRemoveDirectory(
    HINTERNET hConnect,
    LPCTSTR lpszDirectory
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpRemoveDirectory IN wininet;
	INTEGER hConnect,;
	STRING  lpszDirectory  
```  
***  


## Parameters:
hConnect
[in] Valid HINTERNET handle to an FTP session.

lpszDirectory
[in] Pointer to a null-terminated string that contains the name of the directory to remove on the remote system.  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
The possible reasons for the directory not being removed:  
	 - your access level is not valid  
	 - the directory does not exist  
	 - the directory is not empty  
  
***  

