[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to delete file on FTP server

## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER   0
#DEFINE INTERNET_OPEN_TYPE_DIRECT      1
#DEFINE INTERNET_SERVICE_FTP           1
#DEFINE FTP_TRANSFER_TYPE_ASCII        1
#DEFINE FTP_TRANSFER_TYPE_BINARY       2

	PUBLIC hOpen, hFtpSession
    DO decl

	IF connect2ftp ("ftp.???.???", "???", "???")

		* no wildcards accepted; valid file name only
		? FtpDeleteFile (hFtpSession, "ftptest/noname.txt")

		= InternetCloseHandle (hFtpSession)
		= InternetCloseHandle (hOpen)
	ENDIF

PROCEDURE  decl
	DECLARE INTEGER InternetOpen IN wininet.dll;
		STRING  sAgent,;
		INTEGER lAccessType,;
		STRING  sProxyName,;
		STRING  sProxyBypass,;
		STRING  lFlags

    DECLARE INTEGER InternetCloseHandle IN wininet.dll INTEGER hInet

    DECLARE INTEGER InternetConnect IN wininet.dll;
		INTEGER hInternetSession,;
		STRING  sServerName,;
		INTEGER nServerPort,;
		STRING  sUsername,;
		STRING  sPassword,;
		INTEGER lService,;
		INTEGER lFlags,;
		INTEGER lContext

	DECLARE INTEGER FtpDeleteFile IN wininet.dll;
    	INTEGER hConnect,;
    	STRING  lpszFileName

RETURN

FUNCTION  connect2ftp (strHost, strUser, strPwd)
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
```  
***  


## Listed functions:
[FtpDeleteFile](../libraries/wininet/FtpDeleteFile.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

## Comment:
No wildcards accepted; valid file name only  
  
***  

