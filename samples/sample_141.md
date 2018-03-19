[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Another way to go online (it is not about choosing an ISP)

## Code:
```foxpro  
DECLARE INTEGER InternetGoOnline IN wininet;
	STRING  lpszURL, INTEGER hwndParent,;
	INTEGER dwReserved

? InternetGoOnline ("http://www.microsoft.com", 0, 0)  
```  
***  


## Listed functions:
[InternetGoOnline](../libraries/wininet/InternetGoOnline.md)  

## Comment:
If you are in offline mode, this code prompts you for a permission to go online.  
  
If you are online, it is not necessarily that this code forwards you to the selected URL.  
  
***  

