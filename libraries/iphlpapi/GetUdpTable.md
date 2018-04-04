[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUdpTable
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
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
pUdpTable 
[out] Pointer to a buffer that receives the UDP listener table as a MIB_UDPTABLE structure. 

pdwSize 
[in, out] Specifies the size of the buffer pointed to by the pUdpTable parameter. 

bOrder 
[in] Specifies whether the returned table should be sorted.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  

