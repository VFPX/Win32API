[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using GetBinaryType (WinNT only) to determine the type of an executable file

## Code:
```foxpro  
#DEFINE SCS_32BIT_BINARY   0
#DEFINE SCS_DOS_BINARY     1
#DEFINE SCS_WOW_BINARY     2
#DEFINE SCS_PIF_BINARY     3
#DEFINE SCS_POSIX_BINARY   4
#DEFINE SCS_OS216_BINARY   5

	DECLARE SHORT GetBinaryType IN kernel32;
		STRING    lpApplicationName,;
		INTEGER @ lpBinaryType

	DECLARE INTEGER GetModuleFileName IN kernel32;
		INTEGER  hModule,;
		STRING @ lpFilename,;
		INTEGER  nSize

    ? _binaryType (getVFPmodule())
    ? _binaryType ("c:\winnt\system32\win.com")
    ? _binaryType ("c:\winnt\system32\command.com")
    ? _binaryType ("c:\winnt\system32\Commdlg.dll")
    ? _binaryType ("c:\io.sys")

FUNCTION  _binaryType (lpApplicationName)
	LOCAL lpBinaryType
    lpBinaryType = 0
	IF GetBinaryType (lpApplicationName, @lpBinaryType) = 1
		RETURN lpBinaryType
	ELSE
		RETURN -1
	ENDIF

FUNCTION  getVFPmodule
	LOCAL lpFilename
	lpFilename = SPACE(250)
	lnLen = GetModuleFileName (0, @lpFilename, Len(lpFilename))
RETURN Left (lpFilename, lnLen)  
```  
***  


## Listed functions:
[GetBinaryType](../libraries/kernel32/GetBinaryType.md)  
[GetModuleFileName](../libraries/kernel32/GetModuleFileName.md)  

## Comment:
WinNT only. Windows 95/98/Me: Unsupported.  
  
***  

