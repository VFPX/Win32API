[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Converting twips to pixels and vice versa

## Code:
```foxpro  
#DEFINE LOGPIXELSX 88
#DEFINE LOGPIXELSY  90
#DEFINE TwipsPerInch 1440

DO declare

LOCAL hWindow, hdc, pixResX, pixResY
hWindow = 0
hdc = GetDC(m.hWindow)  && entire screen

? "*** Pixels per inch:"
pixResX = GetDeviceCaps(hdc, LOGPIXELSX)
pixResY = GetDeviceCaps(hdc, LOGPIXELSY)
? "Horizontal:", pixResX
? "Vertical:  ", pixResY

?
? "*** Twips per inch:", TwipsPerInch

?
? "*** 100 pixels are equivalent to:"
? "Horizontal:", TwipsPerInch * 100/pixResX, "pixels"
? "Vertical:  ", TwipsPerInch * 100/pixResY, "pixels"

?
? "*** 1000 twips are equivalent to:"
? "Horizontal:", 1000 * pixResX/TwipsPerInch, "twips"
? "Vertical:  ", 1000 * pixResY/TwipsPerInch, "twips"

= ReleaseDC(m.hWindow, m.hdc)

PROCEDURE declare
	DECLARE INTEGER GetDC IN user32 INTEGER hWindow

	DECLARE INTEGER ReleaseDC IN user32;
		INTEGER hWindow, INTEGER hdc

	DECLARE INTEGER GetDeviceCaps IN gdi32;
		INTEGER hdc, INTEGER nIndex  
```  
***  


## Listed functions:
[GetDC](../libraries/user32/GetDC.md)  
[GetDeviceCaps](../libraries/gdi32/GetDeviceCaps.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  
