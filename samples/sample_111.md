[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving information about the main VFP window

## Code:
```foxpro  
#DEFINE GWL_WNDPROC -4
#DEFINE GWL_HINSTANCE -6
#DEFINE GWL_HWNDPARENT -8
#DEFINE GWL_STYLE -16
#DEFINE GWL_EXSTYLE -20
#DEFINE GWL_USERDATA -21
#DEFINE GWL_ID -12

DO declare

LOCAL hWindow
hWindow = GetActiveWindow()

? "Window procedure:", GetWindowLong (m.hWindow, GWL_WNDPROC)
? "Application instance:", GetWindowLong (m.hWindow, GWL_HINSTANCE)
? "Parent window:", GetWindowLong (m.hWindow, GWL_HWNDPARENT)
? "Window styles:", GetWindowLong (m.hWindow, GWL_STYLE)
? "Extended window styles:", GetWindowLong (m.hWindow, GWL_EXSTYLE)
? "User data associated:", GetWindowLong (m.hWindow, GWL_USERDATA)
? "Identifier of the window:", GetWindowLong (m.hWindow, GWL_ID)
? "Class name:", GetClsName(m.hWindow)
?

? "*** Application handle returned by:"
? "    GetModuleHandle:", GetModuleHandle(NULL)
? "    GetWindowLong:", GetWindowLong (m.hWindow, GWL_HINSTANCE)
?

* E_MAGIC
* the GetModuleHandle actually returns the address
* the executable is mapped into memory
LOCAL hModule, cBuffer
hModule = GetModuleHandle(NULL)
cBuffer = REPLICATE(CHR(0),2)
= MemToStr(@cBuffer, hModule, LEN(cBuffer))

* as you may expect, the signature is "MZ",
* the initials of Mark Zbikowski, one of the original architects of MS-DOS.
? "MS-DOS signature:", cBuffer

* end of main

FUNCTION GetClsName(hWindow)
    LOCAL nBufsize, cBuffer
    cBuffer = Repli(Chr(0), 250)
    nBufsize = GetClassName(hWindow, @cBuffer, Len(cBuffer))
RETURN SUBSTR(cBuffer, 1, nBufsize)

PROCEDURE declare
	DECLARE INTEGER GetModuleHandle IN kernel32 STRING @lpModuleName
	DECLARE INTEGER GetActiveWindow IN user32

    DECLARE INTEGER GetClassName IN user32;
        INTEGER hWnd, STRING lpClassName, INTEGER nMaxCount

	DECLARE INTEGER GetWindowLong IN user32;
		INTEGER hWindow, INTEGER nIndex

	DECLARE RtlMoveMemory IN kernel32 As MemToStr;
		STRING @dst, INTEGER src, INTEGER nLength  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClassName](../libraries/user32/GetClassName.md)  
[GetModuleHandle](../libraries/kernel32/GetModuleHandle.md)  
[GetWindowLong](../libraries/user32/GetWindowLong.md)  

## Comment:
Recommended reading:  
[An In-Depth Look into the Win32 Portable Executable File Format](http://bytepointer.com/resources/pietrek_in_depth_look_into_pe_format_pt1.htm) by Matt Pietrek  
  
***  

