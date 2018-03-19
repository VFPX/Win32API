[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to enumerate terminal servers within the specified Windows domain

## Before you begin:
See also:

* [How to enumerate sessions and processes on a specified terminal server](sample_519.md)  

  
***  


## Code:
```foxpro  
DO declare

LOCAL cDomainName, hBuffer, nSvrIndex, nSvrCount, nBufsize,;
	cBuffer, nAddress, cSvrName

STORE 0 TO hBuffer, nSvrCount

* The first parameter is the name of Windows domain to be queried.
* If this parameter is NULL, the current domain is assumed.
cDomainName=NULL
*cDomainName="companydomain"

nResult = WTSEnumerateServers(cDomainName, 0, 1, @hBuffer, @nSvrCount)

IF nResult = 0
* 1212=invalid domain name/format
	? "WTSEnumerateServers failed with error:", GetLastError()
	RETURN
ENDIF

? "Number of terminal servers within the domain:", nSvrCount

* create VFP string variable and allocate amount of space
* required to store the array of WTS_SERVER_INFO structures
* created by WTSEnumerateServers function
nBufsize = GlobalSize(hBuffer)
cBuffer = REPLICATE(CHR(0), nBufsize)
= MemToStr(@cBuffer, hBuffer, nBufsize)

*    The array of WTS_SERVER_INFO structures starts with
* N DWORD (4-byte) values, where N is the number
* of terminal servers detected.
*    Each value is the address in memory where a terminal server
* name is stored.
*    Each terminal server name ends with zero byte.

* retrieve terminal server names from the array
FOR nSvrIndex=0 TO nSvrCount-1
	nAddress = buf2dword(SUBSTR(cBuffer, nSvrIndex*4+1, 4))
	cSvrName = SUBSTR(cBuffer, nAddress - hBuffer+1)
	cSvrName = SUBSTR(m.cSvrName, 1, AT(CHR(0),cSvrName)-1)
	? "["+cSvrName+"]"
NEXT

* release memory implicitly allocated by the WTSEnumerateServers
= WTSFreeMemory(hBuffer)
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE WTSFreeMemory IN Wtsapi32 INTEGER pMemory
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem

	DECLARE INTEGER WTSEnumerateServers IN Wtsapi32;
		STRING pDomainName, LONG Reserved, LONG RqVersion,;
		LONG @ppServerInfo, LONG @SICount

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER ByteCount

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[WTSEnumerateServers](../libraries/wtsapi32/WTSEnumerateServers.md)  
[WTSFreeMemory](../libraries/wtsapi32/WTSFreeMemory.md)  
