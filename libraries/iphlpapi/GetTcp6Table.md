<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTcp6Table
Group: IP Helper - Library: iphlpapi    
***  


#### Retrieves the TCP connection table for IPv6.
***  


## Declaration:
```foxpro  
ULONG WINAPI GetTcp6Table(
  __out    PMIB_TCP6TABLE TcpTable,
  __inout  PULONG SizePointer,
  __in     BOOL Order
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTcp6Table IN Iphlpapi;
	STRING @TcpTable,;
	LONG @SizePointer,;
	INTEGER IsSorted  
```  
***  


## Parameters:
```txt  
TcpTable
A pointer to a buffer that receives the TCP connection table for IPv6 as a MIB_TCP6TABLE structure.

SizePointer
On input, specifies the size in bytes of the buffer pointed to by the TcpTable parameter.

Order
A Boolean value that specifies whether the TCP connection table should be sorted.
  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  


## Comments:
Requires Windows Vista.  
  
See also: GetTcpTable   
  
***  

