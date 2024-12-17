[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetOpen
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Initializes an application"s use of the Microsoft&reg; Win32&reg; Internet functions
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
HINTERNET InternetOpen(
	LPCTSTR lpszAgent,
	DWORD dwAccessType,
	LPCTSTR lpszProxyName,
	LPCTSTR lpszProxyBypass,
	DWORD dwFlags
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetOpen IN wininet;
	STRING  sAgent,;
	INTEGER lAccessType,;
	STRING  sProxyName,;
	STRING  sProxyBypass,;
	STRING  lFlags  
```  
***  


## Parameters:
lpszAgent
[in] Pointer to a string variable that contains the name of the application or entity calling the Internet functions.

dwAccessType
[in] Type of access required

lpszProxyName
[in] Pointer to a string variable that contains the name of the proxy server(s) 

lpszProxyBypass
[in] Pointer to a string variable that contains an optional list of host names or IP addresses, or both, that should not be routed through the proxy when dwAccessType is set to INTERNET_OPEN_TYPE_PROXY

dwFlags
[in] Unsigned long integer value that contains the flags that indicate various options affecting the behavior of the function  
***  


## Return value:
Returns a valid handle that the application passes to subsequent Win32 Internet functions. If InternetOpen fails, it returns NULL  
***  


## Comments:
It"s just a beginning -- to allow your application to use the Microsoft Internet functions. Actually, this function does nothing except this. On exit do not forget to call the closing function -- InternetCloseHandle.  
  
Allow me to allow something, and I soon will be the master of this something.  
  
***  

