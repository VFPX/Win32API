[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Verifying a file using the Authenticode policy provider

## Before you begin:
The following code sample has been developed by *John L Veazey*.  

The WinVerifyTrust performs a trust verification action on a specified object. The function passes the inquiry to a trust provider that supports the action identifier, if one exists.  
  
***  


## Code:
```foxpro  
? WinVerifyTrust( "C:\Windows\System32\mscomct2.ocx" )

FUNCTION WinVerifyTrust
LPARAMETERS cFileName as String
LOCAL pFileName as String, cFileInfo as String,;
	pFileInfo as Integer, cWintrustInfo as String,;
	nResult as Integer

*!* Ensure the file exists.
IF NOT FILE(cFileName) THEN
	RETURN .F.
ENDIF

*!* Structure Sizes
*!*	GUID = 16 = 4 + 2 + 2 + (1 * 8)
*!* http://msdn.microsoft.com/en-us/library/aa373931%28v=VS.85%29.aspx
*!*	WINTRUST_FILE_INFO = 4 + 4(*) + 4 + 4(*)
*!* http://msdn.microsoft.com/en-us/library/aa388206%28v=VS.85%29.aspx
*!*	WINTRUST_DATA = 48 = 4 + 4 + 4 + 4 + 4 + 4 + 4(*) + 4 + 4 + 4(*) + 4 + 4
*!* http://msdn.microsoft.com/en-us/library/aa388205%28v=VS.85%29.aspx

DECLARE LONG WinVerifyTrust IN wintrust;
AS WinVerifyTrustAPI ;
	LONG, STRING, STRING

*!*	LONG WINAPI WinVerifyTrust(
*!*	  __in  HWND hWnd,
*!*	  __in  GUID *pgActionID,
*!*	  __in  LPVOID pWVTData
*!*	);
*!*

DECLARE RtlMoveMemory IN WIN32API AS CopyMemory ;
	LONG, STRING, LONG

*!*	void CopyMemory(
*!*	  __in  PVOID Destination,
*!*	  __in  const VOID *Source,
*!*	  __in  SIZE_T Length
*!*	);
*!*

DECLARE LONG GlobalAlloc IN WIN32API ;
	LONG, LONG

*!*	HGLOBAL WINAPI GlobalAlloc(
*!*	  __in  UINT uFlags,
*!*	  __in  SIZE_T dwBytes
*!*	);
*!*

DECLARE LONG GlobalFree IN WIN32API ;
	LONG

*!*	HGLOBAL WINAPI GlobalFree(
*!*	  __in  HGLOBAL hMem
*!*	);
*!*

#DEFINE GMEM_ZEROINIT					0x0040
#DEFINE WTD_UI_NONE						2
#DEFINE WTD_REVOKE_NONE					0x00000000
#DEFINE WTD_CHOICE_FILE					1
#DEFINE WTD_STATEACTION_IGNORE			0x00000000
#DEFINE WTD_SAFER_FLAG					0x00000100
#DEFINE WTD_UICONTEXT_EXECUTE			0

*!* Allocate UNICODE string
pFileName = GlobalAlloc(GMEM_ZEROINIT, ((LEN(cFileName) + 1) * 2))
*!* Copy filename to UNICODE
cFileName = STRCONV(STRCONV(cFileName,1),5)
*!* Copy UNICODE string to memory allocation
CopyMemory(pFileName, cFileName, LEN(cFileName))
*!* Allocate WINTRUST_FILE_INFO structure
pFileInfo = GlobalAlloc(GMEM_ZEROINIT, 16)
*!* Define contents of WINTRUST_FILE_INFO structure
cFileInfo = BINTOC(16, "4SR") + BINTOC(pFileName, "4SR") +;
	REPLICATE(CHR(0),4) + REPLICATE(CHR(0),4)
*!* Copy Struct data to memory allocation
CopyMemory(pFileInfo, cFileInfo, 16)


*!* {00AAC56B-CD44-11d0-8CC2-00C04FC295EE}
WINTRUST_ACTION_GENERIC_VERIFY_V2  =;
	BINTOC(0x00aac56b, "4SR") +;
	LEFT(BINTOC(0xcd44, "4SR"),2) +;
	LEFT(BINTOC(0x11d0, "4SR"),2) +;
	CHR(0x008c) + CHR(0x00c2) + CHR(0x0000) + CHR(0x00c0) +;
	CHR(0x004f) + CHR(0x00c2) + CHR(0x0095) + CHR(0x00ee)

cWintrustInfo =;
	BINTOC(48, "4SR") +;
	REPLICATE(CHR(0),4) +;
	REPLICATE(CHR(0),4) +;
	BINTOC(WTD_UI_NONE, "4SR") +;
	BINTOC(WTD_REVOKE_NONE, "4SR") +;
	BINTOC(WTD_CHOICE_FILE, "4SR") +;
	BINTOC(pFileInfo, "4SR") +;
	BINTOC(WTD_STATEACTION_IGNORE, "4SR") +;
	REPLICATE(CHR(0),4) +;
	REPLICATE(CHR(0),4) +;
	BINTOC(WTD_SAFER_FLAG, "4SR") +;
	BINTOC(WTD_UICONTEXT_EXECUTE, "4SR")

nResult = WinVerifyTrustAPI(0, WINTRUST_ACTION_GENERIC_VERIFY_V2,;
	cWintrustInfo)

GlobalFree(pFileInfo)
GlobalFree(pFileName)

RETURN nResult == 0
ENDFUNC  
```  
***  


## Listed functions:
[CopyMemory](../libraries/kernel32/CopyMemory.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[WinVerifyTrust](../libraries/wintrust/WinVerifyTrust.md)  
