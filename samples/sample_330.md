<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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
