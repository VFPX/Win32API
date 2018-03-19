[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the name of the primary domain controller (PDC) and join status information

## Code:
```foxpro  
#DEFINE NERR_Success 0
DO decl

? "Primary Domain Controller:", GetPDCName()
? "Join Status Information:", GetJoinInfo()
* end of main

FUNCTION GetJoinInfo
*|typedef enum _NETSETUP_JOIN_STATUS {
*| NetSetupUnknownStatus = 0,
*| NetSetupUnjoined,
*| NetSetupWorkgroupName,
*| NetSetupDomainName
*|} NETSETUP_JOIN_STATUS, *PNETSETUP_JOIN_STATUS;

	LOCAL hBuffer, nResult, nType, nBufsize, cBuffer, cType
	STORE 0 TO hBuffer, nType, nBufsize

	nResult = NetGetJoinInformation(Null, @hBuffer, @nType)
	
	IF nResult <> NERR_Success
		cBuffer = "error " + LTRIM(STR(nResult))
	ELSE
		= NetApiBufferSize(hBuffer, @nBufsize)
		cBuffer = Repli(Chr(0), nBufsize)

		CopyMemory(@cBuffer, hBuffer, nBufsize)
		cBuffer = SUBSTR(cBuffer, 1, AT(Chr(0)+Chr(0),cBuffer))
		cBuffer = STRTRAN(cBuffer, Chr(0), "")

		DO CASE
		CASE nType=1
			cType = "unjoined"
		CASE nType=2
			cType = "workgroup"
		CASE nType=3
			cType = "domain"
		OTHER
			cType = "unknown"
		ENDCASE
		cBuffer = cBuffer + ", " + cType
	ENDIF
	= NetApiBufferFree(hBuffer)
RETURN cBuffer

FUNCTION GetPDCName
	LOCAL hBuffer, nResult, nBufsize, cBuffer
	STORE 0 TO hBuffer, nBufsize
	nResult = NetGetDCName(0,0, @hBuffer)

	IF nResult <> NERR_Success
	* 2453=Could not find domain controller for this domain
		cBuffer = "error " + LTRIM(STR(nResult))
	ELSE
		= NetApiBufferSize(hBuffer, @nBufsize)
		cBuffer = Repli(Chr(0), nBufsize)
		CopyMemory(@cBuffer, hBuffer, nBufsize)
		cBuffer = SUBSTR(cBuffer, 1, AT(Chr(0)+Chr(0),cBuffer))
		cBuffer = STRTRAN(cBuffer, Chr(0), "")
	ENDIF
	= NetApiBufferFree(hBuffer)
RETURN cBuffer

PROCEDURE decl
	DECLARE INTEGER NetGetJoinInformation IN netapi32;
		STRING lpServer, INTEGER @lpNameBuffer, INTEGER @BufferType;

	DECLARE INTEGER NetGetDCName IN netapi32;
		INTEGER servername, INTEGER domainname, INTEGER @bufptr

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Destination, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetGetDCName](../libraries/netapi32/NetGetDCName.md)  
[NetGetJoinInformation](../libraries/netapi32/NetGetJoinInformation.md)  

## Comment:
Notice that SERVERNAME and DOMAIN name parameters are declared as Integers, not Strings, and are set to zero.   
  
This is done to pass NULL values to the function instead of string values. In this case the local computer is used (SERVERNAME), and the function returns the name of the domain controller for the primary domain (DOMAIN).  
   
Error 2453 means that your computer is not joined to domain. Use NetJoinDomain function or go through the network settings to join a domain.  
  
***  

