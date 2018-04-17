[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetSetCookie
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### This function creates a cookie associated with the specified URL.
***  


## Code examples:
[Managing Cookies](../../samples/sample_186.md)  

## Declaration:
```foxpro  
BOOL InternetSetCookie (
	LPCTSTR lpszUrl,
	LPCTSTR lpszCookieName,
	LPCTSTR lpszCookieData
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetSetCookie IN wininet;
	STRING lpszUrl,;
	STRING lpszCookieName,;
	STRING lpszCookieData  
```  
***  


## Parameters:
lpszUrl 
[in] Address of a null-terminated string that specifies the URL for which the cookie should be set. 

lpszCookieName 
[in] Address of a string that contains the name to associate with the cookie data. If this parameter is NULL, no name is associated with the cookie. 

lpszCookieData 
[in] Address of the actual data to associate with the URL.   

***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
See also: [InternetGetCookie](InternetGetCookie.md).  
  
Cookies created by this function without an expiration date are stored in memory and are available only in the same process that created them. Cookies that include an expiration date are stored in the windows\cookies directory.  
  
See in attached examples how to create persistent and session cookies.  
  
***  

