<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Retrieving the System Time adjustment

## Code:
```foxpro  
DECLARE INTEGER GetLastError IN kernel32

	DECLARE SHORT GetSystemTimeAdjustment IN kernel32.dll;
		INTEGER @ lpTimeAdjustment,;
		INTEGER @ lpTimeIncrement,;
		SHORT   @ lpTimeAdjustmentDisabled

	STORE 0 TO lpTimeAdjustment, lpTimeIncrement,;
		lpTimeAdjustmentDisabled

	IF GetSystemTimeAdjustment (@lpTimeAdjustment,;
		@lpTimeIncrement, @lpTimeAdjustmentDisabled) = 1

		? "The time adjustment is: " +;
			Iif(lpTimeAdjustmentDisabled=0, "ENABLED", "disabled")
		?
		? "The number of 100-nanosecond units "
		? "added to the time-of-day clock "
		? "at each periodic time adjustment: "
		?? lpTimeAdjustment
		?
		? "The interval, "
		? "counted in 100-nanosecond units, "
		? "between periodic time adjustments: "
		?? lpTimeIncrement
	ELSE
		? "GetSystemTimeAdjustment calling error: "
		?? GetLastError()
	ENDIF  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetSystemTimeAdjustment](../libraries/kernel32/GetSystemTimeAdjustment.md)  

## Comment:
WinNT only. This function is not supported under Win9*  
  
***  

