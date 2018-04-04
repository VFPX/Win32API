[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetReadFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Reads data from a handle opened by the InternetOpenUrl, FtpOpenFile, FtpCommand, GopherOpenFile, or HttpOpenRequest function

***  


## Code examples:
[Using FtpCommand](../../samples/sample_059.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[How to download this reference`s archive through WinInet functions using InternetOpenUrl](../../samples/sample_110.md)  
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL InternetReadFile(
    HINTERNET hFile,
    LPVOID lpBuffer,
    DWORD dwNumberOfBytesToRead,
    LPDWORD lpdwNumberOfBytesRead
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetReadFile IN wininet;
	INTEGER   hFile,;
	STRING  @ sBuffer,;
	INTEGER   lNumBytesToRead,;
	INTEGER @ dwNumberOfBytesRead  
```  
***  


## Parameters:
hFile
[in] Valid HINTERNET handle returned from a previous call to InternetOpenUrl, FtpOpenFile, FtpCommand, GopherOpenFile, or HttpOpenRequest

lpBuffer
[in] Pointer to a buffer that receives the data to read

dwNumberOfBytesToRead
[in] Unsigned long integer value that contains the number of bytes to read

lpdwNumberOfBytesRead
[out] Pointer to an unsigned long integer variable that receives the number of bytes read
  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  

