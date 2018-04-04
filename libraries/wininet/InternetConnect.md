[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetConnect
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Opens an FTP, Gopher, or HTTP session for a given site
***  


## Code examples:
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
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  
[Reading list of folders and files on FTP server](../../samples/sample_340.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
HINTERNET InternetConnect(
    HINTERNET hInternet,
    LPCTSTR lpszServerName,
    INTERNET_PORT nServerPort,
    LPCTSTR lpszUsername,
    LPCTSTR lpszPassword,
    DWORD dwService,
    DWORD dwFlags,
    DWORD_PTR dwContext
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetConnect IN wininet;
	INTEGER hInternetSession,;
	STRING  sServerName,;
	INTEGER nServerPort,;
	STRING  sUsername,;
	STRING  sPassword,;
	INTEGER lService,;
	INTEGER lFlags,;
	INTEGER lContext
  
```  
***  


## Parameters:
hInternet
[in] Valid HINTERNET handle returned by a previous call to InternetOpen.

lpszServerName
[in] Pointer to a null-terminated string that contains the host name of an Internet server.

nServerPort
[in] longof the TCP/IP port on the server to connect to. These flags set only the port that will be used.

lpszUsername
[in] Pointer to a null-terminated string that contains the name of the user to log on.

lpszPassword
[in] Pointer to a null-terminated string that contains the password to use to log on.

dwService
[in] Unsigned long integer value that contains the type of service to access.

dwFlags
[in] Unsigned long integer value that contains the flags specific to the service used.

dwContext
[in] Pointer to an unsigned long integer value ...  
***  


## Return value:
Returns a valid handle to the FTP, Gopher, or HTTP session if the connection is successful, or NULL otherwise  
***  


## Comments:
Some main FTP functions can be implemented in Visual Foxpro through creating command files and running FTP.EXE utility as an external application. This program is usually installed on Windows computers as a regular part of the OS.   
  
Nevertheless when using the Inet functions you may acquire more control comparing to the FTP.EXE option.  
  
***  

