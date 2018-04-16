[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Custom HttpRequest class (WinINet)

## Short description:
This class is used for sending "GET" and "POST" HTTP requests to webserver and receiving responses.  
***  


## Before you begin:
This class is used for sending "GET" and "POST" HTTP requests. Use the following code to test it:  

```foxpro
LOCAL oHttp  
oHttp = CreateObject("THttpRequest")  
WITH oHttp  
	.Open("GET", "https://github.com/VFPX/Win32API/blob/master/samples/sample_185.md")  
	.Send()  

	? .Status, .StatusText  
	? "Response length:", .ResponseLen  
	? .GetAllResponseHeaders()  
*	? .GetResponseHeader("content-type")  

	STRTOFILE(.ResponseText, "response.txt")  
	MODI FILE response.txt NOWAIT  
ENDWITH
```
See also:

* [Custom WinHTTP HttpRequest class (WinHTTP)](sample_397.md)  
  
***  


## Code:
```foxpro  
DEFINE CLASS THttpRequest As Custom
#DEFINE INTERNET_OPEN_TYPE_DIRECT 1
#DEFINE INTERNET_SERVICE_HTTP 3
#DEFINE INTERNET_DEFAULT_HTTP_PORT 80
#DEFINE INTERNET_FLAG_RELOAD 0x80000000

* some of QueryInfo constants
#DEFINE HTTP_QUERY_CONTENT_TYPE      1   && text/html
#DEFINE HTTP_QUERY_DATE              9   && Sat, 01 Nov 2003 21:49:03 GMT
#DEFINE HTTP_QUERY_VERSION           18  && HTTP/1.1
#DEFINE HTTP_QUERY_STATUS_CODE       19  && 200
#DEFINE HTTP_QUERY_STATUS_TEXT       20  && OK
#DEFINE HTTP_QUERY_RAW_HEADERS       21
#DEFINE HTTP_QUERY_RAW_HEADERS_CRLF  22
#DEFINE HTTP_QUERY_SERVER            37  && Apache/1.3.26 (Unix) ...
#DEFINE HTTP_QUERY_REQUEST_METHOD    45  && GET
#DEFINE HTTP_QUERY_TRANSFER_ENCODING 63  && chunked

#DEFINE cnMaxQueryInfo  68
#DEFINE ccHttpPrefix    "http://"
#DEFINE ccSlash         "/"
#DEFINE cret            CHR(13)+CHR(10)

	Agent="VFP HttpRequest Class"
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
	DIMENSION QueryInfo[cnMaxQueryInfo,3]

PROCEDURE Init
	THIS.decl
	STORE 0 TO THIS.hInternet, THIS.hConnect, THIS.hRequest

FUNCTION GetAllResponseHeaders
	LOCAL nIndex, cResult
	cResult = ""
	FOR nIndex=1 TO THIS.ResponseHeaderCount
		cResult = cResult + THIS.ResponseHeaders[nIndex, 1] + ": " +;
			THIS.ResponseHeaders[nIndex, 2] + cret
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

FUNCTION GetQI(nIndex)
* returns QueryInfo values in 0..cnMaxQueryInfo range
RETURN Iif(BETW(nIndex, 0, cnMaxQueryInfo), THIS.QueryInfo[nIndex+1,2], "")

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

	nPos = AT(ccHttpPrefix, LOWER(cUrl))
	IF nPos <> 0  && add no http:// before
		cUrl = STUFF(cUrl, nPos, LEN(ccHttpPrefix), "")
	ENDIF
	THIS.url = cUrl

	nPos = AT(ccSlash, cUrl)
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

	IF HttpSendRequest(THIS.hRequest, @cHeaders,;
		LEN(cHeaders), @cBody, LEN(cBody)) = 0
		THIS.ErrorCode = GetLastError()
		THIS.CloseRequest
		RETURN .F.
	ENDIF

	THIS.GetQueryInfo

	* QueryInfo values including response headers are already available
	THIS.GetRequestText

	THIS.CloseRequest
RETURN .T.

PROTECTED PROCEDURE GetQueryInfo
	LOCAL nBufSize, cBuffer, nIndex, ii
	FOR ii = 1 TO cnMaxQueryInfo
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

PROTECTED PROCEDURE GetRequestText
	LOCAL nAvailBt, nReadBt, cBuffer
	STORE 0 TO nAvailBt, nReadBt

	DO WHILE .T.
		= InternetQueryDataAvailable(THIS.hRequest, @nAvailBt, 0,0)
		IF nAvailBt = 0
			EXIT
		ENDIF

		cBuffer = REPLI(Chr(0), nAvailBt)
		IF InternetReadFile(THIS.hRequest, @cBuffer, nAvailBt, @nReadBt) = 1
			THIS.ResponseText = THIS.ResponseText +;
				SUBSTR(cBuffer, 1, nReadBt)
			THIS.ResponseLen = THIS.ResponseLen + m.nReadBt
			?? "."
		ENDIF
	ENDDO

PROTECTED PROCEDURE  decl
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
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[HttpOpenRequest](../libraries/wininet/HttpOpenRequest.md)  
[HttpQueryInfo](../libraries/wininet/HttpQueryInfo.md)  
[HttpSendRequest](../libraries/wininet/HttpSendRequest.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  
[InternetQueryDataAvailable](../libraries/wininet/InternetQueryDataAvailable.md)  
[InternetReadFile](../libraries/wininet/InternetReadFile.md)  

## Comment:
*Nov. 2, 2003: code completely rewritten.*  
  
List of <a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/winhttp/http/http_status_codes.asp">HTTP Status Codes</a> on MSDN.  
  
Recommended reading:  
<a href="http://integrationadvisor.com/doc/05238">Post FoxPro Data to Your Web Server with WinInet</a> written by <a href="http://fox.wikis.com/wc.dll?Wiki~RickStrahl~People">Rick Strahl</a> and published in April 1998 issue of FoxPro Advisor.  
  
* * *  
Here is a simple example of using this class to exchange information between VFP application and ASP.Net page. Two pieces of code, VFP and .Net, are required. VFP part posts HTTP Request stuffed with some data. C# part extracts data from the request, processes it and sends back a response.  
  
Create ASP.Net Web application and call it SendRequest. Add new web form and call it ExchangeData.aspx. Both names are optional, though the complete name of the page (URL) must be provided to the VFP part.  
  
Remove all HTML code from the web form. It is not going to be used anyway; moreover it may affect sending HTTP response headers. Open the code part (C#) and add the following method to ExchangeData class.  
  
```cpp
private void ProcessRequest()  
{  
	//read HTTP Request header  
	string sender = Request.Headers["Request_Sender"];  
  
	//convert body of HTTP Request to array of bytes...  
	System.IO.Stream s = Request.InputStream;  
	byte[] buffer = new byte[(int) s.Length];  
	s.Read(buffer, 0, (int) s.Length);  
  
	//...and then to string  
	ASCIIEncoding enc = new ASCIIEncoding();  
	string b = enc.GetString(buffer);  
  
	//send back data as HTTP Response header  
	Response.AddHeader("Request_Confirmation",   
		"Dear " + sender +  
		"! Your request has been received at " +  
		DateTime.Now.ToString() + ".");  
  
	//send back data as HTTP Response body  
	Response.Write("Request received: " + b);  
	Response.End();  
}
```
Call ProcessRequest from Page_Load method of the web form. Compile .Net SendRequest project.  
  
Then create a VFP part for sending requests and obtaining responses from ASP.Net page. As I said, this part must include URL for the webpage. The local server is used for simplicity.  
  
```foxpro
#DEFINE DESTINATION_URL;  
	"http://localhost/sendrequest/exchangedata.aspx"  
SET PROCEDURE TO HttpRequest ADDITIVE  
  
LOCAL oHttp As THttpRequest  
oHttp = CREATEOBJECT("THttpRequest")  
  
oHttp.Open("POST", DESTINATION_URL)  
oHttp.SetRequestHeader("Request_Sender", SYS(0))  
  
WAIT WINDOW NOWAIT "Sending HTTP Request..."  
oHttp.Send(FILETOSTR("config.fpw"))  && body  
WAIT CLEAR  
  
WITH oHttp  
	? .status  && returns "200"  
	? .GetResponseHeader("Request_Confirmation")  
	? .ResponseText  
ENDWITH
```

***  

