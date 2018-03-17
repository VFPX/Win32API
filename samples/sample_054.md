<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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

