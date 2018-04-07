[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadUserProfile
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [userenv](../../Libraries.md#userenv)  
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
hToken [in]
Type: HANDLE
Token for the user, which is returned by the LogonUser, CreateRestrictedToken, DuplicateToken, OpenProcessToken, or OpenThreadToken function. 

lpProfileInfo [in, out]
Type: LPPROFILEINFO
Pointer to a PROFILEINFO structure.  
***  


## Return value:
TRUE if successful; otherwise, FALSE.   
***  


## Comments:
LoadUserProfile fails and returns ERROR_INVALID_PARAMETER if the dwSize member of the structure is not set to sizeof(PROFILEINFO) or if the lpUserName member is NULL.  
  
See also: [UnloadUserProfile](../userenv/UnloadUserProfile.md).  
  
***  

