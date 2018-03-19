[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Time in milliseconds represented as string (e.g. 1 hour 24 min 36 sec)

## Code:
```foxpro  
DECLARE INTEGER StrFromTimeInterval IN Shlwapi;
	STRING @ pszOut,;
   	INTEGER  cchMax,;
   	INTEGER  dwTimeMS,;
	INTEGER  digits

DECLARE INTEGER GetTickCount IN kernel32

lnFromStart = GetTickCount()
? "Elapsed time since the system was started:", lnFromStart

pszOut = SPACE(50)
FOR lnMax=1 TO 10
	lnLen = StrFromTimeInterval (@pszOut, Len(pszOut), lnFromStart, lnMax)
	? LEFT (pszOut, lnLen)
ENDFOR  
```  
***  


## Listed functions:
[GetTickCount](../libraries/kernel32/GetTickCount.md)  
[StrFromTimeInterval](../libraries/shlwapi/StrFromTimeInterval.md)  
