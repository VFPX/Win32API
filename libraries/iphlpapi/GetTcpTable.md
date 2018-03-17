<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetTcpTable
Group: IP Helper - Library: iphlpapi    
***  


#### The GetTcpTable function retrieves the TCP connection table.
***  


## Code examples:
[Displaying all TCP connections for the local system](../../samples/sample_222.md)  

## Declaration:
```foxpro  
DWORD GetTcpTable(
  PMIB_TCPTABLE pTcpTable,  // buffer for the connection table
  PDWORD pdwSize,           // size of the buffer
  BOOL bOrder               // sort the table?
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetTcpTable IN iphlpapi;
	STRING @pTcpTable,;
	INTEGER @pdwSize,;
	INTEGER bOrder  
```  
***  


## Parameters:
```txt  
pTcpTable
[out] Pointer to a buffer that receives the TCP connection table as a MIB_TCPTABLE structure.

pdwSize
[in, out] On input, specifies the size of the buffer pointed to by the pTcpTable parameter.

bOrder
[in] Specifies whether the connection table should be sorted.  
```  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
See also: GetTcp6Table   
  
***  

