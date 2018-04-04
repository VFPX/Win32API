[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetNamedSecurityInfo
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The GetNamedSecurityInfo function retrieves a copy of the security descriptor for an object specified by name.
***  


## Code examples:
[GetFileOwner - Get the owner of an NTFS file](../../samples/sample_433.md)  

## Declaration:
```foxpro  
DWORD GetNamedSecurityInfo(
  LPTSTR pObjectName,
  SE_OBJECT_TYPE ObjectType,
  SECURITY_INFORMATION SecurityInfo,
  PSID* ppsidOwner,
  PSID* ppsidGroup,
  PACL* ppDacl,
  PACL* ppSacl,
  PSECURITY_DESCRIPTOR* ppSecurityDescriptor
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetNamedSecurityInfo IN advapi32;
	STRING    pObjectName,;
	INTEGER   ObjectType,;
	INTEGER   SecurityInfo,;
	INTEGER   ppsidOwner,;
	INTEGER   ppsidGroup,;
	INTEGER   ppDacl,;
	INTEGER   ppSacl,;
	INTEGER @ ppSecurityDescriptor
  
```  
***  


## Parameters:
pObjectName 
[in] Pointer to a null-terminated string that specifies the name of the object from which to retrieve security information.

ObjectType 
[in] Specifies a value from the SE_OBJECT_TYPE enumeration that indicates the type of object named by the pObjectName parameter. 

SecurityInfo 
[in] A set of SECURITY_INFORMATION bit flags that indicate the type of security information to retrieve.

ppsidOwner 
[out] Pointer to a variable that receives a pointer to the owner SID in the security descriptor returned in ppSecurityDescriptor.

ppsidGroup 
[out] Pointer to a variable that receives a pointer to the primary group SID in the returned security descriptor.

ppDacl 
[out] Pointer to a variable that receives a pointer to the DACL in the returned security descriptor.

ppSacl 
[out] Pointer to a variable that receives a pointer to the SACL in the returned security descriptor.

ppSecurityDescriptor 
[out] Pointer to a variable that receives a pointer to the security descriptor of the object.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
When you have finished using the <Em>ppSecurityDescriptor</Em> pointer, free the returned buffer by calling the LocalFree function.   
  
If the <Em>ppsidOwner</Em>, <Em>ppsidGroup</Em>, <Em>ppDacl</Em>, and <Em>ppSacl</Em> parameters are non-NULL, and the <Em>SecurityInfo</Em> parameter specifies that they be retrieved from the object, those parameters will point to the corresponding parameters in the security descriptor returned in <Em>ppSecurityDescriptor</Em>.  
  
***  

