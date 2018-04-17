[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Custom HttpRequest class (WinHTTP)

## Before you begin:
Use this class to send HTTP POST, HTTP GET and other HTTP requests. Use the following code to test it:  

```foxpro
SET MEMOWIDTH TO 120  
#DEFINE ccUrl "https://github.com/VFPX/Win32API/blob/master/samples/sample_397.md"  

oHttp = CreateObject("WinHttpRequest")  
WITH oHttp  
	IF Not .Open("GET", ccUrl)  
		? "Error:", .ErrorCode, .ErrorMsg  
	ELSE  
		IF Not .Send()  
			? "Error:", .ErrorCode, .ErrorMsg  
		ELSE  
			? .Status  
			? .StatusText  
			? .GetAllResponseHeaders()  
			? .GetResponseHeader("connection:")  
			? "Response length:", .ResponseLen  
			SET SAFETY OFF  
			StrToFile(.ResponseText, "tmp.txt")  
			SET SAFETY ON  
			MODI FILE tmp.txt NOWAIT  
		ENDIF  
	ENDIF  
ENDWITH
```
There is a similar class built on WinINet functions: [Custom HttpRequest class (WinINet)](sample_185.md).  
  
***  


## Code:
```foxpro  
DEFINE CLASS WinHttpRequest As Session
#DEFINE INTERNET_DEFAULT_HTTP_PORT  80
#DEFINE WINHTTP_ACCESS_TYPE_DEFAULT_PROXY 0
#DEFINE WINHTTP_ACCESS_TYPE_NAMED_PROXY 3
#DEFINE WINHTTP_ACCESS_TYPE_NO_PROXY 1
#DEFINE WINHTTP_NO_PROXY_NAME NULL
#DEFINE WINHTTP_NO_PROXY_BYPASS NULL
#DEFINE WINHTTP_HEADER_NAME_BY_INDEX 0
#DEFINE WINHTTP_NO_OUTPUT_BUFFER 0
#DEFINE WINHTTP_NO_HEADER_INDEX 0
#DEFINE WINHTTP_QUERY_FLAG_REQUEST_HEADERS 0x80000000
#DEFINE WINHTTP_QUERY_STATUS_CODE 19
#DEFINE WINHTTP_QUERY_STATUS_TEXT 20
#DEFINE WINHTTP_QUERY_RAW_HEADERS_CRLF 22
#DEFINE WINHTTP_ADDREQ_FLAG_ADD 0x20000000
#DEFINE WINHTTP_AUTH_TARGET_SERVER 0
#DEFINE WINHTTP_AUTH_SCHEME_BASIC 1
#DEFINE WINHTTP_ERROR_BASE 12000
#DEFINE ccUserAgent "VFP_WinHttp_Class; version 2006.10.09"
#DEFINE cnMaxQueryInfo 78  && max WINHTTP_QUERY_ value
#DEFINE CRLF CHR(13)+CHR(10)

PROTECTED hInternet, hConnect, hRequest, RequestHeaders
	StatusText=""
	Status=0
	ResponseLen=0
	ResponseText=""
	Host=""
	RemotePath=""
	ExtraInfo=""
	ResponseHeaderCount=0
	ErrorCode=0
	ErrorMsg=""
	DIMENSION ResponseHeaders[1,2]
	DIMENSION QueryInfo[cnMaxQueryInfo+1,3]

PROCEDURE Init
	THIS.declare
	STORE 0 TO THIS.hInternet, THIS.hConnect, THIS.hRequest

PROCEDURE Destroy
	THIS.CloseRequest

FUNCTION Open(cVerb, cUrl, cUser, cPwd, lAsync)
	THIS.CloseRequest
	STORE 0 TO THIS.ResponseLen, THIS.ErrorCode, THIS.Status
	STORE "" TO THIS.ResponseText, THIS.RequestHeaders,;
		THIS.StatusText, THIS.ErrorMsg

	IF Not THIS.CrackUrl(m.cUrl)
		THIS.ErrorCode = -1
		THIS.ErrorMsg = "Could not parse Url"
		RETURN .F.
	ENDIF

	THIS.hInternet = WinHttpOpen(THIS.ToUnicode(ccUserAgent),;
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,;
		WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0)

	IF THIS.hInternet = 0
		THIS.ErrorCode = -2
		THIS.ErrorMsg = "Could not activate WinHTTP library"
		RETURN .F.
	ENDIF

	LOCAL nIndex
	FOR nIndex=1 TO 10  && try several times
		THIS.hConnect = WinHttpConnect(THIS.hInternet, THIS.Host,;
			INTERNET_DEFAULT_HTTP_PORT, 0)
		IF THIS.hConnect <> 0
			THIS.ErrorCode = 0
			THIS.ErrorMsg = ""
			EXIT
		ENDIF
		THIS.ErrorCode = GetLastError()
		THIS.ErrorMsg = "Connection to [" +;
			STRCONV(THIS.Host,6) + "] failed."
		= INKEY(0.5)  && keep a small pause before retrying
	ENDFOR

	IF THIS.hConnect = 0
		THIS.CloseRequest
		RETURN .F.
	ENDIF

	THIS.hRequest = WinHttpOpenRequest(THIS.hConnect, THIS.ToUnicode(cVerb),;
		THIS.RemotePath + THIS.ExtraInfo, 0,0,0,0)

	IF THIS.hRequest = 0
		THIS.ErrorCode = -3
		THIS.ErrorMsg = "Could not open HTTP request"
		THIS.CloseRequest
		RETURN .F.
	ENDIF
	
	* if authorization required
	IF VARTYPE(m.cUser) = "C" And Not EMPTY(m.cUser);
		And VARTYPE(m.cPwd) = "C" And Not EMPTY(m.cPwd)

		LOCAL nResult
		nResult = WinHttpSetCredentials(THIS.hRequest,;
			WINHTTP_AUTH_TARGET_SERVER, WINHTTP_AUTH_SCHEME_BASIC,;
			THIS.ToUnicode(m.cUser), THIS.ToUnicode(m.cPwd), 0)

		IF nResult = 0
			THIS.ErrorCode = GetLastError()
			THIS.ErrorMsg = "Could not pass authorization data"
			THIS.CloseRequest
			RETURN .F.
		ENDIF
	ENDIF
RETURN .T.

PROCEDURE SetRequestHeader(cHeader, cValue)
	cHeader = StrConv(ALLTRIM(cHeader) + ": " +;
		ALLTRIM(cValue) + Chr(0) + CRLF, 5)
	= WinHttpAddRequestHeaders(THIS.hRequest, cHeader, -1,;
		WINHTTP_ADDREQ_FLAG_ADD)

FUNCTION Send(cBody)
	LOCAL nExtendedError
	IF VARTYPE(m.cBody) <> "C"
		cBody = ""
	ENDIF

	IF WinHttpSendRequest(THIS.hRequest, 0,0, cBody, Len(cBody),;
		LEN(cBody), 0) = 0
		* 6 = ERROR_INVALID_HANDLE
		nExtendedError = GetLastError()
		THIS.ErrorCode = -4
		THIS.ErrorMsg = "Call to WinHttpSendRequest failed: " +;
			LTRIM(STR(nExtendedError)) + "."
	ELSE
		IF WinHttpReceiveResponse(THIS.hRequest, 0) = 0
			THIS.ErrorCode = -5
			THIS.ErrorMsg = "HTTP Response error"
		ELSE
			THIS.GetQueryInfo
			THIS.GetRequestText
		ENDIF
	ENDIF

	THIS.CloseRequest
RETURN (THIS.ErrorCode=0)

FUNCTION GetAllResponseHeaders
	LOCAL nIndex, cResult
	cResult = ""
	FOR nIndex=1 TO THIS.ResponseHeaderCount
		cResult = cResult + THIS.ResponseHeaders[nIndex, 1] + ": " +;
			THIS.ResponseHeaders[nIndex, 2] + CRLF
	ENDFOR
RETURN cResult

FUNCTION GetResponseHeader(cHeader)
	cHeader = UPPER(ALLTRIM(cHeader))
	LOCAL nIndex
	FOR nIndex=1 TO THIS.ResponseHeaderCount
		IF cHeader == UPPER(ALLTR(THIS.ResponseHeaders[nIndex, 1]))
			RETURN THIS.ResponseHeaders[nIndex, 2]
		ENDIF
	ENDFOR
RETURN ""

PROTECTED PROCEDURE CloseRequest
	IF THIS.hRequest <> 0
	    = WinHttpCloseHandle(THIS.hRequest)
		THIS.hRequest = 0
	ENDIF
	IF THIS.hConnect <> 0
	    = WinHttpCloseHandle(THIS.hConnect)
		THIS.hConnect = 0
	ENDIF
	IF THIS.hInternet <> 0
	    = WinHttpCloseHandle(THIS.hInternet)
		THIS.hInternet = 0
	ENDIF

PROTECTED FUNCTION CrackUrl(cUrl)
#DEFINE URL_COMPONENTS_SIZE 60
#DEFINE CRACKURL_BUFSIZE 256

*!*	typedef struct {
*!*	  DWORD dwStructSize;       0:4
*!*	  LPWSTR lpszScheme;        4:4
*!*	  DWORD dwSchemeLength;     8:4
*!*	  int nScheme;             12:4
*!*	  LPWSTR lpszHostName;     16:4
*!*	  DWORD dwHostNameLength;  20:4
*!*	  INTERNET_PORT nPort;     24:4
*!*	  LPWSTR lpszUserName;     28:4
*!*	  DWORD dwUserNameLength;  32:4
*!*	  LPWSTR lpszPassword;     36:4
*!*	  DWORD dwPasswordLength;  40:4
*!*	  LPWSTR lpszUrlPath;      44:4
*!*	  DWORD dwUrlPathLength;   48:4
*!*	  LPWSTR lpszExtraInfo;    52:4
*!*	  DWORD dwExtraInfoLength; 56:4
*!*	} URL_COMPONENTS;          60:4

	LOCAL cBuffer, oHost, oRemotePath, oExtraInfo, nLength

	oHost = CREATEOBJECT("PChar", REPLICATE(CHR(0),CRACKURL_BUFSIZE))
	oRemotePath = CREATEOBJECT("PChar", REPLICATE(CHR(0),CRACKURL_BUFSIZE))
	oExtraInfo = CREATEOBJECT("PChar", REPLICATE(CHR(0),CRACKURL_BUFSIZE))

	cBuffer = num2dword(URL_COMPONENTS_SIZE) +;
		num2dword(0) + num2dword(-1) + num2dword(0) +;
		num2dword(oHost.GetAddr()) + num2dword(CRACKURL_BUFSIZE) +;
		num2dword(0) + num2dword(0) + num2dword(-1) +;
		num2dword(0) + num2dword(-1) +;
		num2dword(oRemotePath.GetAddr()) + num2dword(CRACKURL_BUFSIZE) +;
		num2dword(oExtraInfo.GetAddr()) + num2dword(CRACKURL_BUFSIZE)

	IF WinHttpCrackUrl(THIS.ToUnicode(ALLTRIM(m.cUrl)),;
		0,0,@cBuffer) = 0
		RETURN .F.
	ENDIF
	
	nLength = buf2dword(SUBSTR(m.cBuffer, 21, 4))
	THIS.Host = oHost.GetValue()
	THIS.Host = SUBSTR(THIS.Host, 1, nLength*2)

	nLength = buf2dword(SUBSTR(m.cBuffer, 49, 4))
	THIS.RemotePath = oRemotePath.GetValue()
	THIS.RemotePath = SUBSTR(THIS.RemotePath, 1, nLength*2)

	nLength = buf2dword(SUBSTR(m.cBuffer, 57, 4))
	THIS.ExtraInfo = oExtraInfo.GetValue()
	THIS.ExtraInfo = SUBSTR(THIS.ExtraInfo, 1, nLength*2)
RETURN .T.

PROTECTED FUNCTION FixString(cString)
	LOCAL nPos
	nPos = AT(Chr(0)+Chr(0), cString)
	IF nPos > 0
		RETURN SUBSTR(cString, 1, nPos+2)
	ELSE
		RETURN cString
	ENDIF

PROTECTED PROCEDURE GetQueryInfo
	LOCAL nIndex, cHeader, nBufsize, nResult
	FOR nIndex=0 TO cnMaxQueryInfo
		nBufsize = 0x8000
		cHeader = Repli(Chr(0), nBufsize)

		nResult = WinHttpQueryHeaders(THIS.hRequest,;
			nIndex, WINHTTP_HEADER_NAME_BY_INDEX,;
			@cHeader, @nBufsize, WINHTTP_NO_HEADER_INDEX)

		IF nResult = 0
			THIS.QueryInfo[nIndex+1,3] = GetLastError()
			THIS.QueryInfo[nIndex+1,1] = 0
			THIS.QueryInfo[nIndex+1,2] = ""
		ELSE
			cHeader = StrConv(SUBSTR(cHeader, 1, nBufsize), 6)
			THIS.QueryInfo[nIndex+1,3] = 0
			THIS.QueryInfo[nIndex+1,1] = Len(cHeader)
			THIS.QueryInfo[nIndex+1,2] = cHeader
		ENDIF
	ENDFOR
	THIS.ParseResponseHeaders
	THIS.StatusText = THIS.GetQueryHeader[WINHTTP_QUERY_STATUS_TEXT]
	THIS.Status = VAL(THIS.GetQueryHeader[WINHTTP_QUERY_STATUS_CODE])

PROTECTED FUNCTION GetQueryHeader(nIndex)
RETURN Iif(BETW(nIndex, 0, cnMaxQueryInfo), THIS.QueryInfo[nIndex+1,2], "")

PROTECTED PROCEDURE ParseResponseHeaders
	THIS.ResponseHeaderCount = 0
	LOCAL nIndex, nCount, cHeaders, cHeader
	cHeaders = THIS.GetQueryHeader(WINHTTP_QUERY_RAW_HEADERS_CRLF)
	
	nCount = ALINES(arrHeaders, cHeaders)
	FOR nIndex=1 TO nCount
		cHeader = arrHeaders[nIndex]
		THIS.ParseResponseHeader(cHeader)
	ENDFOR

PROTECTED PROCEDURE ParseResponseHeader(cHeader)
	LOCAL nPos
	nPos = AT(":", cHeader)
	IF nPos <> 0
		THIS.ResponseHeaderCount = THIS.ResponseHeaderCount + 1
		DIMENSION THIS.ResponseHeaders[THIS.ResponseHeaderCount, 2]
		THIS.ResponseHeaders[THIS.ResponseHeaderCount, 1] =;
			ALLTRIM(SUBSTR(cHeader, 1, nPos-1))
		THIS.ResponseHeaders[THIS.ResponseHeaderCount, 2] =;
			ALLTRIM(SUBSTR(cHeader, nPos+1))
	ENDIF

PROTECTED PROCEDURE GetRequestText
	LOCAL nAvailBt, nReadBt, cBuffer
	STORE 0 TO nAvailBt, nReadBt
	DO WHILE .T.
		= WinHttpQueryDataAvailable(THIS.hRequest, @nAvailBt)
		IF nAvailBt = 0
			EXIT
		ENDIF
		cBuffer = REPLI(Chr(0), nAvailBt)
		IF WinHttpReadData(THIS.hRequest, @cBuffer, nAvailBt, @nReadBt) = 1
			THIS.ResponseText = THIS.ResponseText +;
				SUBSTR(cBuffer, 1, nReadBt)
			THIS.ResponseLen = THIS.ResponseLen + m.nReadBt
		ENDIF
	ENDDO

PROTECTED FUNCTION ToUnicode(cStr)  && returns normalized Unicode string
RETURN StrConv(ALLTRIM(cStr)+Chr(0), 5)

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hPtr
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER

	DECLARE INTEGER WinHttpCloseHandle IN winhttp INTEGER hInternet

	DECLARE INTEGER WinHttpOpen IN winhttp;
		STRING pwszUserAgent, INTEGER dwAccessType, STRING pwszProxy,;
		STRING pwszProxyBypass, INTEGER dwFlags

	DECLARE INTEGER WinHttpConnect IN winhttp;
		INTEGER hSession, STRING pswzServerName,;
		INTEGER nServerPort, INTEGER dwReserved

	DECLARE INTEGER WinHttpOpenRequest IN winhttp;
		INTEGER hConnect, STRING pwszVerb, STRING pwszObjName,;
		STRING pwszVersion, INTEGER pwszReferrer,;
		INTEGER ppwszAcceptTypes, INTEGER dwFlags

	DECLARE INTEGER WinHttpSendRequest IN winhttp;
		INTEGER hRequest, STRING @pwszHeaders, INTEGER dwHdrsLen,;
		STRING @lpOptional, INTEGER dwOptionalLen, INTEGER dwTotalLen,;
		INTEGER dwContext

	DECLARE INTEGER WinHttpCrackUrl IN winhttp;
		STRING pwszUrl, INTEGER dwUrlLength,;
		INTEGER dwFlags, STRING @lpUrlComponents

	DECLARE INTEGER WinHttpQueryHeaders IN winhttp;
		INTEGER hRequest, INTEGER dwInfoLevel, INTEGER pwszName,;
		STRING @lpBuffer, INTEGER @lpdwBufLen, INTEGER lpdwIndex

	DECLARE INTEGER WinHttpQueryDataAvailable IN winhttp;
		INTEGER hRequest, INTEGER @lpdwNumberOfBytesAvailable

	DECLARE INTEGER WinHttpReadData IN winhttp;
		INTEGER hRequest, STRING @lpBuffer,;
		INTEGER dwNumberOfBytesToRead, INTEGER @lpdwBytesRead

	DECLARE INTEGER WinHttpReceiveResponse IN winhttp;
		INTEGER hRequest, INTEGER lpReserved

	DECLARE INTEGER WinHttpAddRequestHeaders IN winhttp;
		INTEGER hRequest, STRING pwszHeaders,;
		INTEGER dwHeadersLength, INTEGER dwModifiers

	DECLARE INTEGER WinHttpSetCredentials IN winhttp;
		INTEGER hRequest, INTEGER AuthTargets, INTEGER AuthScheme,;
		STRING pwszUserName, STRING pwszPassword, INTEGER pAuthParams
ENDDEFINE

DEFINE CLASS PChar As Session && implements pointer to string
PROTECTED hMem

PROCEDURE Init(lcString)
	THIS.hMem=0
	THIS.SetValue(lcString)

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr  && returns a pointer to the string
RETURN THIS.hMem

FUNCTION GetValue && returns string value
	LOCAL lnSize, lcBuffer
	lnSize = THIS.GetAllocSize()
	lcBuffer = SPACE(lnSize)
	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As MemToStr;
			STRING @, INTEGER, INTEGER
		= MemToStr(@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION GetAllocSize  && returns allocated memory size (string length)
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue(lcString) && assigns new string value
	THIS.ReleaseString

	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(0, lnSize)
	IF THIS.hMem <> 0
		= StrToMem(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		= GlobalFree(THIS.hMem)
		THIS.hMem=0
	ENDIF
ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0 0x100
#DEFINE m1 0x10000
#DEFINE m2 0x1000000
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
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[WinHttpAddRequestHeaders](../libraries/winhttp/WinHttpAddRequestHeaders.md)  
[WinHttpCloseHandle](../libraries/winhttp/WinHttpCloseHandle.md)  
[WinHttpConnect](../libraries/winhttp/WinHttpConnect.md)  
[WinHttpCrackUrl](../libraries/winhttp/WinHttpCrackUrl.md)  
[WinHttpOpen](../libraries/winhttp/WinHttpOpen.md)  
[WinHttpOpenRequest](../libraries/winhttp/WinHttpOpenRequest.md)  
[WinHttpQueryDataAvailable](../libraries/winhttp/WinHttpQueryDataAvailable.md)  
[WinHttpQueryHeaders](../libraries/winhttp/WinHttpQueryHeaders.md)  
[WinHttpReadData](../libraries/winhttp/WinHttpReadData.md)  
[WinHttpReceiveResponse](../libraries/winhttp/WinHttpReceiveResponse.md)  
[WinHttpSendRequest](../libraries/winhttp/WinHttpSendRequest.md)  
[WinHttpSetCredentials](../libraries/winhttp/WinHttpSetCredentials.md)  

## Comment:
*Nov. 26, 2003: code completely rewritten.*  
  
Take a look at [About WinHTTP](https://msdn.microsoft.com/en-us/library/windows/desktop/aa382925(v=vs.85).aspx) page on MSDN.  
  
* * *  
Dec.26, 2006: For C++ part, install WinHttp 5.1 SDK. The most straightforward way of doing that is downloading 400Mb of [Windows&reg; Server 2003 R2 Platform SDK](http://www.microsoft.com/downloads/details.aspx?familyid=A55B6B43-E24F-4EA3-A93E-40C0EC4F68E5&displaylang=en).  

***  

