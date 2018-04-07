[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetUserSetInfo
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Sets the parameters of a user account.

***  


## Code examples:
[Adding and deleting User Accounts](../../samples/sample_478.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserSetInfo(
  LPCWSTR servername,
  LPCWSTR username,
  DWORD level,
  LPBYTE buf,
  LPDWORD parm_err
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserSetInfo IN netapi32;
	STRING    servername,;
	STRING    username,;
	INTEGER   lvl,;
	STRING  @ buf,;
	INTEGER   parm_err
  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

username 
[in] Pointer to a constant string that specifies the name of the user account for which to set information.

level 
[in] Specifies the information level of the data.

buf 
[in] Pointer to the buffer that specifies the data. The format of this data depends on the value of the level parameter. 

parm_err 
[out] Pointer to a value that receives the index of the first member of the user information structure that causes ERROR_INVALID_PARAMETER.   
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Only users or applications having administrative privileges can call the NetUserSetInfo function to change a user"s password.   
  
See also: [NetUserGetInfo](../netapi32/NetUserGetInfo.md), [NetUserAdd](../netapi32/NetUserAdd.md), [NetUserDel](../netapi32/NetUserDel.md), [NetUserChangePassword](../netapi32/NetUserChangePassword.md).  
  
***  

