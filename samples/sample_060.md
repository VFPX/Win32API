[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading Internet Query options

## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER  0
#DEFINE INTERNET_OPEN_TYPE_DIRECT     1
#DEFINE INTERNET_SERVICE_FTP          1
#DEFINE FTP_TRANSFER_TYPE_ASCII       1
#DEFINE FTP_TRANSFER_TYPE_BINARY      2

#DEFINE INTERNET_OPTION_CONNECT_TIMEOUT     2
#DEFINE INTERNET_OPTION_RECEIVE_TIMEOUT     6
#DEFINE INTERNET_OPTION_SEND_TIMEOUT        5
#DEFINE INTERNET_OPTION_USERNAME            28
#DEFINE INTERNET_OPTION_PASSWORD            29
#DEFINE INTERNET_OPTION_VERSION             40
#DEFINE INTERNET_OPTION_PROXY_USERNAME      43
#DEFINE INTERNET_OPTION_PROXY_PASSWORD      44
#DEFINE INTERNET_OPTION_CONNECTED_STATE     50
#DEFINE INTERNET_OPTION_CLIENT_CERT_CONTEXT 84
    DO decl

	PRIVATE hOpen, hFtpSession
	STORE 0 TO hOpen, hFtpSession

	IF connect2ftp("ftp.linux.com", "anonymous",;
			"vfp"+LEFT(SYS(3),5)+"@win32.com")
		? GetFtpStatus (hFtpSession)
		? GetUserData (hFtpSession)
		= InternetCloseHandle (hFtpSession)
		= InternetCloseHandle (hOpen)
	ENDIF
* end of main

FUNCTION GetFtpStatus(hConnection)
	LOCAL lcBuffer, lnBufsize
	lcBuffer = " "
	lnBufsize = 0
	IF ReadOption(hConnection, INTERNET_OPTION_CONNECTED_STATE,;
		@lcBuffer, @lnBufsize)
		RETURN (LEFT(lcBuffer,1) = Chr(1))
	ENDIF
RETURN .F.

FUNCTION GetUserData(hConnection)
	LOCAL lcBuffer, lnBufsize, lcResult

	lnBufsize = 64
	lcBuffer = " "
	= ReadOption(hConnection, INTERNET_OPTION_USERNAME,;
		@lcBuffer, @lnBufsize)
	lcResult = LEFT(lcBuffer, lnBufsize)

	lnBufsize = 64
	lcBuffer = " "
	= ReadOption(hConnection, INTERNET_OPTION_PASSWORD,;
		@lcBuffer, @lnBufsize)
	lcResult = lcResult + ", " + LEFT(lcBuffer, lnBufsize)
RETURN  lcResult

FUNCTION ReadOption(hConnection, lnOption, lcBuffer, lnBufsize)
	LOCAL lnResult
	IF TYPE("lnBufsize")<>"N" Or lnBufsize<=0
	* this call determines the buffer size needed
		= InternetQueryOption(0, lnOption, @lcBuffer, @lnBufsize)
	ENDIF

	* read the option
	lcBuffer = REPLI (Chr(0), lnBufsize)
RETURN InternetQueryOption(hConnection, lnOption, @lcBuffer, @lnBufsize) = 1

FUNCTION connect2ftp(strHost, strUser, strPwd)
	* open access to Inet functions
	hOpen = InternetOpen ("vfp", INTERNET_OPEN_TYPE_DIRECT, 0, 0, 0)

	IF hOpen = 0
		? "Unable to get access to WinInet.Dll"
		RETURN .F.
	ENDIF

	* connect to FTP
	hFtpSession = InternetConnect (hOpen, strHost, INTERNET_INVALID_PORT_NUMBER,;
		strUser, strPwd, INTERNET_SERVICE_FTP, 0, 0)

	IF hFtpSession = 0
	* close access to Inet functions and exit
		= InternetCloseHandle (hOpen)
		? "FTP " + strHost + " is not available"
		RETURN .F.
	ELSE
		? "Connected to " + strHost + " as: [" + strUser + ", *****]"
	ENDIF
RETURN .T.

PROCEDURE  decl
    DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetQueryOption IN wininet;
		INTEGER hInternet, INTEGER lOption,;
		STRING @sBuffer, INTEGER @lBufferLength

	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType, STRING sProxyName,;
		STRING sProxyBypass, STRING lFlags

    DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername,;
		STRING sPassword, INTEGER lService,;
		INTEGER lFlags, INTEGER lContext

RETURN  
```  
***  


## Listed functions:
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  
[InternetQueryOption](../libraries/wininet/InternetQueryOption.md)  

## Comment:
Here you can reach [complete list of Internet Option Flags](https://msdn.microsoft.com/en-us/library/windows/desktop/aa385328(v=vs.85).aspx) as long as presented link stays valid. The MSDN is known for its volatile links.  
  
The testing of FTP status appears to be useful when you have connected to the FTP some time ago and want to validate the connection before exchanging data or sending commands.  
  
**INTERNET_OPTION_CLIENT_CERT_CONTEXT**  
This flag is not supported by InternetQueryOption. The lpBuffer parameter must be a pointer to a CERT CONTEXT structure and not a pointer to a CERT CONTEXT pointer.   
  
If an application receives ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED, it must call InternetErrorDlg or use InternetSetOption to supply a certificate before retrying the request. CertDuplicateCertificateContext is then called so that the certificate context passed can be independently released by the application.   
  
* * *  
There is an article of Ayhan AVCI   
[Connecting to a HTTPS server with SSL using Wininet, sending client certificate and reading response](https://www.codeproject.com/Articles/3898/Connecting-to-a-HTTPS-server-with-SSL-using-Winine),  
which I have found recently at the [Code Project](http://www.codeproject.com/). Though based on VB code it may still save your time.  
 
  
***  

