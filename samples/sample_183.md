[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# URL: converting unsafe characters and spaces into escape sequences

## Before you begin:
Similar [example](sample_292.md) using UrlEscape and UrlUnescape functions.  
  
***  


## Code:
```foxpro  
#DEFINE ICU_BROWSER_MODE 0x2000000
#DEFINE ICU_DECODE 0x10000000
#DEFINE ICU_ENCODE_PERCENT 0x1000
#DEFINE ICU_ENCODE_SPACES_ONLY 0x4000000
#DEFINE ICU_ESCAPE 0x80000000
#DEFINE ICU_NO_ENCODE 0x20000000
#DEFINE ICU_NO_META 0x8000000
#DEFINE ICU_USERNAME 0x40000000

DECLARE INTEGER InternetCanonicalizeUrl IN wininet;
	STRING lpszUrl, STRING @lpszBuffer,;
	INTEGER @lpdwBufferLength, INTEGER dwFlags

LOCAL lcSource, lcTarget, lnResult
lcSource = "A rhyme: Jack and <Jill> went up a hill"
lnResult = 250
lcTarget = Repli (Chr(0), lnResult)

IF InternetCanonicalizeUrl (lcSource,;
	@lcTarget, @lnResult, ICU_BROWSER_MODE) <> 0

	? "Source:", lcSource
	? "Target:", Left(lcTarget, lnResult)
ENDIF  
```  
***  


## Listed functions:
[InternetCanonicalizeUrl](../libraries/wininet/InternetCanonicalizeUrl.md)  

***  

