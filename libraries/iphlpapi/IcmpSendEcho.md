[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : IcmpSendEcho
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Sends an ICMP Echo request and returns any replies. The call returns when the time-out has expired or the reply buffer is filled.
***  


## Code examples:
[How to ping a remote site using ICMP API calls](../../samples/sample_486.md)  

## Declaration:
```foxpro  
DWORD IcmpSendEcho(
  HANDLE IcmpHandle,
  IPAddr DestinationAddress,
  LPVOID RequestData,
  WORD RequestSize,
  PIP_OPTION_INFORMATION RequestOptions,
  LPVOID ReplyBuffer,
  DWORD ReplySize,
  DWORD Timeout
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IcmpSendEcho IN icmp;
	INTEGER  IcmpHandle,;
	INTEGER  DestinationAddress,;
	STRING @ RequestData,;
	LONG     RequestSize,;
	STRING @ RequestOptions,;
	STRING @ ReplyBuffer,;
	LONG     ReplySize,;
	LONG     timeout  
```  
***  


## Parameters:
IcmpHandle 
[in] Open handle returned by IcmpCreateFile. 

DestinationAddress 
[in] Destination of the echo request, in the form of an IPAddr structure. 

RequestData 
[in] Buffer that contains the data to send in the request. 

RequestSize 
[in] Size of the request data buffer, in bytes. 

RequestOptions 
[in] Pointer to the IP header options for the request, in the form of an IP_OPTION_INFORMATION structure. May be NULL. 

ReplyBuffer 
[in, out] Buffer to hold any replies to the request. Upon return, the buffer contains an array of ICMP_ECHO_REPLY structures followed by the options and data for the replies.

ReplySize 
[in] Allocated size of the reply buffer, in bytes.

Timeout 
[in] Time to wait for replies, in milliseconds.   
***  


## Return value:
Returns the number of ICMP_ECHO_REPLY structures stored in ReplyBuffer.  
***  


## Comments:
IcmpSendEcho is available in icmp.dll on Windows 2000; it is available in iphlpapi.dll on later versions of Windows. OS version checking is not recommended.   
  
The IcmpSendEcho2 function sends an ICMP Echo request and returns either immediately (if Event or ApcRoutine is non-NULL) or returns after the specified time-out. The ReplyBuffer contains the ICMP responses, if any.  
  
***  

