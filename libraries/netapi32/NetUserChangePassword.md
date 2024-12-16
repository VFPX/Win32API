[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetUserChangePassword
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Changes user's password for a specified network server or domain.

***  


## Declaration:
```foxpro  
NET_API_STATUS NetUserChangePassword(
  LPCWSTR domainname,
  LPCWSTR username,
  LPCWSTR oldpassword,
  LPCWSTR newpassword
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserChangePassword IN netapi32;
	STRING domainname,;
	STRING username,;
	STRING oldpassword,;
	STRING newpassword

  
```  
***  


## Parameters:
domainname 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of a remote server or domain on which the function is to execute. If this parameter is NULL, the logon domain of the caller is used. 

username 
[in] Pointer to a constant string that specifies a user name. The NetUserChangePassword function changes the password for the specified user.

oldpassword 
[in] Pointer to a constant string that specifies the user"s old password. 

newpassword 
[in] Pointer to a constant string that specifies the user"s new password.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
For this function as for other NetUser functions, convert string input parameters to Unicode. Requires Windows XP, Windows 2000 Professional, or Windows NT Workstation.   
  
The NetUserSetInfo can change passwords too when called with levels 21 and 1003.  
  
See also: [NetUserSetInfo](../netapi32/NetUserSetInfo.md), [NetUserGetInfo](../netapi32/NetUserGetInfo.md).  
  
***  

