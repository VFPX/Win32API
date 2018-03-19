[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

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
