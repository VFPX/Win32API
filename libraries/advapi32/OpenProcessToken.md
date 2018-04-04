[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenProcessToken
Group: [Authorization](../../functions_group.md#Authorization)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Opens the access token associated with a process.
***  


## Code examples:
[How to enable the SE_SHUTDOWN_NAME privilege for the application](../../samples/sample_552.md)  
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL WINAPI OpenProcessToken(
  __in   HANDLE ProcessHandle,
  __in   DWORD DesiredAccess,
  __out  PHANDLE TokenHandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenProcessToken IN advapi32;
	INTEGER ProcessHandle,;
	LONG DesiredAccess,;
	INTEGER @TokenHandle  
```  
***  


## Parameters:
ProcessHandle [in]
A handle to the process whose access token is opened.

DesiredAccess [in]
Specifies an access mask that specifies the requested types of access to the access token.

TokenHandle [out]
A pointer to a handle that identifies the newly opened access token when the function returns.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The process must have the PROCESS_QUERY_INFORMATION access permission.  
  
Close the access token handle returned through the TokenHandle parameter by calling CloseHandle.  
  
***  

