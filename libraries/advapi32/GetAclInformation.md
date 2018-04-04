[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetAclInformation
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### Retrieves information about an access control list (ACL).

***  


## Code examples:
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
BOOL GetAclInformation(
	PACL pAcl,
	LPVOID pAclInformation,
	DWORD nAclInformationLength,
	ACL_INFORMATION_CLASS dwAclInformationClass
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetAclInformation IN advapi32;
	INTEGER pAcl,;
	STRING @pAclInformation,;
	LONG nAclInfoLen,;
	INTEGER dwAclInfoClass  
```  
***  


## Parameters:
pAcl 
[in] A pointer to an ACL. The function retrieves information about this ACL. 

pAclInformation 
[out] A pointer to a buffer to receive the requested information.

nAclInformationLength 
[in] The size, in bytes, of the buffer pointed to by the pAclInformation parameter. 

dwAclInformationClass 
[in] A value of the ACL_INFORMATION_CLASS enumeration that indicates the class of information requested.   
***  


## Return value:
If the function succeeds, the function returns nonzero.  
***  

