[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WinHttpReceiveResponse
Group: [HTTP Functions (WinHTTP)](../../functions_group.md#HTTP_Functions_(WinHTTP))  -  Library: [winhttp](../../Libraries.md#winhttp)  
***  


#### The WinHttpReceiveResponse function waits to receive the response to an HTTP request initiated by WinHttpSendRequest.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
void WinHttpReceiveResponse(
  HINTERNET hRequest,
  LPVOID lpReserved
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpReceiveResponse In winhttp;
	INTEGER hRequest,;
	INTEGER lpReserved
  
```  
***  


## Parameters:
hRequest 
[in] HINTERNET handle returned by WinHttpOpenRequest and sent by WinHttpSendRequest. Wait until WinHttpSendRequest has completed for this handle before calling WinHttpReceiveResponse. 

lpReserved 
[in] Must be set to NULL.   
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
MSDN: When WinHttpReceiveResponse completes successfully, the status code and response headers have been received and are available for the application to inspect using WinHttpQueryHeaders.   
  
An application must call WinHttpReceiveResponse before it can use WinHttpQueryDataAvailable and WinHttpReadData to access the response entity body (if any).  
  
***  

