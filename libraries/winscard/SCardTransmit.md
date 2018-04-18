[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SCardTransmit
Group: [Authentication](../../functions_group.md#Authentication)  -  Library: [winscard](../../Libraries.md#winscard)  
***  

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.


#### Sends a service request to the smart card and expects to receive data back from the card.
***  


## Declaration:
```foxpro  
LONG SCardTransmit(
  __in     SCARDHANDLE hCard,
  __in     LPCSCARD_IO_REQUEST pioSendPci,
  __in     LPCBYTE pbSendBuffer,
  __in     DWORD cbSendLength,
  __inout  LPSCARD_IO_REQUEST pioRecvPci,
  __out    LPBYTE pbRecvBuffer,
  __inout  LPDWORD pcbRecvLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG SCardTransmit IN Winscard;
	INTEGER hCard,;
	STRING pioSendPci,;
	STRING pbSendBuffer,;
	LONG cbSendLength,;
	INTEGER pioRecvPci,;
	STRING @pbRecvBuffer,;
	LONG @pcbRecvLength  
```  
***  


## Parameters:
hCard [in] 
A reference value returned from the SCardConnect function.

pioSendPci [in] 
A pointer to the protocol header structure for the instruction.

pbSendBuffer [in] 
A pointer to the actual data to be written to the card. 

cbSendLength [in] 
The length, in bytes, of the pbSendBuffer parameter. 

pioRecvPci [in, out] 
Pointer to the protocol header structure for the instruction, followed by a buffer in which to receive any returned protocol control information (PCI) specific to the protocol in use. This parameter can be NULL if no PCI is returned.

pbRecvBuffer [out] 
Pointer to any data returned from the card. 

pcbRecvLength [in, out] 
Supplies the length, in bytes, of the pbRecvBuffer parameter and receives the actual number of bytes received from the smart card.  
***  


## Return value:
Returns SCARD_S_SUCCESS (0) or error code.  
***  


## Comments:

<!-- Anatoliy -->
Purchase complete VFP solution.  
<a href="http://www.news2news.com/vfp/?solution=2&src=fn1143"><img src="../../images/acos3_270_48.png" width=270 height=48 border=0  vspace=5 hspace=5 alt="Download ACOS3 Class Library"></a>  
  

The SCardTransmit function is a smart card and reader access function.  
  
See also: [SCardConnect](../winscard/SCardConnect.md).  
  
***  

