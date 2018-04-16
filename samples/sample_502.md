[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Exporting DLL icon resources as .ICO files

## Short description:
This code includes definitions for three classes: IconGroups, IconGroupResource and IconResource. The IconGroups is a collection of the IconGroupResource objects. The icons property of the IconGroupResource class is a collection of the IconResource objects.

The IconGroupResource and IconResource classes include SaveToFile method that saves the resource to .ICO file.
  
***  


## Before you begin:
This code includes definitions for three classes: IconGroups, IconGroupResource and IconResource.  

The IconGroups is a collection of the IconGroupResource objects. The *icons* property of the IconGroupResource class is a collection of the IconResource objects.  

The following code employs classes from this code sample to store VFP Icon resources to ICO files.  
```foxpro
oIconGroups = CREATEOBJECT("IconGroups",;  
	_vfp.ServerName)  

oIconGroups.EnumIconGroupResources  
? "Icon groups:", oIconGroups.Count  

LOCAL cTargetPath, nGroupIndex, nIconIndex  
cTargetPath = GETDIR("", "Select ICO files destination folder.")  

IF NOT EMPTY(m.cTargetPath)  
	SET SAFETY OFF  
	nGroupIndex = 0  

	FOR EACH oIconGroup IN oIconGroups  
		oIconGroup.SaveToFile(cTargetPath +;  
			"groupicon_" + TRANSFORM(nGroupIndex) + ".ico")  

		nIconIndex = 0  
		FOR EACH oIcon IN oIconGroup.icons  
			oIcon.SaveToFile(cTargetPath +;  
				"icon_" +;  
				TRANSFORM(nGroupIndex) + "_" +;  
				TRANSFORM(nIconIndex) + "_" +;  
				TRANSFORM(oIcon.resid) + ".ico")  

			nIconIndex = nIconIndex + 1  
		NEXT  
		nGroupIndex = nGroupIndex + 1  
	NEXT  
	SET SAFETY ON  
ENDIF
```
[![](../images/filearchive.png)](../downloads/imageres_selected_icons.zip) *Download a small selection of Windows icons from System32\Imageres.dll library.* 

See also:

* [Storing DLL icon resources in image files](sample_501.md)  
* [View icons stored in executable files (Icon Viewer)](sample_113.md)  
* [View icons stored in executable files (Icon Viewer II)](sample_019.md)  
* [Displaying Windows Shell Icons](sample_575.md)  
  
***  


## Code:
```foxpro  
DEFINE CLASS IconGroups As Collection
#DEFINE RT_ICON 3
#DEFINE RT_GROUP_ICON RT_ICON+11
#DEFINE ICONENTRY_SIZE 14
#DEFINE ICONDIRENTRY_SIZE 16
#DEFINE ICONENTRY_OFFSET 6
#DEFINE LOAD_LIBRARY_AS_DATAFILE 2
	hmodule=0

PROCEDURE Init(hModule)
* VFP versions 3..9 do not support callback functions
* making impossible using the EnumResourceNames function.
* This collection inludes only resources with integer identifiers
	THIS.declare
	
	DO CASE
	CASE VARTYPE(hModule)="N"
		THIS.hmodule = m.hModule

	CASE VARTYPE(m.hModule)="C"
		THIS.hmodule = LoadLibraryEx(m.hModule,;
			0, LOAD_LIBRARY_AS_DATAFILE)
	OTHERWISE
	ENDCASE

PROCEDURE ClearList
	DO WHILE THIS.Count > 0
		THIS.Remove(1)
	ENDDO

PROCEDURE EnumIconGroupResources
	LOCAL nIndex

	THIS.ClearList
	FOR nIndex=0 TO 0xffff
		THIS.AddIconGroupResource( nIndex )
	NEXT

PROCEDURE AddIconGroupResource( nResId As Number )
* locates Group Icon resource by specified Id
* and adds it to the collection
	LOCAL hResource, nIndex,;
		oIconGroup As IconGroupResource

	nIndex=0
	hResource = FindResourceN( THIS.hmodule,;
		nResId, RT_GROUP_ICON)

	IF hResource <> 0
		oIconGroup = CREATEOBJECT("IconGroupResource",;
			THIS.hmodule, nResId)

		IF VARTYPE(oIconGroup)="O"
			THIS.Add( oIconGroup )
			nIndex = THIS.Count
		ENDIF
		oIconGroup=NULL
	ENDIF
* returns index in the collection or zero
RETURN m.nIndex

PROCEDURE Destroy
	IF THIS.hmodule <> 0
		= FreeLibrary(THIS.hmodule)
		THIS.hmodule=0
	ENDIF

PROCEDURE declare
	DECLARE INTEGER FreeLibrary IN kernel32 INTEGER hLibModule
	DECLARE INTEGER LockResource IN kernel32 INTEGER hResData
	DECLARE INTEGER FreeResource IN kernel32 INTEGER hglbResource

	DECLARE INTEGER LoadLibraryEx IN kernel32;
		STRING lpFileName, INTEGER hFile, INTEGER dwFlags

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @Dest, INTEGER Src, INTEGER nLen

	DECLARE INTEGER LoadResource IN kernel32;
		INTEGER hModule, INTEGER hResInfo

	DECLARE INTEGER SizeofResource IN kernel32;
		INTEGER hModule, INTEGER hResInfo

	DECLARE INTEGER FindResource IN kernel32;
	AS FindResourceN;
		INTEGER hModule, INTEGER lpName, INTEGER lpType

	DECLARE INTEGER FindResource IN kernel32;
	AS FindResourceC;
		INTEGER hModule, STRING lpName, INTEGER lpType

ENDDEFINE

DEFINE CLASS IconGroupResource As TResource
	icons=NULL
	buffer=""

PROCEDURE Init(hModule, nResId)
	TResource::Init(hModule, nResId, RT_GROUP_ICON)
	IF EMPTY(THIS.buffer)
		RETURN .F.
	ENDIF
	
	LOCAL nCount, nIndex, cIconEntry
	nCount = buf2word(SUBSTR(THIS.buffer,5,2))

	THIS.icons = CREATEOBJECT("Collection")
	FOR nIndex=0 TO nCount-1
		cIconEntry = SUBSTR(THIS.buffer,;
			ICONENTRY_OFFSET+1+nIndex*ICONENTRY_SIZE,;
			ICONENTRY_SIZE)

		LOCAL oIcon As IconResource
		oIcon = CREATEOBJECT("IconResource",;
			THIS.hmodule, m.cIconEntry)

		THIS.icons.Add(oIcon)
		oIcon = NULL
	NEXT

PROCEDURE SaveToFile(cFilename)
	LOCAL cBuffer, nIndex, nOffset, oIcon As IconResource
	cBuffer = SUBSTR(THIS.buffer, 1,ICONENTRY_OFFSET)
	
	nOffset = ICONENTRY_OFFSET +;
		THIS.icons.Count * ICONDIRENTRY_SIZE

	FOR EACH oIcon IN THIS.icons
		cBuffer = cBuffer +;
			SUBSTR(oIcon.iconentry,1,12) +;
			num2dword(nOffset)
		nOffset = nOffset + LEN(oIcon.buffer)
	NEXT	

	FOR EACH oIcon IN THIS.icons
		cBuffer = cBuffer + oIcon.buffer
	NEXT
	
	TRY
		nResult = STRTOFILE(m.cBuffer, m.cFilename)
	CATCH
		nResult=0
	ENDTRY
RETURN (nResult!=0)

ENDDEFINE

DEFINE CLASS IconResource As TResource
	iconwidth=0
	iconheight=0
	colorcount=0
	planes=0
	bitcount=0
	bytesinres=0
	resId=0
	iconentry=""

PROCEDURE Init(hModule, cIconEntry)
	THIS.iconentry=m.cIconEntry
	THIS.iconwidth = ASC(SUBSTR(cIconEntry,1,1))
	THIS.iconheight = ASC(SUBSTR(cIconEntry,2,1))
	THIS.colorcount = ASC(SUBSTR(cIconEntry,3,1))
	THIS.planes = buf2word(SUBSTR(cIconEntry,5,2))
	THIS.bitcount = buf2word(SUBSTR(cIconEntry,7,2))
	THIS.bytesinres = buf2dword(SUBSTR(cIconEntry,9,4))
	THIS.resId = buf2word(SUBSTR(cIconEntry,13,2))
	TResource::Init(m.hModule, THIS.resId, RT_ICON)

PROCEDURE SaveToFile(cFileName)
	LOCAL cBuffer

	cBuffer = num2word(0) + num2word(1) + num2word(1) +;
		SUBSTR(THIS.iconentry,1,12) +;
		num2dword(ICONENTRY_OFFSET + ICONDIRENTRY_SIZE) +;
		THIS.buffer

	TRY
		nResult = STRTOFILE(m.cBuffer, m.cFilename)
	CATCH
		nResult=0
	ENDTRY
RETURN (nResult!=0)

ENDDEFINE

DEFINE CLASS TResource As Relation
	hmodule=0
	resid=0
	restype=0
	hglobal=0
	buffer=""

PROCEDURE Init(hModule, nResId, nResType)
	THIS.hmodule=m.hModule
	THIS.resid=m.nResId
	THIS.restype=m.nResType
	THIS.ReadResource

PROCEDURE Destroy
	THIS.FreeResource

PROCEDURE ReadResource
	LOCAL hResource
	
	DO CASE
	CASE VARTYPE(THIS.resid)="N"
		hResource = FindResourceN(THIS.hmodule,;
			THIS.resid, THIS.restype)
	CASE VARTYPE(THIS.resid)="C"
		hResource = FindResourceC(THIS.hmodule,;
			THIS.resid, THIS.restype)
	ENDCASE

	IF m.hResource <> 0
		LOCAL hLocked, nBufsize, cBuffer

		nBufsize = SizeOfResource(THIS.hmodule, hResource)
		THIS.hglobal = LoadResource(THIS.hmodule, m.hResource)
		hLocked = LockResource(THIS.hglobal)

		cBuffer = REPLICATE(CHR(0), nBufsize)
		= MemToStr(@cBuffer, hLocked, nBufsize)
		THIS.buffer = m.cBuffer
	ENDIF

PROCEDURE FreeResource
	IF THIS.hglobal <> 0
		FreeResource(THIS.hglobal)
		THIS.hglobal=0
	ENDIF

ENDDEFINE

**************************** static functions ********************************
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

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[FindResource](../libraries/kernel32/FindResource.md)  
[FreeLibrary](../libraries/kernel32/FreeLibrary.md)  
[LoadLibraryEx](../libraries/kernel32/LoadLibraryEx.md)  
[LoadResource](../libraries/kernel32/LoadResource.md)  
[LockResource](../libraries/kernel32/LockResource.md)  
[SizeofResource](../libraries/kernel32/SizeofResource.md)  

## Comment:
To see a variety of system icons, test this code with Shell32.dll and Imageres.dll files located in System32 folder.  
  
![Storing DLL icon resources in .ICO files](../images/imageres_icons.jpg)
 
  
* * *  
VFP versions 3..9 do not support callback functions. This prevents using the EnumResourceNames function to enumerate available resources in executable or dynamic library files. For that reason, the IconGroups class enumerates IconGroup resources with only integer identifiers in 1..0xffff range.  
  
Read on MSDN: 
* [Icons in Win32](https://msdn.microsoft.com/en-us/library/ms997538.aspx)
* [Using Icons](https://msdn.microsoft.com/en-us/library/windows/desktop/ms648051(v=vs.85).aspx)

***  
