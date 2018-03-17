<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : NetGetJoinInformation
Group: Windows Networking - Library: netapi32    
***  


#### The NetGetJoinInformation function retrieves join status information for the specified computer.
***  


## Code examples:
[Retrieving the name of the primary domain controller (PDC) and join status information](../../samples/sample_166.md)  

## Declaration:
```foxpro  
NET_API_STATUS NetGetJoinInformation(
  LPCWSTR lpServer,
  LPWSTR* lpNameBuffer,
  PNETSETUP_JOIN_STATUS BufferType
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER NetGetJoinInformation IN netapi32;
	STRING    lpServer,;
	INTEGER @ lpNameBuffer,;
	INTEGER @ BufferType  
```  
***  


## Parameters:
```txt  
lpServer
[in] Pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to call the function. If this parameter is NULL, the local computer is used.

lpNameBuffer
[out] Pointer to the buffer that receives the NetBIOS name of the domain or workgroup to which the computer is joined.

BufferType
[out] Receives the join status of the specified computer: <Em>unknown, unjoined, workgroup, domain</Em>  
```  
***  


## Return value:
If the function succeeds, the return value is NERR_Success (0).  
***  


## Comments:
The <Em>lpNameBuffer</Em> buffer is allocated by the system and must be freed using the NetApiBufferFree function.  
  
Regularly this function returns either domain name or workgroup name for selected computer.  
  
***  

