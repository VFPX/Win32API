[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Uploading file to the FTP server using InternetWriteFile

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

<!-- Anatoliy --> 

## Before you begin:
<table cellspacing=3 cellpadding=0 border=0><tr><td valign=top><img src="../images/readarticle.gif" border=0></td><td valign=top class=fdescr><a href="?article=3">Programming File Transfer Protocol in Visual FoxPro </a></td></tr></table>    

  
***  

## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER 0
#DEFINE INTERNET_OPEN_TYPE_DIRECT 1
#DEFINE INTERNET_SERVICE_FTP 1
#DEFINE FTP_TRANSFER_TYPE_ASCII 1
#DEFINE FTP_TRANSFER_TYPE_BINARY 2
#DEFINE GENERIC_READ 0x80000000
#DEFINE GENERIC_WRITE 0x40000000

PUBLIC hOpen, hFtpSession
DO declare

* select FTP connection on which you an appropriate access level
* in all cases it can not be any "anonymous" access
IF connect2ftp("ftp.???.???", "???", "???")
	lcSourcePath = "C:\Temp\"       && local source directory
	lcTargetPath = "ftptest/"       && ftp destination directory
	lnFiles = ADIR(arr, lcSourcePath + "*.html")

	FOR lnCnt=1 TO lnFiles
		lcSource = lcSourcePath + LOWER(arr [lnCnt, 1])
		lcTarget = lcTargetPath + LOWER(arr [lnCnt, 1])
		? lcSource + " -> " + lcTarget
		?? local2ftp(hFtpSession, lcSource, lcTarget)
	ENDFOR

	= InternetCloseHandle(hFtpSession)
	= InternetCloseHandle(hOpen)
ENDIF

PROCEDURE declare
	DECLARE INTEGER InternetOpen IN wininet.dll;
		STRING sAgent, INTEGER lAccessType, STRING sProxyName,;
		STRING sProxyBypass, STRING lFlags

	DECLARE INTEGER InternetCloseHandle IN wininet.dll INTEGER hInet

	DECLARE INTEGER InternetConnect IN wininet.dll;
		INTEGER hInternetSession, STRING sServerName,;
		INTEGER nServerPort, STRING sUsername,;
		STRING sPassword, INTEGER lService,;
		INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpOpenFile IN wininet.dll;
		INTEGER hFtpSession, STRING  sFileName,;
		INTEGER lAccess, INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER InternetWriteFile IN wininet;
		INTEGER hFile, STRING @sBuffer,;
		INTEGER lBytesToWrite, INTEGER @dwBytesWritten

FUNCTION connect2ftp(strHost, strUser, strPwd)
	* open access to Inet functions
	hOpen = InternetOpen("vfp", INTERNET_OPEN_TYPE_DIRECT, 0, 0, 0)

	IF hOpen = 0
		? "Unable to get access to WinInet.Dll"
		RETURN .F.
	ENDIF

	* connect to FTP
	hFtpSession = InternetConnect(hOpen, strHost, INTERNET_INVALID_PORT_NUMBER,;
		strUser, strPwd, INTERNET_SERVICE_FTP, 0, 0)

	IF hFtpSession = 0
	* close access to Inet functions and exit
		= InternetCloseHandle(hOpen)
		? "FTP " + strHost + " is not available"
		RETURN .F.
	ELSE
		? "Connected to " + strHost + " as: [" + strUser + ", *****]"
	ENDIF
RETURN .T.

FUNCTION local2ftp(hConnect, lcSource, lcTarget)
* copying local file to the remote target
	hSource = FOPEN(lcSource)
	IF (hSource = -1)
		RETURN -1
	ENDIF

	* this call creates a new remote file
	hTarget = FtpOpenFile(hConnect, lcTarget, GENERIC_WRITE,;
		FTP_TRANSFER_TYPE_BINARY, 0)
	IF hTarget = 0
		= FCLOSE(hSource)
		RETURN -2
	ENDIF

	lnBytesWritten = 0
	lnChunkSize = 256	&& 128, 512, 16384 and so on are Ok

	DO WHILE Not FEOF(hSource)
		lcBuffer = FREAD(hSource, lnChunkSize)
		lnLength = Len(lcBuffer)
		IF lnLength > 0
			IF InternetWriteFile(hTarget, @lcBuffer, lnLength, @lnLength) = 1
				lnBytesWritten = lnBytesWritten + lnLength
				* at this point you can display the progress
				* and test events: keyboard, mouse etc.
				* to decide on aborting the upload
				?? "�"	&& you can put link to a progress bar here instead
			ELSE
				EXIT
			ENDIF
		ELSE
			EXIT
		ENDIF
	ENDDO
	= InternetCloseHandle(hTarget)
	= FCLOSE(hSource)
RETURN lnBytesWritten  
```  
***  


## Listed functions:
[FtpOpenFile](../libraries/wininet/FtpOpenFile.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  
[InternetWriteFile](../libraries/wininet/InternetWriteFile.md)  

## Comment:
Unlike the FtpPutFile using this function you have control through the whole uploading process. Of course, it depends on how many chunks you split the source file to.  
  
Between chunks you can display the progress of uploading. As well you can test pressed keys or other events and stop the uploading.  
  
***  

