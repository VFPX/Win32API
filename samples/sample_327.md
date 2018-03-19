[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Testing if a connection to an Url can be established

## Code:
```foxpro  
DECLARE INTEGER InternetCheckConnection IN wininet;
	STRING lpszUrl, INTEGER dwFlags, INTEGER dwReserved

#DEFINE FLAG_ICC_FORCE_CONNECTION  1

	= _check ("http://www.microsoft.com")
	= _check ("http://www.microsoft0.com")
	= _check ("http://fox.wikis.com/wc.dll?Wiki~FoxForumWiki")
	= _check ("http://www.universalthread.com/")
	= _check ("http://www.pinnaclepublishing.com/FT")
	= _check ("http://www.allapi.net/")
	= _check ("http://www.dotcomsolution.com/")
	= _check ("http://www.advisor.com/www/FoxProAdvisor")
	
	GO TOP
	BROWSE NORMAL NOWAIT

PROCEDURE _check(lcUrl)
	IF Not USED("csResult")
		CREATE CURSOR csResult (rslt L, url C(250))
	ENDIF
	
	LOCAL lResult
	lResult = (InternetCheckConnection(lcUrl, FLAG_ICC_FORCE_CONNECTION, 0)=1)
	INSERT INTO csResult VALUES (m.lResult, m.lcUrl)  
```  
***  


## Listed functions:
[InternetCheckConnection](../libraries/wininet/InternetCheckConnection.md)  

## Comment:
When you get 404 error page (invalid Url inside a valid domain) this function still returns True. The InternetGetConnectedState provide similar functionality.  
  
***  

