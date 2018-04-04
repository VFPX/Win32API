[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IsValidSid
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The IsValidSid function validates a security identifier (SID) by verifying that the revision number is within a known range, and that the number of subauthorities is less than the maximum.
***  


## Code examples:
[Obtaining a handle to the desktop associated with the calling thread](../../samples/sample_239.md)  
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  
[Reading security permissions for NTFS files and folders](../../samples/sample_516.md)  

## Declaration:
```foxpro  
BOOL IsValidSid(
  PSID pSid
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsValidSid IN advapi32;
	STRING pSid  
```  
***  


## Parameters:
pSid 
[in] Pointer to the SID structure to validate. This parameter cannot be NULL.   
***  


## Return value:
If the SID structure is valid, the return value is nonzero.  
***  

