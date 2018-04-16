[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Managing Cookies

## Code:
```foxpro  
DO declare

LOCAL lcUrl, lcCookieName, lcCookieData, lnLen
lcUrl = "https://github.com/VFPX/Win32API"
lcCookieName = "user settings"
lcCookieData = "regular,54,126,-1,0"
	
*	= AddPersistentCookie(lcUrl, lcCookieName,;
		lcCookieData, date()+2)

	? "Cookie:", ReadCookie(lcUrl, lcCookieName)

*	= DeleteCookie(lcUrl, lcCookieName)
*	? ReadCookie(lcUrl, lcCookieName)
	
FUNCTION ReadCookie(lcUrl, lcCookieName)
	LOCAL lcCookieData, lnLen, lcResult
	lnLen = 4096
	lcCookieData = SPACE(lnLen)
	lcResult = ""

	IF InternetGetCookie(lcUrl, lcCookieName, @lcCookieData, @lnLen) <> 0
		lcResult = LEFT(lcCookieData, lnLen-1)
	ELSE
	* 259 = No more data is available
	ENDIF
RETURN lcResult

PROCEDURE AddSessionCookie(lcUrl, lcCookieName, lcCookieData)
* Session cookies are stored in memory and can be accessed
* only by the process that created them.
	= InternetSetCookie(lcUrl, lcCookieName, lcCookieData)

PROCEDURE AddPersistentCookie(lcUrl, lcCookieName, lcCookieData, lvExpires)
* Persistent cookies are cookies that have an expiration date.
* These cookies are stored in the Windows\System directory.
	= InternetSetCookie(lcUrl, lcCookieName,;
		lcCookieData + ";expires=" + toGMTString(lvExpires))

PROCEDURE DeleteCookie(lcUrl, lcCookieName)
* To delete a persistent cookie you must set its expiry date
* to a time that has already expired.
* Usually it keeps staying as a session cookie after being deleted

	= AddPersistentCookie(lcUrl, lcCookieName,;
		"", date()-1)

FUNCTION toGMTString(ltDate)
* returns datetime formatted as DAY, DD-MMM-YYYY HH:MM:SS GMT
RETURN SUBSTR("SunMonTueWedThuFriSat",;
		(DOW(ltDate,1)-1)*3+1, 3) + ", " +;
	STRTR(STR(Day(ltDate), 2), " ","0") + "-" +;
	SUBSTR("JanFebMarAprMayJunJulAugSepOctNovDec",;
		(MONTH(ltDate)-1)*3+1, 3) + "-" +;
	STR(YEAR(ltDate),4) + " " +;
	STRTR(STR(HOUR(ltDate), 2), " ","0") + ":" +;
	STRTR(STR(MINUTE(ltDate), 2), " ","0") + ":" +;
	STRTR(STR(SEC(ltDate), 2), " ","0") + " GMT"

PROCEDURE declare
	DECLARE INTEGER InternetGetCookie IN wininet;
		STRING lpszUrlName, STRING lpszCookieName,;
		STRING @lpszCookieData, INTEGER @lpdwSize

	DECLARE INTEGER InternetSetCookie IN wininet;
		STRING lpszUrl, STRING lpszCookieName,;
		STRING lpszCookieData  
```  
***  


## Listed functions:
[InternetGetCookie](../libraries/wininet/InternetGetCookie.md)  
[InternetSetCookie](../libraries/wininet/InternetSetCookie.md)  

## Comment:
  
  
***  

