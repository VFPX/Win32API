[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Pocket PC: custom RAPI class for operating with files and folders on mobile device

## Short description:
The class creates a wrapper around RAPI functions allowing to operate with files and folders on remote Windows CE device connected to computer through ActiveSync connection.  
***  


## Before you begin:
![](../images/pocketpcs.png)  

Solutions based on this class:  
* [Folder Viewer](sample_449.md)  
* [Creating directories and files](sample_465.md)  

Note that this class creates several Collections, which makes it unusable in older Visual FoxPro versions.  
  
***  


## Code:
```foxpro  
**************************************************************
* Custom RAPI class for operating with files and folders
* on remote Windows CE device
**************************************************************
DEFINE CLASS Trapi As Custom
#DEFINE OVER_DWORD            0x100000000
#DEFINE GENERIC_READ          0x80000000
#DEFINE GENERIC_WRITE         0x40000000
#DEFINE CREATE_NEW            1
#DEFINE CREATE_ALWAYS         2
#DEFINE OPEN_EXISTING         3
#DEFINE FILE_END              2
#DEFINE FILE_ATTRIBUTE_DIRECTORY 16
#DEFINE FILE_ATTRIBUTE_NORMAL 128
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE CEDB_SEEK_BEGINNING   2
#DEFINE CEDB_ALLOWREALLOC     1
#DEFINE CEPROPVAL_SIZE        16
#DEFINE RAPIINIT_SIZE         12
#DEFINE WAIT_OBJECT_0         0
#DEFINE FAF_FOLDERS_ONLY      0x00004000
#DEFINE FAF_ATTRIB_CHILDREN   0x00001000
#DEFINE FAF_ATTRIBUTES        1
#DEFINE FAF_CREATION_TIME     2
#DEFINE FAF_LASTACCESS_TIME   4
#DEFINE FAF_LASTWRITE_TIME    8
#DEFINE FAF_SIZE_HIGH         0x0010
#DEFINE FAF_SIZE_LOW          0x0020
#DEFINE FAF_OID               0x0040
#DEFINE FAF_NAME              0x0080
#DEFINE FAF_COMPLETE          0x00ff
#DEFINE MAX_PATH              260
#DEFINE FIND_DATA_SIZE        560
	connected=.F.

PROCEDURE Init
	THIS.decl
	THIS.InitRapi()
	
PROTECTED PROCEDURE InitRapi
	LOCAL cBuffer, hEvent
	cBuffer = PADR(CHR(RAPIINIT_SIZE), RAPIINIT_SIZE, CHR(0))

	= CeRapiInitEx(@cBuffer)
	hEvent = buf2dword(SUBSTR(cBuffer,5,4))

	IF WaitForSingleObject(hEvent,2000) = WAIT_OBJECT_0
		THIS.connected = .T.
	ELSE
		THIS.UninitRapi
	ENDIF
RETURN THIS.connected

PROCEDURE UninitRapi
	= CeRapiUninit()
	THIS.connected = .F.

PROCEDURE Destroy
	THIS.UninitRapi

PROCEDURE decl
	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dest, INTEGER src, INTEGER nLength

	DECLARE INTEGER CeRapiUninit IN rapi
	DECLARE INTEGER CeRapiGetError IN rapi
	DECLARE INTEGER CeGetLastError IN rapi
	DECLARE INTEGER CeRapiInitEx IN rapi STRING @pRapiInit
	DECLARE INTEGER CeRapiFreeBuffer IN rapi INTEGER Buffer
	DECLARE INTEGER CeCloseHandle IN rapi INTEGER hObject
	DECLARE INTEGER CeDeleteFile IN rapi STRING lpFileName
	DECLARE INTEGER CeRemoveDirectory IN rapi STRING lpPathName

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds

	DECLARE LONG CeGetFileSize IN rapi;
		INTEGER hFile, LONG lpFileSizeHigh

	DECLARE INTEGER CeMoveFile IN rapi;
		STRING lpExistingFileName, STRING lpNewFileName

	DECLARE INTEGER CeCopyFile IN rapi;
		STRING lpExistingFileName, STRING lpNewFileName,;
		INTEGER bFailIfExists

	DECLARE INTEGER CeWriteFile IN rapi;
		INTEGER hFile, STRING @lpBuffer, INTEGER nBytesToWrite,;
		INTEGER @lpBytesWritten, INTEGER lpOverlapped

	DECLARE INTEGER CeReadFile IN rapi;
		INTEGER hFile, STRING @lpBuffer, INTEGER nBytesToRead,;
		INTEGER @lpNumberOfBytesRead, INTEGER lpOverlapped

	DECLARE INTEGER CeCreateFile IN rapi;
		STRING @lpFileName, INTEGER dwDesiredAccess, INTEGER dwShareMode,;
		INTEGER lpSecurityAttr, INTEGER dwCreationDisposition,;
		INTEGER dwFlagsAndAttributes, INTEGER hTemplateFile

	DECLARE INTEGER CeCreateDirectory IN rapi;
		STRING lpPathName, INTEGER lpSecurityAttributes

	DECLARE INTEGER CeSetFilePointer IN rapi;
		INTEGER hFile, LONG lDistanceToMove,;
		LONG lpDistanceToMoveHigh, INTEGER dwMoveMethod

	DECLARE INTEGER CeFindAllFiles IN rapi;
		STRING szPath, INTEGER dwFlags,;
		INTEGER @lpdwFoundCount, INTEGER @ppFindDataArray

	DECLARE INTEGER CeFindFirstFile IN rapi;
		STRING lpFileName, STRING @lpFindFileData
ENDDEFINE

**************************************************************
DEFINE CLASS Tfile As Custom
	fileattributes=0
	creationtime=""
	lastaccesstime=""
	lastwritetime=""
	filesize=0
	oid=0
	filename=""
ENDDEFINE

**************************************************************
DEFINE CLASS Tfiles As Collection
	errorcode=0
	activepath=""
	activeflags=FAF_COMPLETE

PROCEDURE Init(cPath, nFlags)
	IF VARTYPE(cPath)="C"
		THIS.GetFiles(cPath, nFlags)
	ENDIF

PROCEDURE Destroy
	THIS.ClearObject

PROTECTED PROCEDURE ClearObject
	DO WHILE THIS.Count > 0
		THIS.Remove(1)
	ENDDO
	THIS.activepath=""
	THIS.activeflags=0

PROCEDURE GetFolders(cPath)
RETURN THIS.GetFiles(STRTRAN(ALLTRIM(cPath)+"\", "\\", "\")+"*.*",;
	FAF_COMPLETE+FAF_FOLDERS_ONLY)

PROCEDURE GetFiles(cPath, nFlags)
*|typedef struct _CE_FIND_DATA {
*|  DWORD dwFileAttributes;     0:4
*|  FILETIME ftCreationTime;    4:8
*|  FILETIME ftLastAccessTime; 12:8
*|  FILETIME ftLastWriteTime;  20:8
*|  DWORD nFileSizeHigh;       28:4
*|  DWORD nFileSizeLow;        32:4
*|  DWORD dwOID;               36:4
*|  WCHAR cFileName[MAX_PATH]; 40:520
*|} CE_FIND_DATA;

	THIS.ClearObject

	IF VARTYPE(nFlags) <> "N"
		nFlags = THIS.activeflags
	ELSE
		THIS.activeflags = nFlags
	ENDIF
	IF VARTYPE(cPath) <> "C"
		cPath = THIS.activepath
	ELSE
		THIS.activepath=cPath
	ENDIF

	LOCAL nCount, hBuffer, cBuffer, nBufsize, nIndex, nOffs
	STORE 0 TO nCount, hBuffer, THIS.errorcode
	cPath = ToUnicode(m.cPath)
	IF CeFindAllFiles(cPath, nFlags, @nCount, @hBuffer) = 0
		THIS.errorcode=CeGetLastError()
		RETURN .F.
	ENDIF

	nBufsize = nCount*FIND_DATA_SIZE
	cBuffer = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cBuffer, hBuffer, nBufsize)
	= CeRapiFreeBuffer(hBuffer)

	FOR nIndex=1 TO nCount
		nOffs = (nIndex-1)*FIND_DATA_SIZE+1

		LOCAL oFile As Tfile
		oFile = CREATEOBJECT("Tfile")
		WITH oFile
			.filename = SUBSTR(cBuffer, nOffs+40, MAX_PATH*2)
			.filename = FromUnicode(SUBSTR(.filename, 1,;
				AT(CHR(0)+CHR(0),.filename)))

			.filesize = buf2dword(SUBSTR(cBuffer, nOffs+32, 4)) +;
				OVER_DWORD*buf2dword(SUBSTR(cBuffer, nOffs+28, 4))

			.creationtime = SUBSTR(cBuffer, nOffs+4, 8)
			.lastaccesstime = SUBSTR(cBuffer, nOffs+12, 8)
			.lastwritetime = SUBSTR(cBuffer, nOffs+20, 8)
			.oid = buf2dword(SUBSTR(cBuffer, nOffs+36, 4))
		ENDWITH
		THIS.Add(oFile, UPPER(oFile.filename))
		oFile=Null
	ENDFOR
RETURN .T.

FUNCTION CreateDirectory(cDirName) As Boolean
	IF CeCreateDirectory(ToUnicode(cDirName), 0) = 0
		THIS.errorcode=CeGetLastError()
		RETURN .F.
	ENDIF
RETURN .T.

FUNCTION RemoveDirectory(cDirName) As Boolean
	IF CeRemoveDirectory(ToUnicode(cDirName))=0
		THIS.errorcode=CeGetLastError()
		RETURN .F.
	ENDIF
RETURN .T.

FUNCTION PathExists(cPath)
	cPath = ALLTRIM(m.cPath)
	IF LEN(cPath) > 1 AND RIGHT(cPath,1)="\"
		cPath = SUBSTR(cPath, 1, LEN(cPath)-1)
	ENDIF
	LOCAL cBuffer, hFind, lResult
	cBuffer = REPLICATE(CHR(0), 1024)
	hFind = CeFindFirstFile(ToUnicode(m.cPath), @cBuffer)
	IF hFind = INVALID_HANDLE_VALUE
		RETURN .F.
	ELSE
		lResult = (BITAND(FILE_ATTRIBUTE_DIRECTORY,;
			ASC(LEFT(cBuffer,1)))=FILE_ATTRIBUTE_DIRECTORY)
		= CeCloseHandle(m.hFind)
	ENDIF
RETURN m.lResult

FUNCTION MoveFile(cExistingName, cNewName) As Boolean
	IF CeMoveFile(ToUnicode(m.cExistingName),;
		ToUnicode(m.cNewName)) = 0
		THIS.errorcode=CeGetLastError()
		RETURN .F.
	ENDIF
RETURN .T.

FUNCTION CopyFile(cSourceName, cTargetName) As Boolean
	IF CeCopyFile(m.ToUnicode(cSourceName),;
		ToUnicode(m.cTargetName), 1) = 0
		THIS.errorcode=CeGetLastError()
		RETURN .F.
	ENDIF
RETURN .T.

FUNCTION DeleteFile(cFileName) As Boolean
	IF CeDeleteFile(ToUnicode(m.cFileName)) = 0
		THIS.errorcode=CeGetLastError()
		RETURN .F.
	ENDIF
RETURN .T.

FUNCTION FileExists(cFilename) As Boolean
	LOCAL hFile
	hFile = CeCreateFile(ToUnicode(m.cFilename),;
		GENERIC_READ, 0, 0, OPEN_EXISTING,;
		FILE_ATTRIBUTE_NORMAL, 0)
	IF hFile = INVALID_HANDLE_VALUE
		RETURN .F.
	ELSE
		= CeCloseHandle(m.hFile)
		RETURN .T.
	ENDIF

PROTECTED FUNCTION GetFileSize(hFile) As Number
	LOCAL nFilesizeLo, nFilesizeHi
	nFilesizeHi=0
	nFilesizeLo = CeGetFileSize(hFile, @nFilesizeHi)
RETURN m.nFilesizeHi*OVER_DWORD + m.nFilesizeLo

FUNCTION FileToString(cSourceFile) As String
	LOCAL hFile, cResult, nBytesRead
	cResult=""
	hFile = CeCreateFile(ToUnicode(cSourceFile),;
		GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)
	IF hFile = INVALID_HANDLE_VALUE
		THIS.errorcode=CeGetLastError()
		RETURN m.cResult
	ENDIF

	nBytesRead = THIS.GetFileSize(m.hFile)
	cResult = REPLICATE(CHR(0), m.nBytesRead)

	IF CeReadFile(m.hFile, @cResult, nBytesRead, @nBytesRead, 0) = 0
		THIS.errorcode=CeGetLastError()
	ENDIF
	= CeCloseHandle(m.hFile)
RETURN cResult

FUNCTION StringToFile(cBuffer, cTargetFile, nFlag) As Number
	LOCAL hFile, nBytesWritten
	cTargetFile = ToUnicode(m.cTargetFile)

	DO CASE
	CASE VARTYPE(nFlag) <> "N" OR nFlag = 0
	* overwrite existing or create new file
		hFile = CeCreateFile(m.cTargetFile,;
			GENERIC_WRITE, 0, 0, CREATE_ALWAYS,;
			FILE_ATTRIBUTE_NORMAL, 0)

	CASE nFlag = 1
	* append buffer to existing file
		hFile = CeCreateFile(m.cTargetFile,;
			GENERIC_WRITE, 0, 0, OPEN_EXISTING,;
			FILE_ATTRIBUTE_NORMAL, 0)

		IF hFile = INVALID_HANDLE_VALUE
			hFile = CeCreateFile(m.cTargetFile,;
				GENERIC_WRITE, 0, 0, CREATE_NEW,;
				FILE_ATTRIBUTE_NORMAL, 0)
		ELSE
			= CeSetFilePointer(m.hFile, 0,0, FILE_END)
		ENDIF
	OTHERWISE
		RETURN 0  && invalid flag
	ENDCASE

	IF hFile = INVALID_HANDLE_VALUE
		THIS.errorcode=CeGetLastError()
		RETURN 0
	ENDIF

	nBytesWritten=0
	IF CeWriteFile(m.hFile, @cBuffer, LEN(cBuffer),;
		@nBytesWritten, 0) = 0
		THIS.errorcode=CeGetLastError()
	ENDIF
	= CeCloseHandle(m.hFile)
RETURN m.nBytesWritten
ENDDEFINE

********************* static members **************************
FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION ToUnicode(cStr)
RETURN STRCONV(cStr+CHR(0), 5)

FUNCTION FromUnicode(cStr)
RETURN STRTRAN(STRCONV(cStr, 6), CHR(0), "")  
```  
***  


## Listed functions:
[CeCloseHandle](../libraries/rapi/CeCloseHandle.md)  
[CeCopyFile](../libraries/rapi/CeCopyFile.md)  
[CeCreateDirectory](../libraries/rapi/CeCreateDirectory.md)  
[CeCreateFile](../libraries/rapi/CeCreateFile.md)  
[CeDeleteFile](../libraries/rapi/CeDeleteFile.md)  
[CeFindAllFiles](../libraries/rapi/CeFindAllFiles.md)  
[CeFindFirstFile](../libraries/rapi/CeFindFirstFile.md)  
[CeGetFileSize](../libraries/rapi/CeGetFileSize.md)  
[CeGetLastError](../libraries/rapi/CeGetLastError.md)  
[CeMoveFile](../libraries/rapi/CeMoveFile.md)  
[CeRapiFreeBuffer](../libraries/rapi/CeRapiFreeBuffer.md)  
[CeRapiGetError](../libraries/rapi/CeRapiGetError.md)  
[CeRapiInitEx](../libraries/rapi/CeRapiInitEx.md)  
[CeRapiUninit](../libraries/rapi/CeRapiUninit.md)  
[CeReadFile](../libraries/rapi/CeReadFile.md)  
[CeRemoveDirectory](../libraries/rapi/CeRemoveDirectory.md)  
[CeSetFilePointer](../libraries/rapi/CeSetFilePointer.md)  
[CeWriteFile](../libraries/rapi/CeWriteFile.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  

## Comment:
Class **Tfiles** is a collection of **Tfiles** objects. Use Tfiles methods *GetFolders* and *GetFiles* to populate this collection. Other methods included:  
* CreateDirectory  
* RemoveDirectory  
* PathExists  
* MoveFile  
* CopyFile  
* DeleteFile  
* FileExists  
* FileToString  
* StringToFile  
  
Class **Tfile** implements the File Object and contains only properties: *fileattributes, creationtime, lastaccesstime, lastwritetime, filesize, filename*.  
  
Similar to FoxPro, functions FOPEN, FCREATE, FWRITE, FGETS can be fairly easily implemented based on existing class members.  
  
I was not able find an equivalent of Get /SetActiveDirectory functionality in RAPI library.  
  
***  

