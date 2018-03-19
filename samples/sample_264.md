[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the ChooseColor function

## Before you begin:
Not much a difference from the native VFP function GetColor().  
  
***  


## Code:
```foxpro  
DO declare

#DEFINE CC_RGBINIT 1
#DEFINE CC_FULLOPEN 2
#DEFINE CC_PREVENTFULLOPEN 4
#DEFINE CC_SHOWHELP 8
#DEFINE CC_SOLIDCOLOR 128
#DEFINE CC_ANYCOLOR 256
#DEFINE CC_WIDE 32

*| typedef struct {
*|   DWORD        lStructSize;      0:4
*|   HWND         hwndOwner;        4:4
*|   HWND         hInstance;        8:4
*|   COLORREF     rgbResult;       12:4
*|   COLORREF   * lpCustColors;    16:4
*|   DWORD        Flags;           20:4
*|   LPARAM       lCustData;       24:4
*|   LPCCHOOKPROC lpfnHook;        28:4
*|   LPCTSTR      lpTemplateName;  32:4
*| } CHOOSECOLOR, *LPCHOOSECOLOR; total=36 bytes

#DEFINE CHOOSECOLOR_SIZE     36

*| typedef DWORD COLORREF;
*| typedef DWORD *LPCOLORREF;
*| 0x00bbggrr
#DEFINE COLORREF_ARRAY_SIZE  64

LOCAL hWindow, lcBuffer, lnInitColor, lnFlags,;
	lnCustColors, lcCustColors, ii

hWindow = GetActiveWindow()

* the color initially selected when the dialog box is created
lnInitColor = Rgb(128,0,0)

* allocating memory block for 16 COLORREF values (DWORD)
* for the custom color boxes in the dialog box
* and filling this memory with zeroes

#DEFINE GMEM_FIXED 0
lnCustColors = GlobalAlloc(GMEM_FIXED, COLORREF_ARRAY_SIZE)
= ZeroMemory(lnCustColors, COLORREF_ARRAY_SIZE)

* initialization flags
lnFlags = CC_FULLOPEN + CC_RGBINIT

* compiling the CHOOSECOLOR structure
lcBuffer = num2dword(CHOOSECOLOR_SIZE) +;
	num2dword(hWindow) +;
	num2dword(0) +;
	num2dword(lnInitColor) +;
	num2dword(lnCustColors) +;
	num2dword(lnFlags) +;
	num2dword(0) +;
	num2dword(0) +;
	num2dword(0)

IF ChooseColor(@lcBuffer) <> 0
* the OK button of the dialog box has been selected
	? "Color selected:", buf2dword(SUBSTR(lcBuffer, 13,4))

	? "Custom colors stored:"
	
	* copying the memory block content to a VFP string
	* just to have an opportunity to work with its substring;
	* quite weird way, though not much choice available
	* considering the VFP specifics

	lcCustColors = Repli(Chr(0), COLORREF_ARRAY_SIZE)
	= Heap2Str(@lcCustColors, lnCustColors, COLORREF_ARRAY_SIZE)

	FOR ii=1 TO 16
		? ii, buf2dword(SUBSTR(lcCustColors, (ii-1)*4+1, 4))
	ENDFOR
ENDIF

* free the memory block if you do not use it for the
* following calls to this function
= GlobalFree(lnCustColors)

* end of main

FUNCTION num2dword (lnValue)
#DEFINE m0 0x100
#DEFINE m1 0x10000
#DEFINE m2 0x1000000
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION buf2dword (lcBuffer)
#DEFINE MAX_DWORD 0xffffffff
#DEFINE MAX_LONG 0x7FFFFFFF
	LOCAL lnResult
	lnResult = Asc(SUBSTR(lcBuffer, 1,1)) + ;
		Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
		Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
		Asc(SUBSTR(lcBuffer, 4,1)) * 16777216
RETURN IIF(lnResult>MAX_LONG, lnResult-MAX_DWORD, lnResult)

PROCEDURE declare
	DECLARE INTEGER ChooseColor IN comdlg32 STRING @lpcc
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem
	DECLARE RtlZeroMemory IN kernel32 As ZeroMemory;
		INTEGER dest, INTEGER numBytes

	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	DECLARE RtlMoveMemory IN kernel32 As Heap2Str;
			STRING @, INTEGER, INTEGER  
```  
***  


## Listed functions:
[ChooseColor](../libraries/comdlg32/ChooseColor.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  

## Comment:
WIth the ChooseColor you have some more control on the form presentation, but not its positioning.  
  
16 custom colors are available for reading and writing through a  memory block, which -- if you are interested in -- you have to allocate and release directly.   
  
Using the VFP native GetColor function you can access the custom colors as well, but only changing their values within the Color dialog is available. I guess that VFP keeps that array in its memory during the whole session, exclusively to be used in the ChooseColor calls. To my knowledge there is no regular way to reach it.  
  
Then, not many advantages this function gives to dump the good old GetColor, which is still present unchanged in each VFP version.  
  
***  

