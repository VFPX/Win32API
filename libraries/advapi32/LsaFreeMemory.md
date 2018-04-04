[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LsaFreeMemory
Group: [Security](../../functions_group.md#Security)  -  Library: [advapi32](../../Libraries.md#advapi32)  
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
Buffer 
[in] Pointer to memory buffer that was allocated by an LSA function call.  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS (0).  
***  

