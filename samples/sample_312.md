<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Initiating Inet connection using a modem

## Code:
```foxpro  
#DEFINE INTERNET_AUTODIAL_FORCE_ONLINE         1
#DEFINE INTERNET_AUTODIAL_FORCE_UNATTENDED     2
#DEFINE INTERNET_AUTODIAL_FAILIFSECURITYCHECK  4

DECLARE INTEGER GetActiveWindow IN user32

DECLARE INTEGER InternetDial IN wininet;
	INTEGER hwndParent, STRING lpszConnectoid, INTEGER dwFlags,;
    INTEGER @lpdwConnection, INTEGER dwReserved

LOCAL hConnection
hConnection = 0

? InternetDial (GetActiveWindow(), "MyProvider",;
	INTERNET_AUTODIAL_FORCE_ONLINE, @hConnection, 0)

? "Number associated with the connection:", hConnection  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[InternetDial](../libraries/wininet/InternetDial.md)  
