[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetIpAddrTable
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### The GetIpAddrTable function retrieves the interface–to–IP address mapping table.
***  


## Code examples:
[Retrieving the interface–to–IP address mapping table](../../samples/sample_233.md)  

## Declaration:
```foxpro  
DWORD GetIpAddrTable(
  PMIB_IPADDRTABLE pIpAddrTable,  // buffer for mapping table
  PULONG pdwSize,                 // size of buffer
  BOOL bOrder                     // sort the table
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetIpAddrTable IN iphlpapi;
	STRING  @ pIpAddrTable,;
	INTEGER @ pdwSize,;
	INTEGER   bOrder  
```  
***  


## Parameters:
pIpAddrTable 
[out] Pointer to a buffer that receives the interface–to–IP address mapping table as a MIB_IPADDRTABLE structure. 

pdwSize 
[in, out] The size of the buffer pointed to by the pIpAddrTable parameter. 

bOrder 
[in] Specifies whether the returned mapping table should be sorted in ascending order by IP address.   
***  


## Return value:
If the function succeeds, the return value is NO_ERROR.  
***  

