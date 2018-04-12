[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Determining whether or not the system is connected to the Internet

## Before you begin:
See also:

* [How to ping a remote site using IP Helper API calls](sample_382.md)  
* [How to ping a remote site using ICMP API calls](sample_486.md)  
* [Function InternetAttemptConnect](../libraries/wininet/InternetAttemptConnect.md)

  
***  


## Code:
```foxpro  
DECLARE INTEGER InetIsOffline IN url INTEGER dwFlags

IF InetIsOffline(0) = 0
	? "The local system is connected to the Internet."
ELSE
	? "The local system is not currently connected to the Internet."
ENDIF  
```  
***  


## Listed functions:
[InetIsOffline](../libraries/urlmon/InetIsOffline.md)  
