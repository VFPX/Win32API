[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Opening access to the Microsoft Internet functions for the application

## Code:
```foxpro  
#DEFINE INTERNET_OPEN_TYPE_PRECONFIG 0
#DEFINE INTERNET_OPEN_TYPE_DIRECT 1
#DEFINE INTERNET_OPEN_TYPE_PROXY 3
#DEFINE INTERNET_FLAG_ASYNC 0x10000000
#DEFINE INTERNET_FLAG_FROM_CACHE 0x1000000
#DEFINE INTERNET_FLAG_OFFLINE 0x1000000
#DEFINE INTERNET_FLAG_CACHE_IF_NET_FAIL 0x10000

DECLARE INTEGER InternetOpen IN wininet;
	STRING sAgent, INTEGER lAccessType,;
	STRING sProxyName, STRING sProxyBypass,;
	STRING lFlags
	
DECLARE INTEGER InternetCloseHandle IN wininet INTEGER hInet

sAgent = "w32inetopen"  && you can choose any name, say "John Dow"
sProxyName = Chr(0)     && no proxy
sProxyBypass = Chr(0)   && nothing to bypass
lFlags = 0              && no flags used

hOpen = InternetOpen(sAgent, INTERNET_OPEN_TYPE_DIRECT,;
	sProxyName, sProxyBypass, lFlags)

IF hOpen <> 0
* close the access
	? "Handle retrieved:", hOpen
	= InternetCloseHandle (hOpen)
ELSE
	? "Failed to access the WinINet library"
ENDIF  
```  
***  


## Listed functions:
[InternetCloseHandle](../libraries/wininet/InternetCloseHandle.md)  
[InternetOpen](../libraries/wininet/InternetOpen.md)  

## Comment:
Actually this code does nothing. It just shows how to put your hands on the Internet functions to access HTTP, FTP etc.  
  
***  

