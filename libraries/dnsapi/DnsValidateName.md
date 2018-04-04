[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DnsValidateName
Group: [DNS Functions](../../functions_group.md#DNS_Functions)  -  Library: [dnsapi](../../Libraries.md#dnsapi)  
***  


#### Validates the status of a specified DNS name.
***  


## Declaration:
```foxpro  
DNS_STATUS WINAPI DnsValidateName(
  _In_ PCTSTR          pszName,
  _In_ DNS_NAME_FORMAT Format
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DnsValidateName_A IN dnsapi;
AS DnsValidateName;
	STRING pszName,;
	INTEGER NameFormat  
```  
***  


## Parameters:
pszName [in]
A pointer to a string that represents the DNS name to be examined.

Format [in]
A DNS_NAME_FORMAT value that specifies the format of the name to be examined.  
***  


## Return value:
Returns ERROR_SUCCESS (0) on success.  
***  

