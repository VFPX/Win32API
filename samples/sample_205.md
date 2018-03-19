[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to write and read Window Properties for the specified window

## Before you begin:
A window property is any data assigned to a window. A window property is usually a handle of the window-specific data, but it may be any value. Each window property is identified by a string name.  

The EnumProps and EnumPropsEx functions enumerate all window properties for a given window by using an application-defined callback function -- something that VFP is not capable of doing without employing external modules written in other languages.  
  
***  


## Code:
```foxpro  
#DEFINE SAMPLE_WIN_PROPERTY "MyWinProperty"
DO declare

LOCAL hWindow, hProperty, cBuffer, nBufsize
hWindow = _screen.HWnd

IF VARTYPE(oProperty) <> "O"
* this variable must not be released until
* the window property is not required anymore
	PUBLIC oProperty As PChar

	oProperty = CREATEOBJECT("PChar",;
		TRANSFORM(DATETIME()))

	* creating and assigning window property
	IF SetProp(hWindow, SAMPLE_WIN_PROPERTY,;
		oProperty.GetAddr()) = 0
		? "SetProp failed with error code:", GetLastError()
		RETURN
	ENDIF
ENDIF

* reading window property
hProperty = GetProp(hWindow, SAMPLE_WIN_PROPERTY)
IF hProperty = 0
	? "GetProp failed with error code:", GetLastError()
	RETURN
ENDIF

nBufsize = GlobalSize(hProperty)
cBuffer = REPLICATE(CHR(0), nBufsize)
= MemToStr(@cBuffer, hProperty, nBufsize)
? "Property read:", cBuffer
* end of main

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @, INTEGER, INTEGER

	DECLARE INTEGER SetProp IN user32;
		INTEGER hWindow, STRING lpString,;
		INTEGER hData

	DECLARE INTEGER GetProp IN user32;
		INTEGER hWindow, STRING lpString

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
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProp](../libraries/user32/GetProp.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[SetProp](../libraries/user32/SetProp.md)  

## Comment:
The Window Properties can hardly be used for interprocess communication (IPC) due to inability of the GlobalAlloc to create memory blocks shareable between several Win32 processes.  
  
As a tool of assigning data to windows in VFP application this functionality is probably not better than using the AddProperty.  
  
An application can assign properties to windows owned by other processes, but none can read the assigned data except the assigning application itself.  
  
***  

