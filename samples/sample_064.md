[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# System and Local Time values

## Code:
```foxpro  
DECLARE GetSystemTime IN kernel32 STRING @ lpSystemTime
	DECLARE GetLocalTime  IN kernel32 STRING @ lpSystemTime

*| typedef struct _SYSTEMTIME {
*|	 WORD wYear;
*|	 WORD wMonth;
*|	 WORD wDayOfWeek;
*|	 WORD wDay;
*|	 WORD wHour;
*|	 WORD wMinute;
*|	 WORD wSecond;
*|	 WORD wMilliseconds;
*| } SYSTEMTIME, *PSYSTEMTIME; -> 16 bytes

	lcTimeBuffer = REPLI (Chr(0), 16)  && SYSTEMTIME structure
	= GetSystemTime (@lcTimeBuffer)
	? "GetSystemTime(): ", _systemtime(lcTimeBuffer)
	
	lcTimeBuffer = REPLI (Chr(0), 16)  && SYSTEMTIME structure
	= GetLocalTime (@lcTimeBuffer)
	? "GetLocalTime():  ", _systemtime(lcTimeBuffer)

	? "VFP DateTime():  ", DATETIME()
RETURN

FUNCTION  _systemtime (lcBuffer)
	wYear   = buf2word (SUBSTR(lcBuffer,  1, 2))
	wMonth  = buf2word (SUBSTR(lcBuffer,  3, 2))
	wDay	= buf2word (SUBSTR(lcBuffer,  7, 2))
	wHour   = buf2word (SUBSTR(lcBuffer,  9, 2))
	wMinute = buf2word (SUBSTR(lcBuffer, 11, 2))
	wSecond = buf2word (SUBSTR(lcBuffer, 13, 2))

	lcStoredSet = SET ("DATE")
	SET DATE TO MDY

	lcDate = STRTRAN (STR(wMonth,2) + "/" + STR(wDay,2) +;
		"/" + STR(wYear,4), " ","0")

	lcTime = STRTRAN (STR(wHour,2) + ":" + STR(wMinute,2) +;
		":" + STR(wSecond,2), " ","0")

	ltResult = CTOT (lcDate + " " + lcTime)
	SET DATE TO &lcStoredSet
RETURN  ltResult

FUNCTION  buf2word (lcBuffer)
RETURN;
	Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256
ENDFUNC  
```  
***  


## Listed functions:
[GetLocalTime](../libraries/kernel32/GetLocalTime.md)  
[GetSystemTime](../libraries/kernel32/GetSystemTime.md)  

## Comment:
GetSystemTim rerturns  the UTC (Coordinated Universal Time) value.  
  
* * *  
WMI Time classes are supported on WinXP/2003/Vista systems. On Win2K you can still get the system time by querying the Win32_OperatingSystem class and checking the value of the LocalDateTime property.  
  
***  

