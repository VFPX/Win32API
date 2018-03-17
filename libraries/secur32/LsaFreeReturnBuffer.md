<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : LsaFreeReturnBuffer
Group: Security - Library: secur32    
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
```txt  
Buffer [in]
Pointer to the buffer to be freed.  
```  
***  


## Return value:
If the function succeeds, the return value is STATUS_SUCCESS.  
***  


## Comments:
The LsaNtStatusToWinError function converts an NTSTATUS code to a Windows error code.  
  
***  

