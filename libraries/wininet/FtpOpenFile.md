[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpOpenFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Initiates access to a remote file on an FTP server for reading or writing.

***  


## Code examples:
[Uploading file to the FTP server using InternetWriteFile](../../samples/sample_062.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[How to retrieve the size of a remote file (FTP)](../../samples/sample_069.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
HINTERNET FtpOpenFile(
    HINTERNET hConnect,
    LPCTSTR lpszFileName,
    DWORD dwAccess,
    DWORD dwFlags,
    DWORD_PTR dwContext
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpOpenFile IN wininet;
	INTEGER hFtpSession,;
	STRING  sFileName,;
	INTEGER lAccess,;
	INTEGER lFlags,;
	INTEGER lContext  
```  
***  


## Parameters:
hConnect
[in] Valid HINTERNET handle to an FTP session.

lpszFileName
[in] Pointer to a null-terminated string that contains the name of the file to access on the remote system.

dwAccess
[in] Unsigned long integer value that determines how the file will be accessed. This can be GENERIC_READ or GENERIC_WRITE, but not both.

dwFlags
[in] Unsigned long integer value that contains the conditions under which the transfers occur. 

dwContext
[in] Pointer to an unsigned long integer value  
***  


## Return value:
Returns a handle if successful, or NULL otherwise. Later this handle can be used by InternetWriteFile or InternetReadFile functions  
***  


## Comments:
This function often works in combination with InternetWriteFile and InternetReadFile functions.  
  
***  

