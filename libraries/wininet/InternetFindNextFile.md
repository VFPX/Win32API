[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetFindNextFile
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Continues a file search started as a result of a previous call to FtpFindFirstFile or GopherFindFirstFile
***  


## Code examples:
[Retrieving list of files on the FTP directory](../../samples/sample_046.md)  
[Downloading files from the FTP server using InternetReadFile](../../samples/sample_063.md)  
[Reading list of folders and files on FTP server](../../samples/sample_340.md)  
[Custom FTP Class for Visual FoxPro application](../../samples/sample_344.md)  

## Declaration:
```foxpro  
BOOL InternetFindNextFile(
    HINTERNET hFind,
    LPVOID lpvFindData
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetFindNextFile IN wininet;
	INTEGER  hFind,;
	STRING @ lpvFindData  
```  
***  


## Parameters:
hFind
[in] Valid HINTERNET handle returned from either FtpFindFirstFile or GopherFindFirstFile, or from InternetOpenUrl (directories only).

lpvFindData
[out] Pointer to the buffer that receives information about the found file or directory  
***  


## Return value:
Returns TRUE if the function succeeds, or FALSE otherwise  
***  

