[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# URL: splitting into its component parts

## Code:
```foxpro  
*| typedef struct {
*|     DWORD  dwStructSize;        0:4
*|     LPTSTR  lpszScheme;         4:4 *
*|     DWORD  dwSchemeLength;      8:4
*|     INTERNET_SCHEME  nScheme;  12:4
*|     LPTSTR  lpszHostName;      16:4 *
*|     DWORD  dwHostNameLength;   20:4
*|     INTERNET_PORT  nPort;      24:4
*|     LPTSTR  lpszUserName;      28:4 *
*|     DWORD  dwUserNameLength;   32:4
*|     LPTSTR  lpszPassword;      36:4 *
*|     DWORD  dwPasswordLength;   40:4
*|     LPTSTR  lpszUrlPath;       44:4 *
*|     DWORD  dwUrlPathLength;    48:4
*|     LPTSTR  lpszExtraInfo;     52:4 *
*|     DWORD  dwExtraInfoLength;  56:4
*| } URL_COMPONENTS, *LPURL_COMPONENTS; 15x4 = 60 bytes

LOCAL oUrlSplit As UrlSplit
oUrlSplit = CREATEOBJECT("UrlSplit")

oUrlSplit.url = "http:" + "/" +"/www.google.com/" +;
		"search?q=using+FindText+API&hl=en&start=10&sa=N"

WITH oUrlSplit
	? "URL:", .url
	? "Scheme Name:", .SchemeNme
	? "Host Name:", .HostNme
	? "User Name:", .UserNme
	? "Password:", .Pwd
	? "URL Path:", .UrlPath
	? "Extra info:", .ExtraInfo
	? "Scheme value:", .SchemeValue
	? "Port:", .PortNumber
ENDWITH
* end of main

DEFINE CLASS UrlSplit As Relation
#DEFINE ICU_DECODE  0x10000000
#DEFINE ICU_ESCAPE  0x80000000
#DEFINE MAINBUF_SIZE  60
#DEFINE STRBUF_SIZE 1024
#DEFINE ZERO_DWORD REPLICATE(CHR(0),4)

	url=""
	SchemeNme=""
	HostNme=""
	UserNme=""
	Pwd=""
	UrlPath=""
	ExtraInfo=""
	SchemeValue=0
	PortNumber=0

	oScheme=NULL
	oHostName=NULL
	oUserName=NULL
	oPwd=NULL
	oUrlPath=NULL
	oExtraInfo=NULL

PROCEDURE Init(cUrl As String)
	THIS.oScheme = CREATEOBJECT("PChar", "")
	THIS.oHostName = CREATEOBJECT("PChar", "")
	THIS.oUserName = CREATEOBJECT("PChar", "")
	THIS.oPwd = CREATEOBJECT("PChar", "")
	THIS.oUrlPath = CREATEOBJECT("PChar", "")
	THIS.oExtraInfo = CREATEOBJECT("PChar", "")

	THIS.declare
	THIS.url = m.cUrl

PROCEDURE url_ASSIGN(cUrl As String)
	THIS.ResetObject
	IF VARTYPE(cUrl)="C" AND NOT EMPTY(cUrl)
		THIS.url = ALLTRIM(m.cUrl)
		THIS.SplitUrl
	ELSE
		THIS.url = ""
	ENDIF

PROCEDURE ResetObject
	THIS.SchemeNme = ""
	THIS.HostNme = ""
	THIS.UserNme = ""
	THIS.Pwd = ""
	THIS.UrlPath = ""
	THIS.ExtraInfo = ""
	THIS.SchemeValue = 0
	THIS.PortNumber = 0

PROTECTED PROCEDURE SplitUrl
	THIS.ResetObject

	LOCAL cBuffer, cEmptyString
	
	cEmptyString = REPLICATE(CHR(0), STRBUF_SIZE)

	THIS.oScheme.SetValue(m.cEmptyString)
	THIS.oHostName.SetValue(m.cEmptyString)
	THIS.oUserName.SetValue(m.cEmptyString)
	THIS.oPwd.SetValue(m.cEmptyString)
	THIS.oUrlPath.SetValue(m.cEmptyString)
	THIS.oExtraInfo.SetValue(m.cEmptyString)

	cBuffer = num2dword(MAINBUF_SIZE) +;
		num2dword(THIS.oScheme.GetAddr()) +;
		num2dword(STRBUF_SIZE) +;
		ZERO_DWORD +;
		num2dword(THIS.oHostName.GetAddr()) +;
		num2dword(STRBUF_SIZE) +;
		ZERO_DWORD +;
		num2dword(THIS.oUserName.GetAddr()) +;
		num2dword(STRBUF_SIZE) +;
		num2dword(THIS.oPwd.GetAddr()) +;
		num2dword(STRBUF_SIZE) +;
		num2dword(THIS.oUrlPath.GetAddr()) +;
		num2dword(STRBUF_SIZE) +;
		num2dword(THIS.oExtraInfo.GetAddr()) +;
		num2dword(STRBUF_SIZE)

	= InternetCrackUrl(THIS.url, LEN(THIS.url), ICU_DECODE, @cBuffer)

	THIS.SchemeNme = THIS.ns(THIS.oScheme.GetValue())
	THIS.HostNme = THIS.ns(THIS.oHostName.GetValue())
	THIS.UserNme = THIS.ns(THIS.oUserName.GetValue())
	THIS.Pwd = THIS.ns(THIS.oPwd.GetValue())
	THIS.UrlPath = THIS.ns(THIS.oUrlPath.GetValue())
	THIS.ExtraInfo = THIS.ns(THIS.oExtraInfo.GetValue())
	THIS.SchemeValue = buf2dword(SUBSTR(cBuffer, 13,4))
	THIS.PortNumber = buf2dword(SUBSTR(cBuffer, 25,4))

PROTECTED FUNCTION ns(cSrc As String) As String
	LOCAL nPos
	nPos = AT(CHR(0), m.cSrc)
RETURN IIF(nPos=0, m.cStr, SUBSTR(m.cSrc, 1, m.nPos-1))

PROCEDURE declare
	DECLARE INTEGER InternetCrackUrl IN wininet;
		STRING lpszUrl, INTEGER dwUrlLength,;
		INTEGER dwFlags, STRING @lpUrlComponents

ENDDEFINE

DEFINE CLASS PChar As Relation
	PROTECTED hMem

PROCEDURE Init (lcString)
	THIS.declare
	THIS.hMem = 0
	THIS.setValue (lcString)

PROCEDURE declare
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @, INTEGER, INTEGER

	DECLARE RtlMoveMemory IN kernel32 As Str2Heap;
		INTEGER, STRING @, INTEGER

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr  && returns a pointer to the string
RETURN THIS.hMem

FUNCTION GetValue && returns string value
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		= Heap2Str (@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION GetAllocSize  && returns allocated memory size (string length)
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue (lcString) && assigns new string value
#DEFINE GMEM_FIXED   0
	THIS.ReleaseString

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= Str2Heap(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE  && pchar

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[InternetCrackUrl](../libraries/wininet/InternetCrackUrl.md)  

## Comment:
May.04, 2007 -- the code sample rewritten from scratch.  
  
***  

