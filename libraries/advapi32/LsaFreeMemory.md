<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LsaFreeMemory
Group: Security - Library: advapi32    
***  


#### The LsaFreeMemory function frees memory allocated for an output buffer by an LSA function call.
***  


## Code examples:
[Accessing LSA Policy object (Local Security Authority)](../../samples/sample_427.md)  

## Declaration:
```foxpro  
NTSTATUS LsaFreeMemory(
  PVOID Buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaFreeMemory IN advapi32;
	INTEGER Buffer  
```  
***  


## Parameters:
```txt  
Buffer
[in] Pointer to memory buffer that was allocated by an LSA function call.  
```  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS (0).  
***  

