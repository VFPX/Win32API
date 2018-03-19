[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve the size of a remote file (FTP)

## Before you begin:
See also:

* [How to retrieve the size of a local file](sample_114.md)  
  
***  


## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER   0
#DEFINE INTERNET_OPEN_TYPE_DIRECT      1
#DEFINE INTERNET_SERVICE_FTP           1
#DEFINE FTP_TRANSFER_TYPE_ASCII        1
#DEFINE FTP_TRANSFER_TYPE_BINARY       2

#DEFINE GENERIC_READ 0x80000000
#DEFINE GENERIC_WRITE 0x40000000

    PUBLIC hOpen, hFtpSession
    DO declare

	IF connect2ftp ("ftp.???.???", "???", "???")
		lcRemoteFile = "fpttest/win32api.txt"

		hFile = FtpOpenFile(hFtpSession, lcRemoteFile,;
				GENERIC_READ, FTP_TRANSFER_TYPE_BINARY, 0)

		IF hFile <> 0
			LOCAL lnSizeHigh
			lnSizeHigh = 0
			? "Remote file size:", FtpGetFileSize (hFile, @lnSizeHigh)
			= InternetCloseHandle (hFile)
		ENDIF

		= InternetCloseHandle (hFtpSession)
		= InternetCloseHandle (hOpen)
	ENDIF

PROCEDURE declare
	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType,;
		STRING sProxyName, STRING sProxyBypass, STRING lFlags
	
	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername, STRING sPassword,;
		INTEGER lService, INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpOpenFile IN wininet;
		INTEGER hFtpSession, STRING sFileName,;
		INTEGER lAccess, INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpGetFileSize IN wininet;
		INTEGER hFile, INTEGER @lpdwFileSizeHigh
RETURN

FUNCTION  connect2ftp (strHost, strUser, strPwd)
	* open access to Inet functions
	hOpen = InternetOpen ("w32rmsize",;
			INTERNET_OPEN_TYPE_DIRECT, 0, 0, 0)

	IF hOpen = 0
		? "Unable to get access to WinInet.Dll"
		RETURN .F.
	ENDIF

	* connect to FTP
	hFtpSession = InternetConnect (hOpen, strHost,;
		INTERNET_INVALID_PORT_NUMBER,;
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
[FtpGetFileSize](../libraries/wininet/FtpGetFileSize.md)  
[FtpOpenFile](../libraries/wininet/FtpOpenFile.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

## Comment:
The code does not process the high-order part *lpdwFileSizeHigh*. Process this part for obtaining sizes of files larger than 4 GBytes.  
  
* * *  
2013-Jul-08: <a href="http://msdn.microsoft.com/en-us/library/system.net.webrequestmethods.ftp.getfilesize.aspx">WebRequestMethods.Ftp.GetFileSize</a> fails with error 550: SIZE not allowed in ASCII mode.  
   
Apparently there is no way to make the FtpWebRequest to <a href="http://social.msdn.microsoft.com/Forums/en-US/0c38814e-d8e3-49f3-8818-b5306cc100ce/ftpwebrequestusebinary-does-not-work">send the TYPE I command before the SIZE</a> ?.  
  
***  

