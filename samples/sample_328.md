[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting an HTTP time/date string to a SYSTEMTIME structure

## Code:
```foxpro  
*|typedef struct _SYSTEMTIME {
*|    WORD wYear;
*|    WORD wMonth;
*|    WORD wDayOfWeek;
*|    WORD wDay;
*|    WORD wHour;
*|    WORD wMinute;
*|    WORD wSecond;
*|    WORD wMilliseconds;
*|} SYSTEMTIME, *PSYSTEMTIME; -> 16 bytes

#DEFINE INTERNET_RFC1123_FORMAT   0
#DEFINE INTERNET_RFC1123_BUFSIZE  30

DECLARE INTEGER InternetTimeToSystemTime IN wininet;
	STRING lpszTime, STRING @pst, INTEGER dwReserved

DECLARE INTEGER InternetTimeFromSystemTime IN wininet;
	STRING @pst, INTEGER dwRFC, STRING @lpszTime, INTEGER cbTime

PRIVATE lcSysTime, lcTime
lcSysTime = Repli(Chr(0), 16) && SYSTEMTIME
lcTime = "Fri, 09 Aug 2002 22:50:54 +0300"

= InternetTimeToSystemTime(lcTime, @lcSysTime, 0)

? lcTime
?
? "Year, Month, DOW, Day, Hour, Minute:",;
	GetWord(1), GetWord(3), GetWord(5), GetWord(7),;
	GetWord(9), GetWord(11)
?

* converting backwards
LOCAL lcInetTime
lcInetTime = Repli(Chr(0), INTERNET_RFC1123_BUFSIZE)
= InternetTimeFromSystemTime(@lcSysTime, INTERNET_RFC1123_FORMAT,;
	@lcInetTime, INTERNET_RFC1123_BUFSIZE)

lcInetTime = STRTRAN(lcInetTime, Chr(0),"")
? "Re-converted:", lcInetTime
* end of main

FUNCTION GetWord(lnOffs)
RETURN buf2word(SUBSTR(lcSysTime, lnOffs,2))

FUNCTION buf2word (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256  
```  
***  


## Listed functions:
[InternetTimeFromSystemTime](../libraries/wininet/InternetTimeFromSystemTime.md)  
[InternetTimeToSystemTime](../libraries/wininet/InternetTimeToSystemTime.md)  

***  

