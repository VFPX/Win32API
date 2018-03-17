<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# How to download a file from HTTP server using URL Monikers functions

## Before you begin:
Check <a href="?example=110">similar example</a> based on WinInet functions (HTTP)[similar example](sample_110.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER URLDownloadToFile IN urlmon.dll;
	INTEGER pCaller, STRING szURL,;
	STRING szFileName, INTEGER dwReserved,;
	INTEGER lpfnCB

LOCAL cRemoteFile, cLocalFile, nResult
cRemoteFile = "http://www.news2news.com/vfp/downloads/w32data.zip"
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
  
See also: DeleteUrlCacheEntry   
  
***  

