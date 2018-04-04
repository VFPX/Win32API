[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LookupAccountName
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Accepts the name of a system and an account as input. It retrieves a security identifier (SID) for the account and the name of the domain on which the account was found.

***  


## Code examples:
[Retrieving local computer and user names](../../samples/sample_041.md)  

## Declaration:
```foxpro  
BOOL LookupAccountName(
  LPCTSTR lpSystemName,
  LPCTSTR lpAccountName,
  PSID Sid,
  LPDWORD cbSid,
  LPTSTR ReferencedDomainName,
  LPDWORD cchReferencedDomainName,
  PSID_NAME_USE peUse
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LookupAccountName IN advapi32;
	STRING lpSystemName,;
	STRING lpAccountName,;
	INTEGER Sid,;
	INTEGER @cbSid,;
	STRING @RefDomainName,;
	INTEGER @cchRefDomainName,;
	INTEGER @peUse  
```  
***  


## Parameters:
lpSystemName 
[in] Pointer to a null-terminated character string that specifies the name of the system.

lpAccountName 
[in] Pointer to a null-terminated string that specifies the account name.

Sid 
[out] Pointer to a buffer that receives the SID structure that corresponds to the account name pointed to by the lpAccountName parameter.

cbSid 
[in, out] Pointer to a variable. On input, this value specifies the size, in bytes, of the Sid buffer.

ReferencedDomainName 
[out] Pointer to a buffer that receives the name of the domain where the account name is found.

cchReferencedDomainName 
[in, out] Pointer to a variable. On input, this value specifies the size, in TCHARs, of the ReferencedDomainName buffer.

peUse 
[out] Pointer to a SID_NAME_USE enumerated type that indicates the type of the account when the function returns.  
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  


## Comments:
This function attempts to find a SID for the specified name by first checking a list of well-known SIDs. If the name does not correspond to a well-known SID, the function checks built-in and administratively defined local accounts. Next, the function checks the primary domain. If the name is not found there, trusted domains are checked.  
  
***  

