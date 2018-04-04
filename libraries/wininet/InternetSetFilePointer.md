[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : InternetSetFilePointer
Group: [Internet Functions (WinInet)](../../functions_group.md#Internet_Functions_(WinInet))  -  Library: [wininet](../../Libraries.md#wininet)  
***  


#### Sets a file position for InternetReadFile. 
***  


## Code examples:
[Using InternetSetFilePointer when resuming interrupted download from the Internet](../../samples/sample_191.md)  

## Declaration:
```foxpro  
DWORD InternetSetFilePointer(
	HINTERNET hFile,
    LONG lDistanceToMove,
    PVOID pReserved,
    DWORD dwMoveMethod,
    DWORD dwContext
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER InternetSetFilePointer IN wininet;
	INTEGER hFile,;
	INTEGER lDistanceToMove,;
	INTEGER pReserved,;
	INTEGER dwMoveMethod,;
	INTEGER dwContext  
```  
***  


## Parameters:
hFile
[in] Valid HINTERNET handle returned from a previous call to InternetOpenUrl, or HttpOpenRequest.

lDistanceToMove
[in] Integer of type LONG that specifies the number of bytes to move the file pointer. A positive value moves the pointer forward in the file; a negative value moves it backward.

pReserved
[in] Reserved. Must be set to NULL.

dwMoveMethod
[in] Unsigned long integer value that indicates the starting point for the file pointer move -- a predefined value.

dwContext
[in] Reserved. Must be set to 0.
  
***  


## Return value:
Returns the current file position if the function succeeds, or -1 otherwise.  
***  

