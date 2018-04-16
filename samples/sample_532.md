[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Extensible Storage Engine class library

## Before you begin:
The [Extensible Storage Engine](http://en.wikipedia.org/wiki/Extensible_Storage_Engine) (ESE), also known as JET Blue, is an Indexed Sequential Access Method (ISAM) data storage technology from Microsoft. ESE is notably a core of Microsoft Exchange Server and Active Directory.   

Its purpose is to allow applications to store and retrieve data via indexed and sequential access. Windows Mail and Desktop Search in the Windows Vista operating system also make use of ESE to store indexes and property information respectively.  

The ESE Runtime (ESENT.DLL) has shipped in every Windows release since Windows 2000, with native x64 version of the ESE runtime shipping with x64 versions of Windows XP and Windows Server 2003.   

[Esent.h](../downloads/essent.h)  header file is included in the <a href="http://en.wikipedia.org/wiki/Microsoft_Windows_SDK">Microsoft Windows SDK</a>.  

The ESE (Jet Blue) has no relation to the database engine used in Microsoft Access, the one dubbed [JET Red](http://en.wikipedia.org/wiki/Microsoft_Jet_Database_Engine).  
  
***  


## Code:
```foxpro  
DEFINE CLASS JetBlue As Session
#DEFINE JET_COLUMNDEF_SIZE 28
#DEFINE JET_coltypBit 1
#DEFINE JET_coltypLong 4
#DEFINE JET_coltypIEEESingle 6
#DEFINE JET_coltypDateTime 8
#DEFINE JET_coltypText 10
#DEFINE JET_coltypLongText 12
#DEFINE JET_ColInfo 0
#DEFINE JET_prepInsert 0
#DEFINE JET_prepReplace 2
#DEFINE JET_bitSetOverwriteLV 0x00000004
#DEFINE JET_MoveLast 0x7fffffff

PROTECTED jetinstanceid, jetinstancename, jetsessionid
	errorno=0
	errormessage=""
	jetinstanceid=0
	jetsessionid=0
	jetinstancename=""
	jetdatabaseid=0
	jetdatabasename=""
	jettableid=0
	jettablename=""

PROCEDURE Init(cInstanceName As String)
	THIS.declare
	THIS.jetinstancename = m.cInstanceName
	THIS.JetInit

PROCEDURE Destroy
	THIS.JetTerm

PROTECTED PROCEDURE JetTerm
	THIS.CloseDatabase
	IF THIS.jetsessionid <> 0
		= JetEndSession(THIS.jetsessionid, 0)
		THIS.jetsessionid=0
	ENDIF
	IF THIS.jetinstanceid <> 0
		= JetTerm(THIS.jetinstanceid)
		THIS.jetinstanceid=0
	ENDIF

PROTECTED PROCEDURE JetInit
	LOCAL nInstance, nSession
	STORE 0 TO nInstance, nSession

	THIS.errorno = JetCreateInstance(@nInstance,;
		THIS.jetinstancename)
	IF THIS.errorno <> 0
		THIS.errormessage = "JetCreateInstance call failed."
		RETURN .F.
	ENDIF

	THIS.errorno = JetInit(@nInstance)
	IF THIS.errorno <> 0
		THIS.errormessage = "JetInit call failed."
		RETURN .F.
	ENDIF

	THIS.jetinstanceid = m.nInstance
	
	THIS.errorno = JetBeginSession(THIS.jetinstanceid,;
		@nSession, 0, 0)
	IF THIS.errorno <> 0
		THIS.errormessage = "JetBeginSession call failed."
		RETURN .F.
	ENDIF

	THIS.jetsessionid = m.nSession
RETURN .T.

PROCEDURE CloseDatabase
	THIS.CloseTable
	IF THIS.jetdatabaseid <> 0
		= JetCloseDatabase(THIS.jetsessionid, THIS.jetdatabaseid, 0)
		= JetDetachDatabase(THIS.jetsessionid, THIS.jetdatabasename)
		THIS.jetdatabaseid=0
		THIS.jetdatabasename=""
	ENDIF

PROCEDURE CreateDatabase(cDbName, lOverwrite As Boolean)
	THIS.CloseDatabase

	IF FILE(m.cDbName) AND m.lOverwrite
		LOCAL ex As Exception
		TRY
			DELETE FILE (m.cDbName)
		CATCH TO ex
			THIS.SetError(ex.ErrorNo. ex.Message)
			RETURN .F.
		ENDTRY
	ENDIF

	LOCAL nDatabase
	nDatabase=0

	THIS.errorno = JetCreateDatabase(THIS.jetsessionid,;
		m.cDbName, 0, @nDatabase, 0)

	IF THIS.errorno = 0
		THIS.jetdatabaseid=m.nDatabase
		THIS.jetdatabasename=m.cDbName
	ENDIF
RETURN (THIS.errorno=0)

PROCEDURE CloseTable
	IF THIS.jettableid <> 0
		= JetCloseTable(THIS.jetsessionid, THIS.jettableid)
		THIS.jettableid=0
		THIS.jettablename=""
	ENDIF

PROCEDURE DeleteTable(cTablename)
	= JetDeleteTable(THIS.jetsessionid,;
		THIS.jetdatabaseid, m.cTablename)

PROCEDURE CreateTable(cTablename, lOverwrite)
	THIS.CloseTable
	
	IF m.lOverwrite
		THIS.DeleteTable(m.cTablename)
	ENDIF

	LOCAL nTable
	nTable=0

	THIS.errorno = JetCreateTable(THIS.jetsessionid,;
		THIS.jetdatabaseid, m.cTablename, 0,0, @nTable)

	IF THIS.errorno=0
		THIS.jettableid=m.nTable
		THIS.jettablename=m.cTablename
	ENDIF
RETURN (THIS.errorno=0)

PROCEDURE CreateColumn(cColumnName, cColumnType, nColumnLen)

	LOCAL nColumnType, nColumnId, cColumnDef
	nColumnType = THIS.GetColumnType(m.cColumnType, m.nColumnLen)
	nColumnId=0

	cColumnDef = num2dword(JET_COLUMNDEF_SIZE) +;
		num2dword(0) + num2dword(m.nColumnType) +;
		num2word(0) + num2word(0) + num2word(0) + num2word(0) +;
		num2dword(m.nColumnLen) + num2dword(0)

	THIS.errorno = JetAddColumn(THIS.jetsessionid,;
		THIS.jettableid, m.cColumnName,;
		@cColumnDef, 0, 0, @nColumnId)

RETURN (THIS.errorno=0)

PROCEDURE GetColumnType(cColumnType, nColumnLen) As Number
	LOCAL nColumnType
	DO CASE
	CASE cColumnType="C"
		nColumnType=JET_coltypText
	CASE cColumnType="M"
		nColumnType=JET_coltypLongText
	CASE cColumnType $ "NI"
		nColumnType=JET_coltypLong
	CASE cColumnType="L"
		nColumnType=JET_coltypBit
	CASE cColumnType $ "DT"
		nColumnType=JET_coltypDateTime
	CASE cColumnType="F"
		nColumnType=JET_coltypIEEESingle
	OTHERWISE
		nColumnType=0
	ENDCASE
RETURN m.nColumnType

FUNCTION GetColumnIdByName(cColumnName As String) As Number
	LOCAL cColumnDef, nColumnId
	* prepare empty JET_COLUMNDEF structure
	cColumnDef = PADR(num2dword(JET_COLUMNDEF_SIZE),;
		JET_COLUMNDEF_SIZE,CHR(0))

	= JetGetColumnInfo(THIS.jetsessionid, THIS.jetdatabaseid,;
		THIS.jettablename, cColumnName, @cColumnDef,;
		JET_COLUMNDEF_SIZE, JET_ColInfo)

	nColumnId = buf2dword(SUBSTR(cColumnDef, 5, 4))
RETURN m.nColumnId

PROCEDURE SetColumn(cColumnName, vValue, lInsert)
	THIS.errorno = JetBeginTransaction(THIS.jetsessionid)
	IF THIS.errorno <> 0
		THIS.errormessage = "JetBeginTransaction call failed"
		RETURN .F.
	ENDIF

	LOCAL nPrepFlag, nColumnId
	nPrepFlag = IIF(m.lInsert, JET_prepInsert, JET_prepReplace)
	nColumnId = THIS.GetColumnIdByName(m.cColumnName)

	THIS.errorno = JetPrepareUpdate(THIS.jetsessionid,;
		THIS.jettableid, nPrepFlag)
	IF THIS.errorno <> 0
		= JetRollback(THIS.jetsessionid, 0)
		THIS.errormessage = "JetPrepareUpdate call failed"
		RETURN .F.
	ENDIF

	LOCAL oData As PChar, nDataLen
	oData = CREATEOBJECT("PChar", m.vValue)
	nDataLen = LEN(m.vValue)

	THIS.errorno = JetSetColumn(THIS.jetsessionid,;
		THIS.jettableid, m.nColumnId,;
		oData.GetAddr(), m.nDataLen, JET_bitSetOverwriteLV, 0)

	IF THIS.errorno <> 0
		= JetRollback(THIS.jetsessionid, 0)
		THIS.errormessage = "JetSetColumn call failed."
		RETURN .F.
	ENDIF

	LOCAL nBookmark, nBookmarkSize
	nBookmarkSize=4

	THIS.errorno = JetUpdate(THIS.jetsessionid,;
		THIS.jettableid, @nBookmark,;
		m.nBookmarkSize, @nBookmarkSize)

	IF THIS.errorno <> 0
		= JetRollback(THIS.jetsessionid, 0)
		THIS.errormessage = "JetUpdate call failed."
		RETURN .F.
	ENDIF

	= JetCommitTransaction(THIS.jetsessionid, 0)

	IF m.lInsert
	* position a cursor on the added record
		= JetMove(THIS.jetsessionid,;
			THIS.jettableid, JET_MoveLast, 0)
	ENDIF
RETURN .T.

PROTECTED PROCEDURE declare
	DECLARE INTEGER JetCreateInstance IN esent;
		INTEGER @pinstance, STRING szInstanceName

	DECLARE INTEGER JetInit IN esent INTEGER @pinstance
	DECLARE INTEGER JetTerm IN esent INTEGER pinstance

	DECLARE INTEGER JetBeginSession IN esent;
		INTEGER instance, INTEGER @psesid,;
		INTEGER szUserName, INTEGER szPassword

	DECLARE INTEGER JetEndSession IN esent;
		INTEGER sesid, INTEGER grbit

	DECLARE INTEGER JetCreateDatabase IN esent;
		INTEGER sesid, STRING szFilename, INTEGER szConnect,;
		INTEGER @pdbid, INTEGER grbit

	DECLARE INTEGER JetCloseDatabase IN esent;
		INTEGER sesid, INTEGER dbid, INTEGER grbit

	DECLARE INTEGER JetDetachDatabase IN esent;
		INTEGER sesid, STRING szFilename

	DECLARE INTEGER JetCreateTable IN esent;
		INTEGER sesid, INTEGER dbid, STRING szTableName,;
		LONG lPages, LONG lDensity, INTEGER @ptableid

	DECLARE INTEGER JetDeleteTable IN esent;
		INTEGER sesid, INTEGER dbid, STRING szTableName

	DECLARE INTEGER JetOpenTable IN esent;
		INTEGER sesid, INTEGER dbid, STRING szTableName,;
		INTEGER pvParameters, INTEGER cbParameters,;
		INTEGER grbit, INTEGER @ptableid

	DECLARE INTEGER JetCloseTable IN esent;
		INTEGER sesid, INTEGER tableid

	DECLARE INTEGER JetAddColumn IN esent;
		INTEGER sesid, INTEGER tableid, STRING szColumnName,;
		STRING @pcolumndef, STRING @pvDefault,;
		LONG cbDefault, INTEGER @pcolumnid

	DECLARE INTEGER JetPrepareUpdate IN esent;
		INTEGER sesid, INTEGER tableid, LONG prep

	DECLARE INTEGER JetSetColumn IN esent;
		INTEGER sesid, INTEGER tableid, INTEGER columnid,;
		INTEGER pvData, LONG cbData, INTEGER grbit,;
		INTEGER psetinfo

	DECLARE INTEGER JetUpdate IN esent;
		INTEGER sesid, INTEGER tableid, INTEGER @pvBookmark,;
		LONG cbBookmark, LONG @pcbActual

	DECLARE INTEGER JetRetrieveColumn IN esent;
		INTEGER sesid, INTEGER tableid, INTEGER columnid,;
		INTEGER pvData, LONG cbData, LONG @pcbActual,;
		INTEGER grbit, INTEGER pretinfo

	DECLARE INTEGER JetGetColumnInfo IN esent;
		INTEGER sesid, INTEGER dbid,;
		STRING szTableName, STRING szColumnName,;
		STRING @pvResult, LONG cbMax, LONG InfoLevel

	DECLARE INTEGER JetGotoBookmark IN esent;
		INTEGER sesid, INTEGER tableid,;
		INTEGER pvBookmark, LONG cbBookmark

	DECLARE INTEGER JetMove IN esent;
		INTEGER sesid, INTEGER tableid,;
		LONG cRow, INTEGER grbit

	DECLARE INTEGER JetBeginTransaction IN esent INTEGER sesid

	DECLARE INTEGER JetRollback IN esent;
		INTEGER sesid, INTEGER grbit

	DECLARE INTEGER JetCommitTransaction IN esent;
		INTEGER sesid, INTEGER grbit

ENDDEFINE

DEFINE CLASS PChar As Session
PROTECTED hMem

PROCEDURE Init(lcString)
	THIS.hMem = 0
	THIS.setValue(lcString)

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr
RETURN THIS.hMem

FUNCTION GetValue
	LOCAL lnSize, lcBuffer
	lnSize = THIS.GetAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As MemToStr;
			STRING @, INTEGER, INTEGER
		= MemToStr(@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION GetAllocSize
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue(lcString)
#DEFINE GMEM_FIXED 0
	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= StrToMem(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[JetAddColumn](../libraries/esent/JetAddColumn.md)  
[JetBeginSession](../libraries/esent/JetBeginSession.md)  
[JetBeginTransaction](../libraries/esent/JetBeginTransaction.md)  
[JetCloseDatabase](../libraries/esent/JetCloseDatabase.md)  
[JetCloseTable](../libraries/esent/JetCloseTable.md)  
[JetCommitTransaction](../libraries/esent/JetCommitTransaction.md)  
[JetCreateDatabase](../libraries/esent/JetCreateDatabase.md)  
[JetCreateInstance](../libraries/esent/JetCreateInstance.md)  
[JetCreateTable](../libraries/esent/JetCreateTable.md)  
[JetDeleteTable](../libraries/esent/JetDeleteTable.md)  
[JetDetachDatabase](../libraries/esent/JetDetachDatabase.md)  
[JetEndSession](../libraries/esent/JetEndSession.md)  
[JetGetColumnInfo](../libraries/esent/JetGetColumnInfo.md)  
[JetGotoBookmark](../libraries/esent/JetGotoBookmark.md)  
[JetInit](../libraries/esent/JetInit.md)  
[JetMove](../libraries/esent/JetMove.md)  
[JetOpenTable](../libraries/esent/JetOpenTable.md)  
[JetPrepareUpdate](../libraries/esent/JetPrepareUpdate.md)  
[JetRetrieveColumn](../libraries/esent/JetRetrieveColumn.md)  
[JetRollback](../libraries/esent/JetRollback.md)  
[JetSetColumn](../libraries/esent/JetSetColumn.md)  
[JetTerm](../libraries/esent/JetTerm.md)  
[JetUpdate](../libraries/esent/JetUpdate.md)  

## Comment:
The VFP class library is on an early stage of development with some corners cut.  
  
See also:  
* <a href="https://msdn.microsoft.com/en-us/library/5c485eff-4329-4dc1-aa45-fb66e6554792.aspx">Extensible Storage Engine</a> on MSDN  
* <a href="http://en.wikipedia.org/wiki/Extensible_Storage_Engine">Extensible Storage Engine</a> on Wikipedia  

***  

