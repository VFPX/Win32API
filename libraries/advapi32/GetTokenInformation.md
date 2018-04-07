[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTokenInformation
Group: [Authorization](../../functions_group.md#Authorization)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves a specified type of information about an access token.
***  


## Code examples:
[Reading and setting system access privileges for the current process](../../samples/sample_554.md)  

## Declaration:
```foxpro  
BOOL WINAPI GetTokenInformation(
  __in       HANDLE TokenHandle,
  __in       TOKEN_INFORMATION_CLASS TokenInformationClass,
  __out_opt  LPVOID TokenInformation,
  __in       DWORD TokenInformationLength,
  __out      PDWORD ReturnLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTokenInformation IN advapi32;
	INTEGER TokenHandle,;
	INTEGER TokenInformationClass,;
	STRING @TokenInformation,;
	LONG TokenInformationLength,;
	LONG @ReturnLength  
```  
***  


## Parameters:
TokenHandle [in]
A handle to an access token from which information is retrieved.

TokenInformationClass [in]
Specifies a value from the TOKEN_INFORMATION_CLASS enumerated type to identify the type of information the function retrieves.

TokenInformation [out, optional]
A pointer to a buffer the function fills with the requested information.

TokenInformationLength [in]
Specifies the size, in bytes, of the buffer pointed to by the TokenInformation parameter.

ReturnLength [out]
A pointer to a variable that receives the number of bytes needed for the buffer pointed to by the TokenInformation parameter.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
An access token contains the security information for a logon session. The system creates an access token when a user logs on, and every process executed on behalf of the user has a copy of the token.   
  
The token identifies the user, the user"s groups, and the user"s privileges.  
  
See also: [OpenProcessToken](../advapi32/OpenProcessToken.md).  
  
***  

