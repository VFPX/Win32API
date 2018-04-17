[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Pocket PC: custom RAPI class for operating with the Object Store Databases

## Short description:
This class operates with databases in the Object Store of Pocket PC. It implements enumerating, creating and deleting databases, reading, writing and deleting records in databases.  
***  

## Before you begin:
![](../images/pocketpcs.png)  

This class is subclassed from the [base RAPI class](sample_440.md). Some members of it are implemented through collections. That unfortunately makes it unusable under Visual FoxPro versions 6 and older.  

Solutions based on this class:  
* [enumerating mounted database volumes and databases in the Object Store](sample_446.md)  
* [reading the Contacts Database](sample_447.md)  
* [creating new database and adding records to it](sample_467.md)  
  
***  


## Code:
```foxpro  
****************************************************
* Pocket PC: custom RAPI class for operating
* with the Object Store Databases
****************************************************
DEFINE CLASS TrapiDb As Trapi
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE CEDB_ALLOWREALLOC     1
#DEFINE CEPROPVAL_SIZE        16
#DEFINE CEDB_PROPDELETE   0x0200
#DEFINE CEDB_SEEK_CEOID     1
#DEFINE CEDB_SEEK_BEGINNING 2
#DEFINE CEDB_SEEK_END       4
#DEFINE CEDB_SEEK_CURRENT   8
#DEFINE CeVT_I2       2
#DEFINE CeVT_I4       3
#DEFINE CeVT_UI2      18
#DEFINE CeVT_UI4      19
#DEFINE CeVT_LPWSTR   31
#DEFINE CeVT_FILETIME 64
#DEFINE CeVT_BLOB     65

	databases=0
	dbvolumes=0

PROCEDURE Init
	DODEFAULT()
	THIS.dbvolumes = CREATEOBJECT("RapiDBVolumes")
	THIS.databases = CREATEOBJECT("RapiDatabases")
	
PROCEDURE decl
	DODEFAULT()
	DECLARE INTEGER CeDeleteDatabase IN rapi INTEGER oidDbase

	DECLARE INTEGER CeFindFirstDatabaseEx IN rapi;
		STRING @pceguid, INTEGER dwDbaseType

	DECLARE INTEGER CeFindNextDatabaseEx IN rapi;
		INTEGER hEnum, STRING @pceguid

	DECLARE INTEGER CeEnumDBVolumes IN rapi;
		STRING @pceguid, STRING @lpBuf, INTEGER dwNumChars

	DECLARE INTEGER CeOpenDatabase IN rapi;
		INTEGER @poid, STRING lpszName, INTEGER propid,;
		INTEGER dwFlags, INTEGER hwndNotify

	DECLARE INTEGER CeSeekDatabase IN rapi;
		INTEGER hDatabase, INTEGER dwSeekType,;
		INTEGER dwValue, INTEGER @lpdwIndex

	DECLARE INTEGER CeReadRecordProps IN rapi;
		INTEGER hDbase, INTEGER dwFlags, INTEGER @lpcPropID,;
		INTEGER rgPropID, INTEGER @lplpBuffer, INTEGER @lpcbBuffer

	DECLARE INTEGER CeOidGetInfoEx IN rapi;
		STRING @pceguid, INTEGER oid, STRING @poidInfo

	DECLARE INTEGER CeWriteRecordProps IN rapi;
		INTEGER hDbase, INTEGER oidRecord,;
		SHORT cPropID, INTEGER rgPropVal

	DECLARE INTEGER CeDeleteRecord IN rapi;
		INTEGER hDatabase, INTEGER oidRecord

	DECLARE INTEGER CeCreateDatabase IN rapi;
		STRING lpszName, INTEGER dwDbaseType,;
		SHORT wNumSortOrder, INTEGER rgSortSpecs
ENDDEFINE

DEFINE CLASS RapiDatabases As Collection
	errorcode=0

PROCEDURE Init
	THIS.EnumDatabases

FUNCTION DatabaseExists(cDbname) As Boolean
	LOCAL oDb As RapiDatabase
	oDb = THIS.GetDatabase(cDbname)
	THIS.errorcode=0
RETURN (oDb.oid <> 0)

FUNCTION GetDatabase(vDatabase) As RapiDatabase
	LOCAL oDb As RapiDatabase
	TRY
		oDb = THIS.Item(m.vDatabase)
		THIS.errorcode=0
	CATCH
		oDb = CREATEOBJECT("RapiDatabase")
		THIS.errorcode=-1
	ENDTRY
RETURN oDb

FUNCTION CreateDatabase(cDbname) As Boolean
	LOCAL nOid
	nOid = CeCreateDatabase(ToUnicode(m.cDbname), 0,0,0)
	IF nOid = 0
		THIS.errorcode = CeGetLastError()
		RETURN .F.
	ELSE
		RETURN THIS.AddToCollection(m.nOid)
	ENDIF

FUNCTION DeleteDatabase(vDatabase) As Boolean
	LOCAL oDb As RapiDatabase
	oDb = THIS.GetDatabase(vDatabase)
	IF THIS.errorcode <> 0
		RETURN .F.
	ENDIF
	IF CeDeleteDatabase(oDb.oid) = 0
		THIS.errorcode = CeGetLastError()
		RETURN .F.
	ELSE
		THIS.Remove(oDb.dbname)  && remove from collection
	ENDIF
RETURN .T.

PROTECTED PROCEDURE EnumDatabases
	LOCAL pceguid, hEnum, nOid, cBuffer
	pceguid=REPLICATE(CHR(0), 16)
	hEnum = CeFindFirstDatabaseEx(@pceguid, 0)

	DO WHILE .T.
		nOid = CeFindNextDatabaseEx(hEnum, @pceguid)
		IF nOid = 0
			EXIT
		ENDIF
		THIS.AddToCollection(nOid, pceguid)
	ENDDO
	= CeCloseHandle(hEnum)

PROTECTED PROCEDURE AddToCollection(nOid, pceguid)
	LOCAL cBuffer, oDb
	cBuffer = REPLICATE(CHR(0), 2048)
	IF VARTYPE(pceguid) <> "C"
		pceguid = REPLICATE(CHR(0), 16)
	ENDIF

	IF CeOidGetInfoEx(@pceguid, nOid, @cBuffer)<>0
		oDb = CREATEOBJECT("RapiDatabase", m.nOid)
		THIS.Add(oDb, oDb.dbname)
		RELEASE oDb
	ELSE
		THIS.errorcode = CeGetLastError()
		RETURN .F.
	ENDIF
ENDDEFINE

DEFINE CLASS RapiDatabase As Custom
	errorcode=0
	props=0
	dbflags=0
	dbname=""
	dbtype=0
	dbreccount=0
	dbsortcount=0
	dbbytesize=0
	hdatabase=INVALID_HANDLE_VALUE
	activeorder=0
	oid=0
	recordoid=0

PROCEDURE Init(nOid)
	IF VARTYPE(m.nOid)="N"
		THIS.oid=m.nOid
	ENDIF
	THIS.ReadHeader
	THIS.props = CREATEOBJECT("RecProperties")

PROCEDURE ReadHeader  && refreshes header data
	LOCAL cBuffer, pceguid, cDbname
	cBuffer = REPLICATE(CHR(0), 2048)
	pceguid = REPLICATE(CHR(0), 16)

	WITH THIS
		IF CeOidGetInfoEx(@pceguid, THIS.oid, @cBuffer)<>0
			cDbname = SUBSTR(cBuffer, 9,64)
			.dbname = STRCONV(SUBSTR(cDbname, 1,;
				AT(CHR(0)+CHR(0),m.cDbname)), 6)
			.dbflags = buf2dword(SUBSTR(cBuffer, 5,64))
			.dbtype = buf2dword(SUBSTR(cBuffer, 73, 4))
			.dbreccount = buf2word(SUBSTR(cBuffer, 77, 2))
			.dbsortcount = buf2word(SUBSTR(cBuffer, 79, 2))
			.dbbytesize = buf2dword(SUBSTR(cBuffer, 81, 4))
		ELSE
			STORE 0 TO .dbflags, .dbtype, .dbreccount,;
			.dbsortcount, .dbbytesize
			.errorcode = CeGetLastError()
			RETURN .F.
		ENDIF
	ENDWITH

PROCEDURE Destroy
	THIS.CloseDatabase
	THIS.props.ClearObject

PROCEDURE OpenDatabase(nOrder)
	THIS.CloseDatabase
	THIS.errorcode = 0
	
	LOCAL nOid
	nOid = THIS.oid
	THIS.hdatabase = CeOpenDatabase(@nOid, "", 0,0,0)
	
	IF THIS.hdatabase = INVALID_HANDLE_VALUE
		THIS.errorcode = CeGetLastError()
	ELSE
		THIS.ReadHeader
		IF VARTYPE(m.nOrder)="N"
			THIS.activeorder=m.nOrder
		ENDIF
		THIS.gotop
	ENDIF
RETURN (THIS.hdatabase <> INVALID_HANDLE_VALUE)

PROCEDURE skip(nOffset)
RETURN THIS.SeekDatabase(m.nOffset, CEDB_SEEK_CURRENT)

PROCEDURE gotop
RETURN THIS.SeekDatabase(0, CEDB_SEEK_BEGINNING)

PROCEDURE gobottom
RETURN THIS.SeekDatabase(0, CEDB_SEEK_END)

PROCEDURE goto(nPosition)
RETURN THIS.SeekDatabase(m.nPosition, CEDB_SEEK_BEGINNING)

PROCEDURE SeekOid(nOid)
	LOCAL nResult
	nResult = THIS.SeekDatabase(m.nOid, CEDB_SEEK_CEOID)
RETURN (m.nResult = m.nOid)

PROCEDURE SeekDatabase(nSeekValue, nSeekType, nOrder)
	THIS.errorcode = 0

	IF THIS.hdatabase=INVALID_HANDLE_VALUE
		RETURN .F.
	ENDIF
	IF VARTYPE(nOrder) = "N"
		nOrder=THIS.activeorder
	ENDIF

	THIS.recordoid = CeSeekDatabase(THIS.hDatabase,;
		nSeekType, nSeekValue, @nOrder)

	IF THIS.recordoid = 0
		THIS.errorcode = CeGetLastError()
	ELSE
		THIS.activeorder=m.nOrder
		THIS.props.FillProperties(THIS.hdatabase)
	ENDIF
RETURN THIS.recordoid

FUNCTION WriteProp(nOid, oProp) As Long
	nOid = CeWriteRecordProps(THIS.hdatabase, m.nOid,;
		1, oProp.LockProperty())
	IF nOid = 0
		THIS.errorcode = CeGetLastError()
	ELSE
		THIS.errorcode = 0
	ENDIF
RETURN m.nOid

FUNCTION DeleteRecord(nOid)
	IF VARTYPE(m.nOid) <> "N"
		nOid = THIS.recordoid  && current record
	ELSE
		IF NOT THIS.SeekOid(m.nOid)
			RETURN .F.
		ENDIF
	ENDIF
	IF nOid=0 OR THIS.hdatabase=0
		RETURN .F.
	ENDIF
	
	IF CeDeleteRecord(THIS.hdatabase, m.nOid) = 0
		THIS.errorcode = CeGetLastError()
		RETURN .F.
	ELSE
		THIS.ReadHeader
	ENDIF
	
PROCEDURE CloseDatabase
	IF THIS.hdatabase <> 0
		= CeCloseHandle(THIS.hdatabase)
		THIS.hdatabase=INVALID_HANDLE_VALUE
	ENDIF
ENDDEFINE

DEFINE CLASS RecProperty As Custom
	proptype=0
	propid=0
	proplen=0
	propflags=0
	propvalue=""
	hLock=0

PROCEDURE Destroy
	THIS.UnlockProperty

FUNCTION UnlockProperty
	IF THIS.hLock <> 0
		= LocalFree(THIS.hLock)
		THIS.hLock=0
	ENDIF

FUNCTION LockProperty As Integer
	THIS.UnlockProperty

	LOCAL cBuffer, nBufsize
	WITH THIS
		nBufsize = 20 + .proplen
		.hLock = LocalAlloc(0, nBufsize)

		cBuffer = num2word(.proptype) + num2word(.propid) +;
			num2word(.proplen) + num2word(.propflags)  && 8 bytes

		DO CASE
		CASE .proptype=CeVT_BLOB
			cBuffer = cBuffer + num2dword(.proplen) +;
				num2dword(.hLock+16) + .propvalue
		CASE .proptype=CeVT_LPWSTR
			cBuffer = cBuffer + num2dword(.hLock+12) +;
				.propvalue + CHR(0) + CHR(0)
		OTHERWISE
			cBuffer = cBuffer + .propvalue
		ENDCASE
		= StrToMem(.hLock, @cBuffer, LEN(m.cBuffer))
	ENDWITH
RETURN THIS.hLock
ENDDEFINE

DEFINE CLASS RecProperties As Collection
PROCEDURE ClearObject
	DO WHILE THIS.Count > 0
		THIS.Remove(1)
	ENDDO

FUNCTION GetValue(propid, vDefault)
	LOCAL vResult
	TRY
		vResult = THIS.Item(propid).propvalue
	CATCH
		vResult = vDefault
	ENDTRY
RETURN vResult

PROCEDURE FillProperties(hDatabase)
	LOCAL nPropCount, hBuffer, nBufsize, cBuffer,;
		nIndex, cPropbuf, vValue, ch, hPtr, nBlobsize
	STORE 0 TO nPropCount, hBuffer, nBufsize
	
	THIS.ClearObject
	IF CeReadRecordProps(m.hDatabase, CEDB_ALLOWREALLOC,;
		@nPropCount, 0, @hBuffer, @nBufsize)=0
		RETURN .F.
	ENDIF

	cBuffer = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cBuffer, hBuffer, nBufsize)

	FOR nIndex=1 TO nPropCount
		cPropbuf = SUBSTR(cBuffer,;
			(nIndex-1)*CEPROPVAL_SIZE+1, CEPROPVAL_SIZE)

		LOCAL oProperty
		oProperty = CREATEOBJECT("RecProperty")
		WITH oProperty
			.proptype = buf2word(SUBSTR(cPropbuf, 1,2))
			.propid = buf2word(SUBSTR(cPropbuf, 3,2))
			.propflags = buf2word(SUBSTR(cPropbuf, 7,2))

			DO CASE
			CASE INLIST(.proptype, CeVT_I2, CeVT_UI2)
				.propvalue = SUBSTR(cPropbuf, 9,2)
			CASE INLIST(.proptype, CeVT_I4, CeVT_UI4)
				.propvalue = SUBSTR(cPropbuf, 9,4)
			CASE .proptype=CeVT_FILETIME
				.propvalue = SUBSTR(cPropbuf, 9,8)
			CASE .proptype=CeVT_BLOB
				nBlobsize = buf2dword(SUBSTR(cPropbuf, 9,4))
				hPtr = buf2dword(SUBSTR(cPropbuf, 13,4))-hBuffer+1
				.propvalue = SUBSTR(cBuffer, hPtr, m.nBlobsize)
			CASE .proptype=CeVT_LPWSTR
				hPtr = buf2dword(SUBSTR(cPropbuf, 9,4))-hBuffer+1
				vValue = ""
				DO WHILE .T.
					ch = SUBSTR(cBuffer, hPtr, 2)
					IF ch = CHR(0)+CHR(0) OR hPtr >= LEN(cBuffer)
						EXIT
					ENDIF
					vValue = vValue + SUBSTR(cBuffer, hPtr, 2)
					hPtr = hPtr + 2
				ENDDO
				.propvalue = m.vValue
			ENDCASE
			.proplen = LEN(.propvalue)
		ENDWITH
		THIS.Add(oProperty, LTRIM(STR(oProperty.propid)))  && key?
		RELEASE oProperty
	ENDFOR
	= LocalFree(hBuffer)
ENDDEFINE

DEFINE CLASS RapiDBVolumes As Collection
PROCEDURE Init
	THIS.EnumVolumes

PROTECTED PROCEDURE EnumVolumes
	LOCAL pceguid, nBufsize, cBuffer
	pceguid=REPLICATE(CHR(255), 16)
	nBufsize=64
	
	DO WHILE .T.
		cBuffer = REPLICATE(CHR(0), nBufsize*2)
		IF CeEnumDBVolumes(@pceguid, @cBuffer, nBufsize)=0
			EXIT
		ENDIF
		
		LOCAL oVolume
		oVolume = CREATEOBJECT("RapiDBVolume", pceguid)
		oVolume.volumename = STRCONV(SUBSTR(cBuffer, 1,;
			AT(CHR(0)+CHR(0),cBuffer)+1), 6)
		THIS.Add(oVolume, oVolume.volumename)
		RELEASE oVolume
	ENDDO
ENDDEFINE

DEFINE CLASS RapiDBVolume As Custom
	volumename=""
	guid=""
PROCEDURE Init(cGuid)
	THIS.guid = m.cGuid
ENDDEFINE  
```  
***  


## Listed functions:
[CeCreateDatabase](../libraries/rapi/CeCreateDatabase.md)  
[CeDeleteDatabase](../libraries/rapi/CeDeleteDatabase.md)  
[CeDeleteRecord](../libraries/rapi/CeDeleteRecord.md)  
[CeEnumDBVolumes](../libraries/rapi/CeEnumDBVolumes.md)  
[CeFindFirstDatabaseEx](../libraries/rapi/CeFindFirstDatabaseEx.md)  
[CeFindNextDatabaseEx](../libraries/rapi/CeFindNextDatabaseEx.md)  
[CeOidGetInfoEx](../libraries/rapi/CeOidGetInfoEx.md)  
[CeOpenDatabase](../libraries/rapi/CeOpenDatabase.md)  
[CeReadRecordProps](../libraries/rapi/CeReadRecordProps.md)  
[CeSeekDatabase](../libraries/rapi/CeSeekDatabase.md)  
[CeWriteRecordProps](../libraries/rapi/CeWriteRecordProps.md)  

## Comment:
MSDN:*"Databases provide storage, access, and sorting of property-set records.   
  
The Windows CE database model is that of a small, flat structure, optimized for small, efficient storage. As such, the Windows CE database APIs do not correspond to the Win32 database APIs.   
  
Data operations are transactioned within the object store or a database volume, which protects against data loss. If a Windows CE&reg; based device loses power (reset or suspend/resume, where the RAM is refreshed) during a data transaction, Windows CE reverts all partial database operations to the last known good state. "*  
  
  

***  

