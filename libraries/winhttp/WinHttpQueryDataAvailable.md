<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WinHttpQueryDataAvailable
Group: HTTP Functions (WinHTTP) - Library: winhttp    
***  


#### The WinHttpQueryDataAvailable function returns the number of bytes of data that are immediately available to be read with WinHttpReadData.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpQueryDataAvailable(
  HINTERNET hRequest,
  LPDWORD lpdwNumberOfBytesAvailable
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpQueryDataAvailable IN winhttp;
	INTEGER hRequest,;
	INTEGER @lpdwNumberOfBytesAvailable
  
```  
***  


## Parameters:
```txt  
hRequest
[in] Valid HINTERNET handle, as returned by WinHttpOpenRequest.

lpdwNumberOfBytesAvailable
[out, optional] Pointer to an unsigned long integer variable that receives the number of available bytes.  
```  
***  


## Return value:
Returns TRUE if the function succeeds, or FALSE otherwise.  
***  


## Comments:
MSDN: WinHttpReceiveResponse must have been called for this handle and have completed before WinHttpQueryDataAvailable is called.   
  
This function returns the number of bytes of data that are available to read immediately by a subsequent call to WinHttpReadData. If no data is available and the end of the file has not been reached (for a synchronous session) the request waits until data becomes available.  
  
***  

