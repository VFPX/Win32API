[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating the Save dialog box to specify the drive, directory, and name of a file to save

## Before you begin:
![](../images/savedlg.png) 

See also:
* [How to position the GETPRINTER() dialog](sample_482.md)
* [Using Extended MessageBox() Class](sample_424.md)  
* [Extended MessageBox Class](sample_418.md)  
* [How to change font name and size in the MessageBox dialog](sample_434.md)  
* [Creating an Open dialog box to specify the drive, directory, and name of a file to open (Shell32 version)](sample_365.md)  
* [Creating the Open dialog box to specify the drive, directory, and name of a file to open](sample_363.md)  
* [How to display a dialog box that enables the user to select a folder (an alternative to the GETDIR)](sample_364.md)  
  
***  


## Code:
```foxpro  
DO decl

* some of the bit flags for the dialog
#DEFINE OFN_HIDEREADONLY 4
#DEFINE OFN_NOCHANGEDIR 8
#DEFINE OFN_EXTENSIONDIFFERENT 0x400
#DEFINE OFN_PATHMUSTEXIST 0x800
#DEFINE OFN_CREATEPROMPT 0x2000
#DEFINE OFN_EXPLORER 0x80000
#DEFINE OFN_DONTADDTORECENT 0x2000000

*| typedef struct tagOFN {
*|   DWORD         lStructSize;      0:4
*|   HWND          hwndOwner;        4:4
*|   HINSTANCE     hInstance;        8:4
*|   LPCTSTR       lpstrFilter;     12:4
*|   LPTSTR        lpstrCustFilt;   16:4
*|   DWORD         nMaxCustFilter;  20:4
*|   DWORD         nFilterIndex;    24:4
*|   LPTSTR        lpstrFile;       28:4
*|   DWORD         nMaxFile;        32:4
*|   LPTSTR        lpstrFileTitle;  36:4
*|   DWORD         nMaxFileTitle;   40:4
*|   LPCTSTR       lpstrInitialDir; 44:4
*|   LPCTSTR       lpstrTitle;      48:4
*|   DWORD         Flags;           52:4
*|   WORD          nFileOffset;     56:2
*|   WORD          nFileExtension;  58:2
*|   LPCTSTR       lpstrDefExt;     60:4
*|   LPARAM        lCustData;       64:4
*|   LPOFNHOOKPROC lpfnHook;        68:4
*|   LPCTSTR       lpTemplateName;  72:4 = 76 bytes
*| #if (_WIN32_WINNT >= 0x0500)
*|   void *        pvReserved;      76:4
*|   DWORD         dwReserved;      80:4
*|   DWORD         FlagsEx;         84:4
*| #endif // (_WIN32_WINNT >= 0x0500)
*| } OPENFILENAME, *LPOPENFILENAME; total = 88 bytes

#DEFINE OPENFILENAME_SIZE  76  && set to 88 for W2K

LOCAL lcBuffer, loFilter, loFilename, loFilenameRet,;
	loTitlebar, loDefExt, lnFlags, lnFileOffset, lnExtOffset,;
	lcFullname, lcPath, lcFilename, lcFileext

loFilter = CreateObject("PChar",;
	"Text Files" + Chr(0) + "*.txt;*.bak" + Chr(0)+Chr(0))

loFilename = CreateObject("PChar", Padr("myfile.txt", 250,Chr(0)))

loFilenameRet = CreateObject("PChar", Repli(Chr(0),250))

loTitlebar = CreateObject("PChar",;
	"Will you save this file at least?")

loDefExt = CreateObject("PChar", "TXT")

lnFlags = OFN_PATHMUSTEXIST + OFN_EXTENSIONDIFFERENT +;
	OFN_CREATEPROMPT + OFN_HIDEREADONLY + OFN_NOCHANGEDIR

* compiling the OPENFILENAME structure
* Rem: initdir - default chosen

lcBuffer = num2dword(OPENFILENAME_SIZE) +;
	num2dword(GetActiveWindow()) +;
	num2dword(0) +;
	num2dword(loFilter.GetAddr()) +;
	num2dword(0) +;
	num2dword(0) +;
	num2dword(1) +;
	num2dword(loFilename.GetAddr()) +;
	num2dword(loFilename.GetAllocSize()) +;
	num2dword(loFilenameRet.GetAddr()) +;
	num2dword(loFilenameRet.GetAllocSize()) +;
	num2dword(0) +;
	num2dword(loTitlebar.GetAddr()) +;
	num2dword(lnFlags) +;
	num2dword(0) +;
	num2dword(loDefExt.GetAddr()) +;
	num2dword(0) +;
	num2dword(0) +;
	num2dword(0)

* creating a Save dialog box using the prepared structure

IF GetSaveFileName (@lcBuffer) = 0
	LOCAL lnErrorCode
	lnErrorCode = CommDlgExtendedError()
	IF lnErrorCode <> 0
		? "Error code:", lnErrorCode
	ELSE
	* the Cancel button selected
	ENDIF

ELSE
	lcFullname = STRTRAN(Trim(loFilename.GetValue()), Chr(0),"")
	lcFilename = STRTRAN(Trim(loFilenameRet.GetValue()), Chr(0),"")

	lnFileOffset = buf2word(SUBSTR(lcBuffer, 57,2))
	lnExtOffset = buf2word(SUBSTR(lcBuffer, 59,2))

	lcPath = SUBSTR(lcFullname, 1, lnFileOffset-1)
	lcFileext = SUBSTR(lcFullname, lnExtOffset+1)

	? lcFullname
	? lcPath
	? lcFilename
	? lcFileext
ENDIF
* end of main

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION  buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256

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

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER GetSaveFileName IN comdlg32 STRING @lpofn
	DECLARE INTEGER CommDlgExtendedError IN comdlg32  
```  
***  


## Listed functions:
[CommDlgExtendedError](../libraries/comdlg32/CommDlgExtendedError.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetSaveFileName](../libraries/comdlg32/GetSaveFileName.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  

## Comment:
The OPENFILENAME structure length depends on the OS, and can be 76 or 88 bytes.   
  
This is important, because invalid parameter creates an error. Note that this structure is used with GetOpenFileName and GetSaveFileName functions. There is substantial set of OFN flags to control the dialog behaviour.   
  
To fill the OPENFILENAME structure -- as well as almost all other Comdlg structures used -- you need not just strings but pointers to strings. There is a class PChar in this examples, which creates such extended strings. In more simple cases the StrDup is quite enough to accomplish this task.  
  
***  

