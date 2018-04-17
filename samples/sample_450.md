[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Custom GDI+ class

## Before you begin:
***Note: since this CGI+ class library uses Collections and Try/Catch error handling,   
it requires at least VFP8.***   

The *gdiplusinit* object must be created before instantiating first gdi+ object in the application.  

Code samples based on this class:

* [converting image file to another graphics format ](sample_451.md)  
* [sending image file to printer](sample_452.md)  
* [saving image of FoxPro form to file](sample_454.md)  
* [printing image file](sample_455.md)  
* [sending image of FoxPro form or image file to the Clipboard](sample_457.md)  
* [copying data from the Clipboard to an image file](sample_475.md)  
* [reading and writing metadata in JPEG and TIFF files](sample_461.md)  
* [loading image file, drawing on it, saving the result to another file](sample_458.md)  
* [scaling images](sample_460.md)  
* [cropping images](sample_515.md)  
* [rotating images](sample_525.md)  
* [using Scale and Shear transformations](sample_479.md)  
* [extracting icon resources and saving in image files](sample_501.md)  
* [converting image file to .ICO file](sample_503.md)  
* [enumerating fonts installed on the system](sample_462.md)  
* [GDI+: printing vertical text on VFP reports via generated images](sample_509.md)  
* [converting lines of text to an image and saving in a graphics file](sample_513.md)  
* [obtaining list of installed image encoders and decoders](sample_459.md)  
* [drawing a Pie Chart](sample_514.md)  
* [creating a gradient](sample_596.md)  
* [scrolling through large image with the mouse](sample_546.md)  
* [extending user interface: controls that shake](sample_526.md)  
* [image scrolling with inertia](sample_595.md)  
* [custom Clock Control](sample_597.md) The library contains 14 classes and about 70 GDI+ declarations.
  
***  


## Code:
```foxpro  
********************************************************************
* GDI+ wrapper
********************************************************************
* Classes defined:
* gdiplusbase, graphics, gdiimage, gdibitmap, gdifontcollection,
* gdifontfamily, gdifont, gdipen, gdimatrix, gdistringformat,
* gdiplusinit
********************************************************************
* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
********************************************************************

DEFINE CLASS gdiplusbase As Custom
* abstract base class for graphics, gdiimage, gdifontcollection,
* gdifontfamily, gdifont and others
	errorcode=0
ENDDEFINE

********************************************************************
DEFINE CLASS graphics As gdiplusbase
	SmoothingMode=0
	graphics=0
	hdc=0

PROCEDURE SmoothingMode_ACCESS
	LOCAL nSmoothingMode
	nSmoothingMode = 0
	
	IF GdipGetSmoothingMode(THIS.graphics, @nSmoothingMode) = 0
		THIS.SmoothingMode = nSmoothingMode
	ENDIF
RETURN THIS.SmoothingMode

PROCEDURE SmoothingMode_ASSIGN(vValue)
	IF VARTYPE(vValue) = "N" AND;
		GdipSetSmoothingMode(THIS.graphics, vValue) = 0
		THIS.SmoothingMode = vValue
	ENDIF

PROCEDURE Init(p1, p2)
	IF PCOUNT()>0
		THIS.CreateGraphics(p1, p2)
	ENDIF

PROCEDURE Destroy
	THIS.ReleaseGraphics
	DODEFAULT()

PROCEDURE ReleaseGraphics
	IF THIS.graphics = 0
		RETURN
	ENDIF

	THIS.ReleaseDC
	= GdipDeleteGraphics(THIS.graphics)
	THIS.graphics=0

FUNCTION CreateGraphics(p1, p2)
#DEFINE OBJ_DC 3
	THIS.ReleaseGraphics

	LOCAL graphics, nObjType
	STORE 0 TO graphics
	nObjType = GetObjectType(m.p1)

	DO CASE
	CASE nObjType=0 AND IsWindow(m.p1)<>0
		THIS.errorcode = GdipCreateFromHWND(m.p1, @graphics)
	CASE nObjType=OBJ_DC AND PCOUNT()=1
		THIS.errorcode = GdipCreateFromHDC(m.p1, @graphics)
	CASE nObjType=OBJ_DC AND PCOUNT()=2
		THIS.errorcode = GdipCreateFromHDC2(m.p1, m.p2, @graphics)
	OTHERWISE
		THIS.errorcode = -1
		RETURN .F.
	ENDCASE
	THIS.graphics = m.graphics
RETURN (THIS.errorcode=0)

PROCEDURE GetDC
	THIS.ReleaseDC
	LOCAL hdc
	hdc=0
	IF THIS.graphics <> 0
		= GdipGetDC(THIS.graphics, @hdc)
	ENDIF
	THIS.hdc = m.hdc
RETURN m.hdc

PROCEDURE ReleaseDC
	IF THIS.hdc <> 0
		= GdipReleaseDC(THIS.graphics, THIS.hdc)
		THIS.hdc=0
	ENDIF

PROCEDURE DrawImage(oImage, nX, nY, nWidth, nHeight)
	IF VARTYPE(nWidth) <> "N"
		nWidth = oImage.imgwidth
	ENDIF
	IF VARTYPE(nHeight) <> "N"
		nHeight = oImage.imgheight
	ENDIF
	THIS.errorcode = GdipDrawImageRectI(THIS.graphics,;
		oImage.himage, m.nX, m.nY, m.nWidth, m.nHeight)

PROCEDURE DrawText(cStr, oFont, p1, p2, p3, p4)
	LOCAL rectf
	IF VARTYPE(m.p1)="O"
		rectf = p1.ToString()
	ELSE
		WITH CREATEOBJECT("rectf", m.p1, m.p2, m.p3, m.p4)
			rectf = .ToString()
		ENDWITH
	ENDIF
	
	= GdipSetTextRenderingHint(THIS.graphics, 0)  && 0..5

	THIS.errorcode = GdipDrawString(THIS.graphics,;
		ToWideChar(m.cStr), -1, oFont.fnt, @rectf, 0, oFont.brush)
RETURN (THIS.errorcode=0)

FUNCTION MeasureString(cStr, oFont) As RectF
	LOCAL fmt As gdistringformat, oRect, cRectSrc, cRectDst,;
		nCharsFitted, nLinesFitted

	fmt = CREATEOBJECT("gdistringformat", 0)

	oRect = CREATEOBJECT("rectf", 0, 0, 0, 0)
	STORE oRect.ToString() TO cRectSrc, cRectDst
	
	STORE 0 TO nCharsFitted, nLinesFitted

	THIS.errorcode = GdipMeasureString(THIS.graphics, STRCONV(m.cStr+CHR(0),5),;
		LEN(m.cStr), oFont.fnt, cRectSrc, fmt.fmt, @cRectDst,;
		@nCharsFitted, @nLinesFitted)

	oRect.FromString(m.cRectDst)
RETURN m.oRect

PROCEDURE FillRectangle(p1, p2, p3, p4, p5)
	LOCAL brush
	IF VARTYPE(m.p1)="O"
		brush = p1.brush
	ELSE
		LOCAL oBrush
		oBrush = CREATEOBJECT("gdisolidbrush", m.p1)
		brush = oBrush.brush
	ENDIF

	IF VARTYPE(p2)="O"
		= GdipFillRectangle(THIS.graphics, m.brush,;
			p2.rleft, p2.rtop, p2.rwidth, p2.rheight)
	ELSE
		= GdipFillRectangle(THIS.graphics, m.brush,;
			m.p2, m.p3, m.p4, m.p5)
	ENDIF

PROCEDURE FillEllipse(p1, p2, p3, p4, p5)
	LOCAL brush
	IF VARTYPE(m.p1)="O"
		brush = p1.brush
	ELSE
		LOCAL oBrush
		oBrush = CREATEOBJECT("gdisolidbrush", m.p1)
		brush = oBrush.brush
	ENDIF

	IF VARTYPE(p2)="O"
		= GdipFillEllipse(THIS.graphics, m.brush,;
			p2.rleft, p2.rtop, p2.rwidth, p2.rheight)
	ELSE
		= GdipFillEllipse(THIS.graphics, m.brush,;
			m.p2, m.p3, m.p4, m.p5)
	ENDIF

PROCEDURE DrawRectangle(p1, p2, p3, p4, p5)
	LOCAL nHandle
	IF VARTYPE(m.p1)="O"
		nHandle = p1.hpen
	ELSE
		LOCAL oPenObj
		oPenObj = CREATEOBJECT("gdipen", m.p1, 1)
		nHandle = oPenObj.hpen
	ENDIF

	IF VARTYPE(p2)="O"
		= GdipDrawRectangle(THIS.graphics, m.nHandle,;
			p2.rleft, p2.rtop, p2.rwidth, p2.rheight)
	ELSE
		= GdipDrawRectangle(THIS.graphics, m.nHandle,;
			m.p2, m.p3, m.p4, m.p5)
	ENDIF

PROCEDURE DrawEllipse(p1, p2, p3, p4, p5)
	LOCAL nHandle
	IF VARTYPE(m.p1)="O"
		nHandle = p1.hpen
	ELSE
		LOCAL oPenObj
		oPenObj = CREATEOBJECT("gdipen", m.p1, 1)
		nHandle = oPenObj.hpen
	ENDIF

	IF VARTYPE(p2)="O"
		= GdipDrawEllipse(THIS.graphics, m.nHandle,;
			p2.rleft, p2.rtop, p2.rwidth, p2.rheight)
	ELSE
		= GdipDrawEllipse(THIS.graphics, m.nHandle,;
			m.p2, m.p3, m.p4, m.p5)
	ENDIF

PROCEDURE DrawLine(p1, p2, p3, p4, p5)
	LOCAL nHandle
	IF VARTYPE(m.p1)="O"
		nHandle = p1.hpen
	ELSE
		LOCAL oPenObj
		oPenObj = CREATEOBJECT("gdipen", m.p1, 1)
		nHandle = oPenObj.hpen
	ENDIF

	IF VARTYPE(p2)="O"
		= GdipDrawLine(THIS.graphics, m.nHandle,;
			p2.rleft, p2.rtop, p2.rwidth, p2.rheight)
	ELSE
		= GdipDrawLine(THIS.graphics, m.nHandle,;
			m.p2, m.p3, m.p4, m.p5)
	ENDIF

PROCEDURE SetTransform(vMatrix)
	DO CASE
	CASE VARTYPE(m.vMatrix) = "O"
		THIS.errorcode = GdipSetWorldTransform(;
			THIS.graphics, vMatrix.hmatrix)
	CASE VARTYPE(m.vMatrix) = "N"
		THIS.errorcode = GdipSetWorldTransform(;
			THIS.graphics, m.vMatrix)
	ENDCASE

PROCEDURE ResetTransform
	THIS.errorcode=GdipResetWorldTransform(;
		THIS.graphics)

ENDDEFINE

********************************************************************
DEFINE CLASS gdidbrush As gdiplusbase
	brush=0
PROCEDURE Destroy
	THIS.ReleaseBrush
PROTECTED PROCEDURE ReleaseBrush
	IF THIS.brush <> 0
		= GdipDeleteBrush(THIS.brush)
		THIS.brush=0
	ENDIF
ENDDEFINE

DEFINE CLASS gdisolidbrush As gdidbrush
PROCEDURE Init(argbcolor)
	IF VARTYPE(m.argbcolor) <> "N"
		argbcolor=0
	ENDIF
	THIS.SetBrushColor(argbcolor)

PROCEDURE SetBrushColor(argbcolor)
	THIS.ReleaseBrush
	LOCAL brush
	brush=0
	THIS.errorcode = GdipCreateSolidFill(m.argbcolor, @brush)
	THIS.brush = m.brush
RETURN (THIS.errorcode=0)

ENDDEFINE

********************************************************************
DEFINE CLASS gdiimage As gdiplusbase
	himage=0
	hbitmap=0
	filename=""
	imgtype=0
	imgwidth=0
	imgheight=0
	imgflags=0
	guid=""
	graphics=0

PROCEDURE Init(p1, p2, p3, p4, p5, p6)
	DO CASE
	CASE PCOUNT()=1 AND VARTYPE(p1)="C"
		THIS.CreateFromFile(p1)
	CASE PCOUNT()=1 AND VARTYPE(p1)="N"
		THIS.CreateFromHandle(p1)
	CASE PCOUNT()=1 AND VARTYPE(p1)="O"
		THIS.CloneFromGdiBitmap1(p1)
	CASE PCOUNT()>1 AND VARTYPE(p1)="O"
		THIS.CloneFromGdiBitmap2(p1, p2, p3, p4, p5, p6)
	ENDCASE

PROCEDURE Destroy
	THIS.ReleaseImage
	DODEFAULT()

PROCEDURE ReleaseImage
#DEFINE OBJ_BITMAP 7
	IF VARTYPE(THIS.graphics)="O"
		THIS.graphics=0
	ENDIF
	IF THIS.himage <> 0
		= GdipDisposeImage(THIS.himage)
		THIS.himage=0
	ENDIF
	IF THIS.hbitmap <> 0
		IF GetObjectType(THIS.hbitmap)=OBJ_BITMAP
			= DeleteObject(THIS.hbitmap)
		ENDIF
		THIS.hbitmap=0
	ENDIF
	THIS.filename=""
	THIS.imgtype=0
	THIS.imgwidth=0
	THIS.imgheight=0
	THIS.imgflags=0
	THIS.guid=""
	THIS.errorcode = 0

FUNCTION CreateFromFile(cFile)
	THIS.ReleaseImage
	THIS.filename = m.cFile

	LOCAL img, imgtype, imgwidth, imgheight, imgflags, guid
	STORE 0 TO img, imgtype, imgwidth, imgheight, imgflags

	TRY
		THIS.errorcode = GdipLoadImageFromFile(;
			ToWideChar(cFile), @img)
	CATCH
		THIS.errorcode =-1
	ENDTRY

	THIS.himage=m.img
	THIS.GetImageParameters
RETURN (THIS.himage<>0)

FUNCTION CreateFromHandle(img)
	THIS.ReleaseImage
	THIS.himage=m.img
	THIS.GetImageParameters
	IF THIS.imgtype <> 0
		RETURN .T.
	ELSE
		THIS.ReleaseImage
		RETURN .F.
	ENDIF

FUNCTION CloneFromGdiBitmap1(src)
	LOCAL srcHBitmap, dstHImage, dst
	srcHBitmap = src.GetHBITMAP()
	IF srcHBitmap <> 0
		dstHImage=0
		THIS.errorcode = GdipCreateBitmapFromHBITMAP(;
			m.srcHBitmap, 0, @dstHImage)
		IF THIS.errorcode = 0
			RETURN THIS.CreateFromHandle(dstHImage)
		ENDIF
	ENDIF
RETURN .F.

FUNCTION CloneFromGdiBitmap2(src, dstfmt, x0, y0, dstwidth, dstheight)
	LOCAL dstHImage
	dstHImage = 0
	THIS.errorcode = GdipCloneBitmapArea(;
		m.x0, m.y0, m.dstwidth, m.dstheight,;
		dstfmt, src.himage, @dstHImage)
	IF THIS.errorcode = 0
		RETURN THIS.CreateFromHandle(dstHImage)
	ENDIF
RETURN .F.

PROTECTED PROCEDURE GetImageParameters
	LOCAL imgtype, imgwidth, imgheight, imgflags, guid, graphics
	STORE 0 TO imgtype, imgwidth, imgheight, imgflags, graphics
	guid = REPLICATE(CHR(0), 16)

	IF THIS.himage <> 0
		= GdipGetImageType(THIS.himage, @m.imgtype)
		= GdipGetImageWidth(THIS.himage, @m.imgwidth)
		= GdipGetImageHeight(THIS.himage, @m.imgheight)
		= GdipGetImageFlags(THIS.himage, @m.imgflags)
		= GdipGetImageRawFormat(THIS.himage, @m.guid)
	ENDIF
	THIS.imgtype = m.imgtype
	THIS.imgwidth = m.imgwidth
	THIS.imgheight = m.imgheight
	THIS.imgflags = m.imgflags
	THIS.guid = m.guid

	IF VARTYPE(THIS.graphics) = "N"
		THIS.errorcode =;
			GdipGetImageGraphicsContext(THIS.himage, @graphics)
		IF THIS.errorcode = 0
		* 3=OutOfMemory
			THIS.graphics = CREATEOBJECT("graphics")
			THIS.graphics.graphics = m.graphics
		ENDIF
	ENDIF

FUNCTION GetHBITMAP
	LOCAL hbitmap
	hbitmap=0
	IF THIS.hbitmap = 0
		THIS.errorcode = GdipCreateHBITMAPFromBitmap(;
			THIS.himage, @hbitmap, 0)
		IF THIS.errorcode = 0
			THIS.hbitmap = m.hbitmap
		ENDIF
	ENDIF
RETURN THIS.hbitmap

PROCEDURE CreateHICON
	LOCAL hIcon
	hIcon=0
	THIS.errorcode = GdipCreateHICONFromBitmap(;
		THIS.himage, @hIcon)
RETURN m.hIcon

FUNCTION SaveToFile(cTargetFile)
#DEFINE ccEncoderBitmap "{557cf400-1a04-11d3-9a73-0000f81ef32e}"
#DEFINE ccEncoderJpeg   "{557CF401-1A04-11D3-9A73-0000F81EF32E}"
#DEFINE ccEncoderGif    "{557cf402-1a04-11d3-9a73-0000f81ef32e}"
#DEFINE ccEncoderTiff   "{557cf405-1a04-11d3-9a73-0000f81ef32e}"
#DEFINE ccEncoderPng    "{557cf406-1a04-11d3-9a73-0000f81ef32e}"
	LOCAL cType, cEncoder
	cType = UPPER(ALLTRIM(SUBSTR(cTargetFile,;
		RAT(".",cTargetFile)+1)))

	DO CASE
	CASE cType == "BMP"
		cEncoder=StringToCLSID(ccEncoderBitmap)
	CASE cType == "JPG" OR cType == "JPEG"
		cEncoder=StringToCLSID(ccEncoderJpeg)
	CASE cType == "GIF"
		cEncoder=StringToCLSID(ccEncoderGif)
	CASE cType == "TIF" OR cType == "TIFF"
		cEncoder=StringToCLSID(ccEncoderTiff)
	CASE cType == "PNG"
		cEncoder=StringToCLSID(ccEncoderPng)
	OTHERWISE
		THIS.errorcode=-1
		RETURN .F.
	ENDCASE
	THIS.errorcode = GdipSaveImageToFile(THIS.himage,;
		ToWideChar(m.cTargetFile), m.cEncoder, 0)
RETURN (THIS.errorcode=0)
ENDDEFINE

********************************************************************
DEFINE CLASS gdibitmap As gdiimage

PROCEDURE Init(p1, p2)
	IF PCOUNT()=2 AND VARTYPE(p1)="N" AND VARTYPE(p2)="N"
		THIS.CreateBitmap(p1, p2)
	ENDIF

PROCEDURE CreateBitmap(nWidth, nHeight)
RETURN THIS.CreateFromHWND(nWidth, nHeight, GetDesktopWindow())

PROCEDURE CreateFromHWND(nWidth, nHeight, hwindow)
	LOCAL gr, lResult
	gr = CREATEOBJECT("graphics", m.hwindow)
	lResult = THIS.CreateFromGraphics(nWidth, nHeight, gr.graphics)
RETURN m.lResult

PROCEDURE CreateFromGraphics(nWidth, nHeight, graphics)
	LOCAL img
	img=0
	THIS.errorcode = GdipCreateBitmapFromGraphics(;
		m.nWidth, m.nHeight, m.graphics, @img)
	IF THIS.errorcode = 0
		RETURN THIS.CreateFromHandle(m.img)
	ELSE
		RETURN .F.
	ENDIF

PROCEDURE CreateFromHBITMAP(hBitmap)
	LOCAL img
	img=0
	THIS.errorcode = GdipCreateBitmapFromHBITMAP(;
		m.hBitmap, 0, @m.img)
	IF THIS.errorcode = 0
		RETURN THIS.CreateFromHandle(m.img)
	ELSE
		RETURN .F.
	ENDIF

PROCEDURE CreateFromHICON(hIcon)
	LOCAL img
	img=0
	THIS.errorcode = GdipCreateBitmapFromHICON(;
		m.hIcon, @m.img)
	IF THIS.errorcode = 0
		RETURN THIS.CreateFromHandle(m.img)
	ELSE
		RETURN .F.
	ENDIF

PROCEDURE CreateFromBITMAPINFO(hBitmapinfo, hBitmapdata)
#DEFINE BITMAPINFOHEADER_SIZE 40
	IF VARTYPE(hBitmapdata) <> "N" OR hBitmapdata=0
	* simplified: null color table is assumed
		hBitmapdata = hBitmapinfo +;
			BITMAPINFOHEADER_SIZE
	ENDIF
	LOCAL img
	img=0
	THIS.errorcode = GdipCreateBitmapFromGdiDib(hBitmapinfo,;
		hBitmapdata, @img)
	IF THIS.errorcode = 0
		RETURN THIS.CreateFromHandle(m.img)
	ELSE
		RETURN .F.
	ENDIF

ENDDEFINE

********************************************************************
DEFINE CLASS gdifontcollection As gdiplusbase
* collection of fonts installed on the system
	fontfamilies=0

PROCEDURE Init
	THIS.GetFontFamilies

PROCEDURE GetFontFamily(vFamilyName)
	LOCAL oFamily, ex as Exception
	TRY
		oFamily = THIS.fontfamilies.Item(vFamilyName)
	CATCH TO ex
		IF VARTYPE(vFamilyName)="C"
			oFamily = THIS.GetFamilyByName(vFamilyName)
		ELSE
			oFamily = CREATEOBJECT("gdifontfamily")
		ENDIF
	ENDTRY
RETURN m.oFamily

PROTECTED PROCEDURE GetFamilyByName(cFamilyName)
	cFamilyName = LOWER(ALLTRIM(m.cFamilyName))
	LOCAL oFamily As gdifontfamily
	FOR EACH oFamily IN THIS.fontfamilies
		IF LOWER(oFamily.familyname) = m.cFamilyName
			RETURN oFamily
		ENDIF
	NEXT
	oFamily = CREATEOBJECT("gdifontfamily")
RETURN m.oFamily

PROTECTED PROCEDURE GetFontFamilies
	THIS.fontfamilies = CREATEOBJECT("Collection")

	LOCAL fonts, familycount, cBuffer, hfontfamily, nIndex
	STORE 0 TO fonts, familycount
	= GdipNewInstalledFontCollection(@fonts)
	= GdipGetFontCollectionFamilyCount(fonts, @familycount)

	cBuffer = REPLICATE(CHR(0), m.familycount*4)
	= GdipGetFontCollectionFamilyList(fonts, familycount,;
		@cBuffer, @familycount)
	FOR nIndex=0 TO familycount-1
		LOCAL oFontFamily
		hfontfamily = buf2dword(SUBSTR(cBuffer,;
			nIndex*4+1,4))
		oFontFamily = CREATEOBJECT("gdifontfamily", m.hfontfamily)
		THIS.fontfamilies.Add(oFontFamily, oFontFamily.familyname)
	NEXT
ENDDEFINE

********************************************************************
DEFINE CLASS gdifontfamily As gdiplusbase
	hfontfamily=0
	familyname=""
	hasregular=.F.
	hasbold=.F.
	hasitalic=.F.
	hasbolditalic=.F.
	hasunderline=.F.
	hasstrikeout=.F.

PROCEDURE Init(hfontfamily)
	IF VARTYPE(m.hfontfamily)="N"
		THIS.hfontfamily = m.hfontfamily
		THIS.GetFamilyData
	ENDIF

PROTECTED PROCEDURE GetFamilyData
#DEFINE LF_FACESIZE 32
	LOCAL familyname, langid
	langid = VAL(SYS(3004))
	familyname = REPLICATE(CHR(0), (LF_FACESIZE+1)*2)  && widechar
	= GdipGetFamilyName(THIS.hfontfamily, @m.familyname, m.langid)
	THIS.familyname = STRCONV(m.familyname,6)
	THIS.hasregular=THIS.IsStyleAvailable(0)
	THIS.hasbold=THIS.IsStyleAvailable(1)
	THIS.hasitalic=THIS.IsStyleAvailable(2)
	THIS.hasbolditalic=THIS.IsStyleAvailable(3)
	THIS.hasunderline=THIS.IsStyleAvailable(4)
	THIS.hasstrikeout=THIS.IsStyleAvailable(8)

PROTECTED FUNCTION IsStyleAvailable(nStyle)
	LOCAL nAvailable
	nAvailable=0
	= GdipIsStyleAvailable(THIS.hfontfamily, nStyle, @nAvailable)
RETURN (nAvailable<>0)
ENDDEFINE

********************************************************************
DEFINE CLASS gdifont As gdiplusbase
PROTECTED fontfamilycreated
	hfontfamily=0
	fnt=0
	brush=0

PROCEDURE Init(vFamily, fntsize, fntstyle, argbcolor)
	DO CASE
	CASE PCOUNT()=0
		THIS.InitFont("Arial", 10, 0, ARGB(0,0,0))
	CASE PCOUNT()=1
		THIS.InitFont(vFamily, 10, 0, ARGB(0,0,0))
	CASE PCOUNT()=2
		THIS.InitFont(vFamily, fntsize, 0, ARGB(0,0,0))
	CASE PCOUNT()=3
		THIS.InitFont(vFamily, fntsize, fntstyle, ARGB(0,0,0))
	CASE PCOUNT()=4
		THIS.InitFont(vFamily, fntsize, fntstyle, argbcolor)
	ENDCASE

PROTECTED PROCEDURE InitFont(vFamily, fntsize, fntstyle, argbcolor)
	THIS.ClearFont

	DO CASE
	CASE VARTYPE(m.vFamily)="O"
		THIS.hfontfamily = vFamily.hfontfamily
	CASE VARTYPE(m.vFamily)="N"
		THIS.hfontfamily = m.vFamily
	CASE VARTYPE(m.vFamily)="C"
		LOCAL hfontfamily
		hfontfamily=0
		THIS.errorcode = GdipCreateFontFamilyFromName(;
			ToWideChar(m.vFamily), 0, @m.hfontfamily)
		THIS.hfontfamily = m.hfontfamily
		THIS.fontfamilycreated=.T.
	OTHERWISE
		RETURN .F.
	ENDCASE

	LOCAL brush, fnt
	STORE 0 TO brush, fnt
	= GdipCreateSolidFill(m.argbcolor, @brush)

	THIS.errorcode = GdipCreateFont(THIS.hfontfamily,;
		m.fntsize, m.fntstyle, 3, @m.fnt)

	THIS.fnt = m.fnt
	THIS.brush = m.brush
RETURN (THIS.errorcode=0)

PROCEDURE Destroy
	THIS.ClearFont

PROCEDURE ClearFont
	IF THIS.brush <> 0
		= GdipDeleteBrush(THIS.brush)
		THIS.brush=0
	ENDIF
	IF THIS.fnt <> 0
		= GdipDeleteFont(THIS.fnt)
		THIS.fnt=0
	ENDIF
	IF THIS.hfontfamily <> 0 AND THIS.fontfamilycreated
		= GdipDeleteFontFamily(THIS.hfontfamily)
		THIS.hfontfamily=0
	ENDIF
	THIS.fontfamilycreated=.F.
ENDDEFINE

********************************************************************
DEFINE CLASS gdipen As gdiplusbase
	hpen=0

PROCEDURE Init(nArgbcolor, nPenWidth)
	LOCAL hpen
	hpen=0
	THIS.errorcode = GdipCreatePen1(nArgbcolor, nPenWidth, 0, @hpen)
	THIS.hpen = m.hpen

PROCEDURE Destroy
	IF THIS.hpen <> 0
		= GdipDeletePen(THIS.hpen)
		THIS.hpen=0
	ENDIF

ENDDEFINE

********************************************************************
DEFINE CLASS gdimatrix As gdiplusbase
	hmatrix=0
	m11=0
	m12=0
	m21=0
	m22=0
	dx=0
	dy=0

PROCEDURE Init(m11, m12, m21, m22, dx, dy)
	LOCAL hmatrix
	hmatrix=0

	IF VARTYPE(m.m11)="N" AND VARTYPE(m.m12)="N";
		AND VARTYPE(m.m21)="N" AND VARTYPE(m.m22)="N"
		
		IF VARTYPE(m.dx) <> "N"
			dx = 0
		ENDIF
		IF VARTYPE(m.dy) <> "N"
			dy = 0
		ENDIF

		THIS.errorcode = GdipCreateMatrix2(m11, m12,;
			m21, m22, dx, dy, @m.hmatrix)
	ELSE
	* creates identity matrix [(1,0), (0,1)] zero offset
		THIS.errorcode = GdipCreateMatrix(@m.hmatrix)
	ENDIF

	THIS.hmatrix = m.hmatrix
	THIS.GetElements

PROCEDURE Destroy
	IF THIS.hmatrix <> 0
		= GdipDeleteMatrix(THIS.hmatrix)
		THIS.hmatrix=0
	ENDIF

PROCEDURE SetElements(m11, m12, m21, m22, dx, dy)
	IF VARTYPE(m.dx) <> "N"
		dx = 0
	ENDIF
	IF VARTYPE(m.dy) <> "N"
		dy = 0
	ENDIF

	THIS.errorcode = GdipSetMatrixElements(THIS.hmatrix,;
		m.m11, m.m12, m.m21, m.m22, m.dx, m.dy)

PROCEDURE GetElements
	LOCAL cCoords
	cCoords = REPLICATE(CHR(0), 24)
	THIS.errorcode = GdipGetMatrixElements(THIS.hmatrix, @m.cCoords)

	IF THIS.errorcode = 0
		THIS.m11 = Float2Int(buf2dword(SUBSTR(m.cCoords, 1,4)))
		THIS.m12 = Float2Int(buf2dword(SUBSTR(m.cCoords, 5,4)))
		THIS.m21 = Float2Int(buf2dword(SUBSTR(m.cCoords, 9,4)))
		THIS.m22 = Float2Int(buf2dword(SUBSTR(m.cCoords, 13,4)))
		THIS.dx = Float2Int(buf2dword(SUBSTR(m.cCoords, 17,4)))
		THIS.dy = Float2Int(buf2dword(SUBSTR(m.cCoords, 21,4)))
	ENDIF

PROCEDURE Translate(nOffsetX, nOffsetY, nOrder)
	IF VARTYPE(m.nOrder) <> "N"
		nOrder=0
	ENDIF
	THIS.errorcode = GdipTranslateMatrix(THIS.hmatrix,;
		m.nOffsetX, m.nOffsetY, m.nOrder)

PROCEDURE Scale(nScaleX, nScaleY, nOrder)
	IF VARTYPE(m.nOrder) <> "N"
		nOrder=0
	ENDIF
	THIS.errorcode = GdipScaleMatrix(THIS.hmatrix,;
		m.nScaleX, m.nScaleY, m.nOrder)

PROCEDURE Shear(nShearX, nShearY, nOrder)
	IF VARTYPE(m.nOrder) <> "N"
		nOrder=0
	ENDIF
	THIS.errorcode = GdipShearMatrix(THIS.hmatrix,;
		m.nShearX, m.nShearY, m.nOrder)

PROCEDURE Rotate(nAngle, nOrder)
	IF VARTYPE(m.nOrder) <> "N"
		nOrder=0
	ENDIF
	THIS.errorcode = GdipRotateMatrix(THIS.hmatrix,;
		m.nAngle, m.nOrder)

PROCEDURE Invert
	THIS.errorcode = GdipInvertMatrix(THIS.hmatrix)

ENDDEFINE

********************************************************************
DEFINE CLASS gdistringformat As gdiplusbase
#DEFINE LANG_NEUTRAL 0
	fmt=0

PROCEDURE Init(nAttributes)
	LOCAL nFmt
	nFmt=0
	THIS.errorcode = GdipCreateStringFormat(nAttributes, LANG_NEUTRAL, @nFmt)
	THIS.fmt=m.nFmt

PROCEDURE Destroy
	IF THIS.fmt <> 0
		= GdipDeleteStringFormat(THIS.fmt)
		THIS.fmt=0
	ENDIF

ENDDEFINE

********************************************************************
DEFINE CLASS gdiplusinit As Custom
* an instance of gdiplusinit should be created before
* and released after using any of gdi+ objects
PROTECTED hToken
	errorcode=0
	initialized=.F.

PROCEDURE Init
	THIS.declare
	THIS.initialized = THIS.InitGDIplus()

PROCEDURE Destroy
	THIS.ReleaseGDIplus

PROTECTED FUNCTION InitGDIplus
	LOCAL hToken, cInput
	hToken=0
	cInput = PADR(CHR(1),16,CHR(0))
	TRY
		THIS.errorcode = GdiplusStartup(@hToken, @cInput, 0)
	CATCH
		THIS.errorcode = -1
	ENDTRY
	THIS.hToken=hToken
RETURN (THIS.errorcode=0)

PROTECTED PROCEDURE ReleaseGDIplus
	IF THIS.hToken <> 0
		= GdiplusShutdown(THIS.hToken)
		THIS.hToken=0
	ENDIF

PROCEDURE decl
THIS.declare

PROCEDURE declare
	DECLARE INTEGER IsWindow IN user32 INTEGER hwnd
	DECLARE INTEGER GetDesktopWindow IN user32
	DECLARE INTEGER GetObjectType IN gdi32 INTEGER hObject
	DECLARE INTEGER DeleteObject IN gdi32 INTEGER hObject
	DECLARE INTEGER GdipDeleteFont IN gdiplus INTEGER fnt
	DECLARE INTEGER GdipDeleteFontFamily IN gdiplus INTEGER FontFamily
	DECLARE INTEGER GdiplusShutdown IN gdiplus INTEGER token
	DECLARE INTEGER GdipDeleteGraphics IN gdiplus INTEGER graphics
	DECLARE INTEGER GdipDeletePen IN gdiplus INTEGER gdipen
	DECLARE INTEGER GdipDeleteBrush IN gdiplus INTEGER brush
	DECLARE INTEGER CLSIDFromString IN ole32 STRING lpsz, STRING @pclsid
	DECLARE INTEGER GdipCreateMatrix IN gdiplus INTEGER @matrix
	DECLARE INTEGER GdipDeleteMatrix IN gdiplus INTEGER matrix
	DECLARE INTEGER GdipDeleteStringFormat IN gdiplus INTEGER fmt
	DECLARE INTEGER GdipInvertMatrix IN gdiplus INTEGER matrix

	DECLARE INTEGER GdipSetSmoothingMode IN gdiplus;
		INTEGER graphics, INTEGER smoothingMode

	DECLARE INTEGER GdipGetSmoothingMode IN gdiplus;
		INTEGER graphics, INTEGER @smoothingMode

	DECLARE INTEGER GdipCreateMatrix2 IN gdiplus;
		SINGLE m11, SINGLE m12, SINGLE m21, SINGLE m22,;
		SINGLE dx, SINGLE dy, INTEGER @matrix

	DECLARE INTEGER GdipMeasureString IN gdiplus;
		INTEGER graphics, STRING txt, INTEGER length,;
		INTEGER fnt, STRING layoutRect, INTEGER stringFormat,;
		STRING @boundingBox, INTEGER @codepointsFitted,;
		INTEGER @linesFilled

	DECLARE INTEGER GdipCreateStringFormat IN gdiplus;
		INTEGER formatAttributes, INTEGER language, INTEGER @

	DECLARE INTEGER GdipCreateSolidFill IN gdiplus;
		INTEGER clr, INTEGER @brush

	DECLARE INTEGER GdiplusStartup IN gdiplus;
		INTEGER @token, STRING @input, INTEGER output

	DECLARE INTEGER StringFromGUID2 IN ole32;
		STRING rguid, STRING @lpsz, INTEGER cchMax

	DECLARE INTEGER GdipCreateFromHDC IN gdiplus;
		INTEGER hdc, INTEGER @graphics

	DECLARE INTEGER GdipCreateFromHWND IN gdiplus;
		INTEGER hWindow, INTEGER @graphics

	DECLARE INTEGER GdipCreateFromHDC2 IN gdiplus;
		INTEGER hdc, INTEGER hDevice, INTEGER @graphics

	DECLARE INTEGER GdipLoadImageFromFile IN gdiplus;
		STRING filename, INTEGER @img

	DECLARE INTEGER GdipDisposeImage IN gdiplus INTEGER img

	DECLARE INTEGER GdipGetImageType IN gdiplus;
		INTEGER img, INTEGER @imgtype

	DECLARE INTEGER GdipGetImageWidth IN gdiplus;
		INTEGER img, INTEGER @imgwidth

	DECLARE INTEGER GdipGetImageHeight IN gdiplus;
		INTEGER img, INTEGER @imgheight

	DECLARE INTEGER GdipGetImageFlags IN gdiplus;
		INTEGER img, INTEGER @imgflags

	DECLARE INTEGER GdipGetImageRawFormat IN gdiplus;
		INTEGER img, STRING @guid

	DECLARE INTEGER GdipDrawImageRectI IN gdiplus;
		INTEGER graphics, INTEGER img, INTEGER x, INTEGER y,;
		INTEGER imgwidth, INTEGER imgheight

	DECLARE INTEGER GdipSaveImageToFile IN gdiplus;
		INTEGER img, STRING filename,;
		STRING clsidEncoder, INTEGER encoderParams

	DECLARE INTEGER GdipCreateBitmapFromHBITMAP IN gdiplus;
		INTEGER hbm, INTEGER hpal, INTEGER @hbitmap

	DECLARE INTEGER GdipCreateBitmapFromHICON IN gdiplus;
		INTEGER hicon, INTEGER @hbitmap

	DECLARE INTEGER GdipCreateHICONFromBitmap IN gdiplus;
		INTEGER hbitmap, INTEGER @hbmReturn

	DECLARE INTEGER GdipCreateBitmapFromGdiDib IN gdiplus;
		INTEGER gdiBitmapInfo, INTEGER gdiBitmapData, INTEGER @hBitmap

	DECLARE INTEGER GdipCreateHBITMAPFromBitmap IN gdiplus;
		INTEGER bitmap, INTEGER @hbmReturn, INTEGER background

	DECLARE INTEGER GdipCreateBitmapFromGraphics IN gdiplus;
		INTEGER width, INTEGER height,;
		INTEGER graphics, INTEGER @bitmap

	DECLARE INTEGER GdipCloneBitmapArea IN gdiplus;
		SINGLE x, SINGLE y, SINGLE width, SINGLE height,;
		INTEGER fmt, INTEGER srcBitmap, INTEGER @dstBitmap

	DECLARE INTEGER GdipGetImageGraphicsContext IN gdiplus;
		INTEGER img, INTEGER @graphics

	DECLARE INTEGER GdipGetDC IN gdiplus;
		INTEGER graphics, INTEGER @hdc

	DECLARE INTEGER GdipReleaseDC IN gdiplus;
		INTEGER graphics, INTEGER hdc

	DECLARE INTEGER GdipCreateFont IN gdiplus;
		INTEGER fontFamily, SINGLE emSize,;
		INTEGER fontstyle, INTEGER unit, INTEGER @fnt

	DECLARE INTEGER GdipCreateFontFamilyFromName IN gdiplus;
		STRING familyname, INTEGER fontCollection, INTEGER @FontFamily

	DECLARE INTEGER GdipCreatePen1 IN gdiplus;
		INTEGER color, SINGLE penwidth, INTEGER unit, INTEGER @gdipen

	DECLARE INTEGER GdipFillRectangle IN gdiplus;
		INTEGER graphics, INTEGER brush,;
		SINGLE x, SINGLE y, SINGLE width, SINGLE height

	DECLARE INTEGER GdipFillEllipse IN gdiplus;
		INTEGER graphics, INTEGER brush,;
		SINGLE x, SINGLE y, SINGLE width, SINGLE height

	DECLARE GdipDrawRectangle IN gdiplus;
		INTEGER graphics, INTEGER gdipen,;
		SINGLE x, SINGLE y, SINGLE width, SINGLE height

	DECLARE GdipDrawEllipse IN gdiplus;
		INTEGER graphics, INTEGER gdipen,;
		SINGLE x, SINGLE y, SINGLE width, SINGLE height

	DECLARE GdipDrawLine IN gdiplus;
		INTEGER graphics, INTEGER gdipen,;
		SINGLE x, SINGLE y, SINGLE width, SINGLE height

	DECLARE INTEGER GdipDrawString IN gdiplus;
		INTEGER graphics, STRING widechar, INTEGER length,;
		INTEGER fnt, STRING @rect, INTEGER stringFormat, INTEGER brush

	DECLARE INTEGER GdipSetTextRenderingHint IN gdiplus;
		INTEGER graphics, INTEGER TextRenderingHint

	DECLARE INTEGER GdipNewInstalledFontCollection IN gdiplus;
		INTEGER @fontCollection

	DECLARE INTEGER GdipGetFontCollectionFamilyCount IN gdiplus;
		INTEGER fontCollection, INTEGER @numFound

	DECLARE INTEGER GdipGetFontCollectionFamilyList IN gdiplus;
		INTEGER fontCollection, INTEGER numSought,;
		STRING @gpfamilies, INTEGER @numFound

	DECLARE INTEGER GdipGetFamilyName IN gdiplus;
		INTEGER fontfamily, STRING @familyname, INTEGER language

	DECLARE INTEGER GdipIsStyleAvailable IN gdiplus;
		INTEGER fontfamily, INTEGER fontstyle, INTEGER @IsStyleAvail

	DECLARE INTEGER GdipSetWorldTransform IN gdiplus;
		INTEGER graphics, INTEGER matrix

	DECLARE INTEGER GdipResetWorldTransform IN gdiplus;
		INTEGER graphics

	DECLARE INTEGER GdipRotateMatrix IN gdiplus;
		INTEGER matrix, SINGLE angle, INTEGER ord

	DECLARE INTEGER GdipTranslateMatrix IN gdiplus;
		INTEGER matrix, SINGLE offsetX,;
		SINGLE offsetY, INTEGER ord

	DECLARE INTEGER GdipScaleMatrix IN gdiplus;
		INTEGER matrix, SINGLE scaleX,;
		SINGLE scaleY, INTEGER ord

	DECLARE INTEGER GdipShearMatrix IN gdiplus;
		INTEGER matrix, SINGLE shearX,;
		SINGLE shearY, INTEGER ord

	DECLARE INTEGER GdipSetMatrixElements IN gdiplus;
		INTEGER matrix, SINGLE m11, SINGLE m12,;
		SINGLE m21, SINGLE m22,;
		SINGLE dx, SINGLE dy

	DECLARE INTEGER GdipGetMatrixElements IN gdiplus;
		INTEGER matrix, STRING @matrixOut

ENDDEFINE

DEFINE CLASS rect As Session
	rleft=0
	rtop=0
	rwidth=0
	rheight=0

PROCEDURE Init(nLeft, nTop, nWidth, nHeight)
	THIS.rleft=m.nLeft
	THIS.rtop=m.nTop
	THIS.rwidth=m.nWidth
	THIS.rheight=m.nHeight

FUNCTION ToString As String
RETURN num2dword(THIS.rleft) +;
	num2dword(THIS.rtop) +;
	num2dword(THIS.rwidth) +;
	num2dword(THIS.rheight)

PROCEDURE FromString(cBuffer)
	THIS.rleft=buf2dword(SUBSTR(cBuffer,1,4))
	THIS.rtop=buf2dword(SUBSTR(cBuffer,5,4))
	THIS.rwidth=buf2dword(SUBSTR(cBuffer,9,4))
	THIS.rheight=buf2dword(SUBSTR(cBuffer,13,4))

PROCEDURE FromString1(cBuffer)
	LOCAL nRight, nBottom
	THIS.rleft=buf2dword(SUBSTR(cBuffer,1,4))
	THIS.rtop=buf2dword(SUBSTR(cBuffer,5,4))
	nRight=buf2dword(SUBSTR(cBuffer,9,4))
	nBottom=buf2dword(SUBSTR(cBuffer,13,4))
	THIS.rwidth=nRight-THIS.rleft+1
	THIS.rheight=nBottom-THIS.rtop+1

ENDDEFINE

DEFINE CLASS rectf As rect

FUNCTION ToString As String
RETURN num2dword(Int2Float(THIS.rleft)) +;
	num2dword(Int2Float(THIS.rtop)) +;
	num2dword(Int2Float(THIS.rwidth)) +;
	num2dword(Int2Float(THIS.rheight))

PROCEDURE FromString(cBuffer)
	rect::FromString(cBuffer)
	THIS.rleft=Float2Int(THIS.rleft)
	THIS.rtop=Float2Int(THIS.rtop)
	THIS.rwidth=Float2Int(THIS.rwidth)
	THIS.rheight=Float2Int(THIS.rheight)

PROCEDURE FromString1(cBuffer)
	rect::FromString1(cBuffer)
	THIS.rleft=Float2Int(THIS.rleft)
	THIS.rtop=Float2Int(THIS.rtop)
	THIS.rwidth=Float2Int(THIS.rwidth)
	THIS.rheight=Float2Int(THIS.rheight)

ENDDEFINE

*********************** static functions **************************
#DEFINE REAL_BIAS 127
#DEFINE REAL_MANTISSA_SIZE 23
#DEFINE REAL_NEGATIVE 0x80000000
#DEFINE EXPONENT_MASK 0x7F800000
#DEFINE MANTISSA_MASK 0x7FFFFF

FUNCTION GUIDToString(cGUID)
	LOCAL cBuffer, nBufsize
	nBufsize=128
	cBuffer = REPLICATE(CHR(0), nBufsize*2)
	= StringFromGUID2(cGUID, @cBuffer, nBufsize)
	cBuffer = SUBSTR(cBuffer, 1, AT(CHR(0)+CHR(0), cBuffer))
RETURN STRCONV(cBuffer,6)

FUNCTION StringToCLSID(cStr)
	LOCAL cBuffer
	cBuffer=REPLICATE(CHR(0),16)
	= CLSIDFromString(ToWideChar(cStr), @cBuffer)
RETURN m.cBuffer

FUNCTION ToWideChar(cStr)
RETURN STRCONV(m.cStr+CHR(0),5)

FUNCTION ARGB(nRedValue, nGreenValue, nBlueValue, nAlphaValue)
	IF VARTYPE(m.nAlphaValue) <> "N"
		nAlphaValue=0xff
	ENDIF
RETURN BITOR(BITLSHIFT(m.nAlphaValue,24), BITLSHIFT(m.nRedValue,16),;
	BITLSHIFT(m.nGreenValue,8), m.nBlueValue)

FUNCTION ColorToARGB(nColor, nAlphaValue)
	LOCAL nRedValue, nGreenValue, nBlueValue
	nBlueValue = BITRSHIFT(m.nColor, 16)
	nGreenValue = BITRSHIFT(BITAND(m.nColor, 0x00ff00), 8)
	nRedValue = BITAND(m.nColor, 0x0000ff)
RETURN ARGB(m.nRedValue, m.nGreenValue, m.nBlueValue, m.nAlphaValue)

FUNCTION Float2Int(num)
* converts 32-bit float form to FoxPro numeric
	IF num = 0
		RETURN 0
	ENDIF
	LOCAL sgn, exponent, mantissa
	sgn = IIF(BITTEST(num,31), -1,1)
	exponent = BITRSHIFT(BITAND(num, EXPONENT_MASK),;
		REAL_MANTISSA_SIZE) - REAL_BIAS
	mantissa = BITAND(num,;
		MANTISSA_MASK) / 2^(REAL_MANTISSA_SIZE-exponent)
RETURN (2^exponent + mantissa) * sgn

FUNCTION Int2Float(num)
* converts FoxPro numeric to 32-bit float form
	LOCAL sgn, exponent, mantissa
	DO CASE
	CASE num < 0
		sgn = REAL_NEGATIVE
		num = -num
	CASE num > 0
		sgn = 0
	OTHERWISE
		RETURN 0
	ENDCASE
	exponent = FLOOR(LOG(num)/LOG(2))
	mantissa = (num - 2^exponent)* 2^(REAL_MANTISSA_SIZE-exponent)
	exponent = BITLSHIFT(exponent+REAL_BIAS, REAL_MANTISSA_SIZE)
RETURN BITOR(sgn, exponent, mantissa)

FUNCTION buf2dword(lcBuffer)
* converts DWORD string buffer to FoxPro numeric
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
* converts WORD string buffer to FoxPro numeric
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION num2dword(lnValue)
* converts FoxPro numeric to DWORD string buffer
#DEFINE m0 0x0000100
#DEFINE m1 0x0010000
#DEFINE m2 0x1000000
	IF lnValue < 0
		lnValue = 0x100000000 + lnValue
	ENDIF
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)

FUNCTION num2word(lnValue)
* converts FoxPro numeric to WORD string buffer
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))  
```  
***  


## Listed functions:
[CLSIDFromString](../libraries/ole32/CLSIDFromString.md)  
[DeleteObject](../libraries/gdi32/DeleteObject.md)  
[GdipCloneBitmapArea](../libraries/gdiplus/GdipCloneBitmapArea.md)  
[GdipCreateBitmapFromGdiDib](../libraries/gdiplus/GdipCreateBitmapFromGdiDib.md)  
[GdipCreateBitmapFromGraphics](../libraries/gdiplus/GdipCreateBitmapFromGraphics.md)  
[GdipCreateBitmapFromHBITMAP](../libraries/gdiplus/GdipCreateBitmapFromHBITMAP.md)  
[GdipCreateBitmapFromHICON](../libraries/gdiplus/GdipCreateBitmapFromHICON.md)  
[GdipCreateFont](../libraries/gdiplus/GdipCreateFont.md)  
[GdipCreateFontFamilyFromName](../libraries/gdiplus/GdipCreateFontFamilyFromName.md)  
[GdipCreateFromHDC](../libraries/gdiplus/GdipCreateFromHDC.md)  
[GdipCreateFromHDC2](../libraries/gdiplus/GdipCreateFromHDC2.md)  
[GdipCreateFromHWND](../libraries/gdiplus/GdipCreateFromHWND.md)  
[GdipCreateHBITMAPFromBitmap](../libraries/gdiplus/GdipCreateHBITMAPFromBitmap.md)  
[GdipCreateHICONFromBitmap](../libraries/gdiplus/GdipCreateHICONFromBitmap.md)  
[GdipCreateMatrix](../libraries/gdiplus/GdipCreateMatrix.md)  
[GdipCreateMatrix2](../libraries/gdiplus/GdipCreateMatrix2.md)  
[GdipCreatePen1](../libraries/gdiplus/GdipCreatePen1.md)  
[GdipCreateSolidFill](../libraries/gdiplus/GdipCreateSolidFill.md)  
[GdipCreateStringFormat](../libraries/gdiplus/GdipCreateStringFormat.md)  
[GdipDeleteBrush](../libraries/gdiplus/GdipDeleteBrush.md)  
[GdipDeleteFont](../libraries/gdiplus/GdipDeleteFont.md)  
[GdipDeleteFontFamily](../libraries/gdiplus/GdipDeleteFontFamily.md)  
[GdipDeleteGraphics](../libraries/gdiplus/GdipDeleteGraphics.md)  
[GdipDeleteMatrix](../libraries/gdiplus/GdipDeleteMatrix.md)  
[GdipDeletePen](../libraries/gdiplus/GdipDeletePen.md)  
[GdipDeleteStringFormat](../libraries/gdiplus/GdipDeleteStringFormat.md)  
[GdipDisposeImage](../libraries/gdiplus/GdipDisposeImage.md)  
[GdipDrawImageRectI](../libraries/gdiplus/GdipDrawImageRectI.md)  
[GdipDrawRectangle](../libraries/gdiplus/GdipDrawRectangle.md)  
[GdipDrawString](../libraries/gdiplus/GdipDrawString.md)  
[GdipFillRectangle](../libraries/gdiplus/GdipFillRectangle.md)  
[GdipGetDC](../libraries/gdiplus/GdipGetDC.md)  
[GdipGetFamilyName](../libraries/gdiplus/GdipGetFamilyName.md)  
[GdipGetFontCollectionFamilyCount](../libraries/gdiplus/GdipGetFontCollectionFamilyCount.md)  
[GdipGetFontCollectionFamilyList](../libraries/gdiplus/GdipGetFontCollectionFamilyList.md)  
[GdipGetImageFlags](../libraries/gdiplus/GdipGetImageFlags.md)  
[GdipGetImageGraphicsContext](../libraries/gdiplus/GdipGetImageGraphicsContext.md)  
[GdipGetImageHeight](../libraries/gdiplus/GdipGetImageHeight.md)  
[GdipGetImageRawFormat](../libraries/gdiplus/GdipGetImageRawFormat.md)  
[GdipGetImageType](../libraries/gdiplus/GdipGetImageType.md)  
[GdipGetImageWidth](../libraries/gdiplus/GdipGetImageWidth.md)  
[GdipGetMatrixElements](../libraries/gdiplus/GdipGetMatrixElements.md)  
[GdipGetSmoothingMode](../libraries/gdiplus/GdipGetSmoothingMode.md)  
[GdipInvertMatrix](../libraries/gdiplus/GdipInvertMatrix.md)  
[GdipIsStyleAvailable](../libraries/gdiplus/GdipIsStyleAvailable.md)  
[GdipLoadImageFromFile](../libraries/gdiplus/GdipLoadImageFromFile.md)  
[GdipMeasureString](../libraries/gdiplus/GdipMeasureString.md)  
[GdipNewInstalledFontCollection](../libraries/gdiplus/GdipNewInstalledFontCollection.md)  
[GdipReleaseDC](../libraries/gdiplus/GdipReleaseDC.md)  
[GdipResetWorldTransform](../libraries/gdiplus/GdipResetWorldTransform.md)  
[GdipRotateMatrix](../libraries/gdiplus/GdipRotateMatrix.md)  
[GdipSaveImageToFile](../libraries/gdiplus/GdipSaveImageToFile.md)  
[GdipScaleMatrix](../libraries/gdiplus/GdipScaleMatrix.md)  
[GdipSetMatrixElements](../libraries/gdiplus/GdipSetMatrixElements.md)  
[GdipSetSmoothingMode](../libraries/gdiplus/GdipSetSmoothingMode.md)  
[GdipSetTextRenderingHint](../libraries/gdiplus/GdipSetTextRenderingHint.md)  
[GdipShearMatrix](../libraries/gdiplus/GdipShearMatrix.md)  
[GdipTranslateMatrix](../libraries/gdiplus/GdipTranslateMatrix.md)  
[GdiplusShutdown](../libraries/gdiplus/GdiplusShutdown.md)  
[GdiplusStartup](../libraries/gdiplus/GdiplusStartup.md)  
[GetDesktopWindow](../libraries/user32/GetDesktopWindow.md)  
[GetObjectType](../libraries/gdi32/GetObjectType.md)  
[IsWindow](../libraries/user32/IsWindow.md)  
[StringFromGUID2](../libraries/ole32/StringFromGUID2.md)  

## Comment:
Microsoft&reg; Windows&reg; GDI+ exposes a [flat application programming interface](https://msdn.microsoft.com/en-us/library/windows/desktop/ms533969(v=vs.85).aspx) (API) that consists of about 600 functions implemented in Gdiplus.dll.  
  
```dos
C:\Program Files\Common Files\Microsoft Shared\VFP\gdiplus.dll
```
 

  
For C++ developers the functions in the GDI+ flat API are wrapped in about 40 C++ classes. Visual FoxPro developers are not able to instantiate any such class in pure FoxPro code. That is why the flat API makes a good choice.  
  
July 5, 2004: Visual FoxPro 9 presents new property GdiPlusGraphics. My understanding is that this property is applicable to the ReportListener and probably to the _SCREEN and FoxPro Form objects.  
  
Recommended reading:   
  
Articles of <a href="http://fox.wikis.com/wc.dll?Wiki~MarkusEgger~People">Markus Egger</a>.  
* <a href="http://www.markusegger.com/Articles/Article.aspx?quickid=0305031">The Basics of GDI+</a>   
* <a href="http://www.markusegger.com/Articles/Article.aspx?quickid=03050801">Using GDI+ in ASP.NET Web Applications, Part 1</a>  
* <a href="http://www.markusegger.com/Articles/Article.aspx?quickid=0307031">Using GDI+ in ASP.NET Web Applications, Part 2</a>  
  

* * *  
BINTOC() accepts new parameter in VFP9: bintoc(m.tW,"F") -- conversion to 32-bit float format. That probably makes conversion routines Int2Float and Float2Int in the code above obsolete.  
  
* * *  
May 10, 2006: Names of properties of RECT class have been changed from (Left, Top, Width, Height) to (rleft, rtop, rwidth, rheight). RECTF, a subclass of RECT, could not properly access the methods of the parent class because of those risky names.  
  
* * *  
May 19, 2006: Errors may occur when moving, deleting or copying graphics files that have been used recently for creating GDI+ objects. Most likely  those objects still exist in memory and must be released to enable file operations. This is in a way similar to VFP CLEAR RESOURCES command not clearing cached bitmap file if it is still used in Picture property.  
  
***  

