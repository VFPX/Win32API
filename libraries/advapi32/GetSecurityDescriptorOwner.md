[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetSecurityDescriptorOwner
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The GetSecurityDescriptorOwner function retrieves the owner information from a security descriptor.
***  


## Code examples:
[GetFileOwner - Get the owner of an NTFS file](../../samples/sample_433.md)  

## Declaration:
```foxpro  
BOOL GetSecurityDescriptorOwner(
  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  PSID* pOwner,
  LPBOOL lpbOwnerDefaulted
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSecurityDescriptorOwner IN advapi32;
	STRING  @ pSecurityDescriptor,;
	INTEGER @ pOwner,;
	INTEGER @ lpbOwnerDefaulted
  
```  
***  


## Parameters:
pSecurityDescriptor 
[in] Pointer to a SECURITY_DESCRIPTOR structure whose owner information the function retrieves. 

pOwner 
[out] Pointer to a pointer to a SID identifying the owner when the function returns. 

lpbOwnerDefaulted 
[out] Pointer to a flag set to the value of the SE_OWNER_DEFAULTED flag in the SECURITY_DESCRIPTOR_CONTROL structure when the function returns.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
If the function fails, the return value is zero. To get extended error information, call GetLastError.  
  
***  

