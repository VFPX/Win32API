[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the state of your Internet connection

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

<!-- Anatoliy --> 
## Before you begin:
<table cellspacing=3 cellpadding=0 border=0><tr><td valign=top><img src="../images/readarticle.gif" border=0></td><td valign=top class=fdescr><a href="?article=3">Programming File Transfer Protocol in Visual FoxPro </a></td></tr></table>  

  
***  

## Code:
```foxpro  
#DEFINE INTERNET_CONNECTION_MODEM        1
#DEFINE INTERNET_CONNECTION_LAN          2
#DEFINE INTERNET_CONNECTION_PROXY        4
#DEFINE INTERNET_CONNECTION_MODEM_BUSY   8
#DEFINE INTERNET_RAS_INSTALLED          16
#DEFINE INTERNET_CONNECTION_OFFLINE     32
#DEFINE INTERNET_CONNECTION_CONFIGURED  64

	DECLARE SHORT InternetGetConnectedState IN wininet.dll;
		INTEGER @lpdwFlags, INTEGER dwReserved

	DECLARE SHORT InternetGetConnectedStateEx IN wininet.dll;
    	INTEGER @lpdwFlags, STRING @lpszConnectionName,;
    	INTEGER dwNameLen, INTEGER dwReserved

	DO displayState
	DO displayStateEx
RETURN

PROCEDURE  displayState
	? "*** InternetGetConnectedState:"
	lpdwFlags = 0
	IF InternetGetConnectedState (@lpdwFlags, 0) = 1
		? "  Flags returned:       " +;
			LTRIM(STR(lpdwFlags))

		? "  Modem connection:     " +;
			_ok(lpdwFlags, INTERNET_CONNECTION_MODEM)

		? "  LAN connection:       " +;
			_ok(lpdwFlags, INTERNET_CONNECTION_LAN)

		? "  Proxy connection:     " +;
			_ok(lpdwFlags, INTERNET_CONNECTION_PROXY)

		? "  The modem is busy:    " +;
			_ok(lpdwFlags, INTERNET_CONNECTION_MODEM_BUSY)

		? "  The RAS is installed: " +;
			_ok(lpdwFlags, INTERNET_RAS_INSTALLED)

		? "  Offline connection:   " +;
			_ok(lpdwFlags, INTERNET_CONNECTION_OFFLINE)

		? "  Is configured:        " +;
			_ok(lpdwFlags, INTERNET_CONNECTION_CONFIGURED)
	ELSE
		? "InternetGetConnectedState error"
	ENDIF
RETURN

PROCEDURE  displayStateEx
* the same as the regular one except the connection name is returned
	?
	? "*** InternetGetConnectedStateEx:"
	lpdwFlags = 0
	lcConnection = REPLI (Chr(0), 250)
	IF InternetGetConnectedStateEx (@lpdwFlags,;
		@lcConnection, Len(lcConnection), 0) = 1

		? "  Flags returned:       " + LTRIM(STR(lpdwFlags))
		? "  Connection name: " +;
			SUBSTR (lcConnection, 1, AT(Chr(0), lcConnection)-1)
	ELSE
		? "InternetGetConnectedStateEx error"
	ENDIF
RETURN

FUNCTION  _ok (lnBase, lnValue)
RETURN  Iif(BitAnd(lnBase, lnValue)=lnValue, "Yes","No")  
```  
***  


## Listed functions:
[InternetGetConnectedState](../libraries/wininet/InternetGetConnectedState.md)  
[InternetGetConnectedStateEx](../libraries/wininet/InternetGetConnectedStateEx.md)  

## Comment:
Remote Access Service (RAS) provides remote access capabilities to client applications on computers using Microsoft&reg; Windows&reg; 95 or later and Windows NT&reg; version 3.5 and later, including Windows 2000, operating systems.   
  
***  

