[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to remove FTP directory

## Before you begin:
To run this code you must have an appropriate user level to access the FTP.  
  
***  


## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER   0
#DEFINE INTERNET_OPEN_TYPE_DIRECT      1
#DEFINE INTERNET_SERVICE_FTP           1
#DEFINE FTP_TRANSFER_TYPE_ASCII        1
#DEFINE FTP_TRANSFER_TYPE_BINARY       2

	PUBLIC hOpen, hFtpSession
    DO decl

	* select FTP connection providing you an appropriate access level
	* in all cases it can not be any "anonymous" access
	IF connect2ftp ("ftp.???.???", "???", "???")
		lnResult = FtpRemoveDirectory (hFtpSession, "ftptest")
	
		* possible reasons for the directory not being removed:
		* - your access level is not valid
		* - the directory does not exist
		* - the directory is not empty
		IF lnResult = 0
			? GetLastError()	&& usually the error code is 12003
		ENDIF

		= InternetCloseHandle (hFtpSession)
		= InternetCloseHandle (hOpen)
	ENDIF

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32
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

	DECLARE INTEGER FtpRemoveDirectory IN wininet.dll;
    	INTEGER hConnect,;
		STRING  lpszDirectory
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
[FtpRemoveDirectory](../libraries/wininet/FtpRemoveDirectory.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  


***  

