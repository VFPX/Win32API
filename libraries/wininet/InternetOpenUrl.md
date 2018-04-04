[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetOpenUrl
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Opens a resource specified by a complete FTP, Gopher, or HTTP URL.
***  


## Code examples:
[How to download this reference`s archive through WinInet functions using InternetOpenUrl](../../samples/sample_110.md)  
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  

## Declaration:
```foxpro  
HINTERNET InternetOpenUrl(
    HINTERNET hInternet,
    LPCTSTR lpszUrl,
    LPCTSTR lpszHeaders,
    DWORD dwHeadersLength,
    DWORD dwFlags,
    DWORD_PTR dwContext
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetOpenUrl IN wininet;
	INTEGER hInternet,;
	STRING  lpszUrl,;
	STRING  lpszHeaders,;
	INTEGER dwHeadersLength,;
	INTEGER dwFlags,;
	INTEGER dwContext  
```  
***  


## Parameters:
hInternet
[in] HINTERNET handle to the current Internet session. The handle must have been returned by a previous call to InternetOpen.

lpszUrl
[in] Pointer to a string variable that contains the URL to begin reading. 

lpszHeaders
[in] Pointer to a string variable that contains the headers to be sent to the HTTP server. 

dwHeadersLength
[in] Unsigned long integer value that contains the length, in TCHARs, of the additional headers. 

dwFlags
[in] Unsigned long integer value that contains the API flags. 

dwContext
[in] Pointer to an unsigned long integer value that contains the application-defined value.  
***  


## Return value:
Returns a valid handle to the FTP, Gopher, or HTTP URL if the connection is successfully established, or NULL if the connection fails.  
***  


## Comments:
Use this function to download the archive with this reference data (see the example).  
  
***  

