[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LogonUser
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The LogonUser function attempts to log a user on to the local computer. The local computer is the computer from which LogonUser was called. You cannot use LogonUser to log on to a remote computer. 
***  


## Code examples:
[How to Start a Process as Another User (NT/XP/2K)](../../samples/sample_426.md)  
[How to run FoxPro application under different user name (impersonating user)](../../samples/sample_470.md)  
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL LogonUser(
  LPTSTR lpszUsername,
  LPTSTR lpszDomain,
  LPTSTR lpszPassword,
  DWORD dwLogonType,
  DWORD dwLogonProvider,
  PHANDLE phToken
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LogonUser IN advapi32;
	STRING    lpszUsername,;
	STRING    lpszDomain,;
	STRING    lpszPassword,;
	INTEGER   dwLogonType,;
	INTEGER   dwLogonProvider,;
	INTEGER @ phToken
  
```  
***  


## Parameters:
lpszUsername 
[in] Pointer to a null-terminated string that specifies the name of the user.

lpszDomain 
[in] Pointer to a null-terminated string that specifies the name of the domain or server whose account database contains the lpszUsername account.

lpszPassword 
[in] Pointer to a null-terminated string that specifies the clear-text password for the user account specified by lpszUsername.

dwLogonType 
[in] Specifies the type of logon operation to perform. 

dwLogonProvider 
[in] Specifies the logon provider.

phToken 
[out] Pointer to a handle variable that receives a handle to a token that represents the specified user.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

