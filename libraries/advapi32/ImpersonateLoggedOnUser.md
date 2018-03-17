<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ImpersonateLoggedOnUser
Group: Security - Library: advapi32    
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
```txt  
hToken
[in] Handle to a primary or impersonation access token that represents a logged-on user.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
<Em>hToken</Em> can be a token handle returned by a call to LogonUser, CreateRestrictedToken, DuplicateToken, DuplicateTokenEx, OpenProcessToken, or OpenThreadToken functions.  
  
***  

