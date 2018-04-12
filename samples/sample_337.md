[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Reading the structure of VFP main menu

## Before you begin:
This code sample reads the structure of VFP main menu and saves it in an XML document (the Microsoft.XMLDOM object is used for that).   

This is an output this code produces -- [the structure of VFP9 main menu](../images/vfp9menu.xml).

See also:

* [Transparent Menu on top-level form (requires VFP9)](sample_496.md)  
* [How to hot-track menu item selection in top-level form](sample_521.md)  
* [Adding user-defined items to the Control Menu of VFP form](sample_512.md)  

  
***  


## Code:
```foxpro  
PRIVATE objXml, cTargetFile
cTargetFile = "c:\temp\mnu.xml"  && replace with valid file name

DECLARE INTEGER GetActiveWindow IN user32
objXml = CREATEOBJECT("Tmenu", GetActiveWindow(), cTargetFile)

IF TYPE("objXML") = "O"
	objXml.SaveXML
	objXml.ViewXml
ELSE
	= MessageB("Invalid input parameters. ", 48, " Error")
ENDIF

DEFINE CLASS Tmenu As Custom
PROTECTED hWindow, hMenu, xmldoc, rootnode, targetfile

PROCEDURE Init(hwnd, cTargetFile)
	THIS.declare
	
	cTargetFile = FULLPATH(cTargetFile)
	IF PathFileExists(SUBS(cTargetFile, 1,RAT("\",cTargetFile))) = 0
		RETURN .F.  && invalid path
	ENDIF

	THIS.hWindow = hwnd
	THIS.hMenu = GetMenu(hwnd)
	IF IsMenu(THIS.hMenu) = 0
		RETURN .F.  && no menu found
	ENDIF

	WITH THIS
		.targetfile = cTargetFile
		.xmldoc = CreateObject("Microsoft.XMLDOM")

		.xmldoc.LoadXML(CHR(60)+[?xml version="1.0" ?]+CHR(62)+;
			CHR(60)+[TopMenu ]+CHR(47)+CHR(62))

		.rootnode = .xmldoc.documentElement()
		.SetProperty(.rootnode, "hWnd", m.hwnd)
		.DescribeNode(-1, .rootnode, .hMenu, 0,0)  && recursion
	ENDWITH

PROCEDURE SaveXML
	THIS.xmldoc.Save(THIS.targetfile)

PROCEDURE ViewXml
	= ShellExecute(0,"open", THIS.targetfile, "", "", 3)

PROCEDURE DescribeNode(hParent, objNode, hMenu, lnItemIndex, lnItemID)
	LOCAL lnItemCount, objSubnode, hSubitem, lnIndex, lnID,;
		lnItemType, lnDataType, lnChecked, lnUnchecked, lnBitmap, lcItemType

	THIS.SetProperty(objNode, "hMenu", m.hMenu)
	THIS.SetProperty(objNode, "ItemIndex", m.lnItemIndex)
	THIS.SetProperty(objNode, "ItemID", m.lnItemID)
	
	IF hParent = -1  && root
		THIS.SetProperty(objNode, "WinCaption", THIS.GetWinCaption())
	ELSE
		STORE 0 TO lnItemType, lnDataType, lnBitmap, lnChecked, lnUnchecked
		THIS.GetItemData(hParent, lnItemIndex, @lnItemType,;
			@lnDataType, @lnChecked, @lnUnchecked, @lnBitmap)

		THIS.SetProperty(objNode, "ItemType", lnItemType)
		IF lnItemType <> 0
			lcItemType = THIS.GetItemTypeStr(lnItemType)
			THIS.SetProperty(objNode, "ItemTypeStr", lcItemType)
		ENDIF
		THIS.SetProperty(objNode, "DataType", lnDataType)
	ENDIF
	
	IF hMenu = -1
		RETURN
	ENDIF

	lnItemCount = GetMenuItemCount(m.hMenu)
	THIS.SetProperty(objNode, "ItemCount", m.lnItemCount)

	FOR lnIndex = 0 TO lnItemCount-1
		lnID = GetMenuItemID(m.hMenu, lnIndex)
		IF lnID = -1  && submenu
			objSubnode = THIS.xmldoc.CreateElement("SubMenu")
			hSubitem = THIS.GetSubmenuHandle(m.hMenu, m.lnIndex)
		ELSE  && menu item
			objSubnode = THIS.xmldoc.CreateElement("MenuItem")
			hSubitem = -1
		ENDIF
		objNode.AppendChild(objSubnode)
		THIS.DescribeNode(hMenu, objSubnode, hSubitem, lnIndex, lnID)
	ENDFOR
RETURN

PROCEDURE SetProperty(objNode, lcProperty, lvValue)
	LOCAL loProperty, loAttr, lcType
	loProperty = objNode.SelectSingleNode(lcProperty)
	
	IF TYPE("loProperty.Value") <> "C"
		loProperty = THIS.xmldoc.CreateElement(lcProperty)
		objNode.AppendChild(loProperty)
	ENDIF
	
	lcType = TYPE("lvValue")
	DO CASE
	CASE lcType = "C"
		lvValue = ALLTRIM(lvValue)
	CASE lcType = "L"
		lvValue = Iif(lvValue, "true","false")
	CASE lcType = "D"
		lvValue = DTOC(lvValue)
	CASE lcType = "T"
		lvValue = TTOC(lvValue)
	CASE lcType = "N"
		lvValue = LTRIM(STR(lvValue, 20))
	ENDCASE
	loProperty.Text = lvValue

PROCEDURE declare
#DEFINE MENUITEMINFO_SIZE 48
#DEFINE MIIM_TYPE  16
#DEFINE MIIM_SUBMENU 4
#DEFINE MIIM_DATA 32
#DEFINE MF_STRING 0
#DEFINE MF_BITMAP 4
#DEFINE MF_MENUBARBREAK 0x20
#DEFINE MF_MENUBREAK 0x40
#DEFINE MIIM_BITMAP 0x80
#DEFINE MF_OWNERDRAW 0x100
#DEFINE MFT_RADIOCHECK 0x200
#DEFINE MF_SEPARATOR 0x800
#DEFINE MFT_RIGHTORDER 0x2000
#DEFINE MF_RIGHTJUSTIFY 0x4000

	DECLARE INTEGER GetObjectType IN gdi32 INTEGER h
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GetMenu IN user32 INTEGER hWnd
	DECLARE INTEGER IsMenu IN user32 INTEGER hMenu
	DECLARE INTEGER PathFileExists IN shlwapi STRING pszPath
	DECLARE INTEGER GetMenuItemCount IN user32 INTEGER hMenu
	DECLARE INTEGER GetMenuItemID IN user32 INTEGER hMenu, INTEGER nPos

	DECLARE INTEGER ShellExecute IN shell32;
		INTEGER hwnd, STRING lpOperation, STRING lpFile,;
		STRING lpParams, STRING lpDir, INTEGER nShowCmd

	DECLARE INTEGER GetMenuItemInfo IN user32;
		INTEGER hMenu, INTEGER uItem, INTEGER fByPosition, STRING @lpmii

	DECLARE INTEGER GetMenuString IN user32;
		INTEGER hMenu, INTEGER uIDItem, STRING @lpString,;
		INTEGER @nMaxCount, INTEGER uFlag

	DECLARE INTEGER GetWindowText IN user32;
		INTEGER hwnd, STRING @lpString, INTEGER cch

FUNCTION GetWinCaption
	LOCAL lcCaption
	lcCaption = SPACE(250)
	= GetWindowText(THIS.hWindow, @lcCaption, LEN(lcCaption))
RETURN ALLTRIM(STRTRAN(lcCaption, Chr(0), ""))
	
FUNCTION GetSubmenuHandle(hMenu, lnIndex)
	LOCAL lcBuffer
	lcBuffer = num2dword(MENUITEMINFO_SIZE) +;
		num2dword(MIIM_SUBMENU) + Repli(Chr(0), 40)
	= GetMenuItemInfo(hMenu, lnIndex, 1, @lcBuffer)
RETURN buf2dword(SUBSTR(lcBuffer, 21,4))

PROCEDURE GetItemData
PARAM hMenu, lnIndex, lnIType, lnDType, lnChecked, lnUnchecked, lnBMP
	LOCAL lcBuffer, loItemData
	loItemData = CreateObject("PChar", Repli(Chr(0), 250))
	lcBuffer = num2dword(MENUITEMINFO_SIZE) +;
		num2dword(MIIM_TYPE+MIIM_DATA) + Repli(Chr(0), 28) +;
		num2dword(loItemData.hMem) + Repli(Chr(0), 8)
	= GetMenuItemInfo(hMenu, lnIndex, 1, @lcBuffer), lcBuffer
	lnIType = buf2dword(SUBSTR(lcBuffer, 9,4))
	lnDType = buf2dword(SUBSTR(lcBuffer, 37,4))
	lnBMP = buf2dword(SUBSTR(lcBuffer, 45,4))
	
FUNCTION BTest(lnExpr, lnTest)
RETURN BitAnd(lnExpr, lnTest) = lnTest

FUNCTION GetItemTypeStr(lnType)
	LOCAL cType
	cType = ""
	cType = cType + Iif(THIS.BTest(lnType, MF_BITMAP),       "bitmap;", "")
	cType = cType + Iif(THIS.BTest(lnType, MF_MENUBARBREAK), "barbreak;","")
	cType = cType + Iif(THIS.BTest(lnType, MF_MENUBREAK),    "break;","")
	cType = cType + Iif(THIS.BTest(lnType, MIIM_BITMAP),     "xbitmap;","")
	cType = cType + Iif(THIS.BTest(lnType, MF_OWNERDRAW),    "owner;","")
	cType = cType + Iif(THIS.BTest(lnType, MFT_RADIOCHECK),  "radio;","")
	cType = cType + Iif(THIS.BTest(lnType, MF_SEPARATOR),    "separator;","")
	cType = cType + Iif(THIS.BTest(lnType, MFT_RIGHTORDER),  "rightord;","")
	cType = cType + Iif(THIS.BTest(lnType, MF_RIGHTJUSTIFY), "rightjust;","")
RETURN cType
ENDDEFINE

DEFINE CLASS PChar As Custom
	hMem=0

PROCEDURE Init(lcString)
	THIS.setValue(lcString)
PROCEDURE Destroy
	THIS.ReleaseString

PROCEDURE SetValue(lcString) && assigns new string value
#DEFINE GMEM_FIXED 0
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As Str2Heap;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize

	THIS.ReleaseString
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)

	THIS.hMem = GlobalAlloc(GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= Str2Heap(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree(THIS.hMem)
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
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetMenu](../libraries/user32/GetMenu.md)  
[GetMenuItemCount](../libraries/user32/GetMenuItemCount.md)  
[GetMenuItemID](../libraries/user32/GetMenuItemID.md)  
[GetMenuItemInfo](../libraries/user32/GetMenuItemInfo.md)  
[GetMenuString](../libraries/user32/GetMenuString.md)  
[GetObjectType](../libraries/gdi32/GetObjectType.md)  
[GetWindowText](../libraries/user32/GetWindowText.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[IsMenu](../libraries/user32/IsMenu.md)  
[PathFileExists](../libraries/shlwapi/PathFileExists.md)  
[ShellExecute](../libraries/shell32/ShellExecute.md)  

## Comment:
All VFP menu items are of the OWNERDRAW type. Which means the main window receives at least two types of menu-related window messages: **WM_MEASUREITEM** and **WM_DRAWITEM**.  
  
The first one is received when menu item is created. The second message comes every time when menu item has to be drawn or redrawn (for example, triggered by item selection change).   
  
Since VFP9 allows intercepting window messages through BINDEVENT calls, the processing of the WM_DRAWITEM and other menu-related window messages becomes a feasible task.   
  
***  

