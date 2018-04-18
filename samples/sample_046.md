[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving list of files on the FTP directory

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

<!-- Anatoliy -->
## Before you begin:

<table cellspacing=3 cellpadding=0 border=0><tr><td valign=top><img src="../images/readarticle.gif" border=0></td><td valign=top class=fdescr><a href="?article=3">Programming File Transfer Protocol in Visual FoxPro </a></td></tr></table>  
  

***  


## Code:
```foxpro  
#DEFINE INTERNET_INVALID_PORT_NUMBER   0
#DEFINE INTERNET_OPEN_TYPE_DIRECT      1
#DEFINE INTERNET_SERVICE_FTP           1
#DEFINE FTP_TRANSFER_TYPE_ASCII        1
#DEFINE FTP_TRANSFER_TYPE_BINARY       2
#DEFINE INTERNET_FLAG_NEED_FILE       16
#DEFINE FILE_ATTRIBUTE_DIRECTORY      16

#DEFINE GENERIC_READ  0x80000000
#DEFINE GENERIC_WRITE  0x40000000

PUBLIC hOpen, hFtpSession
DO decl

	* put valid host, user, and password values for the FTP connection
	IF connect2ftp ("ftp.???.???", "???", "???")
		lcMask = "*.*"
		lcRemotePath = "prj/pages/"
		DIMEN arr [1, 3]

		FOR ii=1 TO remoteDir2array (hFtpSession, lcRemotePath, lcMask, @arr)
			?  PADR(arr [ii, 1], 20)
			?? "|"
			?? TRANS (arr [ii, 2], "999,999,999")
			?? " | "
			?? arr [ii, 3]
		ENDFOR

		= InternetCloseHandle (hFtpSession)
		= InternetCloseHandle (hOpen)
	ENDIF

PROCEDURE  decl
	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType, STRING sProxyName,;
		STRING sProxyBypass, STRING lFlags

	DECLARE INTEGER InternetCloseHandle IN wininet.dll INTEGER hInet

    DECLARE INTEGER InternetConnect IN wininet;
		INTEGER hInternetSession, STRING sServerName, INTEGER nServerPort,;
		STRING sUsername, STRING sPassword, INTEGER lService,;
		INTEGER lFlags, INTEGER lContext

	DECLARE INTEGER FtpFindFirstFile IN wininet;
		INTEGER hFtpSession, STRING lpszSearchFile,;
		STRING @lpFindFileData, INTEGER dwFlags, INTEGER dwContent

	DECLARE INTEGER InternetFindNextFile IN wininet;
		INTEGER hFind, STRING @lpvFindData

	DECLARE INTEGER FtpGetCurrentDirectory IN wininet;
		INTEGER hFtpSession, STRING @lpszDir, INTEGER @lpdwCurDir

	DECLARE INTEGER FtpSetCurrentDirectory IN wininet;
		INTEGER hFtpSession, STRING @lpszDirectory

	DECLARE INTEGER FileTimeToSystemTime IN kernel32;
		STRING @lpFileTime, STRING @lpSystemTime
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

FUNCTION  setCurrentDir (hConnection, lcNewdir)
RETURN FtpSetCurrentDirectory (hConnection, @lcNewdir) = 1

FUNCTION  getCurrentDir (hConnection)
	lcDirectory = SPACE(250)
	lnLen = Len(lcDirectory)

	IF FtpGetCurrentDirectory (hConnection, @lcDirectory, @lnLen) = 1
		RETURN LEFT(lcDirectory, lnLen)
	ELSE
		RETURN ""
	ENDIF
	
FUNCTION  remoteDir2array (hConnection, lcRemotePath, lcMask, arr)
* fill the array with file data for the given remote path

	lcStoredPath = getCurrentDir (hConnection)
	IF Not setCurrentDir (hConnection, lcRemotePath)
		RETURN -1	&& path not found
	ENDIF

	* object simulates the structure
	struct = CREATEOBJECT ("struct_WIN32_FIND_DATA")

	* finding the first file
	lnFound = 0
	lpFindFileData = REPLI (Chr(0), 320)
	hFind = FtpFindFirstFile (hConnection, lcMask,;
		@lpFindFileData, INTERNET_FLAG_NEED_FILE, 0)

	IF hFind <> 0
		DO WHILE .T.
			struct.setValue (lpFindFileData)
			IF Not struct.isDirectory()
				lnFound = lnFound + 1
				DIMEN arr [lnFound, 3]
				arr [lnFound, 1] = struct.fileName
				arr [lnFound, 2] = struct.fileSizeLo
				arr [lnFound, 3] = struct.lastWriteTime
			ENDIF

			IF InternetFindNextFile (hFind, @lpFindFileData) <> 1
				EXIT
			ENDIF
		ENDDO
		= InternetCloseHandle (hFind)
	ENDIF
	RELEASE struct
	= setCurrentDir (hConnection, lcStoredPath)
RETURN  lnFound

DEFINE CLASS struct_WIN32_FIND_DATA As Custom
*this class emulates WIN32_FIND_DATA structure
	value            = ""
	fileAttributes   = 0
	creationTimeLo   = 0
	creationTimeHi   = 0
	lastAccessTimeHi = 0
	lastAccessTimeLo = 0
	lastWriteTimeHi  = 0
	lastWriteTimeLo  = 0
	fileSizeLo	     = 0 && fileSizeHi omitted
	fileName         = ""
	creationTime     = CTOT ("")
	lastAccessTime   = CTOT ("")
	lastWriteTime    = CTOT ("")

PROCEDURE  setValue (lcValue)	
* translates the buffer"s content into the object"s properties
	THIS.value            = lcValue
	THIS.fileAttributes   = THIS.buf2num (THIS.value,  0, 4)
	THIS.creationTimeLo   = THIS.buf2num (THIS.value,  4, 4)
	THIS.creationTimeHi   = THIS.buf2num (THIS.value,  8, 4)
	THIS.lastAccessTimeHi = THIS.buf2num (THIS.value, 12, 4)
	THIS.lastAccessTimeLo = THIS.buf2num (THIS.value, 16, 4)
	THIS.lastWriteTimeHi  = THIS.buf2num (THIS.value, 20, 4)
	THIS.lastWriteTimeLo  = THIS.buf2num (THIS.value, 24, 4)
	THIS.fileSizeLo	      = THIS.buf2num (THIS.value, 32, 4)
	THIS.creationTime     = THIS.ftime2dtime (SUBSTR(THIS.value,  5, 8))
	THIS.lastAccessTime   = THIS.ftime2dtime (SUBSTR(THIS.value, 13, 8))
	THIS.lastWriteTime    = THIS.ftime2dtime (SUBSTR(THIS.value, 21, 8))

	THIS.fileName		  = ALLTRIM(SUBSTR(THIS.value, 45,250))
	IF AT(Chr(0), THIS.fileName) <> 0
		THIS.fileName = SUBSTR (THIS.fileName, 1, AT(Chr(0), THIS.fileName)-1)
	ENDIF
ENDPROC

FUNCTION  isDirectory
	RETURN BitAnd(THIS.fileAttributes, FILE_ATTRIBUTE_DIRECTORY) = FILE_ATTRIBUTE_DIRECTORY
ENDFUNC

PROTECTED FUNCTION  buf2num (lcBuffer, lnOffset, lnBytes)
* converts N bytes from the buffer into a numeric value
	lnResult = 0
	FOR ii=1 TO lnBytes
		lnResult = lnResult +;
			BitLShift(Asc(SUBSTR (lcBuffer, lnOffset+ii, 1)), (ii-1)*8)
	ENDFOR
RETURN  lnResult

PROTECTED FUNCTION  ftime2dtime (lcFileTime)
	lcSystemTime = REPLI (Chr(0), 16)
	= FileTimeToSystemTime (@lcFileTime, @lcSystemTime)

	wYear   = THIS.buf2num (lcSystemTime,  0, 2)
	wMonth  = THIS.buf2num (lcSystemTime,  2, 2)
	wDay    = THIS.buf2num (lcSystemTime,  6, 2)
	wHour   = THIS.buf2num (lcSystemTime,  8, 2)
	wMinute = THIS.buf2num (lcSystemTime, 10, 2)
	wSecond = THIS.buf2num (lcSystemTime, 12, 2)

	lcStoredSet = SET ("DATE")
	SET DATE TO MDY
	lcDate = STRTRAN (STR(wMonth,2) + "/" + STR(wDay,2) + "/" + STR(wYear,4), " ","0")
	lcTime = STRTRAN (STR(wHour,2) + ":" + STR(wMinute,2) + ":" + STR(wSecond,2), " ","0")
	ltResult = CTOT (lcDate + " " + lcTime)
	SET DATE TO &lcStoredSet
RETURN  ltResult
ENDDEFINE  
```  
***  


## Listed functions:
[FileTimeToSystemTime](../libraries/kernel32/FileTimeToSystemTime.md)  
[FtpFindFirstFile](../libraries/wininet/FtpFindFirstFile.md)  
[FtpGetCurrentDirectory](../libraries/wininet/FtpGetCurrentDirectory.md)  
[FtpSetCurrentDirectory](../libraries/wininet/FtpSetCurrentDirectory.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetConnect](../libraries/wininet/InternetConnect.md)  
[InternetFindNextFile](../libraries/wininet/InternetFindNextFile.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

## Comment:
The struct_WIN32_FIND_DATA class emulates the structure"s behaviour. The SETVALUE method receives a string of bytes (a buffer) and splits it into the properties resembling fields of a structure.  
  
***  

