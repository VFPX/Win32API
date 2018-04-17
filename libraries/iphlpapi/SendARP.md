[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SendARP
Group: [IP Helper](../../functions_group.md#IP_Helper)  -  Library: [iphlpapi](../../Libraries.md#iphlpapi)  
***  


#### Sends an ARP request to obtain the physical address that corresponds to the specified destination IP address.
***  


## Code examples:
[Obtaining MAC address through Address Resolution Protocol (ARP) request](../../samples/sample_585.md)  

## Declaration:
```foxpro  
DWORD SendARP(
  IPAddr DestIP,
  IPAddr SrcIP,
  PULONG pMacAddr,
  PULONG PhyAddrLen
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SendARP IN iphlpapi;
	INTEGER destIP,;
	INTEGER sourceIP,;
	STRING @pMacAddr,;
	INTEGER @PhyAddrLen
  
```  
***  


## Parameters:
DestIP 
[in] Destination IP address, in the form of an IPAddr structure.

SrcIP 
[in] IP address of the sender, in the form of an IPAddr structure. 

pMacAddr 
[out] Pointer to an array of ULONG variables.

PhyAddrLen 
[in, out] On input, specifies the maximum buffer size the user has set aside at pMacAddr to receive the MAC address, in bytes. On output, specifies the number of bytes written to pMacAddr.  
***  


## Return value:
If the function succeeds, the return value is NO_ERROR (0).  
***  


## Comments:
The ARP (<a href="http://www.erg.abdn.ac.uk/users/gorry/course/inet-pages/arp.html">Address Resolution Protocol</a>) request attempts to obtain the physical address (MAC address) that corresponds to this IP address.  
  
* * *  
Christian Ehlscheid offered this code on UniversalThread as a solution for obtaining physical address for a given ip address:  
  
```foxpro
? IpToMacAddress("192.168.1.0")  
  
FUNCTION IpToMacAddress(lcIP)  
	DECLARE INTEGER inet_addr IN ws2_32.dll STRING cIP  
	DECLARE INTEGER SendARP IN iphlpapi.dll;  
		INTEGER destIP, INTEGER sourceIP,;  
		STRING @ pMacAddr, INTEGER @ PhyAddrLen  
	LOCAL lnHr, lnIpAddr, lcMacAddr, lnLen  
	lnIpAddr = inet_addr(lcIp)  
	lcMacAddr = REPLICATE(CHR(0),6)  
	lnLen = 6  
	lnHr = SendARP(lnIpAddr,0,@lcMacAddr,@lnLen)  
	RETURN BinaryToMac(lcMacAddr,lnLen)  
ENDFUNC  
  
FUNCTION BinaryToMac(lcMacAddr, lnLen)  
	LOCAL lcMac, xj  
	lcMac = ""  
	FOR xj = 1 TO lnLen - 1  
		lcMac = lcMac + RIGHT(TRANSFORM(ASC(;  
			SUBSTR(lcMacAddr,xj,1)),"@0"),2) + ":"  
	ENDFOR  
	lcMac = lcMac + RIGHT(TRANSFORM(ASC(;  
		SUBSTR(lcMacAddr,lnLen,1)),"@0"),2)  
	RETURN lcMac  
ENDFUNC
```
  
The Address Resolution Protocol (ARP) is a protocol used by the Internet Protocol (IP) [RFC826], specifically IPv4, to map IP network addresses to the hardware addresses used by a data link protocol.  
  
***  

