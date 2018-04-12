[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve information about a cache entry (Internet Explorer)

## Code:
```foxpro  
DO decl

*|typedef struct _INTERNET_CACHE_ENTRY_INFO {
*|    DWORD  dwStructSize;         0:4
*|    LPTSTR  lpszSourceUrlName;   4:4
*|    LPTSTR  lpszLocalFileName;   8:4
*|    DWORD  CacheEntryType;      12:4
*|    DWORD  dwUseCount;          16:4
*|    DWORD  dwHitRate;           20:4
*|    DWORD  dwSizeLow;           24:4
*|    DWORD  dwSizeHigh;          28:4
*|    FILETIME  LastModifiedTime; 32:8
*|    FILETIME  ExpireTime;       40:8
*|    FILETIME  LastAccessTime;   48:8
*|    FILETIME  LastSyncTime;     56:8
*|    LPBYTE  lpHeaderInfo;       64:4
*|    DWORD  dwHeaderInfoSize;    68:4
*|    LPTSTR  lpszFileExtension;  72:4
*|    union {                     76:4
*|        DWORD  dwReserved;
*|        DWORD  dwExemptDelta;
*|    };
*|} INTERNET_CACHE_ENTRY_INFO, *LPINTERNET_CACHE_ENTRY_INFO; 80 bytes

#DEFINE cnENTRY_INFO_SIZE  80

LOCAL lcUrl, lcBuffer, lnBufsize, lnResult

* using "Recent Changes" page from FoxForumWiki
lcUrl = "http://fox.wikis.com/wc.dll?Wiki~RecentChanges"

*lcBuffer = Chr(cnENTRY_INFO_SIZE) + Repli(Chr(0), cnENTRY_INFO_SIZE-1)
lcBuffer = ""
lnBufsize = 0

= GetUrlCacheEntryInfo(lcUrl, @lcBuffer, @lnBufsize)

lcBuffer = Chr(cnENTRY_INFO_SIZE) + Repli(Chr(0), lnBufsize)
lnResult = GetUrlCacheEntryInfo(lcUrl, @lcBuffer, @lnBufsize)

IF lnResult = 0
*   2 - ERROR_FILE_NOT_FOUND -- file not in cache
* 122 - ERROR_INSUFFICIENT_BUFFER
	? "Error code:", GetLastError()
	RETURN
ENDIF

? lcBuffer

LOCAL lnPtr, lcValue
CREATE CURSOR csResult (pname C(50), pvalue C(250))

= addparam ("Required buffer size", LTRIM(STR(lnBufsize)))

lnPtr = buf2dword(SUBSTR(lcBuffer, 5,4))
lcValue = mem2str(lnPtr)
= addparam ("Source Url", lcValue)

lnPtr = buf2dword(SUBSTR(lcBuffer, 9,4))
lcValue = mem2str(lnPtr)
= addparam ("Local file name", lcValue)

lnPtr = buf2dword(SUBSTR(lcBuffer, 13,4))
= addparam ("Cache type bitmask", LTRIM(STR(lnPtr)))

lnPtr = buf2dword(SUBSTR(lcBuffer, 17,4))
= addparam ("User count of the cache entry", LTRIM(STR(lnPtr)))

lnPtr = buf2dword(SUBSTR(lcBuffer, 21,4))
= addparam ("Times the cache entry was retrieved", LTRIM(STR(lnPtr)))

lnPtr = buf2dword(SUBSTR(lcBuffer, 25,4))
= addparam ("Low order of the file size", LTRIM(STR(lnPtr)))

lnPtr = buf2dword(SUBSTR(lcBuffer, 29,4))
= addparam ("High order of the file size", LTRIM(STR(lnPtr)))

lcValue = FTime2ITime(SUBSTR(lcBuffer, 33,8))
= addparam ("Time last modified", lcValue)

lcValue = FTime2ITime(SUBSTR(lcBuffer, 41,8))
= addparam ("Time file expires", lcValue)

lcValue = FTime2ITime(SUBSTR(lcBuffer, 49,8))
= addparam ("Time last access", lcValue)

lcValue = FTime2ITime(SUBSTR(lcBuffer, 57,8))
= addparam ("Time cache synchronized", lcValue)

lnPtr = buf2dword(SUBSTR(lcBuffer, 65,4))
lcValue = mem2str(lnPtr)
= addparam ("Header Info", lcValue)

GO TOP
BROWSE NORMAL NOWAIT
* end of main

FUNCTION AddParam (lcName, lcValue)
	INSERT INTO csResult VALUES (lcName, lcValue)
RETURN

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION  mem2str(lnMemBlock)
#DEFINE BUFFER_SIZE   16
#DEFINE EMPTY_BUFFER  Repli(Chr(0), BUFFER_SIZE)

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
		STRING @, INTEGER, INTEGER

	LOCAL lnPtr, lcResult, lcBuffer, lnPos
	lnPtr = lnMemBlock
	lcResult = ""

	DO WHILE .T.
		lcBuffer = EMPTY_BUFFER
		= Heap2Str (@lcBuffer, lnPtr, BUFFER_SIZE)
		lnPos = AT(Chr(0), lcBuffer)

		IF lnPos > 0
			lcResult = lcResult + SUBSTR(lcBuffer, 1, lnPos-1)
			RETURN  lcResult
		ELSE
			lcResult = lcResult + lcBuffer
			lnPtr = lnPtr + BUFFER_SIZE
		ENDIF
	ENDDO
	
FUNCTION FTime2ITime (lcFiletime)
#DEFINE cnSYSTIME_SIZE  16
#DEFINE INTERNET_RFC1123_FORMAT   0
#DEFINE INTERNET_RFC1123_BUFSIZE  30

	LOCAL lcSysTime, lcInetTime
	lcSysTime = Repli(Chr(0), cnSYSTIME_SIZE)
	= FileTimeToSystemTime(lcFiletime, @lcSysTime)

	lcInetTime = Repli(Chr(0), INTERNET_RFC1123_BUFSIZE)
	= InternetTimeFromSystemTime(@lcSysTime, INTERNET_RFC1123_FORMAT,;
		@lcInetTime, INTERNET_RFC1123_BUFSIZE)
RETURN STRTRAN(lcInetTime, Chr(0),"")

PROCEDURE decl
	DECLARE INTEGER InternetTimeFromSystemTime IN wininet;
		STRING @pst, INTEGER dwRFC, STRING @lpszTime,;
		INTEGER cbTime
	
	DECLARE INTEGER FileTimeToSystemTime IN kernel32;
		STRING lpFileTime, STRING @lpSystemTime

	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER GetUrlCacheEntryInfo IN wininet;
		STRING lpszUrlName, STRING @lpCacheEntryInfo,;
		INTEGER @lpdwCacheEntryInfoBufferSize  
```  
***  


## Listed functions:
[FileTimeToSystemTime](../libraries/kernel32/FileTimeToSystemTime.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetUrlCacheEntryInfo](../libraries/wininet/GetUrlCacheEntryInfo.md)  
[InternetTimeFromSystemTime](../libraries/wininet/InternetTimeFromSystemTime.md)  

***  

