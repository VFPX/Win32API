<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : capCreateCaptureWindow
Group: Windows Multimedia - Library: avicap32    
***  


#### The capCreateCaptureWindow function creates a capture window.

***  


## Code examples:
[Using Video Capture: displaying on FoxPro form frames and previewing video obtained from a digital camera](../../samples/sample_437.md)  

## Declaration:
```foxpro  
HWND VFWAPI capCreateCaptureWindow(
  LPCSTR lpszWindowName,
  DWORD dwStyle,
  int x,
  int y,
  int nWidth,
  int nHeight,
  HWND hWnd,
  int nID
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER capCreateCaptureWindow IN avicap32;
	STRING lpszWindowName,;
	INTEGER dwStyle,;
	INTEGER x,;
	INTEGER y,;
	INTEGER nWidth,;
	INTEGER nHeight,;
	INTEGER hParent,;
	INTEGER nID  
```  
***  


## Parameters:
```txt  
lpszWindowName
Null-terminated string containing the name used for the capture window.

dwStyle
Window styles used for the capture window.

x
The x-coordinate of the upper left corner of the capture window.

y
The y-coordinate of the upper left corner of the capture window.

nWidth
Width of the capture window.

nHeight
Height of the capture window.

hWnd
Handle to the parent window.

nID
Window identifier.
  
```  
***  


## Return value:
Returns a handle of the capture window if successful or NULL otherwise.
  
***  


## Comments:
Use BITOR(WS_CHILD, WS_VISIBLE) for <Em>dwStyle</Em> parameter. The class name for the window created with this function is usually ClsCapWin.  
  
See also: CreateWindowEx, DestroyWindow   
  
***  

