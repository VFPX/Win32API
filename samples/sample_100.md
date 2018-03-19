[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# DiskFreeSpace class

## Code:
```foxpro  
dspace = CREATEOBJECT("Tdspace", "c:")
IF dspace.errorcode = 0
	lcMask = "999,999,999,999,999"

	? "Free bytes available to the calling thread:",;
		TRANS(dspace.threadFree, lcMask)

	? "Total free bytes on the disk:",;
		TRANS(dspace.globalFree, lcMask)

	? "Total bytes available to the calling thread:",;
		TRANS(dspace.threadTotal, lcMask)
ELSE
	? "Error code: ", dspace.errorcode
ENDIF

DEFINE CLASS Tdspace As Session
#DEFINE MAX_INTEGER 0x100000000
	threadFree=0
	threadTotal=0
	globalFree=0
	errorcode=0
	
FUNCTION Init(lcPath)
	THIS.declare
	THIS.GetInfo(lcPath)

PROCEDURE GetInfo(lcPath)
	IF TYPE("lcPath") <> "C"
		lcPath = ""
	ENDIF
	LOCAL lpFreeBytesAvailable, lpTotalNumberOfBytes,;
		lpTotalNumberOfFreeBytes,;
		threadFreeLo, threadFreeHi, threadTotalLo,;
		threadTotalHi, freeLo, freeHi

	STORE Repli(Chr(0), 8) TO lpFreeBytesAvailable,;
		lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes
	
	IF GetDiskFreeSpaceEx(lcPath, @lpFreeBytesAvailable,;
		@lpTotalNumberOfBytes, @lpTotalNumberOfFreeBytes) = 1

		threadFreeLo = THIS.buf2dword(SUBSTR(lpFreeBytesAvailable, 1,4))
		threadFreeHi = THIS.buf2dword(SUBSTR(lpFreeBytesAvailable, 5,4))
		threadTotalLo = THIS.buf2dword(SUBSTR(lpTotalNumberOfBytes, 1,4))
		threadTotalHi = THIS.buf2dword(SUBSTR(lpTotalNumberOfBytes, 5,4))
		freeLo = THIS.buf2dword(SUBSTR(lpTotalNumberOfFreeBytes, 1,4))
		freeHi = THIS.buf2dword(SUBSTR(lpTotalNumberOfFreeBytes, 5,4))

		THIS.threadFree = THIS.GetLargeInt(threadFreeLo, threadFreeHi)
		THIS.threadTotal = THIS.GetLargeInt(threadTotalLo, threadTotalHi)
		THIS.globalFree = THIS.GetLargeInt(freeLo, freeHi)
		THIS.errorcode = 0
	ELSE
		STORE 0 TO THIS.threadFree, THIS.threadTotal, THIS.globalFree
		THIS.errorcode = GetLastError()
	ENDIF

PROTECTED PROCEDURE declare
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE SHORT GetDiskFreeSpaceEx IN kernel32;
		STRING lpDirectoryName, STRING @lpFreeBytesAvailable,;
		STRING @lpTotalNumberOfBytes, STRING @lpTotalNumberOfFreeBytes

PROTECTED FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROTECTED FUNCTION GetLargeInt(lo, hi)
RETURN MAX_INTEGER * m.hi + m.lo

ENDDEFINE  
```  
***  


## Listed functions:
[GetDiskFreeSpaceEx](../libraries/kernel32/GetDiskFreeSpaceEx.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
DiskSpace() is not reliable on big disks or NTFS (pre VFP7)  
  
***  

