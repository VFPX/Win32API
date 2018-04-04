[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTempPath
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetTempPath function retrieves the path of the directory designated for temporary files
***  


## Code examples:
[Creating a unique filename based on existing filename](../../samples/sample_014.md)  
[Using the GetTempFileName](../../samples/sample_016.md)  
[Locking and unlocking file of a VFP table](../../samples/sample_154.md)  

## Declaration:
```foxpro  
DWORD GetTempPath(
  DWORD nBufferLength,  // size of buffer
  LPTSTR lpBuffer       // path buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTempPath IN kernel32;
	INTEGER   nBufferLength,;
	STRING  @ lpBuffer
  
```  
***  


## Parameters:
nBufferLength 
[in] Specifies the size, in TCHARs, of the string buffer identified by lpBuffer. 

lpBuffer 
[out] Pointer to a string buffer that receives the null-terminated string specifying the temporary file path. The returned string ends with a backslash, for example, C:\TEMP\.  
***  


## Return value:
If the function succeeds, the return value is the length of the string copied to lpBuffer, not including the terminating null character  
***  

