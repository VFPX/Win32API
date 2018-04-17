[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating Processes -- Win9*

## Before you begin:
See also:

* [Enumerating Processes -- WinNT](sample_162.md)  
* [Terminating all running applications from a VFP program](sample_243.md)  
  
***  


## Code:
```foxpro  
#DEFINE TH32CS_SNAPPROCESS  2
#DEFINE TH32CS_SNAPTHREAD   4
#DEFINE TH32CS_SNAPMODULE   8
#DEFINE MAX_PATH          260

DO decl

* http://msdn.microsoft.com/library/default.asp?url=
* /library/en-us/perfmon/toolhelp_0642.asp
*| typedef struct tagPROCESSENTRY32 {
*|   DWORD dwSize;                     4
*|   DWORD cntUsage;                   4
*|   DWORD th32ProcessID;              4
*|   ULONG_PTR th32DefaultHeapID;      4
*|   DWORD th32ModuleID;               4
*|   DWORD cntThreads;                 4
*|   DWORD th32ParentProcessID;        4
*|   LONG  pcPriClassBase;             4
*|   DWORD dwFlags;                    4
*|   TCHAR szExeFile[MAX_PATH];      260
*| } PROCESSENTRY32; total bytes: 296
*| typedef PROCESSENTRY32 *PPROCESSENTRY32;

#DEFINE PE32_SIZE  296

	* resulting cursor
	CREATE CURSOR csResult (;
		refcount    N(16),;
		processid   N(16),;
		heapid      N(16),;
		moduleid    N(16),;
		threadcount N(16),;
		parentid    N(16),;
		priority    N(16),;
		flags       N(16),;
		execname    C(250);
	)

	LOCAL hSnapshot, lcBuffer

	hSnapshot = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0)
	lcBuffer = num2dword(PE32_SIZE) + Repli(Chr(0), PE32_SIZE-4)

	IF Process32First (hSnapshot, @lcBuffer) = 1
		* storing process properties to the cursor
		= saveProcessData (lcBuffer)

		DO WHILE .T.
			IF Process32Next (hSnapshot, @lcBuffer) = 1
				* storing process properties to the cursor
				= saveProcessData (lcBuffer)
			ELSE
				EXIT
			ENDIF
		ENDDO
	ELSE
	* 87 - ERROR_INVALID_PARAMETER
	ENDIF

	= CloseHandle (hSnapshot)
	SELECT csResult
	GO TOP
	BROWSE NORMAL NOWAIT
RETURN  && main

PROCEDURE  saveProcessData (lcBuffer)
	LOCAL m.refcount, m.processid, m.heapid, m.moduleid, m.threadcount,;
		m.parentid, m.priority, m.flags, m.execname;

	* number of references to the process
	m.refcount = buf2dword (SUBSTR(lcBuffer, 5,4))

	* identifier of the process
	m.processid = buf2dword (SUBSTR(lcBuffer, 9,4))

	* identifier of the default heap for the process
	m.heapid = buf2dword (SUBSTR(lcBuffer, 13,4))

	* module identifier (pseudo) of the process
	m.moduleid = buf2dword (SUBSTR(lcBuffer, 17,4))

	* number of execution threads started by the process
	m.threadcount = buf2dword (SUBSTR(lcBuffer, 21,4))

	* identifier of the process that created this process
	m.parentid = buf2dword (SUBSTR(lcBuffer, 25,4))

	* base priority of any threads created by this process
	m.priority = buf2dword (SUBSTR(lcBuffer, 29,4))

	* reserved; do not use
	m.flags = buf2dword (SUBSTR(lcBuffer, 33,4))

	* path and filename of the executable for the process
	m.execname = SUBSTR(lcBuffer, 37)
	m.execname = SUBSTR(m.execname, 1, AT(Chr(0),m.execname)-1)

	INSERT INTO csResult FROM MEMVAR
RETURN

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

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject

	DECLARE INTEGER CreateToolhelp32Snapshot IN kernel32;
		INTEGER dwFlags, INTEGER th32ProcessID

	DECLARE INTEGER Process32First IN kernel32;
		INTEGER hSnapshot, STRING @ lppe

	DECLARE INTEGER Process32Next IN kernel32;
		INTEGER hSnapshot, STRING @ lppe  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateToolhelp32Snapshot](../libraries/kernel32/CreateToolhelp32Snapshot.md)  
[Process32First](../libraries/kernel32/Process32First.md)  
[Process32Next](../libraries/kernel32/Process32Next.md)  


***  

