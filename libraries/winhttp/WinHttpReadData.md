<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WinHttpReadData
Group: HTTP Functions (WinHTTP) - Library: winhttp    
***  


#### The WinHttpReadData function reads data from a handle opened by the WinHttpOpenRequest function.
***  


## Code examples:
[Custom HttpRequest class (WinHTTP)](../../samples/sample_397.md)  

## Declaration:
```foxpro  
BOOL WinHttpReadData(
  HINTERNET hRequest,
  LPVOID lpBuffer,
  DWORD dwNumberOfBytesToRead,
  LPDWORD lpdwNumberOfBytesRead
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WinHttpReadData IN winhttp;
	INTEGER   hRequest,;
	STRING  @ lpBuffer,;
	INTEGER   dwNumberOfBytesToRead,;
	INTEGER @ lpdwBytesRead  
```  
***  


## Parameters:
```txt  
hRequest
[in] Valid HINTERNET handle returned from a previous call to WinHttpOpenRequest. WinHttpReceiveResponse or WinHttpQueryDataAvailable must have been called for this handle and have completed before WinHttpReadData is called.

lpBuffer
[out] Pointer to a buffer that receives the data read.

dwNumberOfBytesToRead
[in] Unsigned long integer value that contains the number of bytes to read.

lpdwNumberOfBytesRead
[out] Pointer to an unsigned long integer variable that receives the number of bytes read.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
MSDN: If you are using WinHttpReadData synchronously, and the return value is TRUE and the number of bytes read is zero, the transfer has been completed and there are no more bytes to read on the handle. This is analogous to reaching end-of-file in a local file.  
  
***  

