<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : HttpQueryInfo
Group: Internet Functions (WinInet) - Library: wininet    
***  


#### Retrieves header information associated with an HTTP request.
***  


## Code examples:
[Custom HttpRequest class (WinINet)](../../samples/sample_185.md)  

## Declaration:
```foxpro  
BOOL HttpQueryInfo(
	HINTERNET hRequest,
	DWORD dwInfoLevel,
	LPVOID lpvBuffer,
	LPDWORD lpdwBufferLength,
	LPDWORD lpdwIndex
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER HttpQueryInfo IN wininet;
	INTEGER  hRequest,;
	LONG     dwInfoLevel,;
	STRING @ lpvBuffer,;
	LONG   @ lpdwBufferLength,;
	LONG   @ lpdwIndex  
```  
***  


## Parameters:
```txt  
hRequest
[in] Handle returned by HttpOpenRequest or InternetOpenUrl.

dwInfoLevel
[in] Combination of an attribute to be retrieved and flags that modify the request. For a list of possible attribute and modifier values, see Query Info Flags.

lpvBuffer
[in] Pointer to a buffer that receives the information. This parameter must not be NULL.

lpdwBufferLength
[in] Pointer to a variable that contains the size of the data buffer, in bytes.

lpdwIndex
[in, out] Pointer to a zero-based header index used to enumerate multiple headers with the same name.  
```  
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  


## Comments:
<a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/wininet/wininet/query_info_flags.asp">Query Info Flags</a>: The following lists contain the attributes and modifiers used by HttpQueryInfo and QueryInfo.  
  
***  

