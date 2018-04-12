[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Pocket PC: custom RAPI class for operating with the System Registry

## Before you begin:
![](../images/pocketpcs.png)  

Solutions based on this class:  
* [System Registry Viewer](sample_442.md)  
* [System Registry Backup](sample_443.md)  
* [Modifying Keys in the System Registry](sample_444.md)  

Note that this class creates several Collections, which makes it unusable in older Visual FoxPro versions.  
  
***  


## Code:
```foxpro  
DEFINE CLASS Trapi As Custom
#DEFINE ERROR_SUCCESS 0
	connected=.F.

PROCEDURE Init
	THIS.decl
	THIS.InitRapi()
	
PROCEDURE InitRapi
#DEFINE RAPIINIT_SIZE  12
#DEFINE WAIT_OBJECT_0  0
	THIS.UninitRapi

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
	DECLARE INTEGER CeRapiUninit IN rapi
	DECLARE INTEGER CeRapiInitEx IN rapi STRING @pRapiInit
	DECLARE INTEGER CeRegCloseKey IN rapi INTEGER hKey

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds

	DECLARE INTEGER CeRegEnumKeyEx IN rapi;
		INTEGER hKey, INTEGER dwIndex, STRING @lpName,;
		INTEGER @lpcbName, INTEGER lpReserved,;
		STRING @lpClass, INTEGER @lpcbClass, INTEGER lpftLastWriteTime

	DECLARE INTEGER CeRegOpenKeyEx IN rapi;
		INTEGER hKey, STRING lpszSubKey, INTEGER ulOptions,;
		INTEGER samDesired, INTEGER @phkResult

	DECLARE INTEGER CeRegEnumValue IN rapi;
		INTEGER hKey, INTEGER dwIndex, STRING @lpszValueName,;
		INTEGER @lpcbValueName, INTEGER lpReserved, INTEGER @lpType,;
		STRING @lpData, INTEGER @lpcbData

	DECLARE INTEGER CeRegQueryInfoKey IN rapi;
		INTEGER hKey, STRING @lpClass, INTEGER @lpcbClass,;
		INTEGER lpReserved, INTEGER @lpcSubKeys,;
		INTEGER @lpcbMaxSubKeyLen, INTEGER @lpcbMaxClassLen,;
		INTEGER @lpcValues, INTEGER @lpcbMaxValueNameLen,;
		INTEGER @lpcbMaxValueLen, INTEGER lpcbSecurityDescr,;
		INTEGER lpftLastWriteTime

	DECLARE INTEGER CeRegCreateKeyEx IN rapi;
		INTEGER hKey, STRING lpszSubKey, INTEGER Reserved,;
		STRING lpszClass, INTEGER dwOptions, INTEGER samDesired,;
		INTEGER lpSecurityAttr, INTEGER @phkResult, INTEGER @lpdwDisp

	DECLARE INTEGER CeRegDeleteKey IN rapi INTEGER hKey, STRING lpszSubKey
	DECLARE INTEGER CeRegDeleteValue IN rapi INTEGER hKey, STRING lpszValueName

	DECLARE INTEGER CeRegSetValueEx IN rapi;
		INTEGER hKey, STRING lpValueName, INTEGER Reserved,;
		INTEGER dwType, STRING @lpData, INTEGER cbData

	DECLARE INTEGER CeRegQueryValueEx IN rapi;
		INTEGER hKey, STRING lpValueName, INTEGER lpReserved,;
		INTEGER @lpType, STRING @lpData, INTEGER @lpcbData
ENDDEFINE

DEFINE CLASS Tkeys As Collection  && set of registry keys
	hparent=0

PROCEDURE Init(hParent)
	THIS.hparent = m.hParent

	LOCAL nIndex, cName, cClass
	nIndex = 0
	DO WHILE .T.
		STORE "" TO cName, cClass
		IF THIS.GetSubkey(nIndex, @cName, @cClass) = 0
			LOCAL oSubkey
			oSubkey = CREATEOBJECT("Tkey", THIS.hparent, cName)
			oSubkey.classname = cClass
			THIS.Add(oSubkey, cName)
			RELEASE oSubkey
		ELSE
			EXIT
		ENDIF
		nIndex = nIndex + 1
	ENDDO

PROCEDURE GetSubkey(nIndex, cName, cClass)
	LOCAL nNameSize, nClassSize, nResult
	STORE 250 TO nNameSize, nClassSize
	STORE REPLICATE(CHR(0),nNamesize*2) TO cName, cClass
	
	nResult = CeRegEnumKeyEx(THIS.hParent, m.nIndex,;
		@cName, @nNameSize, 0, @cClass, @nClassSize, 0)
		
	IF nResult = ERROR_SUCCESS
		cName = STRCONV(SUBSTR(cName, 1, nNameSize*2), 6)
		cClass = STRCONV(SUBSTR(cClass, 1, nClassSize*2), 6)
	ELSE
		STORE "" TO cName, cClass
	ENDIF
RETURN nResult
ENDDEFINE

DEFINE CLASS Tkey As Custom  && registry key
	hparent=0
	hkey=0
	keyname=""
	classname=""
	subkeycount=0
	valuecount=0
	errorcode=0
	keyvalues=0

PROCEDURE Init(hParent, KeyName)
	THIS.hparent = IIF(VARTYPE(hParent)="N", m.hParent, 0)
	THIS.keyname = IIF(VARTYPE(m.KeyName) = "C", m.KeyName, "")

PROCEDURE Destroy
	THIS.CloseKey

PROCEDURE CloseKey
	IF THIS.hkey <> 0
		= CeRegCloseKey(THIS.hkey)
		THIS.hkey = 0
	ENDIF

PROCEDURE OpenKey
	THIS.CloseKey
	LOCAL hKey, cKeyname
	hKey = 0
	cKeyname = STRCONV(THIS.keyname+CHR(0), 5)
	THIS.errorcode = CeRegOpenKeyEx(THIS.hparent, m.cKeyname, 0,0,@hKey)
	
	THIS.hkey = m.hKey
RETURN (THIS.errorcode=ERROR_SUCCESS)
	
PROCEDURE QueryInfo
	LOCAL cClass, nClassSize, nSubkeyCount, nMaxSubkeyLen,;
		nMaxClassLen, nValueCount, nMaxValueNameLen, nMaxValueLen
	nClassSize = 250
	cClass = REPLICATE(CHR(0), nClassSize*2)
	STORE 0 TO nSubkeyCount, nMaxSubkeyLen, nMaxClassLen,;
		nValueCount, nMaxValueNameLen, nMaxValueLen

	THIS.errorcode = CeRegQueryInfoKey(THIS.hkey, @cClass, @nClassSize, 0,;
		@nSubkeyCount, @nMaxSubkeyLen, @nMaxClassLen,;
		@nValueCount, @nMaxValueNameLen, @nMaxValueLen, 0,0)

	THIS.subkeycount = nSubkeyCount
	THIS.valuecount = nValueCount
	THIS.classname = STRCONV(SUBSTR(cClass, 1, nClassSize*2), 6)

PROCEDURE GetValues
	THIS.keyvalues = CREATEOBJECT("Tvalues", THIS.hkey)

PROCEDURE CreateSubkey(cSubkeyName, cSubkeyClass)
	IF THIS.hKey = 0
		RETURN .F.
	ENDIF

	LOCAL hSubkey, nDisp
	STORE 0 TO hSubkey, nDisp
	cSubkeyName = STRCONV(cSubkeyName+CHR(0), 5)
	cSubkeyClass = STRCONV(cSubkeyClass+CHR(0), 5)
	
	THIS.errorcode = CeRegCreateKeyEx(THIS.hkey, cSubkeyName, 0,;
		cSubkeyClass, 0, 0, 0, @hSubkey, @nDisp)

	IF hSubkey <> 0
		= CeRegCloseKey(hSubkey)
	ENDIF
RETURN (THIS.errorcode=ERROR_SUCCESS)

PROCEDURE DeleteSubkey(cSubkeyName)
	IF THIS.hKey = 0
		RETURN .F.
	ELSE
		cSubkeyName = STRCONV(cSubkeyName+CHR(0), 5)
		THIS.errorcode = CeRegDeleteKey(THIS.hkey, cSubkeyName)
		RETURN (THIS.errorcode=ERROR_SUCCESS)
	ENDIF

PROCEDURE SetValueInt(cValueName, nValue)
	RETURN THIS.SetValue(cValueName, 4, nValue)
PROCEDURE SetValueStr(cValueName, cValue)
	RETURN THIS.SetValue(cValueName, 1, cValue)
PROCEDURE SetValueBin(cValueName, vValue)
	RETURN THIS.SetValue(cValueName, 3, vValue)

PROTECTED PROCEDURE SetValue(cValueName, nValueType, vValue)
	DO CASE
	CASE THIS.hKey = 0
		RETURN .F.
	CASE nValueType=1  && string, REG_SZ
		IF VARTYPE(vValue)<>"C"
			RETURN .F.
		ENDIF
		vValue = STRCONV(ALLTRIM(STRTRAN(vValue, CHR(0),""))+CHR(0), 5)

	CASE nValueType=4 AND VARTYPE(vValue)<>"N" && numeric, REG_DWORD
		RETURN .F.
	CASE nValueType=3  AND NOT VARTYPE(vValue) $ "CN" && binary, REG_BINARY
		RETURN .F.
	CASE NOT INLIST(nValueType, 1,3,4)
		RETURN .F.
	ENDCASE
	
	cValueName = STRCONV(cValueName+CHR(0), 5)
	IF VARTYPE(vValue)="N"
		vValue = num2dword(vValue)
	ENDIF

	THIS.errorcode = CeRegSetValueEx(THIS.hkey, cValueName, 0,;
		nValueType, @vValue, LEN(vValue))
RETURN (THIS.errorcode=ERROR_SUCCESS)

PROCEDURE DeleteValue(cValueName)
	DECLARE INTEGER CeRegDeleteValue IN rapi INTEGER hKey, STRING lpszValueName
	IF THIS.hkey = 0
		RETURN .F.
	ELSE
		cValueName = STRCONV(cValueName+CHR(0), 5)
		THIS.errorcode = CeRegDeleteValue(THIS.hkey, cValueName)
		RETURN (THIS.errorcode=ERROR_SUCCESS)
	ENDIF

ENDDEFINE

DEFINE CLASS Tvalues As Collection  && set of registry key values
	hkey=0

PROCEDURE Init(hKey)
	IF VARTYPE(hKey)="N"
		THIS.hkey=m.hKey
		THIS.GetValues
	ENDIF

PROCEDURE GetValues
	LOCAL nIndex
	nIndex = 0
	DO WHILE THIS.GetValue(nIndex)
		nIndex = nIndex + 1
	ENDDO

PROTECTED PROCEDURE GetValue(nIndex)
	LOCAL cName, nNameSize, nType, cBuffer, nBufsize, nResult, oValue
	nNameSize = 250
	cName = REPLICATE(CHR(0), nNameSize*2)
	nType = 0
	nBufsize = 4096
	cBuffer = REPLICATE(CHR(0), nBufsize*2)
	
	IF CeRegEnumValue(THIS.hkey, nIndex, @cName, @nNameSize,;
		0, @nType, @cBuffer, @nBufsize) <> ERROR_SUCCESS
		RETURN .F.
	ENDIF
	cName = STRCONV(SUBSTR(cName, 1, nNameSize*2), 6)
	cBuffer = SUBSTR(cBuffer, 1, nBufsize)
	oValue = CREATEOBJECT("Tvalue", cName, nType, cBuffer)
	THIS.Add(oValue, cName)
ENDDEFINE

DEFINE CLASS TValue As Custom  && registry key value
	valuename=""
	valuetype=0
	valuerawdata=""

PROCEDURE Init(cName, nType, cBuffer)
	THIS.valuename = cName
	THIS.valuetype = nType
	THIS.valuerawdata = cBuffer
ENDDEFINE

FUNCTION buf2dword(lcBuffer)  && 4-byte buffer (DWORD) to numeric
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION num2dword(lnValue)  && numeric to 4-byte buffer (DWORD)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[CeRapiInitEx](../libraries/rapi/CeRapiInitEx.md)  
[CeRapiUninit](../libraries/rapi/CeRapiUninit.md)  
[CeRegCloseKey](../libraries/rapi/CeRegCloseKey.md)  
[CeRegCreateKeyEx](../libraries/rapi/CeRegCreateKeyEx.md)  
[CeRegDeleteKey](../libraries/rapi/CeRegDeleteKey.md)  
[CeRegDeleteValue](../libraries/rapi/CeRegDeleteValue.md)  
[CeRegEnumKeyEx](../libraries/rapi/CeRegEnumKeyEx.md)  
[CeRegEnumValue](../libraries/rapi/CeRegEnumValue.md)  
[CeRegOpenKeyEx](../libraries/rapi/CeRegOpenKeyEx.md)  
[CeRegQueryInfoKey](../libraries/rapi/CeRegQueryInfoKey.md)  
[CeRegQueryValueEx](../libraries/rapi/CeRegQueryValueEx.md)  
[CeRegSetValueEx](../libraries/rapi/CeRegSetValueEx.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  

## Comment:
Windows CE does not support the HKEY_CURRENT_CONFIG, HKEY_PERFORMANCE_DATA, or HKEY_DYN_DATA predefined reserved handle values.  

***  

