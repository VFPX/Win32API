[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving various system metrics

## Code:
```foxpro  
#DEFINE SM_CXSCREEN 0
#DEFINE SM_CYSCREEN 1
#DEFINE SM_CYCAPTION 4
#DEFINE SM_CYMENU 15
#DEFINE SM_CXFULLSCREEN 16
#DEFINE SM_CYFULLSCREEN 17
#DEFINE SM_CXFRAME 32
#DEFINE SM_CYFRAME 33
#DEFINE SM_CMOUSEBUTTONS 43

	DECLARE INTEGER GetSystemMetrics IN user32 INTEGER nIndex
	
	= PrintLine("Screen width:                   ", SM_CXSCREEN)
	= PrintLine("Screen height:                  ", SM_CYSCREEN)
	= PrintLine("Full-screen client area width:  ", SM_CXFULLSCREEN)
	= PrintLine("Full-screen client area height: ", SM_CYFULLSCREEN)
	= PrintLine("Height of normal caption area:  ", SM_CYCAPTION)
	= PrintLine("Height of single-line menu bar: ", SM_CYMENU)
	= PrintLine("Resizable window frame width:   ", SM_CXFRAME)
	= PrintLine("Resizable window frame height:  ", SM_CYFRAME)
	= PrintLine("Number of mouse buttons:        ", SM_CMOUSEBUTTONS)

PROCEDURE PrintLine(cTitle, nMode)
	? cTitle
	?? GetSystemMetrics(nMode)  
```  
***  


## Listed functions:
[GetSystemMetrics](../libraries/user32/GetSystemMetrics.md)  

## Comment:
See also: SystemParametersInfo, <a href="http://msdn.microsoft.com/en-us/library/39ddf2h2(VS.80).aspx">SYSMETRIC</a>  
  
Obtains the screen resolution. Windows XP Mode in Windows 7 chops off two pixels from the screen height (SM_CYSCREEN).  
  
***  

