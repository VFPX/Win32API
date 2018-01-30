#INCLUDE apiviewer.h
#IFNDEF DEMO_VERSION

DEFINE CLASS THttpRequest As Custom
#DEFINE INTERNET_OPEN_TYPE_DIRECT 1
#DEFINE INTERNET_SERVICE_HTTP 3
#DEFINE INTERNET_DEFAULT_HTTP_PORT 80
#DEFINE INTERNET_FLAG_RELOAD 0x80000000
#DEFINE HTTP_QUERY_STATUS_CODE 19  && 200
#DEFINE HTTP_QUERY_STATUS_TEXT 20  && OK
#DEFINE HTTP_QUERY_RAW_HEADERS_CRLF  22

#DEFINE QUERYINFO_DIMENSION  68
#DEFINE HTTP_PREFIX "http://"
#DEFINE SLASH_CHAR "/"

	Agent="Visual FoxPro Apiviewer"
	hInternet=0
	hConnect=0
	hRequest=0
	RequestHeaders=""
	StatusText=""
	Status=0
	ResponseLen=0
	ResponseText=""
	Url=""
	Host=""
	RemotePath=""
	ResponseHeaderCount=0
	ErrorCode=0
	DIMENSION ResponseHeaders[1,2]
	DIMENSION QueryInfo[QUERYINFO_DIMENSION,3]
	progress=NULL
	transferaborted=.F.

PROCEDURE Init
	THIS.declare
	STORE 0 TO THIS.hInternet, THIS.hConnect, THIS.hRequest
	THIS.progress = NEWOBJECT("httprequest_progress", "apiviewer")

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

PROCEDURE Destroy
	THIS.CloseRequest
	THIS.progress.Release
	THIS.progress=NULL

FUNCTION GetQI(nIndex)
RETURN Iif(BETW(nIndex, 0, QUERYINFO_DIMENSION), THIS.QueryInfo[nIndex+1,2], "")

PROTECTED PROCEDURE CloseRequest
	IF THIS.hRequest <> 0
	    = InternetCloseHandle(THIS.hRequest)
		THIS.hRequest = 0
	ENDIF
	IF THIS.hConnect <> 0
	    = InternetCloseHandle(THIS.hConnect)
		THIS.hConnect = 0
	ENDIF
	IF THIS.hInternet <> 0
	    = InternetCloseHandle(THIS.hInternet)
		THIS.hInternet = 0
	ENDIF
	
	THIS.progress.Visible=.T.
	DOEVENTS

FUNCTION Open(cVerb, cUrl)  && opens HTTP request
	THIS.CloseRequest
	STORE 0 TO THIS.ResponseLen, THIS.ErrorCode, THIS.Status
	STORE "" TO THIS.ResponseText, THIS.RequestHeaders, THIS.StatusText
	THIS.CrackUrl(cUrl)
	
	LOCAL cReferer
	cReferer = ""

    THIS.hInternet = InternetOpen(THIS.Agent, INTERNET_OPEN_TYPE_DIRECT, 0,0,0)

	THIS.hConnect = InternetConnect(THIS.hInternet, THIS.Host,;
		INTERNET_DEFAULT_HTTP_PORT, "", "", INTERNET_SERVICE_HTTP, 0, 0)

	THIS.hRequest = HttpOpenRequest(THIS.hConnect, cVerb, THIS.RemotePath,;
		"HTTP/1.1", cReferer, 0, INTERNET_FLAG_RELOAD, 0)

	IF THIS.hRequest = 0
		THIS.ErrorCode = GetLastError()
		THIS.CloseRequest
		RETURN .F.
	ENDIF
RETURN .T.

PROTECTED PROCEDURE CrackUrl(cUrl)
	LOCAL nPos
	cUrl = ALLTRIM(cUrl)

	nPos = AT(HTTP_PREFIX, LOWER(cUrl))
	IF nPos <> 0
		cUrl = STUFF(cUrl, nPos, LEN(HTTP_PREFIX), "")
	ENDIF
	THIS.url = cUrl

	nPos = AT(SLASH_CHAR, cUrl)
	IF nPos=0 OR nPos = LEN(cUrl)
		THIS.Host=cUrl
		THIS.RemotePath=""
	ELSE
		THIS.Host = SUBSTR(cUrl, 1, nPos-1)
		THIS.RemotePath = SUBSTR(cUrl, nPos)
	ENDIF

PROCEDURE SetRequestHeader(cHeader, cValue)
	THIS.RequestHeaders = THIS.RequestHeaders +;
		ALLTRIM(cHeader) + ": " +;
		ALLTRIM(cValue) + CHR(13) + CHR(10)

FUNCTION Send(cBody)
	LOCAL cHeaders
	cHeaders = THIS.RequestHeaders
	
	IF VARTYPE(cBody) <> "C"
		cBody = ""
	ENDIF

	WITH THIS.progress
		STORE 0 TO .totalbytes, .downloadedbytes
		.Caption = "HTTP Request sent. Waiting for response from remote server..."
		.Visible=.T.
		.Refresh
	ENDWITH
	DOEVENTS

	IF HttpSendRequest(THIS.hRequest, @cHeaders,;
		LEN(cHeaders), @cBody, LEN(cBody)) = 0
		THIS.ErrorCode = GetLastError()
		THIS.CloseRequest
		RETURN .F.
	ENDIF

	THIS.GetQueryInfo
	THIS.GetRequestText
	THIS.CloseRequest
RETURN .T.

PROTECTED PROCEDURE GetQueryInfo
	WITH THIS.progress
		.Caption = "Quering HTTP Response..."
		.Refresh
	ENDWITH

	LOCAL nBufSize, cBuffer, nIndex, ii

	FOR ii = 1 TO QUERYINFO_DIMENSION
		nBufSize = 4192
		cBuffer = Repli(Chr(0), nBufSize)
		nIndex = 0

		IF HttpQueryInfo(THIS.hRequest, ii-1, @cBuffer,;
			@nBufSize, @nIndex) <> 0
			cBuffer = Iif(nBufSize=0, "", Left(cBuffer, nBufSize))
			THIS.QueryInfo[ii,1] = nBufSize
			THIS.QueryInfo[ii,2] = cBuffer
			THIS.QueryInfo[ii,3] = 0
		ELSE
			THIS.QueryInfo[ii,1] = 0
			THIS.QueryInfo[ii,2] = ""
			THIS.QueryInfo[ii,3] = GetLastError()
		ENDIF
	ENDFOR

	THIS.ParseResponseHeaders
	THIS.StatusText = THIS.GetQI[HTTP_QUERY_STATUS_TEXT]
	THIS.Status = VAL(THIS.GetQI[HTTP_QUERY_STATUS_CODE])

PROTECTED PROCEDURE ParseResponseHeaders
	THIS.ResponseHeaderCount = 0

	LOCAL nIndex, nCount, cHeaders, cHeader
	cHeaders = THIS.GetQI(HTTP_QUERY_RAW_HEADERS_CRLF)
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

PROCEDURE OnCancel
	THIS.transferaborted=.T.

PROTECTED PROCEDURE GetRequestText
	LOCAL nAvailBt, nReadBt, cBuffer
	STORE 0 TO nAvailBt, nReadBt
	
	THIS.transferaborted=.F.
	= BINDEVENT(THIS.progress, "OnCancel", THIS, "OnCancel")

	WITH THIS.progress
		.Caption = "Receiving data..."
		.downloadedbytes=0
		.totalbytes=VAL(THIS.GetResponseHeader("Content-Length"))
		.Refresh
	ENDWITH
	
	DO WHILE .T.
		IF 	THIS.transferaborted
			EXIT
		ENDIF

		= InternetQueryDataAvailable(THIS.hRequest, @nAvailBt, 0,0)
		IF nAvailBt = 0
			EXIT
		ENDIF

		cBuffer = REPLI(Chr(0), nAvailBt)
		IF InternetReadFile(THIS.hRequest, @cBuffer, nAvailBt, @nReadBt) = 1
			THIS.ResponseText = THIS.ResponseText +;
				SUBSTR(cBuffer, 1, nReadBt)
			THIS.ResponseLen = THIS.ResponseLen + m.nReadBt
			THIS.progress.downloadedbytes = THIS.ResponseLen
			DOEVENTS
		ENDIF
	ENDDO
	= UNBINDEVENT(THIS.progress)

PROTECTED PROCEDURE declare
	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER InternetReadFile IN wininet;
		INTEGER hFile, STRING @lpBuffer,;
		INTEGER dwBytesToRead, INTEGER @lpdwBytesRead

	DECLARE INTEGER HttpSendRequest IN wininet;
		INTEGER hRequest, STRING @lpszHeaders,;
		INTEGER dwHeadersLength, STRING @lpOptional,;
		INTEGER dwOptionalLength

	DECLARE INTEGER HttpOpenRequest IN wininet;
		INTEGER hConnect, STRING lpszVerb,;
		STRING lpszObjectName, STRING lpszVersion,;
		STRING lpszReferer, INTEGER lpszAcceptTypes,;
		INTEGER dwFlags, INTEGER dwContext

	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType, STRING sProxyName,;
		STRING sProxyBypass, STRING lFlags

	DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername, STRING sPsword,;
		INTEGER lService, INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER InternetQueryDataAvailable IN wininet;
		INTEGER hFile, INTEGER @lpdwBytesAvailable,;
		INTEGER dwFlags, INTEGER dwContext

	DECLARE INTEGER HttpQueryInfo IN wininet;
		INTEGER hRequest, LONG dwInfoLevel, STRING @lpvBuffer,;
		LONG @lpdwBufferLength, LONG @lpdwIndex
ENDDEFINE

#ENDIF
