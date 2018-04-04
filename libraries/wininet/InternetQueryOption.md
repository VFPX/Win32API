[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetQueryOption
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../libraries.md#wininet)  
***  


#### Queries an Internet option on the specified handle
***  


## Code examples:
[Reading Internet Query options](../../samples/sample_060.md)  

## Declaration:
```foxpro  
BOOL InternetQueryOption(
    HINTERNET hInternet,
    DWORD dwOption,
    LPVOID lpBuffer,
    LPDWORD lpdwBufferLength
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetQueryOption IN wininet;
	INTEGER   hInternet,;
	INTEGER   lOption,;
	STRING  @ sBuffer,;
	INTEGER @ lBufferLength  
```  
***  


## Parameters:
hInternet
[in] HINTERNET handle on which to query information

dwOption
[in] Unsigned long integer value that contains the Internet option to query

lpBuffer
[out] Pointer to a buffer that receives the option setting

lpdwBufferLength
[in, out] Pointer to an unsigned long integer variable that contains the length of lpBuffer  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  


## Comments:
You can reach the full list of Internet Option Flags Constants at <a href="http://msdn.microsoft.com/library/default.asp?url=/workshop/networking/wininet/reference/constants/flags.asp">MSDN</a> site.  
  
***  

