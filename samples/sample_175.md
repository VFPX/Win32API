[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to download a file from HTTP server using URL Monikers functions

## Before you begin:
Check [similar example](sample_110.md) based on WinInet functions (HTTP)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER URLDownloadToFile IN urlmon.dll;
	INTEGER pCaller, STRING szURL,;
	STRING szFileName, INTEGER dwReserved,;
	INTEGER lpfnCB

LOCAL cRemoteFile, cLocalFile, nResult
cRemoteFile = "https://github.com/VFPX/Win32API/tree/master/downloads/w32data.zip"
cLocalFile = "c:\temp\w32data.zip"

WAIT WINDOW NOWAIT "Downloading file..."
nResult = URLDownloadToFile(0, cRemoteFile, cLocalFile, 0,0)
WAIT CLEAR

IF nResult = 0
	? "The file has been downloaded."
ELSE
	? "The URLDownloadToFile call failed with error code:", nResult
ENDIF  
```  
***  


## Listed functions:
[URLDownloadToFile](../libraries/urlmon/URLDownloadToFile.md)  

## Comment:
The simplicity and small size of this code does impress. Though there is no way - to my knowledge - to attach a progress bar to a download, since Visual FoxPro does not support callback functions.  
  
The URLDownloadToFile sends HTTP GET and receives a response back from a server. Upon success the response contains a requested file.  
  
See also: [DeleteUrlCacheEntry](.../libraries/wininet/DeleteUrlCacheEntry.md)   
  
***  

