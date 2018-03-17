<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Retrieving the elapsed time since the system was started

## Code:
```foxpro  
DECLARE INTEGER GetTickCount IN kernel32.dll
	lnSeconds = GetTickCount() / 1000

	lnHours = INT (lnSeconds/3600)
	lnSeconds = lnSeconds - lnHours * 3600
	
	lnMinutes = INT (lnSeconds/60)
	lnSeconds = lnSeconds - lnMinutes * 60
	
	? "Time since the restart: "
	?? STRTRAN (STR(lnHours,2) + ":" + STR(lnMinutes,2) + ":";
		+ STR(lnSeconds,2), " ","0")  
```  
***  


## Listed functions:
[GetTickCount](../libraries/kernel32/GetTickCount.md)  
