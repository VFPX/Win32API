[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to delete IE cookies, clear IE history and delete files in Temporary Internet Files directory

## Short description:
The following example presents session class *CacheEntry* and collection class *CacheEntries*. The latter, when created, enumerates Internet cache entries, either cookies or history or cached files depending on the search pattern. Cache entries can be deleted through *DeleteCacheEntry* and *DeleteCacheEntries* methods of the collection class.  
***  


## Before you begin:
The following example presents session class *CacheEntry* and collection class *CacheEntries*. The latter, when created, enumerates Internet cache entries for a given search pattern.  

Depending on the search pattern the enumerated can be  
* *cookies*  
* *visited web pages*  
* *cached Internet files*   

If you choose complete enumeration (empty search pattern or *.* ), it may take long time, like 5..10 minutes, if there are many cached files on the computer.  

Whichever cache entries have been enumerated, they can be deleted through *DeleteCacheEntry* and *DeleteCacheEntries* methods of the collection class.  

Note that this is all about Internet Explorer and WinINet. Other browsers most likely use different caching support.   
  
***  


## Code:
```foxpro  
* cacheentrytype values
#DEFINE NORMAL_CACHE_ENTRY        0x000001
#DEFINE STICKY_CACHE_ENTRY        0x000004
#DEFINE EDITED_CACHE_ENTRY        0x000008
#DEFINE TRACK_OFFLINE_CACHE_ENTRY 0x000010
#DEFINE TRACK_ONLINE_CACHE_ENTRY  0x000020
#DEFINE SPARSE_CACHE_ENTRY        0x010000
#DEFINE COOKIE_CACHE_ENTRY        0x100000
#DEFINE URLHISTORY_CACHE_ENTRY    0x200000

LOCAL oEntries As CacheEntries, oEntry As CacheEntrie

* use search templates "cookie:", "visited:" or "*.*"
* with the last one it may take quite a time to scan all cache entries,
* like 3..5 minutes and more
oEntries = CREATEOBJECT("CacheEntries", "")

? oEntries.Count

CREATE CURSOR cs (url C(250), localfile C(250), entrytype I,;
	usecount I, hitrate I, localfilesize I, lastmodified T,;
	expiretime T, lastaccesstime T, lastsynctime T)

oEntries.KeySort=2
FOR EACH oEntry IN oEntries
	WITH oEntry
		INSERT INTO cs VALUES(;
			.sourceurlname,;
			.localfilename,;
			.cacheentrytype,;
			.usecount,;
			.hitrate,;
			.localfilesize,;
			.lastmodified.GetDateTime(),;
			.expiretime.GetDateTime(),;
			.lastaccesstime.GetDateTime(),;
			.lastsynctime.GetDateTime();
		)
	ENDWITH
NEXT

SELECT cs
GO TOP
BROWSE NORMAL NOWAIT

* this one deletes all cache entries in this collection
* note: not just the collection members but the files
* are to be deleted

*!*	oEntries.DeleteCacheEntries

* end of main

DEFINE CLASS CacheEntry As Session
	sourceurlname=""
	localfilename=""
	cacheentrytype=0
	usecount=0
	hitrate=0
	localfilesize=0
	lastmodified=0
	expiretime=0
	lastaccesstime=0
	lastsynctime=0
ENDDEFINE

DEFINE CLASS CacheEntries As Collection
PROTECTED entrypattern

PROCEDURE Init(cPattern)
	THIS.declare
	THIS.EnumCacheEntries(m.cPattern)

PROCEDURE Destroy
	THIS.ReleaseCollection

PROTECTED PROCEDURE ReleaseCollection
	DO WHILE THIS.Count > 0
		THIS.Remove(1)
	ENDDO

PROCEDURE DeleteCacheEntry(vIndex)
	LOCAL oCookie As CacheEntry, lResult
	lResult=.F.
	TRY
		oCookie = THIS.Item(vIndex)
		IF DeleteUrlCacheEntry(oCookie.sourceurlname) <> 0
			THIS.Remove(vIndex)
			lResult=.T.
		ENDIF
	CATCH
	ENDTRY
RETURN m.lResult

PROCEDURE DeleteCacheEntries
	LOCAL nIndex, nDeleted
	nDeleted=0
	FOR nIndex=THIS.Count TO 1 STEP -1
		IF THIS.DeleteCacheEntry(nIndex)
			nDeleted=nDeleted + 1
		ENDIF
	NEXT
RETURN m.nDeleted

PROCEDURE EnumCacheEntries(cPattern)
	THIS.entrypattern=m.cPattern
	THIS.ReleaseCollection

	LOCAL hFind, hBuffer, nBufsize
	nBufsize=0xffff
	hBuffer = GlobalAlloc(0, nBufsize)
	hFind = FindFirstUrlCacheEntry(cPattern, hBuffer, @nBufsize)
	IF hFind=0
		GlobalFree(hBuffer)
		RETURN
	ENDIF
	
	DO WHILE .T.
		THIS.AddCacheEntry(hBuffer, nBufsize)
		DOEVENTS
		GlobalFree(hBuffer)

		nBufsize=0xffff
		hBuffer = GlobalAlloc(0, nBufsize)
		IF FindNextUrlCacheEntry(hFind, hBuffer, @nBufsize) = 0
			EXIT
		ENDIF
	ENDDO
	= FindCloseUrlCache(hFind)

PROTECTED PROCEDURE AddCacheEntry(hBuffer, nBufsize)
	LOCAL oEntry As CacheEntry, cBuffer, nPtr, ex As Exception
	cBuffer = REPLICATE(CHR(0), nBufsize)
	= MemToStr(@cBuffer, hBuffer, nBufsize)

	oEntry = CREATEOBJECT("CacheEntry")
	WITH oEntry
		.cacheentrytype=buf2dword(SUBSTR(cBuffer,13,4))
		.usecount=buf2dword(SUBSTR(cBuffer,17,4))
		.hitrate=buf2dword(SUBSTR(cBuffer,21,4))

		nPtr = buf2dword(SUBSTR(cBuffer,5,4))
		.sourceurlname=SUBSTR(cBuffer, nPtr-hBuffer+1)
		.sourceurlname=SUBSTR(.sourceurlname, 1, AT(CHR(0),.sourceurlname)-1)

		nPtr = buf2dword(SUBSTR(cBuffer,9,4))
		.localfilename=SUBSTR(cBuffer, nPtr-hBuffer+1)
		.localfilename=SUBSTR(.localfilename, 1, AT(CHR(0),.localfilename)-1)

		.localfilesize=buf2dword(SUBSTR(cBuffer,25,4)) +;
			buf2dword(SUBSTR(cBuffer,29,4)) * (0xffffffff+1)

		.lastmodified=CREATEOBJECT("FileTime", SUBSTR(cBuffer,33,8))
		.expiretime=CREATEOBJECT("FileTime", SUBSTR(cBuffer,41,8))
		.lastaccesstime=CREATEOBJECT("FileTime", SUBSTR(cBuffer,49,8))
		.lastsynctime=CREATEOBJECT("FileTime", SUBSTR(cBuffer,57,8))

		TRY
			WAIT WINDOW NOWAIT .sourceurlname
			THIS.Add(oEntry, .sourceurlname)
		CATCH TO ex
		FINALLY
			WAIT CLEAR
		ENDTRY

	ENDWITH
	oEntry=Null
	
PROTECTED PROCEDURE declare
	DECLARE INTEGER FindFirstUrlCacheEntry In wininet;
		STRING lpszUrlSearchPattern, INTEGER lpFirstCacheEntryInfo,;
		INTEGER @lpdwFirstCacheEntryInfoBufferSize

	DECLARE INTEGER FindNextUrlCacheEntry IN wininet;
		INTEGER hEnumHandle, INTEGER lpNextCacheEntryInfo,;
		INTEGER @lpdwNextCacheEntryInfoBufferSize

	DECLARE INTEGER FileTimeToSystemTime IN kernel32.dll;
		STRING @lpFileTime, STRING @lpSystemTime

	DECLARE INTEGER DeleteUrlCacheEntry IN wininet STRING lpszUrlName
	DECLARE INTEGER FindCloseUrlCache IN wininet INTEGER hEnumHandle
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER wFlags, INTEGER dwBytes

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @Dest, INTEGER Src, INTEGER nLength
ENDDEFINE

DEFINE CLASS FileTime As Session
	wYear=0
	wMonth=0
	wDOW=0
	wDay=0
	wHour=0
	wMinute=0
	wSecond=0

PROCEDURE Init(cFileTime)
	LOCAL cSystemTime
	cSystemTime = REPLICATE(CHR(0), 16)
	= FileTimeToSystemTime(@cFileTime, @cSystemTime)

	THIS.wYear=buf2word(SUBSTR(cSystemTime,1,2))
	THIS.wMonth=buf2word(SUBSTR(cSystemTime,3,2))
	THIS.wDOW=buf2word(SUBSTR(cSystemTime,5,2))
	THIS.wDay=buf2word(SUBSTR(cSystemTime,7,2))
	THIS.wHour=buf2word(SUBSTR(cSystemTime,9,2))
	THIS.wMinute=buf2word(SUBSTR(cSystemTime,11,2))
	THIS.wSecond=buf2word(SUBSTR(cSystemTime,13,2))
	
FUNCTION GetDate
	LOCAL dDate
	TRY
		dDate = EVALUATE("{^" + TRANSFORM(THIS.wYear) + "/" +;
			TRANSFORM(THIS.wMonth) + "/" + TRANSFORM(THIS.wDay) + "}")
	CATCH
		dDate = {}
	ENDTRY
RETURN m.dDate

FUNCTION GetDateTime
RETURN DTOT(THIS.GetDate()) +;
	THIS.wHour*3600 + THIS.wMinute*60 + THIS.wSecond

ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[DeleteUrlCacheEntry](../libraries/wininet/DeleteUrlCacheEntry.md)  
[FileTimeToSystemTime](../libraries/kernel32/FileTimeToSystemTime.md)  
[FindCloseUrlCache](../libraries/wininet/FindCloseUrlCache.md)  
[FindFirstUrlCacheEntry](../libraries/wininet/FindFirstUrlCacheEntry.md)  
[FindNextUrlCacheEntry](../libraries/wininet/FindNextUrlCacheEntry.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  

## Comment:
For FoxPro versions 3..7 you must tinker the code a little bit.  
  
Visiting a single web page may create tens if not a hundred cached files on your computer. Just for fun: clear cookies, history and temporary internet files and start visiting different web pages. If this is your first experience, most likely you will be amazed.   
  
I have all third-party cookies blocked in my IE settings.  
  
***  

