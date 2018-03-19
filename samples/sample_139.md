[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Hiding mouse cursor

## Code:
```foxpro  
DECLARE INTEGER ShowCursor IN user32 INTEGER bShow

PROCEDURE _hide
	DO WHILE ShowCursor(0) >= -1
		DOEVENTS
	ENDDO

PROCEDURE _show
	DO WHILE ShowCursor(1) < 0
		DOEVENTS
	ENDDO  
```  
***  


## Listed functions:
[ShowCursor](../libraries/user32/ShowCursor.md)  

## Comment:
In Visual FoxPro the SET MOUSE setting is ignored. VFP8 often restores hidden mouse cursor automatically. So this API function may not be useful. The MousePointer property, that applies to many VFP controls including the Form, hides the pointer when set to 13  
  
***  

