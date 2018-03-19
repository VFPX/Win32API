[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using InternetGoOnline function

## Code:
```foxpro  
DECLARE SHORT InternetGoOnline IN wininet.dll;
    	STRING  lpszURL,;
    	INTEGER hwndParent,;
    	INTEGER dwReserved

	DECLARE INTEGER GetActiveWindow IN user32
	
	hwnd = GetActiveWindow()
	lcUrl = "http://fox.wikis.com/wc.dll?Wiki~WinInet~WIN_COM_DNA"

	? InternetGoOnline (lcUrl, hwnd, 0)  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[InternetGoOnline](../libraries/wininet/InternetGoOnline.md)  

## Comment:
On my computer (cable Inet) this function always returns 1 as a response and nothing happens -- no dialog or message boxes appear.  
  
Probably with a dial-up access it would behave something different. Anyone who will try, please let me know.  
  
***  

