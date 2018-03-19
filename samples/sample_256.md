[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Drawing a rectangle using Windows regular edges and borders

## Code:
```foxpro  
DO decl

* type of inner and outer edges (some of them)
#DEFINE BDR_RAISEDOUTER 1
#DEFINE BDR_SUNKENOUTER 2
#DEFINE BDR_RAISEDINNER 4
#DEFINE BDR_SUNKENINNER 8

* type of border (some of them)
#DEFINE BF_LEFT         1
#DEFINE BF_TOP          2
#DEFINE BF_RIGHT        4
#DEFINE BF_BOTTOM       8
#DEFINE BF_DIAGONAL    16
#DEFINE BF_SOFT      4096
#DEFINE BF_FLAT     16384

PRIVATE hWindow, hDC
hWindow = GetActiveWindow()
hDC = GetWindowDC(hWindow)

= _rect (BitOr(BDR_RAISEDINNER, BDR_RAISEDOUTER),;
	100, 100, 500, 350)

= _rect (BitOr(BDR_SUNKENINNER, BDR_SUNKENOUTER),;
	110, 110, 490, 340)

= ReleaseDC(hWindow, hDC)

FUNCTION  _rect (lnEdgeType, lnLeft, lnTop, lnRight, lnBottom)
* drawing a rectangle of a given edge type
	= _line(lnEdgeType, BF_TOP,    lnLeft, lnTop, lnRight, lnTop)
	= _line(lnEdgeType, BF_RIGHT,  lnRight, lnTop, lnRight, lnBottom)
	= _line(lnEdgeType, BF_BOTTOM, lnLeft, lnBottom, lnRight, lnBottom)
	= _line(lnEdgeType, BF_LEFT,   lnLeft, lnTop, lnLeft, lnBottom)
RETURN

FUNCTION  _line
LPARAMETERS lnEdgeType, lnBorderType, lnLeft, lnTop, lnRight, lnBottom
* drawing a line of given edge and border types
	LOCAL hlcBuffer
	lcBuffer = num2dword(lnLeft) + num2dword(lnTop) +;
		num2dword(lnRight) + num2dword(lnBottom)

	= DrawEdge(hDC, @lcBuffer, lnEdgeType, lnBorderType)
RETURN

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

PROCEDURE  decl
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER DrawEdge IN user32;
		INTEGER hdc, STRING @qrc,;
		INTEGER edge, INTEGER grfFlags  
```  
***  


## Listed functions:
[DrawEdge](../libraries/user32/DrawEdge.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
