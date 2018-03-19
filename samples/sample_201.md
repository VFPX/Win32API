[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving Window Class information for the VFP window

## Code:
```foxpro  
DO decl

LOCAL hWnd, lcClassName, hInstance, lcWndClass,;
	lcClassNameRet, lcMenuNameRet

STORE SPACE(250) TO lcClassNameRet, lcMenuNameRet

hWnd = GetActiveWindow()
lcClassName = GetClsName (hWnd)
hInstance = GetModuleHandle(0)

? "*** Input parameters"
? "Class name retrieved through the GetClassName:", lcClassName
? "Module handle:", hInstance
?

*| typedef struct _WNDCLASS {
*|     UINT       style;           0:4
*|     WNDPROC    lpfnWndProc;     4:4
*|     int        cbClsExtra;      8:4
*|     int        cbWndExtra;     12:4
*|     HINSTANCE  hInstance;      16:4
*|     HICON      hIcon;          20:4
*|     HCURSOR    hCursor;        24:4
*|     HBRUSH     hbrBackground;  28:4
*|     LPCTSTR    lpszMenuName;   32:4
*|     LPCTSTR    lpszClassName;  36:4
*| } WNDCLASS, *PWNDCLASS; total bytes: 40
#DEFINE WNDCLASS_SIZE  40

lcWndClass = Repli(Chr(0), WNDCLASS_SIZE)
= GetClassInfo (hInstance, lcClassName, @lcWndClass)

* While tested under VFP6+WinMe:
* Have fun: there is no guarantee for you to get the Class and Menu names back;
* despite of the GetClassInfo returns the proper pointers to
* corresponding memory blocks -- lpszMenuName and lpszClassName

* quite often the VFP has its time and inspiration to fill these memory blocks
* with some other stuff within a jiffy before or after the GetClassInfo
* finishes and returns control to the program; at least it looks like it does;

* switch between Try A and Try B -- you could find them returning different
* results, despite their identity; sometimes even Try A returns a garbage

* Try A:
= FillBuffer (@lcClassNameRet, buf2dword(SUBSTR(lcWndClass, 37,4)))
= FillBuffer (@lcMenuNameRet, buf2dword(SUBSTR(lcWndClass, 33,4)))

? "*** Output from the GetClassInfo"
? "Style:        ", buf2dword(SUBSTR(lcWndClass,  1,4))
? "lpfnWndProc:  ", buf2dword(SUBSTR(lcWndClass,  5,4))
? "cbClsExtra:   ", buf2dword(SUBSTR(lcWndClass,  9,4))
? "cbWndExtra:   ", buf2dword(SUBSTR(lcWndClass, 13,4))
? "hInstance:    ", buf2dword(SUBSTR(lcWndClass, 17,4))
? "hIcon:        ", buf2dword(SUBSTR(lcWndClass, 21,4))
? "hCursor:      ", buf2dword(SUBSTR(lcWndClass, 25,4))
? "hbrBackground:", buf2dword(SUBSTR(lcWndClass, 29,4))
? "lpszMenuName: ", buf2dword(SUBSTR(lcWndClass, 33,4))
? "lpszClassName:", buf2dword(SUBSTR(lcWndClass, 37,4))
?

* Try B:
*= FillBuffer (@lcClassNameRet, buf2dword(SUBSTR(lcWndClass, 37,4)))
*= FillBuffer (@lcMenuNameRet, buf2dword(SUBSTR(lcWndClass, 33,4)))

? "Class name:   ", lcClassNameRet
? "Menu name:    ", lcMenuNameRet

PROCEDURE  FillBuffer (lcBuffer, lnPtr)
	IF lnPtr = 0
		lcBuffer = ""
	ELSE
		= Heap2String (@lcBuffer, lnPtr, Len(lcBuffer))
		lcBuffer = SUBSTR(lcBuffer, 1, AT(Chr(0), lcBuffer)-1)
	ENDIF

FUNCTION  GetClsName (lnHwnd)
	LOCAL lnBufsize, lcClassName
	lnBufsize = 250
	lcClassName = SPACE(lnBufsize)
	lnBufsize = GetClassName (lnHwnd, @lcClassName, lnBufsize)
RETURN  SUBSTR(lcClassName, 1, lnBufsize)

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetModuleHandle IN kernel32 STRING lpModuleName

	DECLARE RtlMoveMemory IN kernel32 As Heap2String;
		STRING @Dest, INTEGER Src, INTEGER nLength

	DECLARE INTEGER GetClassName IN user32;
		INTEGER hWnd, STRING lpClassName, INTEGER nMaxCount

	DECLARE INTEGER GetClassInfo IN user32;
		INTEGER hInstance, STRING lpClassName, STRING @lpWndClass  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetClassInfo](../libraries/user32/GetClassInfo.md)  
[GetClassName](../libraries/user32/GetClassName.md)  
[GetModuleHandle](../libraries/kernel32/GetModuleHandle.md)  

## Comment:
**While tested under VFP6+WinMe:**  
  
Have fun: there is no guarantee for you to get the Class and Menu names back, despite of the GetClassInfo returns the proper pointers to corresponding memory blocks -- ***lpszMenuName*** and ***lpszClassName***.  
  
Quite often the VFP has its time and inspiration to fill these memory blocks with some other stuff within a jiffy before or after the GetClassInfo finishes and returns control to the program; at least it looks like it does.  
  
Switch between Try A and Try B -- you could find them returning different results, despite their identity; sometimes even Try A returns a garbage.  
  
* * *  
Having Microsoft Spy++ installed (included in all Visual Studio versions), you may want to spy on some VFP windows. For example, WAIT WINDOW window. Its window class is VFP664000002 for VFP6, vfp884000003 for VFP8 and vfp994000003 for VFP9. I have no data for other VFP versions.  
  
When FoxPro starts, it creates two or three windows of this class, all owned by the main VFP window, and hides them. Every time WAIT WINDOW command is issued, one more WW window is created, the only one visible. Eventually this window is destroyed as a result of WAIT CLEAR or keypress etc.  
  
Each WW window has separate device context, that means it is drawn separately. All of them share same WinProc. It is possible to use SetClassLong to change Window style for all eventually created WW windows.  
  
An instance of FoxPro Timer Control, when started, ticks behind a WAIT WINDOW, which opens possibilty for minor adjustments and pranks.  
  
***  

