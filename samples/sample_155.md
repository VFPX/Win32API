[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving graphic capabilities of default printer

## Code:
```foxpro  
DO decl

#DEFINE RASTERCAPS       38
#DEFINE RC_BITBLT         1
#DEFINE RC_BANDING        2
#DEFINE RC_SCALING        4
#DEFINE RC_BITMAP64       8
#DEFINE RC_GDI20_OUTPUT  16
#DEFINE RC_DI_BITMAP    128
#DEFINE RC_PALETTE      256
#DEFINE RC_DIBTODEV     512
#DEFINE RC_FLOODFILL   4096
#DEFINE RC_STRETCHBLT  2048
#DEFINE RC_STRETCHDIB  8192

#DEFINE DRIVERVERSION     0
#DEFINE TECHNOLOGY        2
#DEFINE LOGPIXELSX       88
#DEFINE LOGPIXELSY       90
#DEFINE PHYSICALWIDTH   110
#DEFINE PHYSICALHEIGHT  111
#DEFINE PHYSICALOFFSETX 112
#DEFINE PHYSICALOFFSETY 113
#DEFINE SCALINGFACTORX  114
#DEFINE SCALINGFACTORY  115

	PRIVATE hdc, lnRasterInfo
	hdc = getDefaultPrnDC()

	IF hdc = 0
		= MessageB ("Unable to retrieve the device context" + Chr(13) +;
			"of default printer")
		RETURN
	ENDIF
	
	? "*** Device Driver version:"
	? GetDeviceCaps(hdc, DRIVERVERSION)
	
	? "*** Device technology: (DT_RASPRINTER=2)"
	? GetDeviceCaps(hdc, TECHNOLOGY)

	?
	? "*** Default Printer Raster Capabilities:"
	lnRasterInfo = GetDeviceCaps(hdc, RASTERCAPS)
	= _displRsCap (RC_BANDING,      "requires banding support for graphics")
	= _displRsCap (RC_BITBLT,       "can be target of BitBlt()")
	= _displRsCap (RC_BITMAP64,     "can handle bitmaps larger than 64K")
	= _displRsCap (RC_DI_BITMAP,    "supports device independent bitmaps")
	= _displRsCap (RC_DIBTODEV,     "supports SetDIBitsToDevice()")
	= _displRsCap (RC_FLOODFILL,    "supports flood fills")
	= _displRsCap (RC_GDI20_OUTPUT, "supports features of 16-bits Windows")
	= _displRsCap (RC_PALETTE,      "supports a palette")
	= _displRsCap (RC_SCALING,      "provides its own scaling capabilities")
	= _displRsCap (RC_STRETCHBLT,   "can be target of StretchBlt()")
	= _displRsCap (RC_STRETCHDIB,   "can be target of StretchDIBits")
	
	?
	? "*** Number of pixels per logical inch:"
	? "Horizontal:", GetDeviceCaps(hdc, LOGPIXELSX)
	? "Vertical:  ", GetDeviceCaps(hdc, LOGPIXELSY)
	
	?
	? "*** Physical page size, in device units:"
	? "Width: ", GetDeviceCaps(hdc, PHYSICALWIDTH)
	? "Height:", GetDeviceCaps(hdc, PHYSICALHEIGHT)
	
	?
	? "*** Offset from the left edge, in device units:"
	? "Horizontal:", GetDeviceCaps(hdc, PHYSICALOFFSETX)
	? "Vertical:  ", GetDeviceCaps(hdc, PHYSICALOFFSETY)
	
	?
	? "*** Scaling factor:"
	? "X-axis:", GetDeviceCaps(hdc, SCALINGFACTORX)
	? "Y-axis:", GetDeviceCaps(hdc, SCALINGFACTORY)
	
	* release system resources
	= DeleteDC (hDc)
RETURN

PROCEDURE  _displRsCap (lnMask, lcCaption)
	LOCAL lcResult
	lcResult = Iif(BitAnd(lnRasterInfo, lnMask)=0, "[ ]","[x]")
	? "   ", lcResult, lcCaption

FUNCTION  getDefaultPrnDC
#DEFINE PD_RETURNDC         256
#DEFINE PD_RETURNDEFAULT   1024
	LOCAL lcStruct, lnFlags
	lnFlags = PD_RETURNDEFAULT + PD_RETURNDC

	* fill PRINTDLG structure
	lcStruct = num2dword(66) + Repli(Chr(0), 16) +;
		num2dword(lnFlags) + Repli(Chr(0), 42)

	IF PrintDlg (@lcStruct) <> 0
		RETURN buf2dword (SUBSTR(lcStruct, 17,4))
	ENDIF
RETURN  0

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

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER PrintDlg IN comdlg32 STRING @lppd

	DECLARE INTEGER GetDeviceCaps IN gdi32;
		INTEGER hdc, INTEGER nIndex  
```  
***  


## Listed functions:
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[PrintDlg](../libraries/comdlg32/PrintDlg.md)  
