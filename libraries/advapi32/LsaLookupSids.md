<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LsaLookupSids
Group: Security - Library: advapi32    
***  


#### The LsaLookupSids function looks up the names that correspond to an array of SIDs.
***  


## Code examples:
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  

## Declaration:
```foxpro  
NTSTATUS LsaLookupSids(
  LSA_HANDLE PolicyHandle,
  ULONG Count,
  PSID* Sids,
  PLSA_REFERENCED_DOMAIN_LIST* ReferencedDomains,
  PLSA_TRANSLATED_NAME* Names
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaLookupSids IN advapi32;
	INTEGER   PolicyHandle,;
	INTEGER   nCount,;
	INTEGER   Sids,;
	INTEGER @ ReferencedDomains,;
	INTEGER @ Names
  
```  
***  


## Parameters:
```txt  
PolicyHandle
[in] Handle to a Policy object. This handle must have the POLICY_LOOKUP_NAMES access right.

Count
[in] Specifies the number of SIDs in the Sids array.

Sids
[in] Pointer to an array of SID pointers to look up.

ReferencedDomains
[out] Receives a pointer to an LSA_REFERENCED_DOMAIN_LIST structure.

Names
[out] Receives a pointer to an array of LSA_TRANSLATED_NAME structures.  
```  
***  


## Return value:
If the function succeeds, the return value is a NTSTATUS value.  
***  

