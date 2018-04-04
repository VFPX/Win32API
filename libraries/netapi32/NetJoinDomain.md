[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : NetJoinDomain
Group: [Windows Networking](../../functions_group.md#Windows_Networking)  -  Library: [netapi32](../../Libraries.md#netapi32)  
***  


#### The NetJoinDomain function joins a computer to a workgroup or domain.

***  


## Code examples:
[Joining local computer to a domain (XP/2000)](../../samples/sample_439.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetJoinDomain(
  LPCWSTR lpServer,
  LPCWSTR lpDomain,
  LPCWSTR lpAccountOU,
  LPCWSTR lpAccount,
  LPCWSTR lpPassword,
  DWORD fJoinOptions
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetJoinDomain IN netapi32;
	STRING  lpServer,;
	STRING  lpDomain,;
	STRING  lpAccountOU,;
	STRING  lpAccount,;
	STRING  lpPassword,;
	INTEGER fJoinOptions  
```  
***  


## Parameters:
lpServer 
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to call the function.

lpDomain 
[in] Pointer to a constant null-terminated character string that specifies the name of the domain or workgroup to join. 

lpAccountOU 
[in] Optionally specifies the pointer to a constant null-terminated character string that contains the RFC 1779 format name of the organizational unit (OU) for the computer account.

lpAccount 
[in] Pointer to a constant null-terminated character string that specifies the account name to use when connecting to the domain controller. 

lpPassword 
[in] If the lpAccount parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller.

fJoinOptions 
[in] Specifies a value that contains a set of bit flags defining the join options.  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
Joining (and unjoining) a computer to a domain or workgroup can be performed only by a member of the Administrators local group on the target computer.   
  
***  

