<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : IcmpCreateFile
Group: IP Helper - Library: iphlpapi    
***  


#### Opens a handle on which ICMP Echo Requests can be issued.

***  


## Code examples:
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  

## Declaration:
```foxpro  
HANDLE IcmpCreateFile(void);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IcmpCreateFile IN icmp  
```  
***  


## Parameters:
```txt  
This function has no parameters.  
```  
***  


## Return value:
Returns an open handle on success. Returns INVALID_HANDLE_VALUE (-1) upon failure.  
***  


## Comments:
Use the returned handle with the IcmpSendEcho function to send an ICMP Echo request and get a reply. The IcmpCloseHandle function closes a handle opened by a call to IcmpCreateFile.  
  
***  

