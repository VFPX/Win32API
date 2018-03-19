[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using InternetSetFilePointer when resuming interrupted download from the Internet

## Before you begin:
The remote source file, presented in this example, is large enough -- 3 465 231 bytes.  

When running this code try to interrupt it completely by pushing the Esc key, and starting the program again one or more times to complete the download. Clear memory or even quit VFP between the calls.  
  
***  


## Code:
```foxpro  
DO decl

PRIVATE hInternet, pcRemotePath, pcLocalPath, pcFilename,;
	phRemote, phLocal

STORE -1 TO hInternet, phRemote, phLocal
pcRemotePath = "http://www.php.net/distributions/manual/"
pcFilename = "php_manual_es.chm"
pcLocalPath = "c:\temp\"  && valid path

#DEFINE INTERNET_OPEN_TYPE_DIRECT   1
hInternet = InternetOpen ("w32vfp", INTERNET_OPEN_TYPE_DIRECT, "","", 0)

IF hInternet <> 0
	ON ERROR DO CloseAllHandles
	ON ESCA DO CloseAllHandles

	= ReadRemote (pcRemotePath+pcFilename, pcLocalPath+pcFilename)

	ON ESCAPE
	ON ERROR
	= CloseAllHandles ()
ENDIF

PROCEDURE  ReadRemote (lcSourceFile, lcTargetFile)
#DEFINE INTERNET_FLAG_NEED_FILE  16
#DEFINE OF_WRITE                  1
#DEFINE FILE_ATTRIBUTE_NORMAL   128
#DEFINE CREATE_ALWAYS             2
#DEFINE FILE_SHARE_WRITE          2
#DEFINE GENERIC_WRITE 0x40000000

#DEFINE FILE_BEGIN 0
#DEFINE TransferBuffer 0x4000

	LOCAL lcOpenBuffer, lcBuffer,;
		lnSizeLo, lnSizeHi, lnBytesRead, lnTotalBytesRead

	phRemote = InternetOpenUrl (hInternet, pcRemotePath + pcFilename,;
			"", 0, INTERNET_FLAG_NEED_FILE, 0)

	IF phRemote <> 0
		STORE 0 TO lnSizeLo, lnSizeHi
		lcOpenBuffer = Repli(Chr(0), 250)

		IF FILE (lcTargetFile)
			phLocal = OpenFile (lcTargetFile, @lcOpenBuffer, OF_WRITE)
			lnSizeLo = GetFileSize (phLocal, @lnSizeHi)
			IF lnSizeLo > 0
				? "Local file found, size LO and HI:", lnSizeLo, lnSizeHi
				? "Setting the remote file position ..."
				= SetFilePointer (phLocal, lnSizeLo, lnSizeHi, FILE_BEGIN)
				?? "Ok"
				
				? "Setting the EOF state for the local file..."
				= InternetSetFilePointer (phRemote,;
					lnSizeLo, lnSizeHi, FILE_BEGIN, 0)
				?? "Ok"
			ENDIF
		ELSE
			? "Local file not found, created..."
			phLocal = CreateFile (lcTargetFile, GENERIC_WRITE,;
					FILE_SHARE_WRITE, 0, CREATE_ALWAYS,;
					FILE_ATTRIBUTE_NORMAL, 0)
			?? "Ok"
		ENDIF
		?

		lnTotalBytesRead = 0
		DO WHILE .T.
			lcBuffer = REPLI (Chr(0), TransferBuffer)
			STORE 0 TO lnBytesWritten, lnBytesRead

			IF InternetReadFile (phRemote, @lcBuffer,;
					TransferBuffer, @lnBytesRead) <> 0

				IF lnBytesRead > 0
					= WriteFile (phLocal, @lcBuffer,;
						lnBytesRead, @lnBytesWritten, 0)
					lnTotalBytesRead = lnTotalBytesRead + lnBytesRead
					?? "·"
				ELSE
					EXIT
				ENDIF
			ELSE
				EXIT
			ENDIF
		ENDDO
		? "lnTotalBytesRead:", lnTotalBytesRead
	ENDIF
RETURN

PROCEDURE  CloseAllHandles
	IF phRemote <> -1
		? "Remote closed"
		= InternetCloseHandle (phRemote)
		phRemote = -1
	ENDIF
	IF phLocal <> -1
		? "Local closed"
		= CloseHandle (phLocal)
		phLocal = -1
	ENDIF
	IF hInternet <> -1
		? "Inet access closed"
		= InternetCloseHandle (hInternet)
		hInternet = -1
	ENDIF
RETURN

PROCEDURE  decl
	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessType,;
		STRING sProxyName, STRING sProxyBypass, STRING lFlags

	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetSetFilePointer IN wininet;
		INTEGER hFile, INTEGER lDistanceToMove,;
		INTEGER pReserved, INTEGER dwMoveMethod, INTEGER dwContext

	DECLARE INTEGER InternetOpenUrl IN wininet;
		INTEGER hInternet, STRING lpszUrl, STRING lpszHeaders,;
		INTEGER dwHeadersLength, INTEGER dwFlags, INTEGER dwContext

	DECLARE INTEGER InternetReadFile IN wininet;
		INTEGER hFile, STRING @lpBuffer,;
		INTEGER dwBytesToRead, INTEGER @lpdwBytesRead

	DECLARE INTEGER GetFileSize IN kernel32;
		INTEGER hFile, INTEGER @lpFileSizeHigh

	DECLARE INTEGER WriteFile IN kernel32;
		INTEGER hFile, STRING @lpBuffer, INTEGER nBt2Write,;
		INTEGER @lpBtWritten, INTEGER lpOverlapped

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwDesiredAccess,;
		INTEGER dwShareMode, INTEGER lpSecurityAttr,;
		INTEGER dwCreationDisp, INTEGER dwFlagsAndAttrs,;
		INTEGER hTemplateFile

	DECLARE INTEGER OpenFile IN kernel32;
		STRING lpFileName, STRING @lpReOpenBuff, INTEGER wStyle

	DECLARE INTEGER SetFilePointer IN kernel32;
		INTEGER hFile, INTEGER lDistanceToMove,;
		INTEGER lpDistanceToMoveHigh, INTEGER dwMoveMethod

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[GetFileSize](../libraries/kernel32/GetFileSize.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  
[InternetOpenUrl](../libraries/wininet/InternetOpenUrl.md)  
[InternetReadFile](../libraries/wininet/InternetReadFile.md)  
[InternetSetFilePointer](../libraries/wininet/InternetSetFilePointer.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  
[SetFilePointer](../libraries/kernel32/SetFilePointer.md)  
[WriteFile](../libraries/kernel32/WriteFile.md)  

## Comment:
If the target local file is found, the program opens the source remote file and sets its pointer equally to the local file size. The local pointer is set to EOF position.  
  
The InternetSetFilePointer parameters include pReserved parameters, which MSDN suggests to set to zero. After comparing interfaces of InternetSetFilePointer and SetFilePointer it is quite logical to say that this parameter is similar to the lpDistanceToMoveHigh (high DWORD).  
  
The simplest way to check this assumption is to download in N-steps a remote file larger than 0xffffffff (4,294,967,295) bytes -- 4 Gb. And at least one interruption should be made after the critical DWORD length offset.  
  
***  

