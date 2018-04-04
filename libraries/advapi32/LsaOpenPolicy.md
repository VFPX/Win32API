[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LsaOpenPolicy
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The LsaOpenPolicy function opens a handle to the Policy object on a local or remote system.
***  


## Code examples:
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  

## Declaration:
```foxpro  
NTSTATUS LsaOpenPolicy(
  PLSA_UNICODE_STRING SystemName,
  PLSA_OBJECT_ATTRIBUTES ObjectAttributes,
  ACCESS_MASK DesiredAccess,
  PLSA_HANDLE PolicyHandle
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaOpenPolicy IN advapi32;
	STRING    SystemName,;
	STRING  @ ObjectAttributes,;
	INTEGER   DesiredAccess,;
	INTEGER @ PolicyHandle
  
```  
***  


## Parameters:
SystemName 
[in] Pointer to an LSA_UNICODE_STRING structure containing the name of the target system.

ObjectAttributes 
[in] Pointer to an LSA_OBJECT_ATTRIBUTES structure that specifies the connection attributes.

DesiredAccess 
[in] An access mask that specifies the requested access rights.

PolicyHandle 
[in, out] Pointer to an LSA_HANDLE variable that receives a handle to the Policy object.  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS (0).  
***  

