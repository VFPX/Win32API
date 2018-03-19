[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining information about all user accounts on a server (WinNT only)

## Code:
```foxpro  
DO decl
#DEFINE NERR_Success                       0
#DEFINE MAX_PREFERRED_LENGTH              -1

#DEFINE FILTER_TEMP_DUPLICATE_ACCOUNT      1
#DEFINE FILTER_NORMAL_ACCOUNT              2
#DEFINE FILTER_INTERDOMAIN_TRUST_ACCOUNT   8
#DEFINE FILTER_WORKSTATION_TRUST_ACCOUNT  16
#DEFINE FILTER_SERVER_TRUST_ACCOUNT       32

LOCAL lcServer, lnBuffer, lnCount, lnCountEnum, lnCountTotal,;
	lnResume, lnResult, lcEntry

* The Null means the local computer
* replace it with a name of a server, e.g. \\MYSERVER
lcServer = .Null.
*lcServer = StrConv("\\MYSERVER", 5)  && conv. to Unicode

STORE 0 TO lnBuffer, lnCountEnum, lnCountTotal, lnResume

lnResult = NetUserEnum(lcServer, 1, 0, @lnBuffer,;
	MAX_PREFERRED_LENGTH, @lnCountEnum, @lnCountTotal, @lnResume)

IF lnResult <> NERR_Success
	*  53 = the network path not found
	* 123 = incorrect syntax for the name
	? "Error code:", lnResult
	RETURN
ENDIF

*| typedef struct _USER_INFO_1 {
*|   LPWSTR    usri1_name;          0:4
*|   LPWSTR    usri1_password;      4:4
*|   DWORD     usri1_password_age;  8:4
*|   DWORD     usri1_priv;         12:4
*|   LPWSTR    usri1_home_dir;     16:4
*|   LPWSTR    usri1_comment;      20:4
*|   DWORD     usri1_flags;        24:4
*|   LPWSTR    usri1_script_path;  28:4
*| }USER_INFO_1, *PUSER_INFO_1, *LPUSER_INFO_1; bytes=32
#DEFINE USERINFO_1_SIZE         32

LOCAL lnCount, lcBuffer, lnBufsize, lcEntry

lnBufsize = USERINFO_1_SIZE * lnCountEnum
lcBuffer = Repli(Chr(0), lnBufsize)
= Heap2String (@lcBuffer, lnBuffer, lnBufsize)

LOCAL lcUsername, lcUserpwd, lcHomedir, lcComment, lcScrPath,;
	lnPwdAge, lnPrivLev, lnFlags

CREATE CURSOR csResult (;
	username C(20), comment C(50), pwd C(12),;
	pwdage N(12), priv N(12), flags N(12),;
	script C(50), homedir C(200))

FOR lnCount=1 TO lnCountEnum
	lcEntry = SUBSTR(lcBuffer,;
		((lnCount-1)*USERINFO_1_SIZE)+1, USERINFO_1_SIZE)

	lcUsername = mem2str(buf2dword(SUBSTR(lcEntry, 1,4)))
	lcUserpwd  = mem2str(buf2dword(SUBSTR(lcEntry, 5,4)))
	lcHomedir  = mem2str(buf2dword(SUBSTR(lcEntry, 17,4)))
	lcComment  = mem2str(buf2dword(SUBSTR(lcEntry, 21,4)))
	lcScrPath  = mem2str(buf2dword(SUBSTR(lcEntry, 29,4)))
	
	lnPwdAge  = buf2dword(SUBSTR(lcEntry, 9,4))
	lnPrivLev = buf2dword(SUBSTR(lcEntry, 13,4))
	lnFlags   = buf2dword(SUBSTR(lcEntry, 25,4))
	
	INSERT INTO csResult VALUES (;
		lcUsername, lcComment, lcUserpwd, lnPwdAge,;
		lnPrivLev, lnFlags, lcScrPath, lcHomedir)
ENDFOR

= NetApiBufferFree(lnBuffer)
GO TOP
BROWSE NORMAL NOWAIT

FUNCTION  mem2str (lnMemBlock)
* converting allocated in memory Unicode string to a VFP string
#DEFINE StrBufferLength   250
	IF lnMemBlock = 0
		RETURN ""
	ELSE
		LOCAL lcBuffer
		lcBuffer = SPACE(StrBufferLength)
		= Heap2String (@lcBuffer, lnMemBlock, StrBufferLength)
		lcBuffer = SUBSTR (lcBuffer, 1, AT(Chr(0)+Chr(0),lcBuffer)-1)
	ENDIF
RETURN  STRTRAN(lcBuffer, Chr(0),"")

FUNCTION buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
       Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
       Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER NetUserEnum IN netapi32;
		STRING servername, INTEGER level, INTEGER filter,;
		INTEGER @bufptr, INTEGER prefmaxlen, INTEGER @entriesread,;
		INTEGER @totalentries, INTEGER @resume_handle

	DECLARE INTEGER NetApiBufferFree IN netapi32 INTEGER Buffer

	DECLARE RtlMoveMemory IN kernel32 As Heap2String;
		STRING @ Destination, INTEGER Source, INTEGER nLength  
```  
***  


## Listed functions:
[NetApiBufferFree](../libraries/netapi32/NetApiBufferFree.md)  
[NetUserEnum](../libraries/netapi32/NetUserEnum.md)  
