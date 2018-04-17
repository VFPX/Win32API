[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Deleting files into the Recycle Bin

## Before you begin:
The SHFileOperation can delete files into the Recycle Bin.  

![](../images/recyclebin.png)  

See also:

* [How to empty the Recycle Bin](sample_301.md)  
* [How to retrieve number of objects in the Recycle Bin](sample_302.md)  
* [How to remove a directory that is not empty](sample_541.md)  
* [Displaying standard progress dialog box when copying file](sample_508.md)  
  
***  


## Code:
```foxpro  
#DEFINE FO_MOVE 1
#DEFINE FO_COPY 2
#DEFINE FO_DELETE 3
#DEFINE FO_RENAME 4
#DEFINE FOF_ALLOWUNDO 64

DO declare

*|typedef struct _SHFILEOPSTRUCT {
*|    HWND  hwnd;                    0:4
*|    UINT  wFunc;                   4:4
*|    LPCTSTR  pFrom;                8:4
*|    LPCTSTR  pTo;                 12:4
*|    FILEOP_FLAGS  fFlags;         16:4
*|    BOOL  fAnyOperationsAborted;  20:4
*|    LPVOID  hNameMappings;        24:4
*|    LPCTSTR  lpszProgressTitle;   28:4
*|} SHFILEOPSTRUCT, *LPSHFILEOPSTRUCT; total bytes: 32

LOCAL lcBuffer, loFileToDelete

* provide valid file name
loFileToDelete = CreateObject("PChar", "c:\a\test1.ldb")

lcBuffer = num2dword(GetActiveWindow()) +;
	num2dword(FO_DELETE) +;
	num2dword(loFileToDelete.GetAddr()) +;
	num2dword(0) +;
	num2dword(FOF_ALLOWUNDO) +;
	num2dword(0) + num2dword(0) + num2dword(0)

= SHFileOperation(@lcBuffer)
* end of main

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

PROCEDURE declare
	DECLARE INTEGER SHFileOperation IN Shell32 STRING @lpFileOp
	DECLARE INTEGER GetActiveWindow IN user32

DEFINE CLASS PChar As Custom
	PROTECTED hMem

PROCEDURE  Init (lcString)
	THIS.hMem = 0
	THIS.setValue (lcString)

PROCEDURE  Destroy
	THIS.ReleaseString

FUNCTION getAddr  && returns a pointer to the string
RETURN THIS.hMem

FUNCTION getValue && returns string value
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
			STRING @, INTEGER, INTEGER
		= Heap2Str (@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION getAllocSize  && returns allocated memory size (string length)
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE setValue (lcString) && assigns new string value
#DEFINE GMEM_FIXED   0
	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As Str2Heap;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc (GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= Str2Heap (THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[SHFileOperation](../libraries/shell32/SHFileOperation.md)  

## Comment:

In .NET sending file to the Recycle Bin is as simple as calling [FileSystem.DeleteFile](https://msdn.microsoft.com/en-us/library/ms127976(v=vs.100).aspx) with *RecycleOption* parameter set to 
*SendToRecycleBin*. Same option can be used when calling 
[FileSystem.DeleteDirectory](https://msdn.microsoft.com/en-us/library/ms127971(v=vs.100).aspx).
  
***  

