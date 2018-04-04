[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LocalFileTimeToFileTime
Group: [Time](../../functions_group.md#Time)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Converts a local file time to a file time based on the Coordinated Universal Time (UTC).
***  


## Code examples:
[A procedure for setting file times](../../samples/sample_128.md)  
[How to suspend or hibernate your system](../../samples/sample_395.md)  
[How to set Creation Date/Time for a folder (WinNT)](../../samples/sample_399.md)  

## Declaration:
```foxpro  
BOOL LocalFileTimeToFileTime(
  CONST FILETIME *lpLocalFileTime,  // local file time
  LPFILETIME lpFileTime             // file time
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LocalFileTimeToFileTime IN kernel32;
	STRING LOCALFILETIME,;
	STRING @ FILETIME  
```  
***  


## Parameters:
lpLocalFileTime 
[in] Pointer to a FILETIME structure that specifies the local file time to be converted into a UTC-based file time. 

lpFileTime 
[out] Pointer to a FILETIME structure to receive the converted UTC-based file time. This parameter cannot be the same as the lpLocalFileTime parameter. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero. 
  
***  

