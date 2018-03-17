<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnloadUserProfile
Group: Shell Functions - Library: userenv    
***  


#### Unloads a user"s profile that was loaded by the LoadUserProfile function.
***  


## Code examples:
[How to load a user profile](../../samples/sample_602.md)  

## Declaration:
```foxpro  
BOOL WINAPI UnloadUserProfile(
  _In_  HANDLE hToken,
  _In_  HANDLE hProfile
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE UnloadUserProfile IN userenv;
	INTEGER hToken,;
	INTEGER hProfile  
```  
***  


## Parameters:
```txt  
hToken [in]
Type: HANDLE
Token for the user, returned from the LogonUser, CreateRestrictedToken, DuplicateToken, OpenProcessToken, or OpenThreadToken function.

hProfile [in]
Type: HANDLE
Handle to the registry key. This value is the hProfile member of the PROFILEINFO structure.  
```  
***  


## Return value:
TRUE if successful; otherwise, FALSE.  
***  


## Comments:
Before calling UnloadUserProfile you should ensure that all handles to keys that you have opened in the user"s registry hive are closed. If you do not close all open registry handles, the user"s profile fails to unload.  
  
See also: LoadUserProfile   
  
***  

