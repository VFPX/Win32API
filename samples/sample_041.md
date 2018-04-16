[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving local computer and user names

## Before you begin:
See also:

* [How to Start a Process as Another User (NT/XP/2K)](sample_426.md)  
* [How to obtain network parameters for the local computer (host, domain, DNS)](sample_348.md)  
  
***  


## Code:
```foxpro  
DO declare

DO GetNames
DO GetNameEx
DO GetNameObj
* end of main

PROCEDURE GetNames
	LOCAL nSize, cBuffer

	nSize = 250
	cBuffer = Repli(Chr(0), nSize)
	IF GetComputerName (@cBuffer, @nSize) > 0
		cBuffer = STRTRAN(SUBSTR(cBuffer, 1, nSize), Chr(0),"")
		? "Computer:", cBuffer
	ENDIF

	nSize = 250
	cBuffer = Repli(Chr(0), nSize)
	IF GetUserName (@cBuffer, @nSize) > 0
		cBuffer = STRTRAN(ALLTRIM(SUBSTR (cBuffer, 1, nSize)), Chr(0),"")
		? "User:", cBuffer
		DO GetSid WITH cBuffer
	ENDIF

PROCEDURE GetNameEx
	LOCAL cBuffer, nBufsize, nIndex
	FOR nIndex=0 TO 7
		nBufsize = 250
		cBuffer = Repli(Chr(0), nBufsize)
		IF GetComputerNameEx(nIndex, @cBuffer, @nBufsize) <> 0
			? nIndex, LEFT(cBuffer, nBufsize)
		ENDIF
	ENDFOR

PROCEDURE GetNameObj
	LOCAL cBuffer, nBufsize, nIndex
	nBufsize = 250
	cBuffer = Repli(Chr(0), nBufsize)

	IF GetComputerObjectName(12, @cBuffer, @nBufsize) = 0
	* 1351 = ERROR_CANT_ACCESS_DOMAIN_INFO
		? "Error code:", GetLastError()
	ELSE
		? nBufsize, "Object name: [" +;
			ALLTRIM(LEFT(cBuffer, nBufsize)) + "]"
	ENDIF

PROCEDURE GetSID(cAccount)
	LOCAL hSid, nSidsize, cDomain, nDomainsize, peUse

	nSidsize=128
	hSid=LocalAlloc(0, nSidsize)

	nDomainsize=250
	cDomain=REPLICATE(CHR(0), nDomainsize)
	
	peUse=0

	* retrieve security identifier (SID) for the account name
	= LookupAccountName(NULL, m.cAccount,;
		hSid, @nSidSize, @cDomain, @nDomainSize, @peUse)

	* convert the SID to string format
	LOCAL nBuffer, nBufsize, cSid
	nBuffer=0
	= ConvertSidToStringSid(hSid, @nBuffer)

	nBufsize = LocalSize(nBuffer)
	cSid = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cSid, nBuffer, nBufsize)

	= LocalFree(nBuffer)
	= LocalFree(hSid)
	
	? "Domain:", SUBSTR(cDomain, 1, AT(CHR(0),cDomain)-1)
	? "SID:", cSid

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER LocalFree IN kernel32 INTEGER hMem
	DECLARE LONG LocalSize IN kernel32 INTEGER hMem

	DECLARE INTEGER LocalAlloc IN kernel32;
		INTEGER uFlags, INTEGER uBytes

	DECLARE INTEGER GetComputerName IN kernel32;
		STRING @lpBuffer, INTEGER @nSize

	DECLARE INTEGER GetComputerNameEx IN kernel32;
		INTEGER NameType, STRING @lpBuffer, INTEGER @lpnSize

	DECLARE INTEGER GetUserName IN advapi32;
		STRING @lpBuffer, INTEGER @nSize

	DECLARE INTEGER GetComputerObjectName IN secur32;
		INTEGER NameFormat, STRING @lpNameBuffer, INTEGER @nSize

	DECLARE INTEGER LookupAccountName IN advapi32;
		STRING lpSystemName, STRING lpAccountName,;
		INTEGER Sid, INTEGER @cbSid,;
		STRING @RefDomainName, INTEGER @cchRefDomainName,;
		INTEGER @peUse

	DECLARE INTEGER ConvertSidToStringSid IN advapi32;
		INTEGER Sid, INTEGER @StringSid

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLength  
```  
***  


## Listed functions:
[ConvertSidToStringSid](../libraries/advapi32/ConvertSidToStringSid.md)  
[GetComputerName](../libraries/kernel32/GetComputerName.md)  
[GetComputerNameEx](../libraries/kernel32/GetComputerNameEx.md)  
[GetComputerObjectName](../libraries/secur32/GetComputerObjectName.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetUserName](../libraries/advapi32/GetUserName.md)  
[LocalAlloc](../libraries/kernel32/LocalAlloc.md)  
[LocalFree](../libraries/kernel32/LocalFree.md)  
[LocalSize](../libraries/kernel32/LocalSize.md)  
[LookupAccountName](../libraries/advapi32/LookupAccountName.md)  

## Comment:
**SYS(0)** returns current computer and user names.   
  
Same information can be retrieved with either **GETENV()** function with "COMPUTERNAME" and "USERNAME" parameters, or with the GetEnvironmentStrings function -- a [sample code](sample_089.md).  
  
***  

