[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

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

