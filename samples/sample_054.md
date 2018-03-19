[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Setting and retrieving the double-click time for the mouse

## Code:
```foxpro  
DO declare

LOCAL nTime

nTime = GetDoubleClickTime()
? "Double click time:", nTime, "msec"

* passing zero is equivalent to setting this parameter
* to OS default value
* which is usually 500 milliseconds

*= SetDoubleClickTime(0)

* end of main

PROCEDURE declare
	DECLARE INTEGER SetDoubleClickTime IN user32;
		INTEGER wCount

	DECLARE INTEGER GetDoubleClickTime IN user32  
```  
***  


## Listed functions:
[GetDoubleClickTime](../libraries/user32/GetDoubleClickTime.md)  
[SetDoubleClickTime](../libraries/user32/SetDoubleClickTime.md)  

## Comment:
When setting double-click time to zero, the system uses the default double-click time of 500 milliseconds  
  
***  

