[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpFindFirstFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Searches the specified directory of the given FTP session
***  


## Code examples:
[Retrieving list of files on the FTP directory](../../samples/sample_046.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[Reading list of folders and files on FTP server](../../samples/sample_340.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
HINTERNET FtpFindFirstFile(
    HINTERNET hConnect,
    LPCTSTR lpszSearchFile,
    LP lpFindFileData,
    DWORD dwFlags,
    DWORD_PTR dwContext
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpFindFirstFile IN wininet;
	INTEGER  hFtpSession,;
	STRING   lpszSearchFile,;
	STRING @ lpFindFileData,;
	INTEGER  dwFlags,;
	INTEGER  dwContent  
```  
***  


## Parameters:
hConnect
[in] Valid handle to an FTP session returned from InternetConnect

lpszSearchFile
[in] Pointer to a null-terminated string that specifies a valid directory path or file name for the FTP server"s file system

lpFindFileData
[out] Pointer to a WIN32_FIND_DATA structure that receives information about the found file or directory

dwFlags
[in] Value of type DWORD that specifies the flags that control the behavior of this function

dwContext
[in] Pointer to a variable of type DWORD that specifies the application-defined value...  
***  


## Return value:
Returns a valid handle for the request if the directory enumeration was started successfully, or returns NULL otherwise  
***  


## Comments:
The old and familiar approach -- to get a handle from the FindFirst call and use it with successive FindNext calls. The trick -- though simple enough - is how to retrieve fields from a structure containing in the resulting buffer.  
  
***  

