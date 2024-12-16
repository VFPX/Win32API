[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetCloseHandle
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Closes a single Internet handle
***  


## Code examples:
[Opening access to the Microsoft Internet functions for the application](../../samples/sample_042.md)  
[How to download a file from the FTP server using FtpGetFile](../../samples/sample_043.md)  
[Retrieving list of files on the FTP directory](../../samples/sample_046.md)  
[Creating a directory on the FTP](../../samples/sample_047.md)  
[Using FtpCommand](../../samples/sample_059.md)  
[Reading Internet Query options](../../samples/sample_060.md)  
[Uploading local file to FTP server with FtpPutFile](../../samples/sample_061.md)  
[Uploading file to the FTP server using InternetWriteFile](../../samples/sample_062.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[How to retrieve the size of a remote file (FTP)](../../samples/sample_069.md)  
[How to remove FTP directory](../../samples/sample_070.md)  
[How to delete file on FTP server](../../samples/sample_071.md)  
[How to download this reference's archive through WinInet functions using InternetOpenUrl](../../samples/sample_110.md)  
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Reading list of folders and files on FTP server](../../samples/sample_340.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL InternetCloseHandle(
	HINTERNET hInternet
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetCloseHandle IN wininet;
	INTEGER hInet  
```  
***  


## Parameters:
hInternet
[in] Valid HINTERNET handle to be closed  
***  


## Return value:
Returns TRUE if the handle is successfully closed, or FALSE otherwise  
***  


## Comments:
This function closes handles created by InternetOpen, InternetOpenUrl, InternetConnect, FtpOpenFile, FtpFindFirstFile etc.  
  
***  

