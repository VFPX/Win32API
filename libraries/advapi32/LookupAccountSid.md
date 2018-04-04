[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LookupAccountSid
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The LookupAccountSid function accepts a security identifier (SID) as input. It retrieves the name of the account for this SID and the name of the first domain on which this SID is found.
***  


## Code examples:
[GetFileOwner - Get the owner of an NTFS file](../../samples/sample_433.md)  
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  
[How to enumerate sessions and processes on a specified terminal server](../../samples/sample_519.md)  

## Declaration:
```foxpro  
BOOL LookupAccountSid(
  LPCTSTR lpSystemName,
  PSID lpSid,
  LPTSTR lpName,
  LPDWORD cchName,
  LPTSTR lpReferencedDomainName,
  LPDWORD cchReferencedDomainName,
  PSID_NAME_USE peUse
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LookupAccountSid IN advapi32;
	STRING  @ lpSystemName,;
	INTEGER   lpSid,;
	STRING  @ lpName,;
	INTEGER @ cchName,;
	STRING  @ lpRefdDomain,;
	INTEGER @ cchRefdDomain,;
	INTEGER @ peUse
  
```  
***  


## Parameters:
lpSystemName 
[in] Pointer to a null-terminated character string that specifies the target computer.

lpSid 
[in] Pointer to the SID to look up. 

lpName 
[out] Pointer to a buffer that receives a null-terminated string that contains the account name that corresponds to the lpSid parameter.

cchName 
[in, out] On input, specifies the size, in TCHARs, of the lpName buffer.

cchReferencedDomainName 
[in, out] On input, specifies the size, in TCHARs, of the lpReferencedDomainName buffer.

peUse 
[out] Pointer to a variable that indicates the type of the account.  
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  


## Comments:
If the function fails, it returns zero. To get extended error information, call GetLastError.  
  
***  

