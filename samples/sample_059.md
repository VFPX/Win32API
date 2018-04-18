[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using FtpCommand

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.


## Before you begin:
<!-- Anatoliy -->
<table cellspacing=3 cellpadding=0 border=0><tr><td valign=top><img src="../images/readarticle.gif" border=0></td><td valign=top class=fdescr><a href="?article=3">Programming File Transfer Protocol in Visual FoxPro </a></td></tr></table>  

 
See also:

* [Winsock: accessing FTP](sample_386.md)  
<!-- Anatoliy -->
Complete FTP solution:  
<a href="http://www.news2news.com/vfp/?solution=1&src=x59"><img src="../images/ftplib_270_48.jpg" width=270 height=48 border=0  vspace=5 hspace=5 alt="Download FTP Class Library"></a>  
 
  
***  


## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER   0
#DEFINE INTERNET_OPEN_TYPE_DIRECT      1
#DEFINE INTERNET_SERVICE_FTP           1
#DEFINE FTP_TRANSFER_TYPE_ASCII        1
#DEFINE FTP_TRANSFER_TYPE_BINARY       2
SET MEMOWIDTH TO 250
DO decl

PRIVATE hWininet, hSession, cServer, cUser, cPwd
STORE 0 TO hWininet, hSession
cServer = "ftp.gutenpress.org"
cUser = "anonymous"
cPwd = "ano@nymous.com"

IF Connect2Ftp()
	DO ShowResponse
	= ExecCmd("SYST", 0)
	= ExecCmd("HELP", 0)

*	DO test1
*	DO test2
*	DO test3
	
	= ExecCmd("QUIT", 0)

	= InternetCloseHandle(hSession)
	= InternetCloseHandle (hWininet)
ELSE
	? "Not connected to", cServer
ENDIF
* end of main

PROCEDURE test1  && root directory list
	= ExecCmd("LIST", 1)

PROCEDURE test2
* these two commands can be replaced with "LIST <directory name>"
	= ExecCmd("CWD pub/gutenberg", 0)
	= ExecCmd("PWD", 0)
*	= ExecCmd("LIST", 1)

PROCEDURE test3  && retrieving an ASCII file
	= ExecCmd("RETR pub/gutenberg/donate-howto.txt", 1)

FUNCTION Connect2Ftp
	* opening access to Inet functions
	hWininet = InternetOpen("vfp", INTERNET_OPEN_TYPE_DIRECT, 0,0,0)

	IF hWininet = 0
	* wininet.dll not available
		RETURN .F.
	ENDIF

	* connecting to FTP
	hSession = InternetConnect(hWininet, cServer,;
		INTERNET_INVALID_PORT_NUMBER,;
		cUser, cPwd, INTERNET_SERVICE_FTP, 0,0)

	IF hSession = 0
	* connection failed
		= InternetCloseHandle(hWininet)
		RETURN .F.
	ENDIF
RETURN .T.

FUNCTION ExecCmd(lcCommand, fExpectResponse)
* note that ASCII type is hard-coded
	? ">>", lcCommand
	LOCAL nResult
	hFile = 0
	nResult = FtpCommand (hSession, fExpectResponse,;
		FTP_TRANSFER_TYPE_ASCII, lcCommand, 0, @hFile)

	IF nResult = 0
		? "Command execution error:", GetLastError()
		RETURN
	ENDIF

	IF hFile <> 0
	* if there is a return - display it on the screen
		lnBufsize = 128		&& reading buffer size
		?
		DO WHILE .T.
			lcBuffer = REPLI (Chr(0), lnBufsize)
			lnBytesRead = 0
			IF InternetReadFile(hFile, @lcBuffer, lnBufsize,;
				@lnBytesRead) = 1
				lcBuffer = LEFT(lcBuffer, lnBytesRead)
				?? lcBuffer
				IF lnBytesRead < lnBufsize
					EXIT
				ENDIF
			ELSE
				EXIT
			ENDIF
		ENDDO
		= InternetCloseHandle (hFile)
	ENDIF
	DO ShowResponse

PROCEDURE ShowResponse
	LOCAL nError, cBuffer, nBufsize
	nBufsize = 16384
	cBuffer = Repli(Chr(0), nBufsize)
	nError = 0
	IF InternetGetLastResponseInfo(@nError, @cBuffer, @nBufsize) <> 0
		? LEFT(cBuffer, nBufsize)
	ENDIF

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType,;
		STRING sProxyName, STRING sProxyBypass, STRING lFlags

	DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername,;
		STRING sPassword, INTEGER lService,;
		INTEGER lFlags,INTEGER lContext

	DECLARE INTEGER FtpCommand IN wininet;
		INTEGER hConnect, INTEGER fExpectResponse,;
		INTEGER dwFlags, STRING lpszCommand,;
		STRING @dwContext, INTEGER @phFtpCommand

	DECLARE INTEGER InternetReadFile IN wininet;
		INTEGER hFile, STRING @sBuffer,;
		INTEGER lNumBytesToRead, INTEGER @dwNumberOfBytesRead

	DECLARE INTEGER InternetGetLastResponseInfo IN wininet;
		INTEGER @lpdwError, STRING @lpszBuffer,;
		INTEGER @lpdwBufferLength  
```  
***  


## Listed functions:
[FtpCommand](../libraries/wininet/FtpCommand.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetGetLastResponseInfo](../libraries/wininet/InternetGetLastResponseInfo.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  
[InternetReadFile](../libraries/wininet/InternetReadFile.md)  

## Comment:
Example revised: Feb.24, 2003  
  
* [RFC 765 (RFC765 ) File Transfer Protocol](http://www.faqs.org/rfcs/rfc765.html)  
* [How to use WinInet FTPCommand function from Visual Basic](http://www.planetsourcecode.com/vb/scripts/ShowCode.asp?txtCodeId=38947&lngWId=1)  

***  

