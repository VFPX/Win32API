[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpCloseHandle
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### The WinHttpCloseHandle function closes a single HINTERNET handle.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpCloseHandle(
  HINTERNET hInternet
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpCloseHandle IN winhttp;
	INTEGER hInternet  
```  
***  


## Parameters:
hInternet 
[in] Valid HINTERNET handle to be closed.  
***  


## Return value:
Returns TRUE if the handle is successfully closed, or FALSE otherwise.  
***  


## Comments:
MSDN: When WinHTTP is used in asynchronous mode (that is, when WINHTTP_FLAG_ASYNC has been set in WinHttpOpen), this function operates synchronously.   
  
The return value indicates success or failure. To get extended error information, call GetLastError.  
  
***  

