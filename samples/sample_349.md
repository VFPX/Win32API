[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to release and renew a lease on an IP address previously obtained through Dynamic Host Configuration Protocol (DHCP)

## Before you begin:
This is an equivalent of two DOS commands  
```dos
IPCONFIG /release  
IPCONFIG /renew
```

***  


## Code:
```foxpro  
*|typedef struct _IP_INTERFACE_INFO {
*| LONG NumAdapters;
*| IP_ADAPTER_INDEX_MAP Adapter[1];
*|} IP_INTERFACE_INFO, *PIP_INTERFACE_INFO;

#DEFINE ERROR_SUCCESS  0
#DEFINE MAX_ADAPTER_NAME 128
#DEFINE INTERFACE_INFO_SIZE (MAX_ADAPTER_NAME+4)
DO declare

LOCAL cBuffer, nBufsize, nAdapterCount
nBufsize = 0
cBuffer = ""

* this call usually returns the 122=ERROR_INSUFFICIENT_BUFFER
* with nBufsize set to the required amount of memory
= GetInterfaceInfo(@cBuffer, @nBufsize)

cBuffer = REPLICATE(Chr(0), nBufsize)
IF GetInterfaceInfo(@cBuffer, @nBufsize) <> ERROR_SUCCESS
* failed to obtain the list of the network adapters
	RETURN
ENDIF

LOCAL nIndex, cBuffer1, cBuffer2, nAdapterIndex, cAdapterName

* the following works if the number of adapters installed
* on your computer is less than 15 :)
nAdapterCount = ASC(SUBSTR(cBuffer, 1,1))
? "Network adapters found:", nAdapterCount

* proceed with the first adapter found,
* otherwise a cycle should be programmed
cBuffer1 = SUBSTR(cBuffer, 1, INTERFACE_INFO_SIZE)
nAdapterIndex = buf2dword(SUBSTR(cBuffer1, 5,1))
cAdapterName = STRCONV(SUBSTR(cBuffer1, 9),6)  && unicode
cAdapterName = STRTRAN(m.cAdapterName, CHR(0), "")
? nAdapterIndex, cAdapterName

cBuffer2 = SUBSTR(cBuffer1, 5)

* the following code is intentionally commented out
* presuming that you are aware of what is going to happen
* uncomment either Release or Renew call

*? IpReleaseAddress(@cBuffer2)
*? IpRenewAddress(@cBuffer2)

* end of main

PROCEDURE declare
	DECLARE INTEGER GetInterfaceInfo IN iphlpapi;
		STRING @pIfTable, LONG @dwOutBufLen

	DECLARE INTEGER IpRenewAddress IN iphlpapi STRING @AdapterInfo
	DECLARE INTEGER IpReleaseAddress IN iphlpapi STRING @AdapterInfo

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetInterfaceInfo](../libraries/iphlpapi/GetInterfaceInfo.md)  
[IpReleaseAddress](../libraries/iphlpapi/IpReleaseAddress.md)  
[IpRenewAddress](../libraries/iphlpapi/IpRenewAddress.md)  
