[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetUnjoinDomain
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetUnjoinDomain function unjoins a computer from a workgroup or a domain.

***  


## Code examples:
[Joining local computer to a domain (XP/2000)](../../samples/sample_439.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetUnjoinDomain(
  LPCWSTR lpServer,
  LPCWSTR lpAccount,
  LPCWSTR lpPassword,
  DWORD fUnjoinOptions
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetUnjoinDomain IN netapi32;
	STRING  lpServer,;
	STRING  lpAccount,;
	STRING  lpPassword,;
	INTEGER fUnjoinOptions  
```  
***  


## Parameters:
lpServer 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which the function is to execute.

lpAccount 
[in] Pointer to a constant string that specifies the account name to use when connecting to the domain controller. 

lpPassword 
[in] If the lpAccount parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller.

fUnjoinOptions 
[in] Specifies the unjoin options. If this parameter is NETSETUP_ACCT_DELETE, the account is disabled when the unjoin occurs. Note that this option does not delete the account.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Unjoining (and joining) a computer to a domain or workgroup can be performed only by a member of the Administrators local group on the target computer.  
  
***  

