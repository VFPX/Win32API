<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetSecurityDescriptorDacl
Group: Security - Library: advapi32    
***  


#### Retrieves a pointer to the discretionary access control list (DACL) in a specified security descriptor.
***  


## Code examples:
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
BOOL GetSecurityDescriptorDacl(
	PSECURITY_DESCRIPTOR pSecurityDescriptor,
	LPBOOL lpbDaclPresent,
	PACL* pDacl,
	LPBOOL lpbDaclDefaulted
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetSecurityDescriptorDacl IN advapi32;
	INTEGER pSecurityDescriptor,;
	INTEGER @lpbDaclPresent,;
	INTEGER @pDacl,;
	INTEGER @lpbDaclDefaulted  
```  
***  


## Parameters:
```txt  
pSecurityDescriptor
[in] A pointer to the SECURITY_DESCRIPTOR structure that contains the DACL. The function retrieves a pointer to it.

lpbDaclPresent
[out] A pointer to a value that indicates the presence of a DACL in the specified security descriptor.

pDacl
[out] A pointer to a pointer to an access control list (ACL). If a DACL exists, the function sets the pointer pointed to by pDacl to the address of the security descriptor"s DACL.

lpbDaclDefaulted
[out] A pointer to a flag set to the value of the SE_DACL_DEFAULTED flag in the SECURITY_DESCRIPTOR_CONTROL structure if a DACL exists for the security descriptor.
  
```  
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  

