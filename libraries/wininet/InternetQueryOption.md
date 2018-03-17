<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : InternetQueryOption
Group: Internet Functions (WinInet) - Library: wininet    
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
```txt  
hInternet
[in] HINTERNET handle on which to query information

dwOption
[in] Unsigned long integer value that contains the Internet option to query

lpBuffer
[out] Pointer to a buffer that receives the option setting

lpdwBufferLength
[in, out] Pointer to an unsigned long integer variable that contains the length of lpBuffer  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise  
***  


## Comments:
You can reach the full list of Internet Option Flags Constants at <a href="http://msdn.microsoft.com/library/default.asp?url=/workshop/networking/wininet/reference/constants/flags.asp">MSDN</a> site.  
  
***  

