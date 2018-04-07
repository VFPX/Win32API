[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetTcpTable
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
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
pTcpTable 
[out] Pointer to a buffer that receives the TCP connection table as a MIB_TCPTABLE structure. 

pdwSize 
[in, out] On input, specifies the size of the buffer pointed to by the pTcpTable parameter. 

bOrder 
[in] Specifies whether the connection table should be sorted.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  


## Comments:
See also: [GetTcp6Table](../iphlpapi/GetTcp6Table.md).  
  
***  

