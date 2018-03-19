[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating a unique filename based on existing filename

## Code:
```foxpro  
#DEFINE CP_ACP         0
#DEFINE CP_OEMCP       1
#DEFINE MB_PRECOMPOSED 1
#DEFINE MAX_PATH       260
DO decl

LOCAL cPath, cFile, cUnique, cTpl

* retrieving FoxPro executable name
cPath = Repli(Chr(0),MAX_PATH)
= GetModuleFileName(0, @cPath, Len(cPath))
cPath = SUBSTR(cPath, 1, AT(Chr(0),cPath)-1)
cFile = SUBSTR(cPath, RAT("\",cPath)+1)
? "Base name:", cPath

cUnique = Repli(Chr(0),MAX_PATH*2)
= PathYetAnotherMakeUniqueName(@cUnique, a2u(cPath), Null, a2u(cFile))
cUnique = u2a(cUnique)
? "Unique filename:", cUnique
?

cUnique = Repli(Chr(0),MAX_PATH*2)
cTpl = "MyFile.Dat"
cPath = GetLongTempPath()
? "Base name:", cPath + cTpl

= PathMakeUniqueName(@cUnique, MAX_PATH, a2u(cTpl), a2u(cTpl), a2u(cPath))
cUnique = u2a(cUnique)
? "Unique filename:", cUnique
* end of main

FUNCTION GetLongTempPath
	LOCAL cPath, cLongPath, nBufsize
	cPath = Repli(Chr(0),MAX_PATH)
	cLongPath = Repli(Chr(0),MAX_PATH*2)
	nBufsize = GetTempPath(Len(cPath), @cPath)
	cPath = LEFT(cPath, nBufsize)
	= GetLongPathName(cPath, @cLongPath, Len(cLongPath))
RETURN SUBSTR(cLongPath, 1,AT(Chr(0),cLongPath)-1)

FUNCTION u2a(cText)
* converting a Unicode string to an ANSI string
	LOCAL lcBuffer, lnBufsize
	cText = SUBSTR(cText, 1, AT(Chr(0)+Chr(0),cText))

	* first calling to define required buffer size
	lcBuffer = ""
	lnBufsize = WideCharToMultiByte(CP_ACP, 0,;
		cText, Len(cText), @lcBuffer, 0, Chr(0), 0)
		
	lcBuffer = Repli(Chr(0), lnBufsize)
	= WideCharToMultiByte(CP_ACP, 0,;
		cText, Len(cText), @lcBuffer, lnBufsize, Chr(0), 0)
RETURN SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)

FUNCTION a2u(cText)
* converting an ANSI string to a Unicode string
	LOCAL lcBuffer, lnBufsize
	
	* first calling to define required buffer size
	lcBuffer = ""
	lnBufsize = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED,;
		cText, Len(cText), @lcBuffer, 0)

	lcBuffer = Repli(Chr(0), lnBufsize*2)  && in wide chars
	= MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED,;
		cText, Len(cText), @lcBuffer, lnBufsize)
RETURN lcBuffer

PROCEDURE decl
	DECLARE INTEGER PathMakeUniqueName IN shell32;
		STRING @pszUniqueName, INTEGER cchMax, STRING pszTemplate,;
		STRING pszLongPlate, STRING pszDir

	DECLARE INTEGER PathYetAnotherMakeUniqueName IN shell32;
		STRING @pszUniqueName, STRING pszPath,;
		STRING pszShort, STRING pszFileSpec

	DECLARE INTEGER GetTempPath IN kernel32;
		INTEGER nBufferLength, STRING @lpBuffer

	DECLARE INTEGER GetLongPathName IN kernel32;
		STRING lpszShortPath, STRING @lpszLongPath,;
		INTEGER cchBuffer

	DECLARE INTEGER GetModuleFileName IN kernel32;
		INTEGER hModule, STRING @lpFilename, INTEGER nSize

	DECLARE INTEGER WideCharToMultiByte IN kernel32;
		INTEGER CodePg, INTEGER dwFlags,;
		STRING lpWideCharStr, INTEGER cchWideChar,;
		STRING @lpMultiByteStr, INTEGER cbMultiByte,;
		STRING lpDefaultChar, INTEGER lpUsedDefaultChar

	DECLARE INTEGER MultiByteToWideChar IN kernel32;
		INTEGER CodePage, LONG dwFlags, STRING lpMultiByteStr,;
		INTEGER cbMultiByte, STRING @lpWCharStr, INTEGER cchWChar  
```  
***  


## Listed functions:
[GetLongPathName](../libraries/kernel32/GetLongPathName.md)  
[GetModuleFileName](../libraries/kernel32/GetModuleFileName.md)  
[GetTempPath](../libraries/kernel32/GetTempPath.md)  
[MultiByteToWideChar](../libraries/kernel32/MultiByteToWideChar.md)  
[PathMakeUniqueName](../libraries/shell32/PathMakeUniqueName.md)  
[PathYetAnotherMakeUniqueName](../libraries/shell32/PathYetAnotherMakeUniqueName.md)  
[WideCharToMultiByte](../libraries/kernel32/WideCharToMultiByte.md)  
