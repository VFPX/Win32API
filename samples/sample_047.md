[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating a directory on the FTP

## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER  0
#DEFINE INTERNET_OPEN_TYPE_DIRECT     1
#DEFINE INTERNET_SERVICE_FTP          1
#DEFINE INTERNET_SERVICE_GOPHER       2
#DEFINE INTERNET_SERVICE_HTTP         3
DO decl

* initialize access to Inet functions
hOpen = InternetOpen ("w32ftpdir", INTERNET_OPEN_TYPE_DIRECT, 0, 0, 0)

IF hOpen = 0
		? "Unable to get access to WinInet.Dll"
	RETURN
ENDIF

* put valid FTP connection settings here
strHost = "???"
strUser = "???"
strPwd  = "???"

* connect to the FTP
hFtpSession = InternetConnect (hOpen, strHost,;
		INTERNET_INVALID_PORT_NUMBER,;
		strUser, strPwd, INTERNET_SERVICE_FTP, 0, 0)

IF hFtpSession <> 0
	IF FtpCreateDirectory (hFtpSession, "mydir" + SUBSTR(SYS(3),5)) = 1
		? "The new directory created"
	ELSE
		? "Unable to create a new directory"
	ENDIF
ELSE
	? "Unable to connect to the selected FTP"
ENDIF

* close FTP connection and Wininet access
= InternetCloseHandle (hFtpSession)
= InternetCloseHandle (hOpen)

PROCEDURE  decl
	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType,;
		STRING sProxyName, STRING sProxyBypass,;
		STRING lFlags
	
	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername, STRING sPassword,;
		INTEGER lService, INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpCreateDirectory IN wininet;
		INTEGER hFtpSession, STRING  lpszDirectory  
```  
***  


## Listed functions:
[FtpCreateDirectory](../libraries/wininet/FtpCreateDirectory.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

***  

