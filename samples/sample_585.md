[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining MAC address through Address Resolution Protocol (ARP) request

## Code:
```foxpro  
DO declare

cIP = "192.168.1.1"
nAddress = inet_addr(m.cIP)

nBufSize = 16
cBuffer = REPLICATE(CHR(0), nBufSize)

IF SendARP(nAddress, 0, @cBuffer, @nBufSize) = 0
	cMacAddress = ""
	
	FOR nIndex=1 TO nBufSize
		cValue = TRANSFORM(buf2dword(;
			SUBSTR(cBuffer, nIndex, 1)), "@0")

		cMacAddress = cMacAddress +;
			IIF(nIndex > 1, "-", "") +;
			RIGHT(m.cValue, 2)
	NEXT
	
	? cMacAddress
ELSE
	? "Call to SendARP failed."
ENDIF

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

PROCEDURE declare

	DECLARE INTEGER inet_addr IN ws2_32 STRING cp
	
	DECLARE INTEGER SendARP IN iphlpapi;
		INTEGER destIP, INTEGER sourceIP,;
		STRING @pMacAddr, INTEGER @PhyAddrLen  
```  
***  


## Listed functions:
[SendARP](../libraries/iphlpapi/SendARP.md)  
[inet_addr](../libraries/ws2_32/inet_addr.md)  
