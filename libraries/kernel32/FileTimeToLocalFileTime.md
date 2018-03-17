<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FileTimeToLocalFileTime
Group: Time - Library: kernel32    
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
```txt  
lpFileTime
[in] Pointer to a FILETIME structure containing the UTC-based file time to be converted into a local file time.

lpLocalFileTime
[out] Pointer to a FILETIME structure to receive the converted local file time.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
typedef struct _FILETIME {   
    DWORD dwLowDateTime;   
    DWORD dwHighDateTime;   
} FILETIME, *PFILETIME; // 8 bytes  
  
***  

