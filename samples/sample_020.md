[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Displaying OS Memory Status

## Code:
```foxpro  
*|typedef struct _MEMORYSTATUS {
*| DWORD dwLength;           0:4
*| DWORD dwMemoryLoad;       4:4
*| SIZE_T dwTotalPhys;       8:4
*| SIZE_T dwAvailPhys;      12:4
*| SIZE_T dwTotalPageFile;  16:4
*| SIZE_T dwAvailPageFile;  20:4
*| SIZE_T dwTotalVirtual;   24:4
*| SIZE_T dwAvailVirtual;   28:4
*| } MEMORYSTATUS, *LPMEMORYSTATUS; total 32 bytes
#DEFINE MEMORYSTATUS_SIZE  32
	
DECLARE GlobalMemoryStatus IN kernel32;
	STRING @lpBuffer

PRIVATE cBuffer
cBuffer = REPLI(Chr(0), MEMORYSTATUS_SIZE)
= GlobalMemoryStatus(@cBuffer)

= Writeln("Memory in use, % ...................",  5)
= Writeln("Physical memory, in bytes ..........",  9)
= Writeln("Physical memory available, bytes ...", 13)
= Writeln("Committed memory limit, bytes ......", 17)
= Writeln("Available memory to commit, bytes ..", 21)
= Writeln("User mode portion..., bytes ........", 25)
= Writeln("Unreserved/uncommitted memory ......", 29)

PROCEDURE Writeln(cCaption, nOffs)
	LOCAL nSize
	nSize = buf2dword(SUBSTR(cBuffer,nOffs,4))
	? cCaption + " " + ALLTRIM(TRANS(nSize, "999,999,999,999,999,999"))

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GlobalMemoryStatus](../libraries/kernel32/GlobalMemoryStatus.md)  

## Comment:
MEMORYSTATUS reflects the state of memory at the time of the call. It reflects the size of the paging file at that time.  
  
Memory in use -- for WinNT this value can be zero.  
  
On computers with more than 4 GB of memory, the MEMORYSTATUS structure may return incorrect information. If your application is at risk for this behavior, use the GlobalMemoryStatusEx function instead.  
  
***  

