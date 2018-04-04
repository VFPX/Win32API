[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LsaClose
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The LsaClose function closes a handle to a Policy or TrustedDomain object.
***  


## Code examples:
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  

## Declaration:
```foxpro  
NTSTATUS LsaClose(
  LSA_HANDLE ObjectHandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaClose IN advapi32;
	INTEGER ObjectHandle  
```  
***  


## Parameters:
ObjectHandle 
Handle to a Policy object returned by the LsaOpenPolicy function or to a TrustedDomain object returned by the LsaOpenTrustedDomainByName function.  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS (0).  
***  

