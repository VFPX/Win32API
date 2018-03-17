<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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

