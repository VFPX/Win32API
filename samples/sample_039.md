[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using GetSysColor

## Code:
```foxpro  
#DEFINE COLOR_SCROLLBAR      0
#DEFINE COLOR_ACTIVECAPTION  2
#DEFINE COLOR_WINDOW         5
#DEFINE COLOR_WINDOWFRAME    6
#DEFINE COLOR_MENUTEXT       7
#DEFINE COLOR_WINDOWTEXT     8

	DECLARE INTEGER GetSysColor IN "user32" INTEGER nIndex
	
	? GetSysColor (COLOR_SCROLLBAR)
	? GetSysColor (COLOR_ACTIVECAPTION)
	? GetSysColor (COLOR_WINDOW)
	? GetSysColor (COLOR_WINDOWFRAME)
	? GetSysColor (COLOR_MENUTEXT)
	? GetSysColor (COLOR_WINDOWTEXT)

	* actually, you can test the whole range
	FOR lnColor=0 TO 28
		? "System color ["
		?? lnColor
		?? "] = "
		?? GetSysColor (lnColor)
	ENDFOR  
```  
***  


## Listed functions:
[GetSysColor](../libraries/user32/GetSysColor.md)  

## Comment:
Some constants are not availble for Win9 or for WinNT  
  
***  

