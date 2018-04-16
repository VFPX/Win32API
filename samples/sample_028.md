[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Testing Clipboard functions: emptying the clipboard

## Code:
```foxpro  
DECLARE INTEGER EmptyClipboard IN user32
DECLARE INTEGER GetActiveWindow IN user32
DECLARE INTEGER CloseClipboard IN user32
DECLARE INTEGER OpenClipboard IN user32 INTEGER hwnd
	
IF OpenClipboard(GetActiveWindow()) <> 0
	= EmptyClipboard()
	= CloseClipboard()  && important
ENDIF  
```  
***  


## Listed functions:
[CloseClipboard](../libraries/user32/CloseClipboard.md)  
[EmptyClipboard](../libraries/user32/EmptyClipboard.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[OpenClipboard](../libraries/user32/OpenClipboard.md)  

## Comment:
The operation above can be done with much less trouble in VFP code:  
```foxpro
_cliptext=""
```
 
  
***  

