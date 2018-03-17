<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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

