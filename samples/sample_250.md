[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Searching for the specified file using the SearchPath

## Before you begin:
This sample code demonstrates how to find a path to the given file. The SearchPath function returns only one result regardless of a number of files with identical names existing in subdirectories on the initial path.  
  
***  


## Code:
```foxpro  
DECLARE INTEGER SearchPath IN kernel32;
	STRING lpPath, STRING lpFileName, STRING lpExtension,;
	INTEGER nBufLen, STRING @lpBuffer,INTEGER @lpFilePart

= GoSearch("Vfp6.exe")
= GoSearch("foxuser.dbf")
= GoSearch("mapi32.dll")
= GoSearch("comdlg32.dll")
= GoSearch("win.ini")
= GoSearch("system.ini")
= GoSearch("calc.exe")
= GoSearch("notepad.exe")
= GoSearch("winzip32.exe")

PROCEDURE GoSearch (lcFilename)
	LOCAL lcBuffer, lnFilepart, lnResult
	lcBuffer = Repli(Chr(0), 250)
	lnFilepart = 0

	* setting the search path to null makes the function
	* looking through a set of basic directories
	* check the SearchPath description for the list

	lnResult = SearchPath(NULL, lcFilename, .Null.,;
		Len(lcBuffer), @lcBuffer, @lnFilepart)

	IF lnResult > 0
		? "Search result:", Left(lcBuffer, lnResult)
	ELSE
		? lcFilename + ": not found"
	ENDIF  
```  
***  


## Listed functions:
[SearchPath](../libraries/kernel32/SearchPath.md)  

## Comment:
Setting the search path to null makes the function looking through a set of basic directories check the SearchPath description for a list of them.  
  
***  

