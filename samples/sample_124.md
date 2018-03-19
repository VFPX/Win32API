[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Finding parameters for the region specified

## Code:
```foxpro  
*| typedef struct _RGNDATA {
*|     RGNDATAHEADER rdh;
*|     char          Buffer[1];
*| } RGNDATA, *PRGNDATA;

*| typedef struct _RGNDATAHEADER {
*|     DWORD dwSize;
*|     DWORD iType;
*|     DWORD nCount;
*|     DWORD nRgnSize;
*|     RECT  rcBound;
*| } RGNDATAHEADER, *PRGNDATAHEADER;

*| typedef struct _RECT {
*|   LONG left;
*|   LONG top;
*|   LONG right;
*|   LONG bottom;
*| } RECT, *PRECT;


	* creating a region to test
	hRgn = CreateRectRgn (0, 0, 200, 100)

	dwCount = 200
	lpRgnData = Repli (Chr(0), dwCount)

	lnLength = GetRegionData (hRgn, dwCount, @lpRgnData)
	lpRgnData = LEFT (lpRgnData, lnLength)

	? "Length of return buffer:", lnLength
	?

	? "*** RGNDATAHEADER Structure:"
	? "dwSize:  ", buf2dword (SUBSTR(lpRgnData,  1,4))
	? "iType:   ", buf2dword (SUBSTR(lpRgnData,  5,4))
	? "nCount:  ", buf2dword (SUBSTR(lpRgnData,  9,4))
	? "nRgnSize:", buf2dword (SUBSTR(lpRgnData, 13,4))
	? "Rect:    ",;
		buf2dword (SUBSTR(lpRgnData, 17,4)),;
		buf2dword (SUBSTR(lpRgnData, 21,4)),;
		buf2dword (SUBSTR(lpRgnData, 25,4)),;
		buf2dword (SUBSTR(lpRgnData, 29,4))

	?
	? "*** RECT structures that make up the region"
	? "Rect1:    ",;
		buf2dword (SUBSTR(lpRgnData, 33,4)),;
		buf2dword (SUBSTR(lpRgnData, 37,4)),;
		buf2dword (SUBSTR(lpRgnData, 41,4)),;
		buf2dword (SUBSTR(lpRgnData, 45,4))

	* there can be more RECT structures following
	* for a combination of regions
	
	?
	? "*** Region bounding rectangle:"
	
	lprc = SPACE(16)
	lnResult = GetRgnBox (hRgn, @lprc)
	? "Type:", lnResult
	? "Rectangle:    ",;
		buf2dword (SUBSTR(lprc,  1,4)),;
		buf2dword (SUBSTR(lprc,  5,4)),;
		buf2dword (SUBSTR(lprc,  9,4)),;
		buf2dword (SUBSTR(lprc, 13,4))

* end of main


FUNCTION  buf2dword (lcBuffer)
RETURN;
	Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER GetRegionData IN gdi32;
		INTEGER hRgn,;
		INTEGER dwCount,;
		STRING @ lpRgnData

	DECLARE INTEGER CreateRectRgn IN gdi32;
		INTEGER nLeftRect,;
		INTEGER nTopRect,;
		INTEGER nRightRect,;
		INTEGER nBottomRect

	DECLARE INTEGER GetRgnBox IN gdi32;
		INTEGER hrgn,;
		STRING @ lprc  
```  
***  


## Listed functions:
[CreateRectRgn](../libraries/gdi32/CreateRectRgn.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetRegionData](../libraries/gdi32/GetRegionData.md)  
[GetRgnBox](../libraries/gdi32/GetRgnBox.md)  
