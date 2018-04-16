[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting long file names to the short format and vice versa

## Before you begin:
See also:

* [How to access a file using not its name but an alias (hard link)](sample_018.md)  

  
***  


## Code:
```foxpro  
DO declare

LOCAL lcSourceFile, lcShort, lcLong
lcSourceFile = "C:\Program Files\Microsoft Office\Office10\finderr.exe"
lcShort = GetShort(lcSourceFile)
lcLong = GetLong(lcShort)

? "Source name:", lcSourceFile
? "Short name obtained:", lcShort
? "Long name obtained: ", lcLong

FUNCTION GetLong(lcName)
	LOCAL lcBuffer, lnResult
	lcBuffer = Repli(Chr(0), 512)
	lnResult = GetLongPathName(lcName, @lcBuffer, Len(lcBuffer))
* 2=ERROR_FILE_NOT_FOUND
RETURN IIF(lnResult=0, "error #" + LTRIM(STR(GetLastError())),;
	Left(lcBuffer, lnResult))

FUNCTION GetShort(lcName)
	LOCAL lcBuffer, lnResult
	lcBuffer = Repli(Chr(0), 512)
	lnResult = GetShortPathName(lcName, @lcBuffer, Len(lcBuffer))
RETURN IIF(lnResult=0, "error #" + LTRIM(STR(GetLastError())),;
	Left(lcBuffer, lnResult))

PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER GetLongPathName IN kernel32;
		STRING lpszShortPath, STRING @lpszLongPath,;
		INTEGER cchBuffer

	DECLARE INTEGER GetShortPathName IN kernel32;
		STRING lpszLongPath, STRING @lpszShortPath,;
		INTEGER cchBuffer  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetLongPathName](../libraries/kernel32/GetLongPathName.md)  
[GetShortPathName](../libraries/kernel32/GetShortPathName.md)  

## Comment:
The "short path" means the 8.3 compliant path/filename. The source path must be always valid. You can not convert the name of a file that does not exist.  
  
See also: [PathGetShortPath](../libraries/shell32/PathGetShortPath.md)
  
***  

