<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IcmpCloseHandle
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
```txt  
IcmpHandle
[in] Handle to close.  
```  
***  


## Return value:
If the handle is closed successfully the return value is TRUE, otherwise FALSE.  
***  

