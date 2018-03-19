[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Determining if an Active Network Connection is Available

## Code:
```foxpro  
#DEFINE NETWORK_ALIVE_LAN 1
#DEFINE NETWORK_ALIVE_WAN 2
#DEFINE NETWORK_ALIVE_AOL 4

DECLARE INTEGER IsNetworkAlive IN sensapi INTEGER @lpdwFlags
DECLARE INTEGER GetLastError IN kernel32

LOCAL lnMode
lnMode = 0
IF IsNetworkAlive(@lnMode) = 0
	? "Error code: ", GetLastError()
ELSE
	? "The computer has one or more LAN cards that are active:",;
		(lnMode=NETWORK_ALIVE_LAN)

	? "The computer has one or more active RAS connections:",;
		(lnMode=NETWORK_ALIVE_WAN)

	* Win95, Win98 only
	? "The computer is connected to the America Online network:",;
		(lnMode=NETWORK_ALIVE_AOL)
ENDIF  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[IsNetworkAlive](../libraries/sensapi/IsNetworkAlive.md)  

## Comment:
Check similar VB example <a href="http://www.mvps.org/vbnet/index.html?code/network/isnetworkalive.htm">"Determining if an Active Network Connection is Available"</a> at  the <a href="http://www.mvps.org/vbnet/">VBNet</a>.  
  
***  

