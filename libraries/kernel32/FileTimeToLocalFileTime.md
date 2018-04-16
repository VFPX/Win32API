[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FileTimeToLocalFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The FileTimeToLocalFileTime function converts a file time to a local file time.
***  


## Code examples:
[HOWTO: Use the Win32 API to Access File Dates and Times](../../samples/sample_177.md)  

## Declaration:
```foxpro  
BOOL FileTimeToLocalFileTime(
  CONST FILETIME *lpFileTime,  // UTC file time to convert
  LPFILETIME lpLocalFileTime   // converted file time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FileTimeToLocalFileTime IN kernel32;
	STRING   lpFileTime,;
	STRING @ lpLocalFileTime  
```  
***  


## Parameters:
lpFileTime 
[in] Pointer to a FILETIME structure containing the UTC-based file time to be converted into a local file time. 

lpLocalFileTime 
[out] Pointer to a FILETIME structure to receive the converted local file time.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
```cpp
typedef struct _FILETIME {   
    DWORD dwLowDateTime;   
    DWORD dwHighDateTime;   
} FILETIME, *PFILETIME; // 8 bytes
```
  
  
***  

