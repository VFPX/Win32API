[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using the FindMediaType function

## Code:
```foxpro  
DO decl

#DEFINE S_OK  0

#DEFINE CFSTR_MIME_AIFF         "audio/aiff"
#DEFINE CFSTR_MIME_AVI          "video/avi"
#DEFINE CFSTR_MIME_BASICAUDIO   "audio/basic"
#DEFINE CFSTR_MIME_BMP          "image/bmp"
#DEFINE CFSTR_MIME_FRACTALS     "application/fractals"
#DEFINE CFSTR_MIME_GIF          "image/gif"
#DEFINE CFSTR_MIME_HTML         "text/html"
#DEFINE CFSTR_MIME_JPEG         "image/jpeg"
#DEFINE CFSTR_MIME_MPEG         "video/mpeg"
#DEFINE CFSTR_MIME_PDF          "application/pdf"
#DEFINE CFSTR_MIME_PJPEG        "image/pjpeg"
#DEFINE CFSTR_MIME_POSTSCRIPT   "application/postscript"
#DEFINE CFSTR_MIME_QUICKTIME    "video/quicktime"
#DEFINE CFSTR_MIME_RAWDATA      "application/octet-stream"
#DEFINE CFSTR_MIME_RAWDATASTRM  "application/octet-stream"
#DEFINE CFSTR_MIME_RICHTEXT     "text/richtext"
#DEFINE CFSTR_MIME_TEXT         "text/plain"
#DEFINE CFSTR_MIME_TIFF         "image/tiff"
#DEFINE CFSTR_MIME_WAV          "audio/wav"
#DEFINE CFSTR_MIME_XBM          "image/xbm"
#DEFINE CFSTR_MIME_X_AIFF       "audio/x-aiff"
#DEFINE CFSTR_MIME_X_ART        "image/x-jg"
#DEFINE CFSTR_MIME_X_BITMAP     "image/x-xbitmap"
#DEFINE CFSTR_MIME_X_EMF        "image/x-emf"
#DEFINE CFSTR_MIME_X_MSVIDEO    "video/x-msvideo"
#DEFINE CFSTR_MIME_X_PNG        "image/x-png"
#DEFINE CFSTR_MIME_X_REALAUDIO  "audio/x-pn-realaudio"
#DEFINE CFSTR_MIME_X_SGI_MOVIE  "video/x-sgi-movie"
#DEFINE CFSTR_MIME_X_WAV        "audio/x-wav"
#DEFINE CFSTR_MIME_X_WMF        "image/x-wmf"

	CREATE CURSOR csResult (mediatype C(30), clipformat I)

	= FindType(CFSTR_MIME_AIFF)
	= FindType(CFSTR_MIME_AVI)
	= FindType(CFSTR_MIME_BASICAUDIO)
	= FindType(CFSTR_MIME_BMP)
	= FindType(CFSTR_MIME_FRACTALS)
	= FindType(CFSTR_MIME_GIF)
	= FindType(CFSTR_MIME_HTML)
	= FindType(CFSTR_MIME_JPEG)
	= FindType(CFSTR_MIME_MPEG)
	= FindType(CFSTR_MIME_PDF)
	= FindType(CFSTR_MIME_PJPEG)
	= FindType(CFSTR_MIME_POSTSCRIPT)
	= FindType(CFSTR_MIME_QUICKTIME)
	= FindType(CFSTR_MIME_RAWDATA)
	= FindType(CFSTR_MIME_RAWDATASTRM)
	= FindType(CFSTR_MIME_RICHTEXT)
	= FindType(CFSTR_MIME_TEXT)
	= FindType(CFSTR_MIME_TIFF)
	= FindType(CFSTR_MIME_WAV)
	= FindType(CFSTR_MIME_XBM)
	= FindType(CFSTR_MIME_X_AIFF)
	= FindType(CFSTR_MIME_X_ART)
	= FindType(CFSTR_MIME_X_BITMAP)
	= FindType(CFSTR_MIME_X_EMF)
	= FindType(CFSTR_MIME_X_MSVIDEO)
	= FindType(CFSTR_MIME_X_PNG)
	= FindType(CFSTR_MIME_X_REALAUDIO)
	= FindType(CFSTR_MIME_X_SGI_MOVIE)
	= FindType(CFSTR_MIME_X_WAV)
	= FindType(CFSTR_MIME_X_WMF)
	
	GO TOP
	BROW NORMAL NOWAIT

PROCEDURE FindType (lcMediaType)
	LOCAL lnClipformat
	lnClipformat = 0
	IF FindMediaType(lcMediaType, @lnClipformat) = S_OK
		INSERT INTO csResult VALUES (lcMediaType, lnClipformat)
	ELSE
		INSERT INTO csResult VALUES (lcMediaType, -1)
	ENDIF

PROCEDURE decl
	DECLARE INTEGER FindMediaType IN urlmon;
		STRING rgszTypes, INTEGER @rgcfTypes  
```  
***  


## Listed functions:
[FindMediaType](../libraries/urlmon/FindMediaType.md)  
