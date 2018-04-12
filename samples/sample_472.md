[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Class library providing access to the System Registry

## Short description:
This code sample includes classes *registry*, *regkey*, *regkeys*, *regvalue* and *regvalues*. All together they provide view, read, write and delete functionality for the System Registry. Examples showing how to use this class are coming soon.  
***  


## Before you begin:
The following code includes classes *registry*, *regkey*, *regkeys*, *regvalue* and *regvalues*. All together they provide view, read, write and delete functionality for the System Registry. Examples showing how to use this class are coming soon.  

Create *Registry* object before using any other class from this library. This object contains API declarations the other classes use.  

```foxpro
LOCAL rg As Registry  
rg = CREATEOBJECT("Registry")
```
The next snip opens Software key in HKEY_LOCAL_MACHINE and adds _test subkey to it.  

```foxpro
LOCAL rgkey As regkey  
rgkey = CREATEOBJECT("regkey",;  
	HKEY_LOCAL_MACHINE, "Software")  

WITH rgkey  
	IF .OpenKey()  
		.CreateSubkey("_test", "")  
	ENDIF  
ENDWITH
```
And the last one adds several values to a key.  

```foxpro
WITH rgkey  
	IF .OpenKey()  
		.SetValue("TestValue0", 0, 16)  && REG_NONE  
		.SetValue("TestValue1", 1, "abc")  && REG_SZ  
		.SetValue("TestValue3", 3, "abc")  && REG_BINARY  
		.SetValue("TestValue4", 4, "128")  && REG_DWORD  
	ENDIF  
ENDWITH
```

Usage samples:  
* [Enumerating Windows Sound Schemes avaialble to the current user](sample_593.md)  

  
***  


## Code:
```foxpro  
DEFINE CLASS Registry As Custom
#DEFINE KEY_ALL_ACCESS 0xf003f
#DEFINE ERROR_SUCCESS 0
#DEFINE REG_SZ 1
#DEFINE REG_EXPAND_SZ 2
#DEFINE REG_BINARY 3
#DEFINE REG_DWORD 4

PROCEDURE Init
	DECLARE INTEGER RegOpenKeyEx IN advapi32;
		INTEGER hKey, STRING lpSubKey, INTEGER ulOptions,;
		INTEGER samDesired, INTEGER @phkResult

	DECLARE INTEGER RegCreateKeyEx IN advapi32;
		INTEGER hKey, STRING lpSubKey, INTEGER Reserved,;
		STRING lpClass, INTEGER dwOptions, INTEGER samDesired,;
		INTEGER lpSecurityAttributes, INTEGER @phkResult,;
		INTEGER @lpdwDisposition

	DECLARE INTEGER RegEnumKeyEx IN advapi32;
		INTEGER hKey, INTEGER dwIndex, STRING @lpName,;
		INTEGER @lpcbName, INTEGER lpReserved,;
		STRING @lpClass, INTEGER @lpcbClass, INTEGER lpftLastWriteTime

	DECLARE INTEGER RegQueryInfoKey IN advapi32;
		INTEGER hKey, STRING @lpClass, INTEGER @lpcbClass,;
		INTEGER lpReserved, INTEGER @lpcSubKeys,;
		INTEGER @lpcbMaxSubKeyLen, INTEGER @lpcbMaxClassLen,;
		INTEGER @lpcValues, INTEGER @lpcbMaxValueNameLen,;
		INTEGER @lpcbMaxValueLen, INTEGER lpcbSecurityDescr,;
		INTEGER lpftLastWriteTime

	DECLARE INTEGER RegSetValueEx IN advapi32;
		INTEGER hKey, STRING lpValueName, INTEGER Reserved,;
		INTEGER dwType, STRING @lpData, INTEGER cbData

	DECLARE INTEGER RegEnumValue IN advapi32;
		INTEGER hKey, INTEGER dwIndex, STRING @lpszValueName,;
		INTEGER @lpcbValueName, INTEGER lpReserved, INTEGER @lpType,;
		STRING @lpData, INTEGER @lpcbData

	DECLARE INTEGER RegCloseKey IN advapi32 INTEGER hKey
	DECLARE INTEGER RegDeleteKey IN advapi32 INTEGER hKey, STRING lpSubKey

	DECLARE INTEGER RegDeleteValue IN advapi32;
		INTEGER hKey, STRING lpValueName

ENDDEFINE

Define Class regkey As Custom
	hparent=0
	hkey=0
	keyname=""
	classname=""
	subkeycount=0
	valuecount=0
	keyvalues=0
	errorcode=0

Procedure Init(hparent, keyname)
	This.hparent = Iif(Vartype(hparent)="N", m.hparent, 0)
	This.keyname = Iif(Vartype(m.keyname) = "C", m.keyname, "")

Procedure Destroy
	This.closekey

Procedure closekey
	If This.hkey <> 0
		= RegCloseKey(This.hkey)
		This.hkey = 0
	Endif

Procedure openkey
	This.closekey
	Local hkey
	hkey = 0
	This.errorcode = RegOpenKeyEx(This.hparent, THIS.keyname,;
		0, KEY_ALL_ACCESS, @hkey)
	This.hkey = m.hkey
Return (This.errorcode=ERROR_SUCCESS)

Procedure queryinfo
	Local cClass, nClassSize, nSubkeyCount, nMaxSubkeyLen,;
		nMaxClassLen, nValueCount, nMaxValueNameLen, nMaxValueLen

	nClassSize = 250
	cClass = Replicate(Chr(0), nClassSize*2)
	Store 0 To nSubkeyCount, nMaxSubkeyLen, nMaxClassLen,;
		nValueCount, nMaxValueNameLen, nMaxValueLen

	This.errorcode = RegQueryInfoKey(This.hkey, @cClass, @nClassSize, 0,;
		@nSubkeyCount, @nMaxSubkeyLen, @nMaxClassLen,;
		@nValueCount, @nMaxValueNameLen, @nMaxValueLen, 0,0)

	This.subkeycount = nSubkeyCount
	This.valuecount = nValueCount
	This.classname = Substr(cClass, 1, nClassSize*2)

Procedure getvalues
	This.keyvalues = Newobject("regvalues", "","", This.hkey)

PROCEDURE subkeyexists(cSubkeyName As String, lCreate As Boolean) As Boolean
	If This.hkey = 0
		Return .F.
	ENDIF
	
	LOCAL oSubKey As regkey, lResult
	oSubKey = CREATEOBJECT("regkey", THIS.hKey, cSubKeyName)
	lResult= oSubKey.OpenKey()
	
	IF ((NOT m.lResult) AND m.lCreate)
		THIS.createsubkey(cSubkeyName, "")
		RETURN THIS.subkeyexists(cSubkeyName)
	ENDIF
RETURN m.lResult

Procedure createsubkey(cSubkeyName, cSubkeyClass)
	If This.hkey = 0
		Return .F.
	Endif

	Local hSubkey, nDisp
	Store 0 To hSubkey, nDisp

	This.errorcode = RegCreateKeyEx(This.hkey, cSubkeyName, 0,;
		cSubkeyClass, 0, 0, 0, @hSubkey, @nDisp)

	If hSubkey <> 0
		= RegCloseKey(hSubkey)
	Endif
Return (This.errorcode=ERROR_SUCCESS)

Procedure deletesubkey(cSubkeyName)
	If This.hkey = 0
		Return .F.
	Endif
	
	IF RegDeleteKey(This.hkey, cSubkeyName) = ERROR_SUCCESS
		RETURN .T.
	ENDIF

	LOCAL oSubkey As regkey
	oSubkey = CREATEOBJECT("regkey", THIS.hkey, cSubkeyname)
	IF NOT oSubkey.openkey()
		RETURN .F.
	ENDIF

	LOCAL oSubSubkeys As regkeys
	oSubSubkeys = CREATEOBJECT("regkeys", oSubkey.hkey)
	FOR EACH oSubSubkey IN oSubSubkeys
		oSubkey.deletesubkey(oSubSubkey.keyname)
	NEXT
	oSubSubkey=Null
	
	This.errorcode = RegDeleteKey(This.hkey, cSubkeyName)
Return (This.errorcode=ERROR_SUCCESS)

Procedure setvalue(cValueName, nValueType, vValue)
	Do Case
	Case This.hkey = 0
		Return .F.
	Case INLIST(nValueType, REG_SZ, REG_EXPAND_SZ)
		If Vartype(vValue)<>"C"
			vValue = TRANSFORM(m.vValue)
		Endif
		vValue = Alltrim(Strtran(vValue, Chr(0),""))+Chr(0)
	Case nValueType=REG_DWORD
		IF Vartype(vValue)<>"N"
			vValue = VAL(m.vValue)
		ENDIF
	Case nValueType=REG_BINARY
		IF NOT Vartype(vValue) $ "CN"
			vValue = TRANSFORM(m.vValue)
		ENDIF
	Case Not Inlist(nValueType, 0,1,2,3,4)
		Return .F.
	Endcase

	If Vartype(vValue)="N"
		vValue = num2dword(vValue)
	Endif

	This.errorcode = RegSetValueEx(This.hkey, cValueName, 0,;
		nValueType, @vValue, Len(vValue))
Return (This.errorcode=ERROR_SUCCESS)

Procedure setvalueint(cValueName, nValue)
Return This.setvalue(cValueName, 4, nValue)

Procedure setvaluestr(cValueName, cValue)
Return This.setvalue(cValueName, 1, cValue)

Procedure setvaluebin(cValueName, vValue)
Return This.setvalue(cValueName, 3, vValue)

Procedure deletevalue(cValueName)
	If This.hkey = 0
		Return .F.
	Else
		This.errorcode = RegDeleteValue(This.hkey, cValueName)
		Return (This.errorcode=ERROR_SUCCESS)
	Endif

Enddefine

Define Class regvalue As Custom
	valuename = ""
	valuetype = 0
	valuerawdata = ""

Procedure Init(cName, nType, cBuffer)
	This.valuename = m.cName
	This.valuetype = m.nType
	This.valuerawdata = m.cBuffer
	
Enddefine

Define Class regkeys As Collection
	hparent = 0

Procedure Init(hparent)
	This.hparent = m.hparent

	Local nIndex, cName, cClass
	nIndex = 0

	Do While .T.
		Store "" To cName, cClass
		If This.getsubkey(nIndex, @cName, @cClass) = 0
			Local oSubkey
			oSubkey = CreateObject ("regkey", This.hparent, cName)
			oSubkey.classname = cClass
			This.Add(oSubkey, cName)
			Release oSubkey
		Else
			Exit
		Endif
		nIndex = nIndex + 1
	Enddo

Protected Procedure getsubkey(nIndex, cName, cClass)
	Local nNameSize, nClassSize, nResult
	Store 250 To nNameSize, nClassSize
	Store Replicate(Chr(0),nNameSize*2) To cName, cClass

	nResult = RegEnumKeyEx(This.hparent, m.nIndex,;
		@cName, @nNameSize, 0, @cClass, @nClassSize, 0)

	If nResult = ERROR_SUCCESS
		cName = Substr(cName, 1, nNameSize*2)
		cClass = Substr(cClass, 1, nClassSize*2)
	Else
		Store "" To cName, cClass
	Endif
Return nResult

Procedure getregkey(cName As String)
	Local oRegKey As regkey
	oRegKey = Newobject("regkey", "","", This.hparent, m.cName)
Return m.oRegKey

Enddefine

Define Class regvalues As Collection
	hkey = 0

Procedure Init(hkey)
	If Vartype(hkey)="N"
		This.hkey=m.hkey
		This.getvalues
	Endif

Procedure getvalues
	Local nIndex
	nIndex = 0
	Do While This.GetValue(nIndex)
		nIndex = nIndex + 1
	Enddo

Protected Procedure GetValue(nIndex)
	Local cName, nNameSize, nType, cBuffer, nBufsize, nResult, oValue
	nNameSize = 250
	cName = Replicate(Chr(0), nNameSize*2)
	nType = 0
	nBufsize = 4096
	cBuffer = Replicate(Chr(0), nBufsize*2)

	nResult = RegEnumValue(This.hkey, nIndex, @cName, @nNameSize,;
			0, @nType, @cBuffer, @nBufsize)

	IF nResult <> ERROR_SUCCESS
		Return .F.
	Endif

	cName = Substr(cName, 1, nNameSize*2)
	cBuffer = Substr(cBuffer, 1, nBufsize)
	oValue = Newobject("regvalue", "","", cName, nType, cBuffer)

	IF EMPTY(cName)
		This.Add(oValue, "(Default)")
	ELSE
		This.Add(oValue, cName)
	ENDIF

Enddefine

FUNCTION num2dword(lnValue)
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

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[RegCloseKey](../libraries/advapi32/RegCloseKey.md)  
[RegCreateKeyEx](../libraries/advapi32/RegCreateKeyEx.md)  
[RegDeleteKey](../libraries/advapi32/RegDeleteKey.md)  
[RegDeleteValue](../libraries/advapi32/RegDeleteValue.md)  
[RegEnumKeyEx](../libraries/advapi32/RegEnumKeyEx.md)  
[RegEnumValue](../libraries/advapi32/RegEnumValue.md)  
[RegOpenKeyEx](../libraries/advapi32/RegOpenKeyEx.md)  
[RegQueryInfoKey](../libraries/advapi32/RegQueryInfoKey.md)  
[RegSetValueEx](../libraries/advapi32/RegSetValueEx.md)  

## Comment:
RegDeleteKey: the subkey to be deleted must not have subkeys. CeRegDeleteKey (Windows CE, RAPI) deletes the subkey regardless of whether it has its own subkeys.  
  
***  

