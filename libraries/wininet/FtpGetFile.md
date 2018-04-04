[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpGetFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves a file from the FTP server and stores it under the specified file name, creating a new local file in the process.
***  


## Code examples:
[How to download a file from the FTP server using FtpGetFile](../../samples/sample_043.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL FtpGetFile(
    HINTERNET hConnect,
    LPCTSTR lpszRemoteFile,
    LPCTSTR lpszNewFile,
    BOOL fFailIfExists,
    DWORD dwFlagsAndAttributes,
    DWORD dwFlags,
    DWORD_PTR dwContext
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpGetFile IN wininet;
	INTEGER hFtpSession,;
	STRING  lpszRemoteFile,;
	STRING  lpszNewFile,;
	INTEGER fFailIfExists,;
	INTEGER dwFlagsAndAttributes,;
	INTEGER dwFlags,;
	INTEGER dwContext  
```  
***  


## Parameters:
hConnect
[in] Valid handle to an FTP session.

lpszRemoteFile
[in] Pointer to a null-terminated string that contains the name of the file to retrieve from the remote system.

lpszNewFile
[in] Pointer to a null-terminated string that contains the name of the file to create on the local system.

fFailIfExists
[in] BOOL that indicates whether the function should proceed if a local file of the specified name already exists.

dwFlagsAndAttributes
[in] Unsigned long integer value that contains the file attributes for the new file.

dwFlags
[in] Unsigned long integer value that contains the flags that control how the function will handle the file download.

dwContext
[in] Pointer to an unsigned long integer value that contains the application-defined value...  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  

