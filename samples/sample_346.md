[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Passing data records between VFP applications via the Clipboard

## Before you begin:
The Custom class *TClipboard* communicates with Windows Clipboard through several Win32 functions. Both applications -- sender and recipient -- should create an instance of this object.  

See also:

* [Using shared memory to exchange data between two FoxPro applications](sample_498.md)  
  
***  


## Code:
```foxpro  
DEFINE CLASS TClipboard As Custom
#DEFINE ccFmtPlan  "VFPTablePlan"
#DEFINE ccFmtData  "VFPTableData"
#DEFINE ccDefTarget "clipb"  && target cursor default name

idFmtPlan = 0
idFmtData = 0

PROCEDURE Init
	DECLARE INTEGER RegisterClipboardFormat IN user32 STRING lpszFormat
	* it is safe registering a format more than once
	THIS.idFmtPlan = RegisterClipboardFormat(ccFmtPlan)
	THIS.idFmtData = RegisterClipboardFormat(ccFmtData)

FUNCTION IsDataAvailable
	DECLARE INTEGER IsClipboardFormatAvailable IN user32 INTEGER wFmt
RETURN IsClipboardFormatAvailable(THIS.idFmtPlan) <> 0;
	And IsClipboardFormatAvailable(THIS.idFmtData) <> 0

FUNCTION CopyToClip
* copies structure and records from the active area to the Clipboard
#DEFINE CF_OEMTEXT  7
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER EmptyClipboard  IN user32
	DECLARE INTEGER GlobalLock IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalUnlock IN kernel32 INTEGER hMem
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER SetClipboardData IN user32 INTEGER wFmt, INTEGER hMem
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes

	LOCAL lcPlan, lcData, lcOemText hPlan, hData, hhPlan, hhData
	lcPlan = THIS.CreateTblPlan() + Chr(0)
	lcData = THIS.CreateTblData() + Chr(0)
	lcOemText = lcData
	
	IF OpenClipboard(0) <> 0
		= EmptyClipboard()
		THIS.CopyBuffer(THIS.idFmtData, lcData)
		THIS.CopyBuffer(THIS.idFmtPlan, lcPlan)
		THIS.CopyBuffer(CF_OEMTEXT, lcOemText)
		= CloseClipboard()
	ENDIF
RETURN THIS.IsDataAvailable()

PROCEDURE CopyBuffer(lnFormat, lcBuffer)
#DEFINE GMEM_MOVEABLE 2
	DECLARE RtlMoveMemory IN kernel32 As Str2Mem;
		INTEGER Dest, STRING @Src, INTEGER nLength

	LOCAL hBuffer, hhBuffer
	hBuffer = GlobalAlloc(GMEM_MOVEABLE, Len(lcBuffer))
	hhBuffer = GlobalLock(hBuffer)
	= Str2Mem(hhBuffer, @lcBuffer, Len(lcBuffer))
	= GlobalUnlock(hBuffer)
	* no need to release globally allocated memory, dont do that :)
RETURN (SetClipboardData(lnFormat, hBuffer) <> 0)

FUNCTION CreateTblPlan
* returns partial SQL CREATE statement for the active area
	LOCAL lnFCount, lnFIndex, lcSQL
	lcSQL = ""
	lnFCount = AFIELDS(arrTblPlan)
	FOR lnFIndex=1 TO lnFCount
		lcSQL = lcSQL + Iif(lnFIndex=1, "", ", ") +;
			arrTblPlan[lnFIndex,1] + " " +;
			arrTblPlan[lnFIndex,2] + "(" +;
			LTRIM(STR(arrTblPlan[lnFIndex,3])) + "," +;
			LTRIM(STR(arrTblPlan[lnFIndex,4])) + ")"
	ENDFOR
RETURN lcSQL

FUNCTION CreateTblData
* returns table data in a tab-delimited buffer
	LOCAL lcTmpfile, lcBuffer
	lcTmpfile = SUBSTR(SYS(2015),3) + ".tmp"
	COPY TO (lcTmpfile) TYPE DELIMITED WITH TAB
	lcBuffer = THIS.File2Str(lcTmpfile)
	DELETE FILE (lcTmpfile)
RETURN lcBuffer

FUNCTION File2Str(lcAsciiFile)
* returns a content of an ASCII file in a string
	DECLARE INTEGER OpenFile IN kernel32 STRING, STRING @, INTEGER
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER
	DECLARE INTEGER GetFileSize IN kernel32 INTEGER, INTEGER
	DECLARE INTEGER ReadFile IN kernel32;
		INTEGER, STRING @, INTEGER, INTEGER @, INTEGER

	LOCAL lcReopenBuffer, lcReadBuffer, hFile, lnFileSize, lnBytesRead
	lcReopenBuffer = Repli(Chr(0), 250)

	hFile = OpenFile(lcAsciiFile, @lcReOpenBuffer, 0)
	lnFileSize = GetFileSize (hFile, 0)
	lcReadBuffer = SPACE(lnFileSize)
	
	lnBytesRead = 0
	= ReadFile (hFile, @lcReadBuffer, lnFileSize, @lnBytesRead,0)
	= CloseHandle (hFile)
RETURN lcReadBuffer

FUNCTION Str2File(lcBuffer, lcAsciiFile)
* saves string to a file
	LOCAL hFile, lResult
	hFile = FCREATE(lcAsciiFile)
	IF hFile = -1
		RETURN .F.
	ENDIF
	lResult = FWRITE(hFile, lcBuffer)
	= FCLOSE(hFile)
RETURN (lResult <> 0)

FUNCTION NewFromClip(lcTarget)
* creates new cursor with structure and data copied from the clipboard
	IF TYPE("lcTarget") <> "C" Or EMPTY(lcTarget)
		lcTarget = ccDefTarget
	ENDIF
RETURN THIS.ReadClip(lcTarget)

FUNCTION AppendFromClip
* appends records from the clipboard to the active alias
	IF EMPTY(ALIAS())
		RETURN .F.
	ENDIF

	LOCAL lcTarget, lcTmpDbf
	lcTarget = SUBSTR(SYS(2015),3)

	IF Not THIS.ReadClip(lcTarget)
		RETURN .F.
	ENDIF

	lcTmpDbf = DBF(lcTarget)
	APPEND FROM (lcTmpDbf)
	USE IN (lcTarget)
RETURN .T.

FUNCTION ReadClip(lcTarget)
* creates a cursor using structure and records stored in the clipboard
	IF Not THIS.IsDataAvailable()
		RETURN .F.
	ENDIF

	LOCAL OldSel, lcPlan, lcData, lcSQL, lcTmpfile, lcTmpDbf,;
		lnPlanLen, lnDataLen
	OldSel = SELECT()

	lcPlan = THIS.GetClipData(THIS.idFmtPlan)
	lcSQL = "CREATE CURSOR " + lcTarget + " (" + lcPlan + ")"
	&lcSQL

	lcData = THIS.GetClipData(THIS.idFmtData)
	lcTmpfile = SUBSTR(SYS(2015),3) + ".tmp"
	THIS.Str2File(lcData, lcTmpfile)
	APPEND FROM (lcTmpfile) TYPE DELIMITED WITH TAB
	DELETE FILE (lcTmpfile)
	SELECT(OldSel)
RETURN .T.

PROTECTED FUNCTION GetClipData(lnFmt)
* restores data from the clipboard for a given format
	DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	DECLARE INTEGER CloseClipboard IN user32
	DECLARE INTEGER GetClipboardData IN user32 INTEGER uFmt
	DECLARE INTEGER GlobalLock IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalUnlock IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem

	DECLARE RtlMoveMemory IN kernel32 As Mem2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength

	LOCAL lcBuffer, lnBufsize, hBuffer, hhBuffer
	lcBuffer = ""

	IF OpenClipboard(0) <> 0
		hBuffer = GetClipboardData(lnFmt)
		IF hBuffer <> 0
			lnBufsize = GlobalSize(hBuffer)
			hhBuffer = GlobalLock(hBuffer)
			IF hhBuffer <> 0
				lcBuffer = Repli(Chr(0), lnBufsize)
				Mem2Str(@lcBuffer, hhBuffer, lnBufsize)
			ENDIF
			GlobalUnlock(hBuffer)
		ENDIF
		= CloseClipboard()
	ENDIF
RETURN STRTRAN(lcBuffer, Chr(0),"")
ENDDEFINE  
```  
***  


## Listed functions:
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[EmptyClipboard](../libraries/user32/EmptyClipboard.md)  
[GetClipboardData](../libraries/user32/GetClipboardData.md)  
[GetFileSize](../libraries/kernel32/GetFileSize.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalLock](../libraries/kernel32/GlobalLock.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[GlobalUnlock](../libraries/kernel32/GlobalUnlock.md)  
[IsClipboardFormatAvailable](../libraries/user32/IsClipboardFormatAvailable.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  
[ReadFile](../libraries/kernel32/ReadFile.md)  
[RegisterClipboardFormat](../libraries/user32/RegisterClipboardFormat.md)  
[SetClipboardData](../libraries/user32/SetClipboardData.md)  

## Comment:
This is another way of passing information between VFP applications. Normally such data exchange is based on a table or tables, which can be accessed by participating applications. Table names must be available to the applications either through global objects, or they are hard-coded.  
  
On initialization the TClipboard object registers two Clipboard formats: *VFPTablePlan* and *VFPTableData*.  
  
The sender application uses the *CopyToClip* method to copy records from the active alias to the Windows Clipboard. The structure of the alias is copied in the VFPTablePlan format, which is a regular SQL CREATE expression. The records are copied in the VFPTableData format, which is a tab delimited buffer.  
  
The recipient can use either *AppendFromClip* or *NewFromClip* methods. The *AppendFromClip* appends records from the Clipboard to active alias (if any). The *NewFromClip* creates a new cursor with the structure and records retrieved from the Clipboard.  
  


***  

