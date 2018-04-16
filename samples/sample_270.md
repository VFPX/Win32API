[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to read email messages using Simple MAPI

## Before you begin:
This code retrieves messages from your mailbox (Inbox) and stores them in a cursor.   

See also:

* [MAPI example (file attachments enabled)](sample_343.md)  
* [MAPI: sending email messages](sample_193.md)  
* [MAPI: reading email messages](sample_270.md)  
* [Winsock: sending email messages (SMTP, port 25)](sample_385.md)  
* [Winsock: reading email messages (POP3, port 110)](sample_388.md)  
* [Function MAPISendDocument](../libraries/mapi32/MAPISendDocuments.md)

***  


## Code:
```foxpro  
#DEFINE SUCCESS_SUCCESS 0
#DEFINE MAPI_LONG_MSGID 0x4000
#DEFINE MAPI_UNREAD_ONLY 32
#DEFINE MAPI_PEEK 0x0080
#DEFINE MAPI_SUPPRESS_ATTACH 0x0800
#DEFINE MAPIMESSAGE_STRU_SIZE 48
#DEFINE MAPIRECIPDESC_STRU_SIZE 24
#DEFINE MAPI_LOGON_UI 1
#DEFINE MAPI_NEW_SESSION 2
#DEFINE MAPI_USE_DEFAULT 64
#DEFINE MAPI_FORCE_DOWNLOAD 0x1000
#DEFINE MAPI_PASSWORD_UI 0x20000

DO declare

PRIVATE hSession
hSession = GetMapiSession()

IF hSession = 0
	? "Unable to log on."
ELSE
	* the resulting cursor
	CREATE CURSOR csResult (messageid C(64), origname C(50),;
		origaddr C(50), subj C(200), msg M)

	= ScanMessages()

	* it may take some time
	= MAPILogoff(hSession, 0, 0, 0)
	
	GO TOP
	BROWSE NORMAL NOWAIT
ENDIF
* end of main

PROCEDURE ScanMessages

	LOCAL lcBuffer, lnResult, lcMsgId, lnMsgCount
	lcBuffer = REPLICATE(CHR(0), 1024)
	
	* retrieve message identifiers
	lcMsgId = NULL
	lnMsgCount = 0

	DO WHILE .T.
		lnResult = MAPIFindNext(hSession, 0, NULL, m.lcMsgId,;
			MAPI_LONG_MSGID, 0, @lcBuffer)

		IF lnResult = SUCCESS_SUCCESS
			lnMsgCount = lnMsgCount + 1
			lcMsgId = SUBSTR(lcBuffer, 1,AT(Chr(0),lcBuffer)-1)
			= ReadMessage(m.lcMsgId)
		ELSE
			EXIT
		ENDIF
	ENDDO
RETURN

PROCEDURE ReadMessage(lcMsgId)
	LOCAL lnResult, lnMemPtr
	lnMemPtr = 0

	lnResult = MAPIReadMail(hSession, 0, lcMsgId,;
		MAPI_PEEK+MAPI_SUPPRESS_ATTACH, 0, @lnMemPtr)

	IF lnResult = SUCCESS_SUCCESS
		= SaveMessage(lcMsgId, lnMemPtr)
		= MAPIFreeBuffer(lnMemPtr)
	ENDIF
RETURN

PROCEDURE SaveMessage(lcMsgId, lnMemPtr)
*| typedef struct {
*|  ULONG ulReserved;            0:4
*|  LPTSTR lpszSubject;          4:4
*|  LPTSTR lpszNoteText;         8:4
*|  LPTSTR lpszMessageType;     12:4
*|  LPTSTR lpszDateReceived;    16:4
*|  LPTSTR lpszConversationID;  20:4
*|  FLAGS flFlags;              24:4
*|  lpMapiRecipDesc lpOrigin;   28:4
*|  ULONG nRecipCount;          32:4
*|  lpMapiRecipDesc lpRecips;   36:4
*|  ULONG nFileCount;           40:4
*|  lpMapiFileDesc lpFiles;     44:4
*| } MapiMessage, FAR *lpMapiMessage; total = 48 bytes

	LOCAL lcBuffer, lcSubject, lcNoteTxt

	lcBuffer = REPLICATE(CHR(0), MAPIMESSAGE_STRU_SIZE)
	= MemToStr(@lcBuffer, lnMemPtr, MAPIMESSAGE_STRU_SIZE)
	
	lcSubject = GetStruParam(@lcBuffer, 5)
	lcNoteTxt = GetStruParam(@lcBuffer, 9)

*| typedef struct {
*|  ULONG ulReserved             0:4
*|  ULONG ulRecipClass;          4:4
*|  LPTSTR lpszName;             8:4
*|  LPTSTR lpszAddress;         12:4
*|  ULONG ulEIDSize;            16:4
*|  LPVOID lpEntryID;           20:4
*| } MapiRecipDesc, FAR *lpMapiRecipDesc; total = 24 bytes

	LOCAL lnOrigPtr, lcOrigBuf, lcOrigName, lcOrigAddr
	lnOrigPtr = buf2dword(SUBSTR(lcBuffer, 29,4))

	lcOrigBuf = Repli(Chr(0), MAPIRECIPDESC_STRU_SIZE)
	= MemToStr(@lcOrigBuf, lnOrigPtr, MAPIRECIPDESC_STRU_SIZE)

	lcOrigName = GetStruParam(@lcOrigBuf, 9)
	lcOrigAddr = GetStruParam(@lcOrigBuf, 13)

	INSERT INTO csResult VALUES (m.lcMsgId, m.lcOrigName, m.lcOrigAddr,;
		m.lcSubject, m.lcNoteTxt)
RETURN

FUNCTION GetStruParam(lcBuffer, lnOffs)
	LOCAL lnPtr, lcResult
	lnPtr = buf2dword(SUBSTR(lcBuffer, lnOffs,4))
RETURN Iif(lnPtr=0, "", GetStringFromPtr(lnPtr))

FUNCTION GetMapiSession()
	WAIT WINDOW "Creating a new MAPI session..." NOWAIT
	LOCAL lnResult, lnSession, lcStoredPath
	lcStoredPath = SYS(5) + SYS(2003)
	lnSession = 0

*	lnResult = MAPILogon(0, "Novell Default Settings", NULL,;
		MAPI_USE_DEFAULT+MAPI_NEW_SESSION, 0, @lnSession)

	lnResult = MAPILogon(0, "", NULL,;
		MAPI_USE_DEFAULT+MAPI_NEW_SESSION, 0, @lnSession)

	* often you need to restore default path - Outlook Express
	SET DEFAULT TO (lcStoredPath)
	WAIT CLEAR
RETURN Iif(lnResult=SUCCESS_SUCCESS, lnSession, 0)

FUNCTION GetStringFromPtr(lnMemBlock)
	LOCAL lnPtr, lcResult, lnBufsize, lcBuffer, lnPos
	lnPtr = lnMemBlock
	lcResult = ""
	lnBufsize=16

	DO WHILE .T.
		lcBuffer = REPLICATE(CHR(0), m.lnBufsize)
		= MemToStr(@lcBuffer, lnPtr, m.lnBufsize)
		lnPos = AT(Chr(0), lcBuffer)

		IF lnPos > 0
			lcResult = lcResult + SUBSTR(lcBuffer, 1, lnPos-1)
			RETURN lcResult
		ELSE
			lcResult = lcResult + lcBuffer
			lnPtr = lnPtr + m.lnBufsize
		ENDIF
	ENDDO

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)), 8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)

PROCEDURE declare
	DECLARE INTEGER MAPILogon IN mapi32;
		INTEGER ulUIParam, STRING lpszProfileName,;
		STRING lpszPassword, INTEGER flFlags,;
		INTEGER ulReserved, INTEGER @lplhSession

	DECLARE INTEGER MAPILogoff IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam,;
		INTEGER flFlags, INTEGER ulReserved

	DECLARE INTEGER MAPIReadMail IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam,;
		STRING lpszMessageID, INTEGER flFlags,;
		INTEGER ulReserved, INTEGER @lppMessage

	DECLARE INTEGER MAPIFreeBuffer IN mapi32 INTEGER pv

	DECLARE INTEGER MAPIFindNext IN mapi32;
		INTEGER lhSession, INTEGER ulUIParam,;
		STRING lpszMsgType, STRING lpszSeedMsgID,;
		INTEGER flFlags, INTEGER ulReserved, STRING @lpszMsgID

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @, INTEGER, INTEGER  
```  
***  


## Listed functions:
[MAPIFindNext](../libraries/mapi32/MAPIFindNext.md)  
[MAPIFreeBuffer](../libraries/mapi32/MAPIFreeBuffer.md)  
[MAPILogoff](../libraries/mapi32/MAPILogoff.md)  
[MAPILogon](../libraries/mapi32/MAPILogon.md)  
[MAPIReadMail](../libraries/mapi32/MAPIReadMail.md)  

## Comment:
Add MAPI_FORCE_DOWNLOAD to MAPILogon flags to to download messages before returning.   
  
Using the ***Outlook Express*** with rules applied to incoming messages moving them to folders other than Inbox folder, you have no chance to reach these messages through this code. Not to my knowledge, to say more precisely.  
  
Attachments are not processed in this example (MAPI_SUPPRESS_ATTACH flag).  Using MAPI_PEEK flag ensures that MAPIReadMail does not mark the messages as read.   
  
Code for retrieving name and address for the recipient is not included. The routine is quite similar to the retrieving parameters for the sender (origin).  
  
If you are not able to logon, try use your messaging system profile name as a parameter. e.g. "Novell Default Settings".  
  
Check the VB link -- [Updated Mapivb32.bas for Simple MAPI on 32-Bit Platforms (Q163216)](https://support.microsoft.com/en-us/help/163216/updated-mapivb32-bas-for-simple-mapi-on-32-bit-platforms).  
  
* * *  
Each time the MAPIReadMail called without applying the MAPI_SUPPRESS_ATTACH flag, all attachments to messages in Inbox folder are copied to temp files. Continuous trying may seriously deplete the hard drive free space. Actually the MSDN suggests those temp files to be deleted once they are no longer needed.  
  

***  

