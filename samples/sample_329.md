[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving country-specific dialing information from the Windows Telephony list of countries

## Code:
```foxpro  
DECLARE INTEGER RasGetCountryInfo IN rasapi32;
	STRING @lpRasCtryInfo, INTEGER @lpdwSize

*|typedef struct RASCTRYINFO {
*|  DWORD   dwSize;                0:4
*|  DWORD   dwCountryID;           4:4
*|  DWORD   dwNextCountryID;       8:4
*|  DWORD   dwCountryCode;        12:4
*|  DWORD   dwCountryNameOffset;  16:4
*|} RASCTRYINFO; total bytes = 20
#DEFINE RASCTRYINFO_SIZE  20

CREATE CURSOR csResult (countryId N(12), countryCode N(12),;
	countryName C(50))

PRIVATE pnIndex
pnIndex = 1

DO WHILE GetCountryInfo()
ENDDO

WAIT CLEAR
GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE GetCountryInfo()
	LOCAL lcBuffer, lnBufsize, lnResult

	lcBuffer = num2dword(RASCTRYINFO_SIZE) +;
		num2dword(pnIndex) + Repli(Chr(0), 12)
	lnBufsize = 0

	* first call with insufficient buffer size
	* returns required buffer size
	= RasGetCountryInfo(@lcBuffer, @lnBufsize)

	* real call
	lcBuffer = PADR(lcBuffer, lnBufsize, Chr(0))
	lnResult = RasGetCountryInfo(@lcBuffer, @lnBufsize)

	IF lnResult <> 0
		RETURN .F.
	ENDIF
	
	LOCAL lnId, lnCode, lnOffset, lcName
	pnIndex = buf2dword(SUBSTR(lcBuffer, 9,4))
	IF pnIndex = 0
	* the list is over
		RETURN .F.
	ENDIF

	lnId = buf2dword(SUBSTR(lcBuffer, 5,4))
	lnCode = buf2dword(SUBSTR(lcBuffer, 13,4))
	lnOffset = buf2dword(SUBSTR(lcBuffer, 17,4))
	lcName = STRTRAN(SUBSTR(lcBuffer, lnOffset+1), Chr(0),"")
	WAIT WINDOW lcName NOWAIT

	INSERT INTO csResult VALUES (m.lnId, m.lnCode, m.lcName)
RETURN .T.

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[RasGetCountryInfo](../libraries/rasapi32/RasGetCountryInfo.md)  
