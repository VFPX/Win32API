[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating network resources

## Short description:
The code uses WNet API calls to enumerate all resources on the network.  
***  


## Before you begin:
This is an example of the output produced by the code sample below:  
```txt
Microsoft Terminal Services  
	\\tsclient  
		\\tsclient\Y  
		\\tsclient\E  
		\\tsclient\D  
		\\tsclient\C  
Microsoft Windows Network  
	$PCC  
	PCCBASE  
		\\DTS  
			\\DTS\_office  
			\\DTS\winapi  
			\\DTS\database  
			\\DTS\corp  
		\\BASEDONALD  
		\\BASESRV  
			\\BASESRV\Group_Docs  
			\\BASESRV\Group-Folders  
			\\BASESRV\Share  
			\\BASESRV\ofcscan  
			\\BASESRV\SERVERSW  
			\\BASESRV\ACCPAC  
	WORKGROUP  
		\\CHARLES-07PCBC  
		\\MARIE-07PCBC  
		\\PETER_PAN  
		\\OFFICEUSER  
		\\TOSHIBA  
		\\MARIE-NB1  
Web Client Network  
LogMeIn Virtual Disk Network
```

See also:

* [Mapping and disconnecting network drives in FoxPro application](sample_387.md)  
* [Get the list of servers of the specified type in the primary domain (WinNT only)](sample_165.md)  

  
***  


## Code:
```foxpro  
#DEFINE NO_ERROR 0
#DEFINE RESOURCE_GLOBALNET 2
#DEFINE RESOURCETYPE_ANY 0
#DEFINE GMEM_ZEROINIT 0x0040
#DEFINE NETRESOURCE_SIZE 32
#DEFINE RESOURCEUSAGE_CONTAINER 2

DEFINE CLASS NetResourcesRoot As BaseNetResource

PROCEDURE Init
	THIS.declare
	THIS.EnumResources

PROTECTED PROCEDURE declare
	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalLock IN kernel32 STRING @hMem
	DECLARE INTEGER GlobalUnlock IN kernel32 STRING @hMem
	DECLARE INTEGER WNetCloseEnum IN mpr INTEGER hEnum

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLength

	DECLARE INTEGER WNetOpenEnum IN mpr;
		INTEGER dwScope, INTEGER dwType, INTEGER dwUsage,;
		INTEGER lpNetResource, INTEGER @lphEnum

	DECLARE INTEGER WNetEnumResource IN mpr;
		INTEGER hEnum, INTEGER @lpcCount, INTEGER lpBuffer,;
		INTEGER @lpBufferSize
ENDDEFINE

DEFINE CLASS BaseNetResource As Relation
PROTECTED hEnum, hBuffer
	hEnum=0
	hBuffer=0
	errormessage=""
	errorno=0

	scope=0
	rstype=0
	displaytype=0
	usage=0
	localname=""
	remotename=""
	rscomment=""
	provider=""
	netresources=NULL

PROCEDURE Destroy
	THIS.CloseEnum

FUNCTION IsContainer() As Boolean
RETURN (BITAND(THIS.usage, RESOURCEUSAGE_CONTAINER) <> 0)

PROTECTED FUNCTION OpenEnum(hContainer) As Boolean
	THIS.CloseEnum

	LOCAL hEnum
	hEnum=0
	THIS.errorno = WNetOpenEnum(RESOURCE_GLOBALNET, RESOURCETYPE_ANY,;
		0, hContainer, @hEnum)

	IF THIS.errorno <> NO_ERROR
		THIS.errormessage = "WNetOpenEnum failed."
	ENDIF
	
	THIS.hEnum = hEnum
RETURN (THIS.hEnum <> 0)

PROTECTED PROCEDURE CloseEnum
	IF THIS.hEnum <> 0
		= WNetCloseEnum(THIS.hEnum)
		THIS.hEnum=0
	ENDIF
	IF THIS.hBuffer <> 0
		= GlobalFree(THIS.hBuffer)
		THIS.hBuffer=0
	ENDIF
	IF NOT ISNULL(THIS.netresources)
		DO WHILE THIS.netresources.Count > 0
			THIS.netresources.Remove(1)
		ENDDO
	ENDIF

PROCEDURE EnumResources(hContainer)
	IF ISNULL(THIS.netresources)
		THIS.netresources = CREATEOBJECT("Collection")
	ENDIF

	IF VARTYPE(hContainer) <> "N"
		hContainer=0
	ENDIF

	IF NOT THIS.OpenEnum(hContainer)
		THIS.CloseEnum
		RETURN
	ENDIF
	
	LOCAL nBufsize, nCount, cBuffer, nIndex
	nBufsize = 1024
	THIS.hBuffer = GlobalAlloc(GMEM_ZEROINIT, nBufsize)
	nCount = -1

	THIS.errorno = WNetEnumResource(THIS.hEnum, @nCount,;
		THIS.hBuffer, @nBufsize)

	IF THIS.errorno <> NO_ERROR
		THIS.errormessage = "WNetEnumResource failed."
		RETURN
	ENDIF
	
	cBuffer = REPLICATE(CHR(0), m.nBufsize)
	= MemToStr(@cBuffer, THIS.hBuffer, m.nBufsize)

	FOR nIndex=0 TO nCount-1
		cRsbuffer = SUBSTR(cBuffer,;
			nIndex*NETRESOURCE_SIZE+1, NETRESOURCE_SIZE)

		LOCAL rs As BaseNetResource
		rs = CREATEOBJECT("BaseNetResource")
		WITH rs
			.scope = buf2dword(SUBSTR(cRsbuffer, 1,4))
			.rstype = buf2dword(SUBSTR(cRsbuffer, 5,4))
			.displaytype = buf2dword(SUBSTR(cRsbuffer, 9,4))
			.usage = buf2dword(SUBSTR(cRsbuffer, 13,4))

			.localname = THIS.StrFromPtr(buf2dword(;
				SUBSTR(cRsbuffer, 17, 4)), @cBuffer)

			.remotename = THIS.StrFromPtr(buf2dword(;
				SUBSTR(cRsbuffer, 21, 4)), @cBuffer)

			.rscomment = THIS.StrFromPtr(buf2dword(;
				SUBSTR(cRsbuffer, 25, 4)), @cBuffer)

			.provider = THIS.StrFromPtr(buf2dword(;
				SUBSTR(cRsbuffer, 29, 4)), @cBuffer)
			
			IF rs.IsContainer()
			* recursive call
				rs.EnumResources(THIS.hBuffer + nIndex*NETRESOURCE_SIZE)
			ENDIF
		ENDWITH

		THIS.netresources.Add(rs)
		rs = NULL
	NEXT

PROTECTED FUNCTION StrFromPtr(nPtr, cBuffer)
	IF nPtr = 0
		RETURN ""
	ENDIF
	
	LOCAL nOffset, ch, cResult
	nOffset = m.nPtr - THIS.hBuffer + 1
	cResult=""

	DO WHILE nOffset <= LEN(cBuffer)
		ch = SUBSTR(cBuffer, nOffset, 1)
		IF m.ch = CHR(0)
			EXIT
		ENDIF
		cResult = m.cResult + m.ch
		nOffset = nOffset + 1
	ENDDO
RETURN m.cResult

ENDDEFINE

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalLock](../libraries/kernel32/GlobalLock.md)  
[GlobalUnlock](../libraries/kernel32/GlobalUnlock.md)  
[WNetCloseEnum](../libraries/mpr/WNetCloseEnum.md)  
[WNetEnumResource](../libraries/mpr/WNetEnumResource.md)  
[WNetOpenEnum](../libraries/mpr/WNetOpenEnum.md)  

## Comment:
Feb.20, 2006: completely rewritten.  
  
Test *NetResourcesRoot* and *BaseNetResource* classes as follows:  
  
```foxpro
LOCAL oNetResources As NetResourcesRoot  
oNetResources = CREATEOBJECT("NetResourcesRoot")  
DO ShowResources WITH oNetResources, 0  
  
PROCEDURE ShowResources(oContainer, nLevel)  
	LOCAL oRs As BaseNetResource  
  
	FOR EACH oRs IN oContainer.netresources  
		WITH oRs  
			? REPLICATE(" ", nLevel*4) + .remotename  
			IF oRs.IsContainer()  
				DO ShowResources WITH oRs, nLevel+1  
			ENDIF  
		ENDWITH  
	NEXT
```
  

***  

