<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetEnvironmentVariable
Group: Process and Thread - Library: kernel32    
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
```txt  
lpName
[in] Pointer to a null-terminated string that specifies the environment variable.

lpBuffer
[out] Pointer to a buffer to receive the value of the specified environment variable.

nSize
[in] Specifies the size, in TCHARs, of the buffer pointed to by the lpBuffer parameter.  
```  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs stored into the buffer pointed to by lpBuffer, not including the terminating null character.  
***  

