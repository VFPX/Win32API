[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IcmpCreateFile
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
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
This function has no parameters.  
***  


## Return value:
Returns an open handle on success. Returns INVALID_HANDLE_VALUE (-1) upon failure.  
***  


## Comments:
Use the returned handle with the IcmpSendEcho function to send an ICMP Echo request and get a reply. The IcmpCloseHandle function closes a handle opened by a call to IcmpCreateFile.  
  
***  

