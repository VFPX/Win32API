[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Sending email messages with Simple MAPI

## Before you begin:
See also:

* [MAPI example (file attachments enabled)](sample_343.md)  
* [MAPI: reading email messages](sample_270.md)  
* [Winsock: sending email messages (SMTP, port 25)](sample_385.md)  
* [Winsock: reading email messages (POP3, port 110)](sample_388.md)  
* [Function MAPISendDocuments](../libraries/mapi32/MAPISendDocuments.md)  

  
***  


## Code:
```foxpro  
#DEFINE MAPI_ORIG  0
#DEFINE MAPI_TO 1
#DEFINE MAPI_DIALOG  8
#DEFINE SUCCESS_SUCCESS  0
DO decl

LOCAL hSession
hSession = getNewSession()

IF hSession = 0
	? "Unable to log on."
	RETURN
ENDIF

LOCAL loRcpEmail, loSndBuf, lcRcpBuf, loSubject, loNoteText,;
	loRcpBuf, lcMapiMessage, lnResult

* populating message recipient, subject and body
loRcpEmail = CreateObject ("PChar", "devicecontext@msn.com")
loSubject  = CreateObject ("PChar", "W32: testing Simple MAPI")
loNoteText = CreateObject ("PChar", "Test message.")

* initializing buffer with single recipient data
lcRcpBuf = num2dword(0) +;
		num2dword(MAPI_TO) +;
		num2dword(loRcpEmail.getAddr()) +;
		Repli(Chr(0), 12)
loRcpBuf = CreateObject ("PChar", lcRcpBuf)

* initializing buffer with sender data -- practically empty
loSndBuf = CreateObject ("PChar", Repli(Chr(0), 24))

* merging all parts to a message buffer -- no file attachments
lcMapiMessage = num2dword(0) +;
		num2dword(loSubject.getAddr()) +;
		num2dword(loNoteText.getAddr()) +;
		num2dword(0) + num2dword(0) + num2dword(0) + num2dword(0) +;
		num2dword(loSndBuf.getAddr()) +;
		num2dword(1) +;
		num2dword(loRcpBuf.getAddr()) +;
		num2dword(0) + num2dword(0)

* sending the message with or without a confirmation dialog
*lnResult = MAPISendMail(hSession, 0, @lcMapiMessage, MAPI_DIALOG, 0)
lnResult = MAPISendMail(hSession, 0, @lcMapiMessage, 0, 0)

IF lnResult <> SUCCESS_SUCCESS
* 1 MAPI_E_USER_ABORT
* 2 MAPI_E_FAILURE
* 3 MAPI_E_LOGIN_FAILURE
* 5 MAPI_E_INSUFFICIENT_MEMORY
* 6 MAPI_E_ACCESS_DENIED
* 9 MAPI_E_TOO_MANY_FILES
*10 MAPI_E_TOO_MANY_RECIPIENTS
*15 MAPI_E_BAD_RECIPTYPE
*18 MAPI_E_TEXT_TOO_LARGE
*14 MAPI_E_UNKNOWN_RECIPIENT
* ...
	? "Error returned:", lnResult
ELSE
	? "Sent initiated successfully!"
ENDIF

* closing current MAPI session
= MAPILogoff (hSession, 0, 0, 0)

FUNCTION  getNewSession()
* creates a new MAPI session and returns its handle
#DEFINE MAPI_LOGON_UI  1
#DEFINE MAPI_NEW_SESSION  2
#DEFINE MAPI_USE_DEFAULT 64
#DEFINE MAPI_FORCE_DOWNLOAD 0x1000
#DEFINE MAPI_PASSWORD_UI 0x20000

	LOCAL lnResult, lnSession, lcStoredPath
	lcStoredPath = SYS(5) + SYS(2003)
	lnSession = 0

	lnResult = MAPILogon (0, "", "",;
		MAPI_USE_DEFAULT+MAPI_NEW_SESSION, 0, @lnSession)

	* sometimes you need to restore default path - Outlook Express
	SET DEFAULT TO (lcStoredPath)
RETURN Iif(lnResult=SUCCESS_SUCCESS, lnSession, 0)

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

*| for some structures you need not just strings but pointers to strings
*| to be assigned to structure fields;
*| this class implements such "dual" strings
DEFINE CLASS PChar As Custom
	PROTECTED hMem

PROCEDURE  Init (lcString)
	THIS.hMem = 0
	THIS.setValue (lcString)

PROCEDURE  Destroy
	THIS.ReleaseString

FUNCTION getAddr  && returns a pointer to the string
RETURN THIS.hMem

FUNCTION getValue && returns string value
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
			STRING @, INTEGER, INTEGER
		= Heap2Str (@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION getAllocSize  && returns allocated memory size (string length)
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE setValue (lcString) && assigns new string value
#DEFINE GMEM_FIXED   0
	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As Str2Heap;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc (GMEM_FIXED, lnSize)
	IF THIS.hMem <> 0
		= Str2Heap (THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString  && releases allocated memory
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE

PROCEDURE  decl
	DECLARE INTEGER MAPILogon IN mapi32;
		INTEGER ulUIParam, STRING lpszProfileName,;
		STRING lpszPassword, INTEGER flFlags,;
		INTEGER ulReserved, INTEGER @lplhSession

	DECLARE INTEGER MAPILogoff IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam,;
		INTEGER flFlags, INTEGER ulReserved

	DECLARE INTEGER MAPISendMail IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam, STRING @lpMessage,;
		INTEGER flFlags, INTEGER ulReserved

*| participating structures
*| typedef struct {
*|      ULONG ulReserved;              0:4
*|      LPTSTR lpszSubject;            4:4
*|      LPTSTR lpszNoteText;           8:4
*|      LPTSTR lpszMessageType;       12:4
*|      LPTSTR lpszDateReceived;      16:4
*|      LPTSTR lpszConversationID;    20:4
*|      FLAGS flFlags;                24:4
*|      lpMapiRecipDesc lpOriginator; 28:4
*|      ULONG nRecipCount;            32:4
*|      lpMapiRecipDesc lpRecips;     36:4
*|      ULONG nFileCount;             40:4
*|      lpMapiFileDesc lpFiles;       44:4
*| } MapiMessage, FAR *lpMapiMessage; total: 48 bytes

*| typedef struct {
*|      ULONG ulReserved               0:4
*|      ULONG ulRecipClass;            4:4
*|      LPTSTR lpszName;               8:4
*|      LPTSTR lpszAddress;           12:4
*|      ULONG ulEIDSize;              16:4
*|      LPVOID lpEntryID;             20:4
*| } MapiRecipDesc, FAR *lpMapiRecipDesc; total: 24 bytes  
```  
***  


## Listed functions:
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[MAPILogoff](../libraries/mapi32/MAPILogoff.md)  
[MAPILogon](../libraries/mapi32/MAPILogon.md)  
[MAPISendMail](../libraries/mapi32/MAPISendMail.md)  

## Comment:
The *hSession* can be 0. In this case, the MAPILogon and MAPILogoff are not required. It is called an *implicit* logon -- a temporary MAPI session is created. The implicit session is closed by the time the call returns.  
  

***  

