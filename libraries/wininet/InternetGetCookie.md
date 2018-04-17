[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetGetCookie
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  

#### This function retrieves the cookie for the specified URL.
***  


## Code examples:
[Managing Cookies](../../samples/sample_186.md)  

## Declaration:
```foxpro  
BOOL InternetGetCookie(
	LPCTSTR lpszUrl,
	LPCTSTR lpszCookieName,
	LPSTR lpCookieData,
	LPDWORD lpdwSize
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetGetCookie IN wininet;
	STRING    lpszUrlName,;
	STRING    lpszCookieName,;
	STRING  @ lpszCookieData,;
	INTEGER @ lpdwSize  
```  
***  


## Parameters:
lpszUrl 
[in] Address of a string that contains the URL to get cookies for. 

lpszCookieName 
[in] Address of a string that contains the name of the cookie to get for the specified URL. This has not been implemented in this release. 

lpCookieData 
[out] Address of the buffer that receives the cookie data. This value can be NULL. 

lpdwSize 
[in] [out] Address of an unsigned long integer variable that specifies the size of the lpszCookieData buffer.   
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
See [InternetSetCookie](InternetSetCookie.md).  
  
***  

