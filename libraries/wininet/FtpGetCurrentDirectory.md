[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FtpGetCurrentDirectory
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves the current directory for the specified FTP session
***  


## Code examples:
[Retrieving list of files on the FTP directory](../../samples/sample_046.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[Reading list of folders and files on FTP server](../../samples/sample_340.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL FtpGetCurrentDirectory(
	HINTERNET hConnect,
	LPTSTR lpszCurrentDirectory,
	LPDWORD lpdwCurrentDirectory
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FtpGetCurrentDirectory IN wininet;
    INTEGER   hFtpSession,;
    STRING  @ lpszDirectory,;
    INTEGER @ lpdwCurrentDirectory  
```  
***  


## Parameters:
hConnect
[in] Valid handle to an FTP session.

lpszCurrentDirectory
[out] Pointer to a buffer that receives the current directory string

lpdwCurrentDirectory
[in, out] Pointer to a variable that specifies the length, in characters, of the buffer for the current directory string  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  


## Comments:
Before calling this function you must secure enough bytes in a string to return a directory name. The second parameter is also passed by a reference, the function stores the resulting string"s length in it.  
  
***  

