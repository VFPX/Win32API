[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Listing INF files in a specified directory

## Code:
```foxpro  
DO decl

#DEFINE INVALID_HANDLE_VALUE -1

#DEFINE INF_STYLE_NONE        0
#DEFINE INF_STYLE_OLDNT       1
#DEFINE INF_STYLE_WIN4        2

	LOCAL lcPath, lcBuffer, lnRequired, lnResult, lnInfStyle

*	lcPath = "c:\windows\system"
*	lcPath = "c:\windows\inf\"
*	lcPath = "c:\winnt\system32"
	lnInfStyle = INF_STYLE_OLDNT

	lnRequired = 0

	* first call with insufficient buffer
	* just to define how much space should be allocated
	* Possible error code = 122:
	* The data area passed to a system call is too small
	lcBuffer = ""

	lnResult = SetupGetInfFileList (lcPath,;
		lnInfStyle, @lcBuffer, Len(lcBuffer), @lnRequired)
	
	IF lnRequired > 0
		* output buffer resized as required
		lcBuffer = Repli(Chr(0), lnRequired)

		* another call
		lnResult = SetupGetInfFileList (lcPath,;
			INF_STYLE_OLDNT, @lcBuffer, lnRequired, @lnRequired)
	
		IF lnResult <> 0
			* resulting cursor
			CREATE CURSOR csResult (infname C(20), infstyle N(2),;
				result L, errline N(6))

			LOCAL ii, ch, lcFilename
			lcFilename = ""

			* WinMe allocates a huge buffer, but returns
			* only a few file names in it -- only a part of existing
			* INF files
			lcBuffer = Left(lcBuffer, AT(Chr(0)+Chr(0), lcBuffer)+1)

			* scan the buffer to retrieve INF file names
			FOR ii=1 TO Len(lcBuffer)
				ch = SUBSTR (lcBuffer, ii,1)
				IF ch = Chr(0)
					IF Not EMPTY(lcFilename)
						= testInfFile (lcFilename, lnInfStyle)
						lcFilename = ""
					ENDIF
				ELSE
					lcFilename = lcFilename + ch
				ENDIF
			ENDFOR
		ENDIF
	ENDIF

	IF USED ("csResult")
		SELECT csResult
		GO TOP
		BROW NORMAL NOWAIT
	ENDIF

PROCEDURE  testInfFile (lcFilename, lnInfStyle)
	LOCAL hFile, lnErrline
	lnErrline = 0

	hFile = SetupOpenInfFile (lcFilename, 0,;
		lnInfStyle, @lnErrline)

	IF hFile <> INVALID_HANDLE_VALUE
		= SetupCloseInfFile (hFile)
	ENDIF

	INSERT INTO csResult VALUES (lcFilename, lnInfStyle,;
		hFile <> INVALID_HANDLE_VALUE, m.lnErrline)
RETURN

PROCEDURE  decl
	DECLARE INTEGER SetupOpenInfFile IN setupapi;
		STRING FileName, INTEGER InfClass,;
		INTEGER InfStyle, INTEGER @ ErrorLine

	DECLARE INTEGER SetupGetInfFileList IN setupapi;
		STRING DirectoryPath, INTEGER InfStyle,;
		STRING @ ReturnBuffer, INTEGER ReturnBufferSize,;
		INTEGER @ RequiredSize

	DECLARE SetupCloseInfFile IN setupapi INTEGER InfHandle  
```  
***  


## Listed functions:
[SetupCloseInfFile](../libraries/setupapi/SetupCloseInfFile.md)  
[SetupGetInfFileList](../libraries/setupapi/SetupGetInfFileList.md)  
[SetupOpenInfFile](../libraries/setupapi/SetupOpenInfFile.md)  

## Comment:
WinNT4 lists all INF files in the directory -- Ok; but WinME -- it lists only a few of them, though it allocates a buffer that is large enough to place all existing INF files in the directory.   
  
So far I have no other explanation except a bug in WinMe (4.90.3000) implementation of this function.  
  
Whoever can test this code with more Windows versions, please share the results here.  
  
***  

