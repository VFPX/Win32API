[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Comparing file times

## Code:
```foxpro  
DO decl

*| typedef struct _FILETIME {
*|     DWORD dwLowDateTime;
*|     DWORD dwHighDateTime;
*| } FILETIME, *PFILETIME;

	LOCAL lcTime1, lcTime2, lnResult

	lcTime1 = GetLastWriteTime ("c:\i386\Comctl32.dl_")
	lcTime2 = GetLastWriteTime ("c:\winnt\system32\Comctl32.dll")
	lnResult = CompareFileTime (lcTime1, lcTime2)

	DO CASE
	CASE lnResult = -1
		? "First file time is less than second file time"
	CASE lnResult = 0
		? "First file time is equal to second file time"
	CASE lnResult = 1
		? "First file time is greater than second file time"
	ENDCASE
RETURN

FUNCTION  GetLastWriteTime (lcFilename)
#DEFINE OF_READ   0
#DEFINE OF_WRITE  1
	LOCAL hFile, lcBuffer, lcCreationTm, lcLastAccessTm, lcLastWriteTm

	* 8 bytes - size of FILETIME structure
   	STORE Repli(Chr(0),8) TO lcCreationTm, lcLastAccessTm, lcLastWriteTm

	lcBuffer = REPLI (Chr(0), 250)
    hFile = OpenFile (lcFilename, @lcBuffer, OF_READ)
    IF hFile > 0
    	= GetFileTime (hFile, @lcCreationTm, @lcLastAccessTm, @lcLastWriteTm)
	    = CloseHandle (hFile)
	ELSE
		*  5 = Access is denied
		* 32 = The file is being used by another process
    ENDIF
RETURN lcLastWriteTm

PROCEDURE  decl
	DECLARE INTEGER CompareFileTime IN kernel32;
		STRING lpFileTime1, STRING lpFileTime2

	DECLARE GetFileTime IN kernel32;
		INTEGER hFile, STRING @lpCreationTime,;
		STRING @lpLastAccessTime, STRING @lpLastWriteTime

	DECLARE INTEGER OpenFile IN kernel32;
		STRING lpFileName, STRING @lpReOpenBuff,;
        INTEGER wStyle

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CompareFileTime](../libraries/kernel32/CompareFileTime.md)  
[GetFileTime](../libraries/kernel32/GetFileTime.md)  
[OpenFile](../libraries/kernel32/OpenFile.md)  

## Comment:
When using CompareFileTime there is no need to untwist retrieved FILETIME records into year-month-day-etc. values  
  
***  

