[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpPutFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Stores a file on the FTP server.
***  


## Code examples:
[Uploading local file to FTP server with FtpPutFile](../../samples/sample_061.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL FtpPutFile(
    HINTERNET hConnect,
    LPCTSTR lpszLocalFile,
    LPCTSTR lpszNewRemoteFile,
    DWORD dwFlags,
    DWORD_PTR dwContext
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpPutFile IN wininet;
	INTEGER hConnect,;
	STRING  lpszLocalFile,;
	STRING  lpszNewRemoteFile,;
	INTEGER dwFlags,;
	INTEGER dwContext  
```  
***  


## Parameters:
hConnect
[in] Valid HINTERNET handle to an FTP session.

lpszLocalFile
[in] Pointer to a null-terminated string that contains the name of the file to send from the local system.

lpszNewRemoteFile
[in] Pointer to a null-terminated string that contains the name of the file to create on the remote system.

dwFlags
[in] Unsigned long integer value that contains the conditions under which the transfers occur. 

dwContext
[in] Pointer to an unsigned long integer value  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
When you upload files using the FtpPutFile function you can start the process and wait until it finishes.   
  
During the process you have no backward information, and then you can not estimate the uploading progress. Nevertheless this method is quite good on reliable FTP connections.   
  
In a situation when you want to have more control on the process another function is more appropriate -- InternetWriteFile  
  
***  

