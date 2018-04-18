[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Pocket PC: base class

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Short description:
This class is used as a base class for several custom RAPI classes created to access objects stored on Pocket PC: system registry, object store databases, files and folder, remote routines.  
***  


## Before you begin:
![](../images/pocketpcs.png)  

* [System Registry](sample_441.md)  
* [Object Store Databases](sample_445.md)  
* [Files and folders](sample_448.md)  
* [Executing routines](sample_466.md)  

<!-- Anatoliy -->
See also:

* [FoxPro Advisor article: Access a Pocket PC from Visual FoxPro](?article=6)  
* [FoxPro Advisor article: Access a Palm OS PDA from Visual FoxPro](?article=7)   
  
***  


## Code:
```foxpro  
****************************************************
* Pocket PC: base RAPI class
****************************************************
DEFINE CLASS Trapi As Custom
#DEFINE RAPIINIT_SIZE  12
#DEFINE WAIT_OBJECT_0  0
	majorver=0
	minorver=0
	buildno=0
	aclinestatus=0
	batteryflag=0
	batterylifepercent=0
	storesize=0
	freesize=0
	phmemtotal=0
	phmemavail=0
	cputype=0
	cpulevel=0
	cpurevision=0
	connected=.F.

PROCEDURE Init
	THIS.decl
	THIS.InitRapi
	
PROCEDURE InitRapi
	THIS.UninitRapi

	LOCAL cBuffer, hEvent
	cBuffer = PADR(CHR(RAPIINIT_SIZE), RAPIINIT_SIZE, CHR(0))

	= CeRapiInitEx(@cBuffer)
	hEvent = buf2dword(SUBSTR(cBuffer,5,4))

	IF WaitForSingleObject(hEvent,2000) = WAIT_OBJECT_0
		THIS.connected = .T.
	ELSE
		THIS.UninitRapi
	ENDIF
RETURN THIS.connected

PROCEDURE UninitRapi
	= CeRapiUninit()
	THIS.connected = .F.

PROCEDURE Destroy
	THIS.UninitRapi

PROCEDURE GetSysInfo
	THIS.GetVersion
	THIS.GetPowerStatus
	THIS.GetStoreSize
	THIS.GetGlobalMemoryStatus
	THIS.GetCPUInfo

PROCEDURE GetVersion
#DEFINE CEOSVERSIONINFO_SIZE 276
	LOCAL cBuffer, hBuffer
	cBuffer = PADR(num2dword(CEOSVERSIONINFO_SIZE),;
		CEOSVERSIONINFO_SIZE, Chr(0))
	= CeGetVersionEx(@cBuffer)
	THIS.majorver = buf2dword(SUBSTR(cBuffer, 5,4))
	THIS.minorver = buf2dword(SUBSTR(cBuffer, 9,4))
	THIS.buildno = buf2dword(SUBSTR(cBuffer, 13,4))

FUNCTION GetSpecialFolderPath(nFolder)
	LOCAL nBufsize, cBuffer
	nBufsize = 250
	cBuffer = REPLICATE(CHR(0), nBufsize*2)
	nBufsize = CeGetSpecialFolderPath(nFolder, nBufsize, @cBuffer)
RETURN STRCONV(SUBSTR(cBuffer,1,nBufsize*2),6)

PROCEDURE GetPowerStatus
#DEFINE SYSTEM_POWER_STATUS 24
	LOCAL cBuffer
	cBuffer = REPLICATE(CHR(0), SYSTEM_POWER_STATUS)
	= CeGetSystemPowerStatusEx(@cBuffer, 0)
	THIS.aclinestatus = ASC(SUBSTR(cBuffer,1,1))
	THIS.batteryflag = ASC(SUBSTR(cBuffer,2,1))
	THIS.batterylifepercent = ASC(SUBSTR(cBuffer,3,1))

PROCEDURE GetStoreSize
#DEFINE STORE_INFORMATION_SIZE 8
	LOCAL cBuffer
	cBuffer = Repli(Chr(0), STORE_INFORMATION_SIZE)
	= CeGetStoreInformation(@cBuffer)
	THIS.storesize = buf2dword(SUBSTR(cBuffer, 1,4))
	THIS.freesize = buf2dword(SUBSTR(cBuffer, 5,4))

PROCEDURE GetGlobalMemoryStatus
#DEFINE MEMORYSTATUS_SIZE 32
	LOCAL cBuffer
	cBuffer = PADR(CHR(MEMORYSTATUS_SIZE), MEMORYSTATUS_SIZE, CHR(0))
	= CeGlobalMemoryStatus(@cBuffer)
	THIS.phmemtotal = buf2dword(SUBSTR(cBuffer, 9,4))
	THIS.phmemavail = buf2dword(SUBSTR(cBuffer, 13,4))

PROCEDURE GetCPUInfo
#DEFINE SYSTEM_INFO_SIZE 36
	LOCAL cBuffer
	cBuffer = PADR(CHR(SYSTEM_INFO_SIZE), SYSTEM_INFO_SIZE, CHR(0))
	= CeGetSystemInfo(@cBuffer)
	THIS.cputype = buf2dword(SUBSTR(cBuffer, 25,4))
	THIS.cpulevel = buf2word(SUBSTR(cBuffer, 33,2))
	THIS.cpurevision = buf2word(SUBSTR(cBuffer, 35,2))

PROTECTED PROCEDURE decl
	DECLARE INTEGER LocalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER CeRapiUninit IN rapi
	DECLARE INTEGER CeGetLastError IN rapi
	DECLARE INTEGER CeRapiInitEx IN rapi STRING @pRapiInit
	DECLARE INTEGER CeCloseHandle IN rapi INTEGER hObject
	DECLARE INTEGER CeGetVersionEx IN rapi STRING @lpVersionInfo
	DECLARE INTEGER CeGetStoreInformation IN rapi STRING @lpsi
	DECLARE CeGlobalMemoryStatus IN rapi STRING @lpmst
	DECLARE CeGetSystemInfo IN rapi STRING @lpSystemInfo

	DECLARE INTEGER CeGetSystemPowerStatusEx IN rapi;
		STRING @pstatus, INTEGER fUpdate

	DECLARE INTEGER CeGetSpecialFolderPath IN rapi;
		INTEGER nFolder, INTEGER nBufferLength, STRING @lpBuffer

	DECLARE INTEGER LocalAlloc IN kernel32;
		INTEGER uFlags, INTEGER uBytes

	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER Dest, STRING @Src, INTEGER nLength

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dest, INTEGER src, INTEGER nLength

	DECLARE INTEGER WaitForSingleObject IN kernel32;
		INTEGER hHandle, INTEGER dwMilliseconds
ENDDEFINE

*************************** static members ***************************
FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word(lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

FUNCTION ToUnicode(cStr)
RETURN STRCONV(m.cStr+CHR(0), 5)

FUNCTION FromUnicode(cStr)
RETURN STRCONV(m.cStr, 6)  
```  
***  


## Listed functions:
[CeCloseHandle](../libraries/rapi/CeCloseHandle.md)  
[CeGetLastError](../libraries/rapi/CeGetLastError.md)  
[CeGetSpecialFolderPath](../libraries/rapi/CeGetSpecialFolderPath.md)  
[CeGetStoreInformation](../libraries/rapi/CeGetStoreInformation.md)  
[CeGetSystemInfo](../libraries/rapi/CeGetSystemInfo.md)  
[CeGetSystemPowerStatusEx](../libraries/rapi/CeGetSystemPowerStatusEx.md)  
[CeGetVersionEx](../libraries/rapi/CeGetVersionEx.md)  
[CeGlobalMemoryStatus](../libraries/rapi/CeGlobalMemoryStatus.md)  
[CeRapiInitEx](../libraries/rapi/CeRapiInitEx.md)  
[CeRapiUninit](../libraries/rapi/CeRapiUninit.md)  
[LocalAlloc](../libraries/kernel32/LocalAlloc.md)  
[LocalFree](../libraries/kernel32/LocalFree.md)  
[WaitForSingleObject](../libraries/kernel32/WaitForSingleObject.md)  

***  

