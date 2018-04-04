[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetAdaptersAddresses
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Retrieves the addresses associated with the adapters on the local computer.
***  


## Code examples:
[Obtaining addresses for the adapters on the local computer (Win XP/2003/Vista)](../../samples/sample_506.md)  

## Declaration:
```foxpro  
DWORD WINAPI GetAdaptersAddresses(
  ULONG Family,
  DWORD Flags,
  PVOID Reserved,
  PIP_ADAPTER_ADDRESSES pAdapterAddresses,
  PULONG pOutBufLen
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetAdaptersAddresses IN Iphlpapi;
	LONG Family,;
	LONG flgs,;
	INTEGER Reserved,;
	INTEGER pAdapterAddresses,;
	LONG @pOutBufLen  
```  
***  


## Parameters:
Family 
[in] Address family of the addresses to retrieve: AF_INET, AF_INET6, AF_UNSPEC

Flags 
[in] Type of addresses to retrieve.

Reserved 
[in] The calling application should pass NULL for this parameter. 
pAdapterAddresses 

[out] Pointer to a buffer. On successful return, this buffer contains the address information. 

pOutBufLen 
[in, out] Pointer to a variable that specifies the size of the buffer pointed to by pAdapterAddresses.  
***  


## Return value:
If the function is successful, the return value is ERROR_SUCCESS (0).  
***  

