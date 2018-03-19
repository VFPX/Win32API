[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Dial the Net Automatically

## Code:
```foxpro  
* Source: http://www.vb-world.net/tips/tip478.html
* Author: http://www.vb-world.net/php-bin/authorbio.php?
*         authorid=3&associd=478&assoctype=3

#DEFINE INTERNET_AUTODIAL_FORCE_ONLINE      1
#DEFINE INTERNET_AUTODIAL_FORCE_UNATTENDED  2

DECLARE INTEGER InternetAutodial IN wininet.dll;
	INTEGER dwFlags, INTEGER dwReserved

DECLARE INTEGER InternetAutodialHangup IN wininet.dll;
	INTEGER dwReserved

* To prompt the user to establish a Net connection
= InternetAutodial (INTERNET_AUTODIAL_FORCE_ONLINE, 0)

* To automatically start dialling
= InternetAutodial (INTERNET_AUTODIAL_FORCE_UNATTENDED, 0)

* To disconnect an automatically dialled connection
= InternetAutodialHangup(0)  
```  
***  


## Listed functions:
[InternetAutodial](../libraries/wininet/InternetAutodial.md)  
[InternetAutodialHangup](../libraries/wininet/InternetAutodialHangup.md)  

## Comment:
With my cable connection to the Net I have no chance to test this code. Have no dial-up modem either.  
  
*Whoever could test it, please let me know if any corrections needed to this code. *  
  
***  

