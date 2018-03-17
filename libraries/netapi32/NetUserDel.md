<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : NetUserDel
Group: Network Management - Library: netapi32    
***  


#### Deletes a user account from a server.
***  


## Code examples:
[Adding and deleting User Accounts](../../samples/sample_478.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUserDel(
  LPCWSTR servername,
  LPCWSTR username
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUserDel IN netapi32;
	STRING servername,;
	STRING username
  
```  
***  


## Parameters:
```txt  
servername
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is NULL, the local computer is used.

username
[in] Pointer to a constant string that specifies the name of the user account to delete.  
```  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Windows NT:  This <Em>servername</Em> must begin with \\.   
  
Only members of the Administrators or the Account Operators local group can successfully execute NetUserDel on a remote server or on a computer that has local security enabled. Only members of the Administrators local group can delete an Administrators privilege account.  
  
See also: NetUserAdd, NetUserEnum, NetUserSetInfo.  
  
***  

