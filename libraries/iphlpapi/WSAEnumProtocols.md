<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WSAEnumProtocols
Group: Windows Sockets 2 (Winsock) - Library: iphlpapi    
***  


#### The WSAEnumProtocols function retrieves information about available transport protocols.
***  


## Code examples:
[Winsock: retrieving information about available transport protocols](../../samples/sample_223.md)  

## Declaration:
```foxpro  
int WSAEnumProtocols(
  LPINT lpiProtocols,
  LPWSAPROTOCOL_INFO lpProtocolBuffer,
  ILPDWORD lpdwBufferLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER WSAEnumProtocols IN ws2_32;
	INTEGER   lpiProtocols,;
	STRING  @ lpProtBuf,;
	INTEGER @ lpdwBufLen  
```  
***  


## Parameters:
```txt  
lpiProtocols
[in] Null-terminated array of iProtocol values.

lpProtocolBuffer
[out] Buffer that is filled with WSAPROTOCOL_INFO structures.

lpdwBufferLength
[in, out] On input, the count of bytes in the lpProtocolBuffer buffer passed to WSAEnumProtocols.  
```  
***  


## Return value:
If no error occurs, WSAEnumProtocols returns the number of protocols to be reported. Otherwise, a value of SOCKET_ERROR is returned and a specific error code can be retrieved by calling WSAGetLastError.  
***  

