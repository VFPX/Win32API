<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DnsValidateName
Group: DNS Functions - Library: dnsapi    
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
```txt  
pszName [in]
A pointer to a string that represents the DNS name to be examined.

Format [in]
A DNS_NAME_FORMAT value that specifies the format of the name to be examined.  
```  
***  


## Return value:
Returns ERROR_SUCCESS (0) on success.  
***  

