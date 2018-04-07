[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetCurrentDirectory
Group: [File Management](../../functions_group.md#File_Management)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetCurrentDirectory function retrieves the current directory for the current process.

***  


## Code examples:
[Current directory of the application](../../samples/sample_004.md)  

## Declaration:
```foxpro  
DWORD GetCurrentDirectory(
  DWORD nBufferLength,  // size of directory buffer
  LPTSTR lpBuffer       // directory buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCurrentDirectory IN kernel32;
	INTEGER   nBufferLength,;
	STRING  @ lpBuffer
  
```  
***  


## Parameters:
nBufferLength 
[in] Specifies the length, in TCHARs, of the buffer for the current directory string. The buffer length must include room for a terminating null character. 

lpBuffer 
[out] Pointer to the buffer that receives the current directory string. This null-terminated string specifies the absolute path to the current directory.  
***  


## Return value:
If the function succeeds, the return value specifies the number of characters written to the buffer, not including the terminating null character  
***  


## Comments:
The difference between this function and SYS(2003) is next to negligible if any.  
  
See also: [SetCurrentDirectory](../kernel32/SetCurrentDirectory.md), [GetFullPathName](../kernel32/GetFullPathName.md).  
  
***  

