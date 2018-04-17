[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# The DetectAutoProxyUrl function identifies the auto-config script location

## Before you begin:
  
Internet Explorer has an **[x] Automatically detect settings** check box. This will cause the browser to search for the configuration file.   

If your *DomainName* is **machine.something.meta.net.nz** then InternetExplorer will request the following urls until it finds a WPAD configuration file.   
  
```txt
http://wpad.something.meta.net.nz/wpad.dat   
http://wpad.meta.net.nz/wpad.dat   
http://wpad.net.nz/wpad.dat   
http://wpad.nz/wpad.dat
```

WPAD stands for *Web Proxy Auto-Discovery*.   
  
***  


## Code:
```foxpro  
DO decl

LOCAL lcRmScript, lcLocal
lcRmScript = Repli(Chr(0), 250)

* dwDetectFlags = 1, 2
* PROXY_AUTO_DETECT_TYPE_DHCP
* PROXY_AUTO_DETECT_TYPE_DNS_A
IF DetectAutoProxyUrl(@lcRmScript, Len(lcRmScript), 2) = 0
	WAIT WINDOW NOWAIT "Not detected. "
	RETURN
ENDIF

lcRmScript = STRTRAN(lcRmScript, Chr(0), "")

IF Not EMPTY(lcRmScript)
	= MessageB("Location of a WPAD autoproxy script:     " +;
		Chr(13)+Chr(13) + lcRmScript, 64, " DetectAutoProxyUrl")

	WAIT WINDOW NOWAIT "Donwloading from URL... "
	lcLocal = SYS(2003) + "\autoscript.txt"
	URLDownloadToFile(0, lcRmScript, lcLocal, 0,0)
	WAIT WINDOW NOWAIT "Downloaded from " + lcRmScript + "   "

	IF FILE(lcLocal)
		MODI FILE (lcLocal) NOMODI NOWAIT
	ENDIF
ENDIF
* end of main

PROCEDURE decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER DetectAutoProxyUrl IN wininet;
		STRING @lpszAutoProxyUrl, LONG dwAutoProxyUrlLength,;
		LONG dwDetectFlags

	DECLARE INTEGER URLDownloadToFile IN urlmon;
		INTEGER pCaller, STRING szURL, STRING szFileName,;
		INTEGER dwReserved, INTEGER lpfnCB  
```  
***  


## Listed functions:
[DetectAutoProxyUrl](../libraries/wininet/DetectAutoProxyUrl.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[URLDownloadToFile](../libraries/urlmon/URLDownloadToFile.md)  

## Comment:
An example of WPAD.DAT file:  
  
```csharp
function FindProxyForURL(url, host)  
{  
	// We only cache http and ftp  
	if (url.substring(0, 5) == "http:" || url.substring(0, 4) == "ftp:")  
		return "PROXY cache:8080; DIRECT";  
  
	// Otherwise use direct connection  
	return "DIRECT";  
}
```

***  

