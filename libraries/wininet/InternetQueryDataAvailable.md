
## Function name : InternetQueryDataAvailable
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### This function queries the amount of data available.
***  


## Code examples:
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  

## Declaration:
```foxpro  
BOOL WINAPI InternetQueryDataAvailable(
	HINTERNET hFile,
	LPDWORD lpdwNumberOfBytesAvailable,
	DWORD dwFlags,
	DWORD dwContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetQueryDataAvailable IN wininet;
	INTEGER   hFile,;
	INTEGER @ lpdwBytesAvailable,;
	INTEGER   dwFlags,;
	INTEGER   dwContext  
```  
***  


## Parameters:
hFile 
Valid Internet file handle, as returned by InternetOpenUrl, FtpOpenFile, or HttpOpenRequest. 

lpdwNumberOfBytesAvailable 
Optional. Long pointer to a variable that receives the number of available bytes. 

dwFlags 
Reserved; set to zero. 

dwContext 
Reserved; set to zero.   
***  


## Return value:
TRUE indicates success. FALSE indicates failure.   
***  


## Comments:
Especially long name for this function, makes me sick. Though not the longest, see InternetGetConnectedStateEx and InternetGetLastResponseInfo.  
  
***  

