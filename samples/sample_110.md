[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to download this reference`s archive through WinInet functions using InternetOpenUrl

## Before you begin:
Check [similar example](sample_175.md) based on URL Monikers functions.  
  
***  


## Code:
```foxpro  
#DEFINE INTERNET_OPEN_TYPE_DIRECT    1
#DEFINE INTERNET_FLAG_NEED_FILE     16

	DO decl		&& declare external functions

	* initialize Wininet library
	PRIVATE hOpen

    hOpen = InternetOpen ("w32vfp=110", INTERNET_OPEN_TYPE_DIRECT, 0, 0, 0)
    IF hOpen = 0
		? "GetLastError:", GetLastError()
		? "WinInet is not available on this computer"
		RETURN
    ENDIF

	LOCAL lcBaseUrl, lcDstPath, hFile, lcFile

	lcBaseUrl = "https://github.com/VFPX/Win32API/tree/master/downloads/"
	lcFile    = "w32data.zip"	&& remote archive file with DBF tables
	lcDstPath = "c:\Temp\"  && assign a destination directory

	* get a handle of the remote file
	hFile = InternetOpenUrl (hOpen,;
				lcBaseUrl + lcFile, "", 0,;
				INTERNET_FLAG_NEED_FILE, 0)

	IF hFile <> 0
	* even if there is no such file, the most evidently
	* you will get an ASCII file in response (404 error page)
		= http2local (hFile, lcDstPath + lcFile)
		= InternetCloseHandle (hFile)
	ELSE
		? "Unable to open source file"
		? "GetLastError:", GetLastError()
	ENDIF
	
	* release WinInet library
    = InternetCloseHandle (hOpen)
RETURN		&& main

FUNCTION http2local (hSource, lcTarget)
* reads data from a remote file
#DEFINE TransferBuffer   4096
	? lcTarget + " "
	
	* create the target file
	hTarget = FCREATE (lcTarget)
	IF (hTarget = -1)
		?? "invalid target file name"
		RETURN -1
	ENDIF

	LOCAL lnTotalBytesRead, lnBytesRead
	lnTotalBytesRead = 0
	
	DO WHILE .T.
		lcBuffer = REPLI (Chr(0), TransferBuffer)
		lnBytesRead = 0

		IF InternetReadFile (hSource, @lcBuffer,;
			TransferBuffer, @lnBytesRead) = 1

			= FWRITE (hTarget, lcBuffer, lnBytesRead)
			IF lnBytesRead = 0
				EXIT
			ENDIF

			lnTotalBytesRead = lnTotalBytesRead + lnBytesRead
			?? "�"
		ELSE
			EXIT
		ENDIF
	ENDDO

	= FCLOSE (hTarget)
	?? " " + LTRIM(STR(lnTotalBytesRead)) + " bytes Ok"
RETURN  lnBytesRead

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER InternetOpen IN wininet;
		STRING sAgent, INTEGER lAccessTypem,;
		STRING sProxyName, STRING ProxyBypass, STRING lFlags

	DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

	DECLARE INTEGER InternetOpenUrl IN wininet;
		INTEGER hInternet, STRING lpszUrl, STRING lpszHeaders,;
		INTEGER dwHeadersLength, INTEGER dwFlags,;
		INTEGER dwContext

	DECLARE INTEGER InternetReadFile IN wininet;
		INTEGER hFile, STRING @lpBuffer,;
		INTEGER dwNumberOfBytesToRead,;
		INTEGER @lpdwNumberOfBytesRead  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  
[InternetOpenUrl](../libraries/wininet/InternetOpenUrl.md)  
[InternetReadFile](../libraries/wininet/InternetReadFile.md)  

## Comment:
This particular example let you download VFP tables containing the recent data of this reference:  
\- list of functions  
\- list of examples  
\- function groups  
\- list of libraries  
  
After that you can work with this data locally.   
  
Through Hypertext Transfer Protocol -- also known as HTTP -- this program opens a remote Zip archive and transfers it into a local file on your computer.  
  
Though the primary task of this code is to demonstrate InternetOpenUrl function.  
  
And of course, you can [download it directly here](../downloads/w32data.zip).  
  
***  

