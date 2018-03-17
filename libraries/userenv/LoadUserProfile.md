<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LoadUserProfile
Group: Shell Functions - Library: userenv    
***  


#### Loads the specified user"s profile. The profile can be a local user profile or a roaming user profile.
***  


## Code examples:
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL WINAPI LoadUserProfile(
  _In_     HANDLE hToken,
  _Inout_  LPPROFILEINFO lpProfileInfo
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadUserProfile IN userenv;
	INTEGER hToken,;
	INTEGER lpProfileInfo  
```  
***  


## Parameters:
```txt  
hToken [in]
Type: HANDLE
Token for the user, which is returned by the LogonUser, CreateRestrictedToken, DuplicateToken, OpenProcessToken, or OpenThreadToken function.

lpProfileInfo [in, out]
Type: LPPROFILEINFO
Pointer to a PROFILEINFO structure.  
```  
***  


## Return value:
TRUE if successful; otherwise, FALSE.   
***  


## Comments:
LoadUserProfile fails and returns ERROR_INVALID_PARAMETER if the dwSize member of the structure is not set to sizeof(PROFILEINFO) or if the lpUserName member is NULL.  
  
See also: UnloadUserProfile   
  
***  

