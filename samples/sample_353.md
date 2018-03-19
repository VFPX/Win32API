[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the GradientFill function

## Code:
```foxpro  
DO declare

*|typedef struct _TRIVERTEX {
*|  LONG        x;       0:4
*|  Long        y;       4:4
*|  COLOR16     Red;     8:2
*|  COLOR16     Green;  10:2
*|  COLOR16     Blue;   12:2
*|  COLOR16     Alpha;  14:2
*|}TRIVERTEX, *PTRIVERTEX; total 16 bytes

*|typedef struct _GRADIENT_RECT {
*|  ULONG    UpperLeft;
*|  ULONG    LowerRight;
*|}GRADIENT_RECT, *PGRADIENT_RECT; total 8 bytes

#DEFINE GRADIENT_FILL_RECT_V  1

LOCAL hWindow, hDC
hWindow = GetActiveWindow()
hDC = GetWindowDC(hWindow)

= DrawGradient(hDC, 10,100, 800,200,;
	192,192,192, 250,250,250)

= DrawGradient(hDC, 10,200, 800,300,;
	250,250,250, 192,192,192)

ReleaseDC(hWindow, hDC)
* end of main

PROCEDURE DrawGradient
LPARAMETERS hDC, x1,y1, x2,y2,;
	nRed1,nGreen1,nBlue1, nRed2,nGreen2,nBlue2

	LOCAL lcVertex, lcMesh
	lcMesh = num2dword(0) + num2dword(1)

	lcVertex = num2dword(x1) + num2dword(y1) +;
		num2word(nRed1*256) +;
		num2word(nGreen1*256) +;
		num2word(nBlue1*256) +;
		num2word(0) +;
		num2dword(x2) + num2dword(y2)  +;
		num2word(nRed2*256) +;
		num2word(nGreen2*256) +;
		num2word(nBlue2*256) +;
		num2word(0)

	= GradientFill(hDC, @lcVertex, 2, @lcMesh, 1, GRADIENT_FILL_RECT_V)
RETURN

PROCEDURE declare
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hWnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc

	DECLARE INTEGER GradientFill IN Msimg32;
		INTEGER hdc, STRING @pVertex, LONG dwNumVertex,;
		STRING @pMesh, LONG dwNumMesh, LONG dwMode

FUNCTION num2dword(lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word (lnValue)
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[GradientFill](../libraries/msimg32/GradientFill.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
