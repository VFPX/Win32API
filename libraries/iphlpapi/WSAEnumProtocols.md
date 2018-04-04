[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WSAEnumProtocols
Group: [Windows Sockets 2 (Winsock)](../../functions_group.md#Windows_Sockets_2_(Winsock))  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
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
lpiProtocols 
[in] Null-terminated array of iProtocol values. 

lpProtocolBuffer 
[out] Buffer that is filled with WSAPROTOCOL_INFO structures. 

lpdwBufferLength 
[in, out] On input, the count of bytes in the lpProtocolBuffer buffer passed to WSAEnumProtocols.   
***  


## Return value:
If no error occurs, WSAEnumProtocols returns the number of protocols to be reported. Otherwise, a value of SOCKET_ERROR is returned and a specific error code can be retrieved by calling WSAGetLastError.  
***  

