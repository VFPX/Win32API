<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUdpTable
Group: IP Helper - Library: iphlpapi    
***  


#### The GetUdpTable function retrieves the User Datagram Protocol (UDP) listener table.
***  


## Code examples:
[Retrieving the User Datagram Protocol (UDP) listener table](../../samples/sample_234.md)  

## Declaration:
```foxpro  
DWORD GetUdpTable(
  PMIB_UDPTABLE pUdpTable,  // buffer for the listener table
  PDWORD pdwSize,           // size of buffer
  BOOL bOrder               // sort the table?
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUdpTable IN iphlpapi;
	STRING  @ pUdpTable,;
	INTEGER @ pdwSize,;
	INTEGER   bOrder  
```  
***  


## Parameters:
```txt  
pUdpTable
[out] Pointer to a buffer that receives the UDP listener table as a MIB_UDPTABLE structure.

pdwSize
[in, out] Specifies the size of the buffer pointed to by the pUdpTable parameter.

bOrder
[in] Specifies whether the returned table should be sorted.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  

