[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using NetWkstaTransportEnum to obtain MAC Address of remote server

## Before you begin:
See also:

* [SendARP function](../libraries/iphlpapi/SendARP.md)  
* [How to retrieve adapter information for the local computer (including MAC address)](sample_347.md)  
* [Obtaining addresses for the adapters on the local computer (Win XP/2003/Vista)](sample_506.md)  
* [How to ping a remote site using IP Helper API calls](sample_382.md)  
* [How to ping a remote site using ICMP API calls](sample_486.md)  

  
***  


## Code:
```foxpro  
#DEFINE MAX_PREFERRED_LENGTH -1
#DEFINE NERR_Success 0

	DO decl
	
	LOCAL cServer, cBuffer, hBuffer, nBufsize,;
		nEntriesRead, nEntriesTotal

	* for other computers, not the local computer,
	* convert server name to Unicode
	cServer = null
*	cServer = StrConv("myserver"+Chr(0), 5)

	cBuffer = Repli(Chr(0), 16384)
	STORE 0 TO hBuffer, nBufsize, nEntriesRead, nEntriesTotal
	
	nResult = NetWkstaTransportEnum(cServer, 0, @hBuffer,;
		MAX_PREFERRED_LENGTH, @nEntriesRead, @nEntriesTotal, 0)

	IF nResult <> NERR_Success
	* 5=ERROR_ACCESS_DENIED -- connect to the server
	* 53=ERROR_BAD_NETPATH
	* 124=ERROR_INVALID_LEVEL
	* 234=ERROR_MORE_DATA
	* 1113=ERROR_NO_UNICODE_TRANSLATION
	* 2123=The API return buffer is too small
		= NetApiBufferFree(hBuffer)
		? "Error code:", nResult
		RETURN
	ENDIF
	
	? "Entries read:", nEntriesRead

	* obtain size of the buffer
	= NetApiBufferSize(hBuffer, @nBufsize)

	cBuffer = Repli(Chr(0), nBufsize)
	CopyMemory(@cBuffer, hBuffer, nBufsize)

*	? cBuffer

* this is how you can view and analyze the buffer
* populated by NetWkstaTransportEnum function
*	CREATE CURSOR cs (cc C(1), aa I)
*	FOR ii=1 TO Len(cBuffer)
*		ch = SUBSTR(cBuffer, ii,1)
*		INSERT INTO cs VALUES (m.ch, Asc(m.ch))
*	ENDFOR

*|typedef struct _WKSTA_TRANSPORT_INFO_0 {
*|  DWORD wkti0_quality_of_service; 0:4
*|  DWORD wkti0_number_of_vcs;      4:4
*|  LPWSTR wkti0_transport_name;    8:4
*|  LMSTR wkti0_transport_address; 12:4
*|  BOOL wkti0_wan_ish;            16:4
*|} WKSTA_TRANSPORT_INFO_0, ... total 20 bytes
#DEFINE TRANSPORT_INFO_SIZE 20

	LOCAL nIndex, hName, hAddress, cName, cAddress, ch
	CREATE CURSOR cs (devname C(70), srvaddress C(50))

	* retrieving device names and server address for existing
	* transport protocols
	FOR nIndex=1 TO nEntriesRead
		hName = buf2dword(SUBSTR(cBuffer,;
			(nIndex-1)*TRANSPORT_INFO_SIZE+9,4))

		hAddress = buf2dword(SUBSTR(cBuffer,;
			(nIndex-1)*TRANSPORT_INFO_SIZE+13,4))

		hName = hName - hBuffer  && decrease by initial offset
		cName = ""
		DO WHILE .T.
			ch = SUBSTR(cBuffer, hName, 2)
			IF ch = Chr(0)+Chr(0) Or hName > Len(cBuffer)
				EXIT
			ENDIF
			cName = cName + ch
			hName = hName + 2
		ENDDO
		cName = STRTRAN(cName, Chr(0), "")

		hAddress = hAddress - hBuffer  && decrease by initial offset
		cAddress = ""
		DO WHILE .T.
			ch = SUBSTR(cBuffer, hAddress, 2)
			IF ch = Chr(0)+Chr(0) Or hAddress > Len(cBuffer)
				EXIT
			ENDIF
			cAddress = cAddress + ch
			hAddress = hAddress + 2
		ENDDO
		cAddress = STRTRAN(cAddress, Chr(0), "")
		
		INSERT INTO cs VALUES (cName, cAddress)
	ENDFOR

	= NetApiBufferFree(hBuffer)
	
	SELECT cs
	GO TOP
	BROWSE NORMAL NOWAIT
* end of main

PROCEDURE decl

	DECLARE INTEGER NetWkstaTransportEnum IN netapi32;
		STRING servername, LONG lvl, INTEGER @bufptr,;
		LONG prefmaxlen, LONG @entriesread,;
		LONG @totalentries, LONG resumehandle

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE INTEGER NetApiBufferSize IN netapi32;
		INTEGER Buffer, INTEGER @ByteCount

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @dst, INTEGER src, INTEGER bufsize

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetApiBufferSize](../libraries/netapi32/NetApiBufferSize.md)  
[NetWkstaTransportEnum](../libraries/netapi32/NetWkstaTransportEnum.md)  

## Comment:
For those who want to improve their MAC address skills :)  -- read <a href="http://www.codeguru.com/Cpp/I-N/network/networkinformation/article.php/c5451/">Three ways to get your MAC address</a> of  Khalid Shaikh on the <a href="http://www.codeguru.com/">http://www.codeguru.com/</a>.  
  
***  

