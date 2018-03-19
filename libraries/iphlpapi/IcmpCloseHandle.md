
## Function name : IcmpCloseHandle
Group: IP Helper - Library: iphlpapi    
***  


#### Closes a handle opened by a call to IcmpCreateFile.
***  


## Code examples:
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  

## Declaration:
```foxpro  
BOOL IcmpCloseHandle(
	HANDLE IcmpHandle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IcmpCloseHandle IN icmp;
	INTEGER IcmpHandle  
```  
***  


## Parameters:
IcmpHandle 
[in] Handle to close.   
***  


## Return value:
If the handle is closed successfully the return value is TRUE, otherwise FALSE.  
***  

