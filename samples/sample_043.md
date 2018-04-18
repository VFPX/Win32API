[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to download a file from the FTP server using FtpGetFile

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.


## Before you begin:
See also:

* [Custom FTP Class for Visual FoxPro application](sample_344.md)  
<!-- Anatoliy --> 
* [Programming File Transfer Protocol in Visual FoxPro ](?article=3)  

  
***  


## Code:
```foxpro  
* lAccessType - some values
#DEFINE INTERNET_INVALID_PORT_NUMBER  0
#DEFINE INTERNET_OPEN_TYPE_DIRECT     1
#DEFINE INTERNET_OPEN_TYPE_PROXY      3
#DEFINE INTERNET_DEFAULT_FTP_PORT     21

* lFlags: only a few
#DEFINE INTERNET_FLAG_ASYNC 0x10000000
#DEFINE INTERNET_FLAG_FROM_CACHE  0x1000000
#DEFINE INTERNET_FLAG_OFFLINE  0x1000000
#DEFINE INTERNET_FLAG_CACHE_IF_NET_FAIL 0x10000

* registry access settings
#DEFINE INTERNET_OPEN_TYPE_PRECONFIG  0
#DEFINE FTP_TRANSFER_TYPE_ASCII       1
#DEFINE FTP_TRANSFER_TYPE_BINARY      2

* type of service to access
#DEFINE INTERNET_SERVICE_FTP     1
#DEFINE INTERNET_SERVICE_GOPHER  2
#DEFINE INTERNET_SERVICE_HTTP    3

* file attributes
#DEFINE FILE_ATTRIBUTE_NORMAL  0x80

	do decl

	* you are free to choose any name, say "John Dow"
	* server-side variable $AGENT is the target
	sAgent = "vfp6"

	sProxyName = Chr(0)		&& I have no proxy
	sProxyBypass = Chr(0)	&& so there is nothing to bypass
	lFlags = 0				&& no flags used

	* initialize access to Inet functions
	hOpen = InternetOpen (sAgent, INTERNET_OPEN_TYPE_DIRECT,;
		sProxyName, sProxyBypass, lFlags)

	IF hOpen = 0
		? "Unable to get access to WinInet.Dll"
		RETURN
	ELSE
		? "Wininet access handle: " + LTRIM(STR(hOpen))
	ENDIF
	
	* connection parameters - you better put your data
	strHost = "ftp.gnu.org"
	strUser = "anonymous"		&& this user name is accepted almost everywhere
	strPwd  = "vfp" + SYS(3) + "@msn.com"

	* connecting to the FTP
	hFtpSession = InternetConnect (hOpen, strHost,;
		INTERNET_INVALID_PORT_NUMBER,;
		strUser, strPwd,;
		INTERNET_SERVICE_FTP, 0, 0)

	IF hFtpSession = 0
	* close access to Inet functions and exit
		= InternetCloseHandle (hOpen)
		? "Unable to connect to the selected FTP"
		RETURN
	ELSE
		? "Connected to " + strHost + " as: [" + strUser + ", " + strPwd + "]"
		? "FTP connection handle: " + LTRIM(STR(hFtpSession))
	ENDIF
	
	* downloading a file from the FTP
	* no check whether the target file exists
	lpszRemoteFile = "welcome.msg"		    && if it still exists
	lpszNewFile    = "c:\Temp\welcome.txt"	&& check the destination folder
	fFailIfExists  = 0		&& do not stop if the target already exists
	dwContext      = 0

	lnResult = FtpGetFile (hFtpSession, lpszRemoteFile, lpszNewFile,;
		fFailIfExists, FILE_ATTRIBUTE_NORMAL, FTP_TRANSFER_TYPE_ASCII,;
		dwContext)

	IF lnResult = 1
		MODI FILE (lpszNewFile)	&& opens the result file
	ELSE
		? "Unable to download selected file"
	ENDIF

	* close handles
	= InternetCloseHandle (hFtpSession)
	= InternetCloseHandle (hOpen)
RETURN		&& main

PROCEDURE  decl
	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType, STRING sProxyName,;
		STRING sProxyBypass, STRING  lFlags
	
	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING  sServerName,;
		INTEGER nServerPort, STRING  sUsername,;
		STRING  sPassword, INTEGER lService,;
		INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpGetFile IN wininet;
		INTEGER hFtpSession, STRING  lpszRemoteFile,;
		STRING  lpszNewFile, INTEGER fFailIfExists,;
		INTEGER dwFlagsAndAttributes,;
		INTEGER dwFlags, INTEGER dwContext  
```  
***  


## Listed functions:
[FtpGetFile](../libraries/wininet/FtpGetFile.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

## Comment:
This example is simplified: I know that this remote file exists on the FTP, and it is of the ASCII type.  
  
Well I suggest you better choose another FTP and a file name to test. Just to avoid disturbing folks at the GNU ftp.  

***  

