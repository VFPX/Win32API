[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetUserAdd
Group: [Network Management](../../functions_group.md#Network_Management)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### Adds a user account and assigns a password and privilege level.

***  


## Code examples:
[Adding and deleting User Accounts](../../samples/sample_478.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserAdd(
  LMSTR servername,
  DWORD level,
  LPBYTE buf,
  LPDWORD parm_err
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserAdd IN netapi32;
	STRING    servername,;
	INTEGER   lvl,;
	STRING  @ buf,;
	INTEGER   parm_err
  
```  
***  


## Parameters:
servername 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

level 
[in] Specifies the information level of the data (1..4). 

buf 
[in] Pointer to the buffer that specifies the data.

parm_err 
[out] Pointer to a value that receives the index of the first member of the user information structure that causes ERROR_INVALID_PARAMETER.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Windows NT:  Only members of the Administrators or Account Operators local group can successfully execute the NetUserAdd function. Only members of the Administrators local group can add an Administrators privilege account.  
  
See also: [NetUserEnum](../netapi32/NetUserEnum.md), [NetUserSetInfo](../netapi32/NetUserSetInfo.md), [NetUserDel](../netapi32/NetUserDel.md).  
  
***  

