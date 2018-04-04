[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LsaFreeReturnBuffer
Group: [Security](../../functions_group.md#Security)  -  Library: [secur32](../../Libraries.md#secur32)  
***  


#### Frees the memory used by a buffer previously allocated by the LSA.
***  


## Code examples:
[How to enumerate logon sessions on local computer](../../samples/sample_591.md)  

## Declaration:
```foxpro  
NTSTATUS LsaFreeReturnBuffer(
  _In_  PVOID Buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LsaFreeReturnBuffer IN secur32;
	INTEGER Buffer  
```  
***  


## Parameters:
Buffer [in]
Pointer to the buffer to be freed.  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS.  
***  


## Comments:
The LsaNtStatusToWinError function converts an NTSTATUS code to a Windows error code.  
  
***  

