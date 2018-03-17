<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Determining whether or not the system is connected to the Internet

## Before you begin:
See also:

* [How to ping a remote site using IP Helper API calls](sample_382.md)  
* [How to ping a remote site using ICMP API calls](sample_486.md)  
* InternetAttemptConnect function  

  
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
