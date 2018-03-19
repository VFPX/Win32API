[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving long values associated with the class of the VFP window

## Code:
```foxpro  
DO decl

#DEFINE GCW_ATOM           -32
#DEFINE GCL_CBCLSEXTRA     -20
#DEFINE GCL_CBWNDEXTRA     -18
#DEFINE GCL_HBRBACKGROUND  -10
#DEFINE GCL_HCURSOR        -12
#DEFINE GCL_HICON          -14
#DEFINE GCL_HICONSM        -34
#DEFINE GCL_HMODULE        -16
#DEFINE GCL_MENUNAME        -8
#DEFINE GCL_STYLE          -26
#DEFINE GCL_WNDPROC        -24

LOCAL hwnd
hwnd = GetActiveWindow()

? "Atom value:         ", GetClassLong (hwnd, GCW_ATOM)
? "Extra memory, bytes:", GetClassLong (hwnd, GCL_CBCLSEXTRA)
? "Extra window memory:", GetClassLong (hwnd, GCL_CBWNDEXTRA)
? "Bkgr brush handle:  ", GetClassLong (hwnd, GCL_HBRBACKGROUND)
? "Cursor handle:      ", GetClassLong (hwnd, GCL_HCURSOR)
? "Icon handle:        ", GetClassLong (hwnd, GCL_HICON)
? "Small icon handle:  ", GetClassLong (hwnd, GCL_HICONSM)
? "Module handle:      ", GetClassLong (hwnd, GCL_HMODULE)
? "Menu string addr:   ", GetClassLong (hwnd, GCL_MENUNAME)
? "Window-class style: ", GetClassLong (hwnd, GCL_STYLE)
? "Window procedure:   ", GetClassLong (hwnd, GCL_WNDPROC)


PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetClassLong IN user32 INTEGER hWnd, INTEGER nIdx  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClassLong](../libraries/user32/GetClassLong.md)  
