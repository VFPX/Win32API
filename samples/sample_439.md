[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Joining local computer to a domain (XP/2000)

## Code:
```foxpro  
#DEFINE NETSETUP_JOIN_DOMAIN 1
#DEFINE NETSETUP_DOMAIN_JOIN_IF_JOINED 0x0020
#DEFINE NERR_Success 0
DO decl

LOCAL cServer, cDomain, cAccount, cPwd, nOptions, nResult
cServer = Null
cDomain = sconv("MYDOMAIN")
cAccount = sconv("MYSERVER\TheUser")
cPwd = sconv("mypassword")

*nOptions = NETSETUP_JOIN_DOMAIN + NETSETUP_DOMAIN_JOIN_IF_JOINED
nOptions = NETSETUP_JOIN_DOMAIN

nResult = NetJoinDomain(cServer, cDomain, Null,;
	cAccount, cPwd, nOptions)
	
IF nResult <> NERR_Success
* 5=ERROR_ACCESS_DENIED
* 1323=ERROR_WRONG_PASSWORD
* 1355=The specified domain either does not exist...
* 2691=This machine is already joined a domain
* 2698=This version of Windows cannot be joined to domain
* 9560=DNS name contains an invalid character
	? "Error code:", nResult
ELSE
	? "Joined to domain successfully..."
	? "NetUnjoinDomain:", NetUnjoinDomain(cServer, cAccount, cPwd, 0)
ENDIF
* end of main

FUNCTION sconv(cStr)
RETURN STRCONV(cStr+CHR(0),5)

PROCEDURE decl
	DECLARE INTEGER NetJoinDomain IN netapi32;
		STRING lpServer, STRING lpDomain, STRING lpAccountOU,;
		STRING lpAccount, STRING lpPassword, INTEGER fJoinOptions

	DECLARE INTEGER NetUnjoinDomain IN netapi32;
		STRING lpServer, STRING lpAccount,;
		STRING lpPassword, INTEGER fUnjoinOptions  
```  
***  


## Listed functions:
[NetJoinDomain](../libraries/netapi32/NetJoinDomain.md)  
[NetUnjoinDomain](../libraries/netapi32/NetUnjoinDomain.md)  

## Comment:
Joining (and unjoining) a computer to a domain or workgroup can be performed only by a member of the Administrators local group on the target computer.  
  
***  

