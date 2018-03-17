<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetLengthSid
Group: Security - Library: advapi32    
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
```txt  
pSid
[in] Pointer to the SID structure whose length is returned.  
```  
***  


## Return value:
If the SID structure is valid, the return value is the length, in bytes, of the SID structure.  
***  

