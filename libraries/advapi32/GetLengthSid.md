[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetLengthSid
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The GetLengthSid function returns the length, in bytes, of a valid security identifier (SID).
***  


## Code examples:
[Obtaining a handle to the desktop associated with the calling thread](../../samples/sample_239.md)  
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  

## Declaration:
```foxpro  
DWORD GetLengthSid(
  PSID pSid
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetLengthSid IN advapi32;
	STRING pSid  
```  
***  


## Parameters:
pSid 
[in] Pointer to the SID structure whose length is returned.   
***  


## Return value:
If the SID structure is valid, the return value is the length, in bytes, of the SID structure.  
***  

