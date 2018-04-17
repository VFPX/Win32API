[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : HttpQueryInfo
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
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
***  


## Return value:
Returns TRUE if successful, or FALSE otherwise.  
***  

## Comments:
The following lists contain the attributes and modifiers used by HttpQueryInfo and QueryInfo: [Query Info Flags](https://msdn.microsoft.com/en-us/library/windows/desktop/aa385351(v=vs.85).aspx).  
  
***  

