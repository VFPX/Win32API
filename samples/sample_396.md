[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting characters in a URL into corresponding escape sequences and backwards

## Before you begin:
Similar [example](sample_616.md) using InternetCanonicalizeUrl function.  
  
***  


## Code:
```foxpro  
#DEFINE URL_ESCAPE_PERCENT         0x1000
#DEFINE URL_ESCAPE_SEGMENT_ONLY    0x2000
#DEFINE URL_ESCAPE_SPACES_ONLY     0x4000000
#DEFINE URL_UNESCAPE_INPLACE       0x100000
#DEFINE URL_INTERNAL_PATH          0x800000
#DEFINE URL_DONT_ESCAPE_EXTRA_INFO 0x2000000
#DEFINE URL_DONT_SIMPLIFY          0x8000000

LOCAL cSource

cSource = "http://xyz.com/test/t%e< s t.asp >?" +;
	"url=/{ex% ample < /abc.asp?frame=true#fr%agment"
? "*** Source:"
? cSource
?

? "*** UrlEscape:"
? GetEscaped(cSource, URL_ESCAPE_SPACES_ONLY)
? GetEscaped(cSource, URL_ESCAPE_PERCENT)
cSource = GetEscaped(cSource, URL_ESCAPE_SEGMENT_ONLY)
? cSource
?
? "*** UrlUnescape:"
? GetUnescaped(cSource, 0)
* end of main

FUNCTION GetEscaped(cSource, nFlag)
	DECLARE INTEGER UrlEscape IN shlwapi;
		STRING pszURL, STRING @pszEscaped,;
		INTEGER @pcchEscaped, INTEGER dwFlags

	LOCAL cTarget, nBufsize
	nBufsize = Len(cSource) * 4
	cTarget = Repli(Chr(0), nBufsize)
	= UrlEscape(cSource, @cTarget, @nBufsize, nFlag)
RETURN Left(cTarget, nBufsize)

FUNCTION GetUnescaped(cSource, nFlag)
	DECLARE INTEGER UrlUnescape IN shlwapi;
		STRING pszURL, STRING @pszUnescaped,;
		INTEGER @pcchUnescaped, INTEGER dwFlags

	LOCAL cTarget, nBufsize
	nBufsize = Len(cSource) * 4
	cTarget = Repli(Chr(0), nBufsize)
	= UrlUnescape(cSource, @cTarget, @nBufsize, nFlag)
RETURN Left(cTarget, nBufsize)  
```  
***  


## Listed functions:
[UrlEscape](../libraries/shlwapi/UrlEscape.md)  
[UrlUnescape](../libraries/shlwapi/UrlUnescape.md)  
