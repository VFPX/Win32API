[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating two-byte hashes for a list of URLs

## Code:
```foxpro  
DECLARE INTEGER UrlHash IN shlwapi;
	STRING pszURL, STRING @pbHash,;
	INTEGER cbHash

= _printHash ("http://msdn.microsoft.com/vfoxpro")
= _printHash ("http://www.foxite.com")
= _printHash ("http://www.foxforum.com")
= _printHash ("http://www.comcodebook.com")
= _printHash ("http://go.compuserve.com/msdevapps")
= _printHash ("http://www.takenote.com")
= _printHash ("http://www.universalthread.com")
= _printHash ("http://www.west-wind.com")
= _printHash ("http://www.west-wind.com/wwthreads")
= _printHash ("http://www.classx.com")
= _printHash ("http://www.stevenblack.com")
= _printHash ("http://www.craigberntson.com")
= _printHash ("http://www.computer-consulting.com")
= _printHash ("http://home.dwave.net/~clemmer/index.htm")
= _printHash ("http://www.prairienet.org/ita/foxpage.htm")
= _printHash ("http://www.prairienet.org/ita/devgroup.htm")
= _printHash ("http://www.hentzenwerke.com")
= _printHash ("http://www.geocities.com/df_FoxPro")

PROCEDURE  _printHash (lcUrl)
	? getHash(lcUrl), " ", lcUrl

FUNCTION  getHash (lcUrl)
#DEFINE S_OK      0
#DEFINE HashSize  2

	LOCAL lcHash
	lcHash = Repli(Chr(0), HashSize)
	IF UrlHash (lcUrl, @lcHash, HashSize) = S_OK
		RETURN buf2word(lcHash)
	ELSE
		RETURN 0
	ENDIF

FUNCTION  buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[UrlHash](../libraries/shlwapi/UrlHash.md)  
