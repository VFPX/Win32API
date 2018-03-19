[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving graphic capabilities of your display

## Code:
```foxpro  
#DEFINE DRIVERVERSION      0
#DEFINE TECHNOLOGY         2
#DEFINE HORZSIZE           4
#DEFINE VERTSIZE           6
#DEFINE HORZRES            8
#DEFINE VERTRES           10
#DEFINE LOGPIXELSX        88
#DEFINE LOGPIXELSY        90
#DEFINE BITSPIXEL         12
#DEFINE PLANES            14
#DEFINE NUMBRUSHES        16
#DEFINE NUMPENS           18
#DEFINE NUMFONTS          22
#DEFINE NUMCOLORS         24
#DEFINE ASPECTX           40
#DEFINE ASPECTY           42
#DEFINE ASPECTXY          44
#DEFINE CLIPCAPS          36
#DEFINE SIZEPALETTE      104
#DEFINE NUMRESERVED      106
#DEFINE COLORRES         108
#DEFINE PHYSICALWIDTH    110
#DEFINE PHYSICALHEIGHT   111
#DEFINE PHYSICALOFFSETX  112
#DEFINE PHYSICALOFFSETY  113
#DEFINE SCALINGFACTORX   114
#DEFINE SCALINGFACTORY   115
#DEFINE RASTERCAPS        38
#DEFINE CURVECAPS         28
#DEFINE LINECAPS          30
#DEFINE POLYGONALCAPS     32
#DEFINE TEXTCAPS          34

DO decl

	LOCAL hdc
	hdc = GetDC(0)  && entire screen
	
	CREATE CURSOR csResult (name C(30), prm N(12))

	= AddLog("Driver version", GetDeviceCaps(hdc, DRIVERVERSION))
	= AddLog("Device technology", GetDeviceCaps(hdc, TECHNOLOGY))
	= AddLog("Physical screen, width, mm", GetDeviceCaps(hdc, HORZSIZE))
	= AddLog("Physical screen, height, mm", GetDeviceCaps(hdc, VERTSIZE))
	= AddLog("Screen, width, pixels", GetDeviceCaps(hdc, HORZRES))
	= AddLog("Screen, height, pixels", GetDeviceCaps(hdc, VERTRES))
	= AddLog("Pixels per inch, X", GetDeviceCaps(hdc, LOGPIXELSX))
	= AddLog("Pixels per inch, Y", GetDeviceCaps(hdc, LOGPIXELSY))
	= AddLog("Bits per pixel", GetDeviceCaps(hdc, BITSPIXEL))
	= AddLog("Color planes", GetDeviceCaps(hdc, PLANES))
	= AddLog("Device-spec. brushes", GetDeviceCaps(hdc, NUMBRUSHES))
	= AddLog("Device-spec. pens", GetDeviceCaps(hdc, NUMPENS))
	= AddLog("Device-spec. fonts", GetDeviceCaps(hdc, NUMFONTS))
	= AddLog("Colors in table", GetDeviceCaps(hdc, NUMCOLORS))
	= AddLog("Pixel relative width", GetDeviceCaps(hdc, ASPECTX))
	= AddLog("Pixel relative height", GetDeviceCaps(hdc, ASPECTY))
	= AddLog("Pixel relative diagonal", GetDeviceCaps(hdc, ASPECTXY))
	= AddLog("Clipping capab.", GetDeviceCaps(hdc, CLIPCAPS))
	= AddLog("Entries in sys.palette", GetDeviceCaps(hdc, SIZEPALETTE))
	= AddLog("Res.entries in sys.palette", GetDeviceCaps(hdc, NUMRESERVED))
	= AddLog("Actual color resolution", GetDeviceCaps(hdc, COLORRES))
	= AddLog("Physical page width", GetDeviceCaps(hdc, PHYSICALWIDTH))
	= AddLog("Physical page height", GetDeviceCaps(hdc, PHYSICALHEIGHT))
	= AddLog("Physical offset X", GetDeviceCaps(hdc, PHYSICALOFFSETX))
	= AddLog("Physical offset Y", GetDeviceCaps(hdc, PHYSICALOFFSETY))
	= AddLog("Printer scaling factor X", GetDeviceCaps(hdc, SCALINGFACTORX))
	= AddLog("Printer scaling factor Y", GetDeviceCaps(hdc, SCALINGFACTORY))
	= AddLog("Raster caps", GetDeviceCaps(hdc, RASTERCAPS))
	= AddLog("Curve caps", GetDeviceCaps(hdc, CURVECAPS))
	= AddLog("Line caps", GetDeviceCaps(hdc, LINECAPS))
	= AddLog("Polygon caps", GetDeviceCaps(hdc, POLYGONALCAPS))
	= AddLog("Text caps", GetDeviceCaps(hdc, TEXTCAPS))

	= ReleaseDC(0, hdc)
	
	GO TOP
	BROWSE NORMAL NOWAIT

PROCEDURE AddLog(lcName, lnPrm)
	INSERT INTO csResult VALUES(m.lcName, m.lnPrm)

PROCEDURE decl
	DECLARE INTEGER GetDC IN user32 INTEGER hwnd
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER hdc
	DECLARE INTEGER GetDeviceCaps IN gdi32 INTEGER hdc, INTEGER nIndex  
```  
***  


## Listed functions:
[GetDC](../libraries/user32/GetDC.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
