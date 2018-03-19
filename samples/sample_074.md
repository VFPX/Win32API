[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the rectangle area where the mouse cursor is confined

## Code:
```foxpro  
DECLARE INTEGER GetClipCursor IN user32 STRING @lpRect

* points to a RECT structure (four DWORDs - 16 bytes)
lpRect = REPLICATE(Chr(0), 16)
= GetClipCursor(@lpRect)
	
? "left:  ", buf2dword(SUBSTR(lpRect, 1,4))
? "top:   ", buf2dword(SUBSTR(lpRect, 5,4))
? "right: ", buf2dword(SUBSTR(lpRect, 9,4))
? "bottom:", buf2dword(SUBSTR(lpRect, 13,4))

? "SYSMETRIC():", SYSMETRIC(1), "x", SYSMETRIC(2)

FUNCTION buf2dword(cBuffer)
RETURN Asc(SUBSTR(cBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(cBuffer, 2,1)), 8) +;
	BitLShift(Asc(SUBSTR(cBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(cBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetClipCursor](../libraries/user32/GetClipCursor.md)  

## Comment:
In most cases the coordinates returned are the current display resolution.  
  
Use this function to save the original values before changing them.  
  
***  

