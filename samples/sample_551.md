[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Starting a dialog box for connecting to network resources and passing input parameters

## Short description:
This code sample is an extension of  "#309. Starting a dialog box for connecting to network resources". The code is written around the WNetConnectionDialog1 function and provides a better control of the network connection dialog through input parameters.  
***  


## Before you begin:
This code sample is an extension of  [Starting a dialog box for connecting to network resources](sample_309.md). The code is written around the WNetConnectionDialog1 function and provides to some extent better control of the network connection dialog through input parameters.  

![](../images/mapnetworkdrive_dlg.jpg)

See also:

* [Connecting a local device to a network resource](sample_318.md)  
* [Mapping and disconnecting network drives in FoxPro application](sample_387.md)  
  
***  


## Code:
```foxpro  
#DEFINE NO_ERROR 0
#DEFINE CONNDLG_HIDE_BOX  0x00000008
#DEFINE CONNDLG_NOT_PERSIST  0x00000020
#DEFINE CONNDLG_PERSIST  0x00000010
#DEFINE CONNDLG_RO_PATH  0x00000001
#DEFINE CONNDLG_USE_MRU  0x00000004
#DEFINE RESOURCE_CONNECTED 1
#DEFINE RESOURCEDISPLAYTYPE_GENERIC 0

LOCAL oDlg As WNetConnectionDialog1
oDlg=CREATEOBJECT("WNetConnectionDialog1")

WITH oDlg
	.ConnectDlg.dwFlags=BITOR(CONNDLG_USE_MRU,CONNDLG_NOT_PERSIST)
	.ConnectDlg.NetResource.dwScope=RESOURCE_CONNECTED
	.ConnectDlg.NetResource.RemoteName="\\MyServer\Share"
	.ConnectDlg.NetResource.LocalName="U:" && irrelevant?
	.ShowDialog
ENDWITH
* end of main

DEFINE CLASS WNetConnectionDialog1 As Session
	ConnectDlg=NULL
	hwndOwner=0

PROCEDURE Init
	THIS.declare
	THIS.ConnectDlg=CREATEOBJECT("ConnectDlgStructure")

PROCEDURE ShowDialog
	LOCAL ptrConnectDlg, nResult

	WITH THIS.ConnectDlg
		.fillbuffer
		ptrConnectDlg=.stringbuffer.GetAddr()
	ENDWITH

	* 66=ERROR_BAD_DEV_TYPE
	nResult=WNetConnectionDialog1(ptrConnectDlg)
	THIS.ConnectDlg.FromBuffer

PROCEDURE declare
	DECLARE LONG WNetConnectionDialog1 IN mpr;
		INTEGER lpConnDlgStruct

ENDDEFINE

DEFINE CLASS ConnectDlgStructure As Relation
#DEFINE CONNECTDLGSTRUCT 20
	hwndOwner=0
	dwFlags=0
	dwDevNum=0
	NetResource=NULL
	stringbuffer=NULL

PROCEDURE Init
	THIS.hwndOwner=Application.hWnd
	THIS.NetResource=CREATEOBJECT("NetResourceStructure")

FUNCTION ToString() As String
	LOCAL cBuffer
	WITH THIS
		.NetResource.FillBuffer

		cBuffer=num2dword(CONNECTDLGSTRUCT)+;
			num2dword(.hwndOwner)+;
			num2dword(.NetResource.stringbuffer.GetAddr())+;
			num2dword(.dwFlags)+;
			num2dword(.dwDevNum)
	ENDWITH
RETURN m.cBuffer

PROCEDURE FillBuffer
	THIS.stringbuffer=CREATEOBJECT("PChar", THIS.ToString())

PROCEDURE FromBuffer
	THIS.NetResource.FromBuffer
	
	LOCAL cBuffer
	cBuffer=THIS.stringbuffer.GetValue()
	THIS.dwDevNum=buf2dword(SUBSTR(cBuffer,17,4))

ENDDEFINE

DEFINE CLASS NetResourceStructure As Relation
#DEFINE RESOURCETYPE_DISK 1
PROTECTED oLocalName, oRemoteName, oComment1, oProvider
	dwScope=0
	dwType=RESOURCETYPE_DISK  && const;read-only
	dwDisplayType=0
	dwUsage=0
	
	oLocalName=NULL
	LocalName=""

	oRemoteName=NULL
	RemoteName=""

	oComment1=NULL
	Comment1=""

	oProvider=NULL
	Provider=""

	stringbuffer=NULL

PROCEDURE Init
#DEFINE MAX_PATH 260
	WITH THIS
		.oLocalName=CREATEOBJECT("PChar","U:")
		.oRemoteName=CREATEOBJECT("PChar",SPACE(MAX_PATH))
		.oComment1=CREATEOBJECT("PChar",SPACE(100))
		.oProvider=CREATEOBJECT("PChar",SPACE(100))
	ENDWITH

PROCEDURE dwType_ASSIGN(vValue)
* read-only

PROCEDURE LocalName_ACCESS() As String
RETURN THIS.oLocalName.GetValue()

PROCEDURE LocalName_ASSIGN(vValue As String)
	THIS.oLocalName.SetValue(vValue)

PROCEDURE Comment1_ACCESS() As String
RETURN THIS.oComment1.GetValue()

PROCEDURE Comment1_ASSIGN(vValue As String)
* read-only

PROCEDURE Provider_ACCESS() As String
RETURN THIS.oProvider.GetValue()

PROCEDURE Provider_ASSIGN(vValue As String)
* read-only

PROCEDURE RemoteName_ACCESS() As String
RETURN THIS.oRemoteName.GetValue()

PROCEDURE RemoteName_ASSIGN(vValue As String)
	THIS.oRemoteName.SetValue(vValue)

FUNCTION ToString() As String
	LOCAL cBuffer
	WITH THIS
		cBuffer=;
			num2dword(.dwScope) +;
			num2dword(.dwType) +;
			num2dword(.dwDisplayType) +;
			num2dword(.dwUsage) +;
			num2dword(.oLocalName.GetAddr()) +;
			num2dword(.oRemoteName.GetAddr()) +;
			num2dword(.oComment1.GetAddr()) +;
			num2dword(.oProvider.GetAddr())
	ENDWITH
RETURN m.cBuffer

PROCEDURE FillBuffer
	THIS.stringbuffer=CREATEOBJECT("PChar", THIS.ToString())

PROCEDURE FromBuffer
	LOCAL cBuffer
	cBuffer=THIS.stringbuffer.GetValue()

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
	lnSize = THIS.getAllocSize()
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
#DEFINE GMEM_MOVEABLE 2
#DEFINE GMEM_ZEROINIT 0x0040

	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(0x0040, lnSize)
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

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

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
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[WNetConnectionDialog1](../libraries/mpr/WNetConnectionDialog1.md)  

## Comment:
The WNetConnectionDialog1 requires a CONNECTDLGSTRUCT to establish the dialog box parameters. In its turn the CONNECTDLGSTRUCT contains a pointer to a NETRESOURCE structure. This combination of two structures leads to rather disproportional amount of FoxPro code around this call.  
  
***  

