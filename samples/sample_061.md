[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Uploading local file to FTP server with FtpPutFile

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.


## Before you begin:
<!-- Anatoliy -->
<table cellspacing=3 cellpadding=0 border=0><tr><td valign=top><img src="../images/readarticle.gif" border=0></td><td valign=top class=fdescr><a href="?article=3">Programming File Transfer Protocol in Visual FoxPro </a></td></tr></table>  
The FtpPutFile stores a file on the FTP server in a single operation. You can not have a close control over the file transfer that you may need, for example, for displaying a progress bar. For those situations you should use the FtpOpenFile and InternetWriteFile functions.  

 
See also: [Uploading file to the FTP server using InternetWriteFile](sample_062.md).

  
***  


## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER 0
#DEFINE INTERNET_OPEN_TYPE_DIRECT 1
#DEFINE INTERNET_SERVICE_FTP 1
#DEFINE FTP_TRANSFER_TYPE_ASCII 1
#DEFINE FTP_TRANSFER_TYPE_BINARY 2
DO declare

	PRIVATE hInet, hSession
	STORE 0 TO hInet, hSession

	* select FTP connection for which you have appropriate access level
	* allowing to upload files to and rename files on the remote server
	LOCAL cHost, cUser, cPwd
	cHost = "ftp2.server.com"
	cUser = "foxpro"
	cPwd = "qwerty"

	IF connect2ftp(cHost, cUser, cPwd)

		* select valid source and target file names;
		* the source file must exist on a local drive;
		* note that the names below are just examples
		LOCAL cSource, cTarget, cRenameTo
		cSource  = "c:\temp\test.txt"
		cTarget  = "test.txt"
		cRenameTo = "test.tx~"
		
		* the Binary Transfer Type is selected that means
		* the file is transfered exactly as it is
		IF FtpPutFile(hSession, cSource,;
			cTarget, FTP_TRANSFER_TYPE_BINARY, 0) = 0
			= MESSAGEBOX("Failed to upload file " + cSource +;
				" to " + cTarget + ".     ", 48, "Error")
		ELSE
			? "File downloaded successfully."
		* if file (cRenameTo) already exists on the remote server,
		* it may be replaced with the new one being renamed,
		* or you"ll get an error message;
		* it varies with different FTP servers
			IF FtpRenameFile(hSession, cTarget, cRenameTo) = 0
				= MESSAGEBOX("Failed to rename file " + cTarget +;
					" to " + cRenameTo + ".     ", 48, "Error")
			ELSE
				? "File renamed successfully."
			ENDIF
		ENDIF

		* release system resources on exit
		= InternetCloseHandle(hSession)
		= InternetCloseHandle(hInet)
	ENDIF

FUNCTION connect2ftp(cHost, cUser, cPwd)
* this function opens access to Inet functions

	* the first parameter, lpszAgent, can be any string
	hInet = InternetOpen(VERSION(),;
		INTERNET_OPEN_TYPE_DIRECT, 0,0,0)

	IF hInet = 0
		= MESSAGEBOX("Could not open access " +;
			"to WinINet library.     ", 48, "Error")
		RETURN .F.
	ENDIF

	WAIT WINDOW NOWAIT "Establishing connection with FTP server..."
	hSession = InternetConnect(hInet, cHost,;
		INTERNET_INVALID_PORT_NUMBER,;
		cUser, cPwd, INTERNET_SERVICE_FTP, 0,0)
	WAIT CLEAR

	IF hSession = 0
	* close access to WinINet functions and exit
		= InternetCloseHandle(hInet)
		= MESSAGEBOX("FTP server [" + cHost +;
			"] can not be accessed.     ", 48, "Error")
		RETURN .F.
	ELSE
		WAIT WINDOW NOWAIT "Connected to " + cHost +;
			" as: [" + cUser + ", *****]"
	ENDIF
RETURN .T.

PROCEDURE declare
	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType, STRING sProxyName,;
		STRING sProxyBypass, STRING lFlags

	DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername,;
		STRING sPassword, INTEGER lService,;
		INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpPutFile IN wininet;
		INTEGER hConnect, STRING lpszLocalFile,;
		STRING lpszNewRemoteFile, INTEGER dwFlags,;
		INTEGER dwContext

	DECLARE INTEGER FtpRenameFile IN wininet;
		INTEGER hConnect, STRING lpszExisting,;
		STRING lpszNew  
```  
***  


## Listed functions:
[FtpPutFile](../libraries/wininet/FtpPutFile.md)  
[FtpRenameFile](../libraries/wininet/FtpRenameFile.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

## Comment:
Note that you can test this example only on FTP server for which you have sufficient access level.  
  
***  

