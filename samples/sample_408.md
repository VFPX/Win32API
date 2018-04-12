[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Simple MAPI: how to resolve a name to unique address list entry

## Code:
```foxpro  
#DEFINE SUCCESS_SUCCESS  0
#DEFINE MAPI_DIALOG      0x00000008
#DEFINE MAPI_AB_NOMODIFY 0x00000400
DO decl

PRIVATE hRecip
hRecip = 0

LOCAL nResult, cPath, nFlags, cSearch
cPath = SYS(5) + SYS(2003)
nFlags = MAPI_DIALOG + MAPI_AB_NOMODIFY
cSearch = "Peter"

nResult = MAPIResolveName(0, 0, cSearch, nFlags,0, @hRecip)

IF nResult = SUCCESS_SUCCESS
	DO ShowRecip
ELSE
* MAPI_E_FAILURE              2
* MAPI_E_LOGIN_FAILURE        3
* MAPI_E_INSUFFICIENT_MEMORY  5
* MAPI_E_UNKNOWN_RECIPIENT    14
* MAPI_E_AMBIGUOUS_RECIPIENT  21
* MAPI_E_NOT_SUPPORTED        26
	? "Error code:", nResult
ENDIF

= MAPIFreeBuffer(hRecip)
SET DEFAULT TO (cPath)
* end of main

PROCEDURE ShowRecip
*|typedef struct {
*|     ULONG ulReserved      0:4
*|     ULONG ulRecipClass;   4:4
*|     LPTSTR lpszName;      8:4
*|     LPTSTR lpszAddress;  12:4
*|     ULONG ulEIDSize;     16:4
*|     LPVOID lpEntryID;    20:4
*|} MapiRecipDesc, FAR *lpMapiRecipDesc; total 24 bytes
#DEFINE MapiRecipDesc_SIZE  24
#DEFINE DefNameSize         32

	LOCAL cRecip, hNamePtr, hAddrPtr, nEIDSize,;
		hEntryIDPtr, nEntryID, cName, cAddress

	cRecip = Repli(Chr(0), MapiRecipDesc_SIZE)
	= CopyMemory(@cRecip, hRecip, MapiRecipDesc_SIZE)
	
	nEIDSize = buf2dword(SUBSTR(cRecip, 17,4))
	hEntryIDPtr = buf2dword(SUBSTR(cRecip, 21,4))

	IF nEIDSize <> 0
		nEntryID = Repli(Chr(0), nEIDSize)
		= CopyMemory(@nEntryID, hEntryIDPtr, nEIDSize)
		nEntryId = buf2dword(nEntryID)
	ENDIF

	hNamePtr = buf2dword(SUBSTR(cRecip, 9,4))
	cName = Repli(Chr(0), DefNameSize)
	= CopyMemory(@cName, hNamePtr, DefNameSize)
	cName = SUBSTR(cName, 1,AT(Chr(0),cName)-1)

	hAddrPtr = buf2dword(SUBSTR(cRecip, 13,4))
	cAddress = Repli(Chr(0), DefNameSize)
	= CopyMemory(@cAddress, hAddrPtr, DefNameSize)
	cAddress = SUBSTR(cAddress, 1,AT(Chr(0),cAddress)-1)
	
	? "Recipient:", cName
	? "Email:", cAddress
	? "Address Book ID:", nEntryId

PROCEDURE decl
	DECLARE INTEGER MAPIResolveName IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam, STRING lpszName,;
		INTEGER flFlags, INTEGER ulReserved, INTEGER @lppRecip

	DECLARE INTEGER MAPIFreeBuffer IN mapi32 INTEGER pv

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Destination, INTEGER Source, INTEGER nLength

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[MAPIFreeBuffer](../libraries/mapi32/MAPIFreeBuffer.md)  
[MAPIResolveName](../libraries/mapi32/MAPIResolveName.md)  


***  

