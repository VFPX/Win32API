[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Saving local machine ODBC Registry Entries to XML file

## Before you begin:
This is an example of [resulting XML file](downloads/odbc.xml).
  
***  


## Code:
```foxpro  
#DEFINE ERROR_SUCCESS       0
#DEFINE KEY_ALL_ACCESS      0xF003F
#DEFINE HKEY_CURRENT_USER   0x80000001
#DEFINE HKEY_LOCAL_MACHINE  0x80000002
#DEFINE HKEY_USERS          0x80000003

#DEFINE REG_SZ        1
#DEFINE REG_EXPAND_SZ 2
#DEFINE REG_BINARY    3
#DEFINE REG_DWORD     4
#DEFINE REG_MULTI_SZ  7

DO decl

LOCAL oReg
oReg = CreateObject("Tregister", HKEY_LOCAL_MACHINE, "Software\ODBC")

IF TYPE("oReg") = "O"
	oReg.SaveToFile("c:\temp\reg.xml")
ENDIF
* end of main

DEFINE CLASS Tregister As Custom
	oXml=.F.

PROCEDURE Init(hParentKey, cSubkey)
	LOCAL hKey, oXml, oKey
	hKey = 0
	IF RegOpenKeyEx(hParentKey, cSubkey, 0, KEY_ALL_ACCESS, @hKey) <> ERROR_SUCCESS
		RETURN .F.
	ENDIF
	
	THIS.oXml = CreateObject("Microsoft.XMLDOM")
	THIS.oXml.LoadXML(CHR(60) + "Registry" + CHR(47) + CHR(62))

	WITH THIS.oXml.documentElement()
		.SetAttribute("name", cSubkey)
		.SetAttribute("parent", hParentKey)
	ENDWITH

	oKey = CreateObject("Tkey", THIS.oXml, THIS.oXml.documentElement(), hKey)

PROCEDURE SaveToFile(cFilename)
	IF FILE(cFilename)
		DELETE FILE(cFilename)
	ENDIF
	THIS.oXml.Save(cFilename)
	= ShellExecute(0,"open", cFilename, "", "", 3)

ENDDEFINE

DEFINE CLASS Tkey As Custom
	oXml=.F.
	parentnode=.F.
	hKey=0

PROCEDURE Init(oXml, oParentNode, hKey)
	THIS.oXml = oXml
	THIS.parentnode = oParentNode
	THIS.hKey = hKey

	THIS.EnumValues
	THIS.EnumSubKeys

	= RegCloseKey(THIS.hKey)

PROCEDURE EnumValues
	LOCAL nIndex, nNameLen, nDataLen, nType, cName, cData, objProperty
	nIndex = 0
	DO WHILE .T.
		STORE 4096 TO nNameLen, nDataLen
		STORE Repli(Chr(0), nDataLen) TO cName, cData
		nType = 0

		IF RegEnumValue(THIS.hKey, nIndex, @cName, @nNameLen,;
			0, @nType, @cData, @nDataLen) <> ERROR_SUCCESS
			EXIT
		ENDIF

		cName = SUBSTR(cName, 1, AT(Chr(0),cName)-1)
		cData = SUBSTR(cData, 1, AT(Chr(0),cData)-1)

		IF Not EMPTY(cName)
			objProperty = THIS.oXml.CreateElement("Value")
			objProperty.SetAttribute("name", cName)
			objProperty.SetAttribute("type", nType)

			IF nType = REG_DWORD
				cData = buf2dword(PADR(cData,4,Chr(0)))
			ENDIF
			objProperty.SetAttribute("Data", cData)

			THIS.parentnode.AppendChild(objProperty)
		ENDIF
		nIndex = nIndex + 1
	ENDDO

PROCEDURE EnumSubKeys
	LOCAL nIndex, cBuffer, nResult, hKey, objSubnode, oKey
	nIndex = 0
	DO WHILE .T.
		cBuffer = Repli(Chr(0), 512)
		nResult = RegEnumKey(THIS.hKey, nIndex, @cBuffer, Len(cBuffer))
		IF nResult <> ERROR_SUCCESS
			EXIT
		ENDIF

		cBuffer = SUBSTR(cBuffer, 1, AT(Chr(0),cBuffer)-1)
		hKey = 0

		IF RegOpenKeyEx(THIS.hKey, cBuffer, 0, KEY_ALL_ACCESS, @hKey) = ERROR_SUCCESS
			objSubnode = THIS.oXml.CreateElement("Key")
			objSubnode.SetAttribute("name", cBuffer)
			THIS.parentnode.AppendChild(objSubNode)
			oKey = CreateObject("Tkey", THIS.oXml, objSubNode, hKey)
		ENDIF
		nIndex = nIndex + 1
	ENDDO

ENDDEFINE

PROCEDURE decl
	DECLARE INTEGER RegEnumKey IN advapi32;
		INTEGER hKey, INTEGER dwIndex, STRING @lpName,;
		INTEGER cchName

	DECLARE INTEGER RegOpenKeyEx IN advapi32;
		INTEGER hKey, STRING lpSubKey, INTEGER ulOptions,;
		INTEGER samDesired, INTEGER @phkResult

	DECLARE INTEGER RegEnumValue IN advapi32;
		INTEGER hKey, INTEGER dwIndex, STRING @lpValueName,;
		INTEGER @lpcValueName, INTEGER lpReserved, INTEGER @lpType,;
		STRING @lpData, INTEGER @lpcbData

	DECLARE INTEGER ShellExecute IN shell32;
		INTEGER hwnd, STRING lpOperation, STRING lpFile,;
		STRING lpParams, STRING lpDir, INTEGER nShowCmd

	DECLARE INTEGER RegCloseKey IN advapi32 INTEGER hKey

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[RegCloseKey](../libraries/advapi32/RegCloseKey.md)  
[RegEnumKey](../libraries/advapi32/RegEnumKey.md)  
[RegEnumValue](../libraries/advapi32/RegEnumValue.md)  
[RegOpenKeyEx](../libraries/advapi32/RegOpenKeyEx.md)  
[ShellExecute](../libraries/shell32/ShellExecute.md)  

## Comment:
There is no much sense in copying data from one Tree structure to another, except the showing a variety of information being stored in that part of the Windows Registry. Also it can give you an idea about adding new Data Source Names (DSN) programmatically.  
  
 
  
Try also Software\ODBC with a combination with HKEY_CURRENT_USER, and of course other parts of the Registry are available too.  
  
***  

