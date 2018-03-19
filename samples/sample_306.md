[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the IsWindowEnabled function

## Code:
```foxpro  
DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetDesktopWindow IN user32
	DECLARE INTEGER IsWindowEnabled IN user32 INTEGER hwnd

	? IsWindowEnabled (GetActiveWindow())  && main VFP window
	? IsWindowEnabled (GetDesktopWindow()) && Windows desktop  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[IsWindowEnabled](../libraries/user32/IsWindowEnabled.md)  
