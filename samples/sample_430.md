[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to play AVI file on the _screen

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
Custom class **Tavi** plays AVI files on main FoxPro window using API functions from *avifil32* and *msvfw32* libraries. Audio stream is not processed only to make this example more simple.  

See also:

* [Scrolling text on the form horizontally (a newsreel)](sample_352.md)  
* [Scrolling text on the form vertically (a movie cast)](sample_354.md)  
* [Shaking VFP form controls](sample_526.md)  
* [Displaying animated images](sample_355.md)  
* [Form Magnifier](sample_414.md)  

<!-- Anatoliy -->
<a href="?solution=3&src=x430" target=_blank><img src="../images/xmsg_270_48.png" border=0></a>   

  
***  


## Code:
```foxpro  
= PlayAvi("c:\windows\clock.avi", 50, 100, .T.)
* end of main

FUNCTION PlayAvi(cAviFile, nLeft, nTop, lNonstop)
	IF VARTYPE(_screen.avi) = "U"
		_SCREEN.AddObject("avi", "Tavi")
	ENDIF

	WITH _SCREEN.avi
		IF Not .StartPlay(cAviFile, nLeft, nTop, lNonstop)
			= MessageB("Error code: " + LTRIM(STR(.ErrorCode)) +;
				"     " + Chr(13) + .ErrorMsg, 48, "Error")
		ENDIF
	ENDWITH

DEFINE CLASS Tavi As Timer
#DEFINE BHDR_SIZE                   40  && BITMAPINFOHEADER
#DEFINE OF_SHARE_DENY_WRITE         0x00000020
#DEFINE streamtypeVIDEO             "vids"
#DEFINE AVIGETFRAMEF_BESTDISPLAYFMT 1
#DEFINE AVISTREAMREAD_CONVENIENT   -1
#DEFINE AVIFILEINFO_SIZE            108
PROTECTED hAviFile, hVideoStream, hGetFrame, hDrawDC, SrcWidth, SrcHeight,;
	SrcScale, SrcRate, SrcLength, LeftPos, TopPos, starttime, IsDrawing
	Interval=0
	ErrorCode=0
	ErrorMsg=""
	nonstop=.F.

PROCEDURE Init
	THIS.decl
	= AVIFileInit()  && AVI library initialized

PROCEDURE Destroy
	THIS.StopPlay
	= AVIFileExit()  && AVI library released

PROCEDURE Timer
	THIS.DrawFrame

PROCEDURE StartPlay(cFilename, nLeft, nTop, lNonstop)
	THIS.StopPlay
	THIS.nonstop = lNonstop
	IF THIS.OpenFile(m.cFilename)
		THIS.GetFileInfo
		IF THIS.OpenVideoStream()
			THIS.hDrawDC = DrawDibOpen()  && creates a DrawDib DC
			THIS.LeftPos = m.nLeft
			THIS.TopPos = m.nTop
			THIS.starttime = 0
			THIS.IsDrawing = .F.
			THIS.DrawFrame  && draws first frame and then starts timer
			THIS.Interval = Int((THIS.SrcScale/THIS.SrcRate) * 1000)
		ENDIF
	ENDIF
RETURN (THIS.ErrorCode = 0)

PROCEDURE StopPlay
	STORE 0 TO THIS.Interval, THIS.ErrorCode
	THIS.ErrorMsg = ""

	IF Not EMPTY(THIS.hDrawDC)
		= DrawDibClose(THIS.hDrawDC)
		THIS.hDrawDC = 0
	ENDIF
	IF Not EMPTY(THIS.hGetFrame)
		= AVIStreamGetFrameClose(THIS.hGetFrame)
		THIS.hGetFrame = 0
	ENDIF
	IF Not EMPTY(THIS.hVideoStream)
		= AVIStreamRelease(THIS.hVideoStream)  && AVI stream released
		THIS.hVideoStream = 0
	ENDIF
	IF Not EMPTY(THIS.hAviFile)
		= AVIFileRelease(THIS.hAviFile)  && AVI file released
		THIS.hAviFile = 0
	ENDIF

PROTECTED FUNCTION OpenFile(cFilename)
	LOCAL hFile
	hFile = 0
	THIS.ErrorCode = AVIFileOpen(@hFile, cFilename, OF_SHARE_DENY_WRITE, 0)
	IF THIS.ErrorCode = 0
		THIS.hAviFile = m.hFile
		RETURN .T.
	ELSE
		THIS.ErrorMsg="Could not open AVI file"
		RETURN .F.
	ENDIF

PROTECTED FUNCTION OpenVideoStream
	LOCAL hStream, nFormatFlag

	hStream = 0
	THIS.ErrorCode = AVIFileGetStream(THIS.hAviFile,;
		@hStream, buf2dword(streamtypeVIDEO), 0)

	IF THIS.ErrorCode = 0
		THIS.hVideoStream = m.hStream
		nFormatFlag = 0  && or AVIGETFRAMEF_BESTDISPLAYFMT
		THIS.hGetFrame = AVIStreamGetFrameOpen(THIS.hVideoStream, nFormatFlag)

		IF THIS.hGetFrame = 0
			THIS.ErrorCode = GetLastError()
			THIS.ErrorMsg="Could not create GetFrame handle"
			RETURN .F.
		ELSE
			RETURN .T.
		ENDIF
	ELSE
		THIS.ErrorCode = GetLastError()
		THIS.ErrorMsg="Could not open video stream"
		RETURN .F.
	ENDIF

PROTECTED PROCEDURE DrawFrame
	IF THIS.IsDrawing Or THIS.hVideoStream = 0
		RETURN
	ENDIF
	THIS.IsDrawing = .T.

	LOCAL hWindow, hDC, hFrame, cBuffer, nBufsize, nTime, nSample
	
	* calculating next sample to show
	IF THIS.starttime = 0
		THIS.starttime = GetTickCount()
	ENDIF

	nTime = GetTickCount() - THIS.starttime
	nSample = AVIStreamTimeToSample(THIS.hVideoStream, nTime)
	hFrame = AVIStreamGetFrame(THIS.hGetFrame, nSample)
	
	IF hFrame <> 0
		hWindow = GetActiveWindow()  && main FoxPro window
		hDC = GetWindowDC(hWindow)

		* calculating offset to bits
		nBufsize = BHDR_SIZE
		cBuffer = Repli(Chr(0), nBufsize)
		= AVIStreamReadFormat(THIS.hVideoStream, 0, @cBuffer, @nBufsize)

		* draw frame using default width and height (-1)
		= DrawDibDraw(THIS.hDrawDC, hDC, THIS.LeftPos, THIS.TopPos, -1, -1,;
			hFrame, hFrame+nBufsize, 0, 0,;
			THIS.SrcWidth, THIS.SrcHeight, 0)

		= ReleaseDC(hWindow, hDC)
	ENDIF

	IF nSample >= THIS.SrcLength-1
		IF THIS.nonstop
			THIS.starttime = 0  && continue playing...
		ELSE
			THIS.StopPlay
		ENDIF
	ENDIF
	THIS.IsDrawing = .F.

PROTECTED PROCEDURE GetFileInfo  && obtains AVI file parameters
	LOCAL cBuffer
	cBuffer = Repli(Chr(0), AVIFILEINFO_SIZE)
	= AVIFileInfo(THIS.hAviFile, @cBuffer, AVIFILEINFO_SIZE)
	THIS.SrcWidth = buf2dword(SUBSTR(cBuffer, 21,4))
	THIS.SrcHeight = buf2dword(SUBSTR(cBuffer, 25,4))
	THIS.SrcScale = buf2dword(SUBSTR(cBuffer, 29,4))
	THIS.SrcRate = buf2dword(SUBSTR(cBuffer, 33,4))
	IF THIS.SrcRate = 0
		THIS.SrcRate = MAX(THIS.SrcScale, 1)
	ENDIF
	THIS.SrcLength = buf2dword(SUBSTR(cBuffer, 37,4))

PROTECTED PROCEDURE decl
	DECLARE AVIFileInit IN avifil32
	DECLARE AVIFileExit IN avifil32
	DECLARE INTEGER DrawDibOpen IN msvfw32
	DECLARE INTEGER DrawDibClose IN msvfw32 INTEGER hdd
	DECLARE INTEGER AVIFileRelease IN avifil32 INTEGER pfile
	DECLARE INTEGER AVIStreamRelease IN avifil32 INTEGER pavi
	DECLARE INTEGER AVIStreamGetFrameClose IN avifil32 INTEGER pget
	DECLARE INTEGER AVIStreamGetFrame IN avifil32 INTEGER pgf, LONG lPos
	DECLARE INTEGER ReleaseDC IN user32 INTEGER hwnd, INTEGER dc
	DECLARE INTEGER GetWindowDC IN user32 INTEGER hwnd
	DECLARE INTEGER GetActiveWindow IN user32
	DECLARE INTEGER GetTickCount IN kernel32
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER AVIFileOpen IN avifil32;
		INTEGER @ppfile, STRING szFile,;
		INTEGER mode, INTEGER pclsidHandler

	DECLARE INTEGER AVIFileInfo IN avifil32;
		INTEGER pfile, STRING @pfi, INTEGER lSize

	DECLARE INTEGER AVIFileGetStream IN avifil32;
		INTEGER pfile, INTEGER @ppavi,;
		INTEGER fccType, INTEGER lParam

	DECLARE INTEGER AVIStreamGetFrameOpen IN avifil32;
		INTEGER pavi, INTEGER lpbiWanted

	DECLARE INTEGER DrawDibDraw IN msvfw32;
		INTEGER hdd, INTEGER hdc, INTEGER xDst, INTEGER yDst,;
		INTEGER dxDst, INTEGER dyDst, INTEGER lpbi, INTEGER lpBits,;
		INTEGER xSrc, INTEGER ySrc, INTEGER dxSrc, INTEGER dySrc,;
		INTEGER wFlags

	DECLARE RtlMoveMemory IN kernel32 As CopyMemory;
		STRING @Destination, INTEGER Source, INTEGER nLength

	DECLARE INTEGER AVIStreamReadFormat IN avifil32;
		INTEGER pavi, INTEGER lPos, STRING @lpFormat, INTEGER @lpcbFormat

	DECLARE INTEGER AVIStreamTimeToSample IN avifil32;
		INTEGER pavi, LONG lTime
ENDDEFINE

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[AVIFileExit](../libraries/avifil32/AVIFileExit.md)  
[AVIFileGetStream](../libraries/avifil32/AVIFileGetStream.md)  
[AVIFileInfo](../libraries/avifil32/AVIFileInfo.md)  
[AVIFileInit](../libraries/avifil32/AVIFileInit.md)  
[AVIFileOpen](../libraries/avifil32/AVIFileOpen.md)  
[AVIFileRelease](../libraries/avifil32/AVIFileRelease.md)  
[AVIStreamGetFrame](../libraries/avifil32/AVIStreamGetFrame.md)  
[AVIStreamGetFrameClose](../libraries/avifil32/AVIStreamGetFrameClose.md)  
[AVIStreamGetFrameOpen](../libraries/avifil32/AVIStreamGetFrameOpen.md)  
[AVIStreamReadFormat](../libraries/avifil32/AVIStreamReadFormat.md)  
[AVIStreamRelease](../libraries/avifil32/AVIStreamRelease.md)  
[AVIStreamTimeToSample](../libraries/avifil32/AVIStreamTimeToSample.md)  
[DrawDibClose](../libraries/msvfw32/DrawDibClose.md)  
[DrawDibDraw](../libraries/msvfw32/DrawDibDraw.md)  
[DrawDibOpen](../libraries/msvfw32/DrawDibOpen.md)  
[GetActiveWindow](../libraries/user32/GetActiveWindow.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetTickCount](../libraries/kernel32/GetTickCount.md)  
[GetWindowDC](../libraries/user32/GetWindowDC.md)  
[ReleaseDC](../libraries/user32/ReleaseDC.md)  

## Comment:
Any other window can be used as a target (or a silver screen, if you like) for playing AVI files: FoxPro form, Windows desktop etc. Use that window handle instead of the handle obtained through the GetActiveWindow in the code above.   
  
Technically, you can even play AVIs on a MessageBox window, once you know its window handle (examples [424](sample_424.md) and [434](sample_434.md) explain how to obtain such handle).  
  
Note that on the last sample, the *DrawFrame* method either stops playing the AVI or resumes it from the first sample, depending on the *nonstop* property.  
  
The set of DrawDib functions used in this example can be substituted with a call to the StretchDIBits.  
  

***  
Playing multimedia files in .NET code is a snap. Once you download and install DirectX SDK (merely 450 Mb) you are almost done.  
  
***  

