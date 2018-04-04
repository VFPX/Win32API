[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetEnvironmentVariable
Group: [Process and Thread](../../functions_group.md#Process_and_Thread)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the value of the specified variable from the environment block of the calling process. The value is in the form of a null-terminated string of characters.
***  


## Code examples:
[Reading and setting Environment variables](../../samples/sample_152.md)  

## Declaration:
```foxpro  
DWORD GetEnvironmentVariable(
  LPCTSTR lpName,  // environment variable name
  LPTSTR lpBuffer, // buffer for variable value
  DWORD nSize      // size of buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetEnvironmentVariable IN kernel32;
	STRING   lpName,;
	STRING @ lpBuffer,;
	INTEGER  nSize  
```  
***  


## Parameters:
lpName 
[in] Pointer to a null-terminated string that specifies the environment variable. 

lpBuffer 
[out] Pointer to a buffer to receive the value of the specified environment variable. 

nSize 
[in] Specifies the size, in TCHARs, of the buffer pointed to by the lpBuffer parameter.  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs stored into the buffer pointed to by lpBuffer, not including the terminating null character.  
***  

