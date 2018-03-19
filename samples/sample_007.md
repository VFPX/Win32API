[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using LoadLibrary

## Before you begin:
See also:

* [Loading a string resource from an executable file](sample_213.md)  
* [How to extract icon resources from EXE or DLL and save them in .ICO files](sample_502.md)  
  
***  


## Code:
```foxpro  
DO declare

lpLibFileName = GetSystemDir() + "\mapi32.dll"
hLibModule = LoadLibrary(lpLibFileName)

IF hLibModule <> 0
	? "Library handle:", hLibModule
	= FreeLibrary(hLibModule)
ELSE
	* 1157 = ERROR_DLL_NOT_FOUND
	? "Error code returned:", GetLastError()
ENDIF
* end of main

FUNCTION GetSystemDir
	LOCAL lpBuffer, nSizeRet
	lpBuffer = SPACE(250)
	nSizeRet = GetSystemDirectory(@lpBuffer, Len(lpBuffer))
RETURN Iif(nSizeRet<>0, Left(lpBuffer, nSizeRet), "")

PROCEDURE declare
	DECLARE INTEGER LoadLibrary IN kernel32;
		STRING lpLibFileName

	DECLARE INTEGER FreeLibrary IN kernel32;
		INTEGER hLibModule

	DECLARE INTEGER GetSystemDirectory IN kernel32;
		STRING @ lpBuffer, INTEGER nSize

	DECLARE INTEGER GetLastError IN kernel32  
```  
***  


## Listed functions:
[FreeLibrary](../libraries/kernel32/FreeLibrary.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetSystemDirectory](../libraries/kernel32/GetSystemDirectory.md)  
[LoadLibrary](../libraries/kernel32/LoadLibrary.md)  
