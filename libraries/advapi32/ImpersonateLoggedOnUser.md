[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ImpersonateLoggedOnUser
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The ImpersonateLoggedOnUser function lets the calling thread impersonate the security context of a logged-on user. The user is represented by a token handle.
***  


## Code examples:
[How to run FoxPro application under different user name (impersonating user)](../../samples/sample_470.md)  

## Declaration:
```foxpro  
BOOL ImpersonateLoggedOnUser(
  HANDLE hToken
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ImpersonateLoggedOnUser IN advapi32;
	INTEGER hToken  
```  
***  


## Parameters:
hToken 
[in] Handle to a primary or impersonation access token that represents a logged-on user.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
<Em>hToken</Em> can be a token handle returned by a call to LogonUser, CreateRestrictedToken, DuplicateToken, DuplicateTokenEx, OpenProcessToken, or OpenThreadToken functions.  
  
***  

