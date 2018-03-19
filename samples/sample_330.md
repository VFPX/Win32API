[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# List of addresses in the AutoDial mapping database

## Code:
```foxpro  
DECLARE INTEGER RasEnumAutodialAddresses IN rasapi32;
	STRING @lppAddresses, INTEGER @lpdwcbAddresses, INTEGER @lpdwcAddresses

LOCAL lcBuffer, lnBufsize, lnCount

STORE 0 TO lnBufsize, lnCount
lnBufsize = 16384
lcBuffer = Repli(Chr(0), lnBufsize)

= RasEnumAutodialAddresses (@lcBuffer, @lnBufsize, @lnCount)

IF lnCount = 0
	? "AutoDial mapping database is empty"
ENDIF  
```  
***  


## Listed functions:
[RasEnumAutodialAddresses](../libraries/rasapi32/RasEnumAutodialAddresses.md)  
