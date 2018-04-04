[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetIpNetTable
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### The GetIpNetTable function retrieves the IP-to-physical address mapping table.
***  


## Code examples:
[Retrieving the IP-to-physical address mapping table](../../samples/sample_230.md)  

## Declaration:
```foxpro  
DWORD GetIpNetTable(
  PMIB_IPNETTABLE pIpNetTable,  // buffer for mapping table
  PULONG pdwSize,               // size of buffer
  BOOL bOrder                   // sort by IP address
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetIpNetTable IN iphlpapi;
	STRING  @ pIpNetTable,;
	INTEGER @ pdwSize,;
	INTEGER   bOrder  
```  
***  


## Parameters:
pIpNetTable 
[out] Pointer to a buffer that receives the IP-to-physical address mapping table as a MIB_IPNETTABLE structure. 

pdwSize 
[in, out] On input, specifies the size of the buffer pointed to by the pIpNetTable parameter. 
bOrder 
[in] Specifies whether the returned mapping table should be sorted in ascending order by IP address.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  

