[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : AdjustTokenPrivileges
Group: [Authorization](../../functions_group.md#Authorization)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Enables or disables privileges in the specified access token.
***  


## Code examples:
[How to enable the SE_SHUTDOWN_NAME privilege for the application](../../samples/sample_552.md)  
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL WINAPI AdjustTokenPrivileges(
  __in       HANDLE TokenHandle,
  __in       BOOL DisableAllPrivileges,
  __in_opt   PTOKEN_PRIVILEGES NewState,
  __in       DWORD BufferLength,
  __out_opt  PTOKEN_PRIVILEGES PreviousState,
  __out_opt  PDWORD ReturnLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER AdjustTokenPrivileges IN advapi32;
	INTEGER TokenHandle,;
	INTEGER DisableAllPrivileges,;
	STRING @NewState,;
	LONG BufferLength,;
	INTEGER PreviousState,;
	INTEGER ReturnLength  
```  
***  


## Parameters:
TokenHandle [in]
A handle to the access token that contains the privileges to be modified. The handle must have TOKEN_ADJUST_PRIVILEGES access to the token.

DisableAllPrivileges [in]
Specifies whether the function disables all of the token"s privileges.

NewState [in, optional]
A pointer to a TOKEN_PRIVILEGES structure that specifies an array of privileges and their attributes.

BufferLength [in]
Specifies the size, in bytes, of the buffer pointed to by the PreviousState parameter.

PreviousState [out, optional]
A pointer to a buffer that the function fills with a TOKEN_PRIVILEGES structure that contains the previous state of any privileges that the function modifies. 

ReturnLength [out, optional]
A pointer to a variable that receives the required size, in bytes, of the buffer pointed to by the PreviousState parameter.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Enabling or disabling privileges in an access token requires TOKEN_ADJUST_PRIVILEGES access.  
  
See also: [OpenProcessToken](../advapi32/OpenProcessToken.md), [GetTokenInformation](../advapi32/GetTokenInformation.md).  
  
***  

