[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetGetLastResponseInfo
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Retrieves the last Microsoft&reg; Win32&reg; Internet function error description or server response on the thread calling this function.
***  


## Code examples:
[Using FtpCommand](../../samples/sample_059.md)  
[Wininet last error description](../../samples/sample_109.md)  

## Declaration:
```foxpro  
BOOL InternetGetLastResponseInfo(
    LPDWORD lpdwError,
    LPTSTR lpszBuffer,
    LPDWORD lpdwBufferLength
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT InternetGetLastResponseInfo IN wininet;
	INTEGER @ lpdwError,;
	STRING  @ lpszBuffer,;
	INTEGER @ lpdwBufferLength  
```  
***  


## Parameters:
lpdwError
[out] Pointer to an unsigned long integer variable that receives an error message pertaining to the operation that failed.

lpszBuffer
[out] Pointer to a buffer that receives the error text.

lpdwBufferLength
[in, out] Pointer to an unsigned long integer variable that contains the size of the lpszBuffer buffer in TCHARs.  
***  


## Return value:
Returns TRUE if error text was successfully written to the buffer, or FALSE otherwise.  
***  

