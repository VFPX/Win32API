[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Printing Image File, programmatically set print page orientation to landscape

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
The images in this code sample are handled with the help of GDI+ objects instantiated from [VFP library of GDI+ classes](sample_450.md). Download the library module first and save it in *gdiplus.prg* file.   

See also:
  
<!-- Anatoliy --> 
<a href="http://www.news2news.com/vfp/?solution=9"><img src="../images/screencapture_270_48.png" width=270 height=48 border=0 alt="Download ScreenCapture Library"></a>   

  
***  


## Code:
```foxpro  
#DEFINE DM_OUT_BUFFER 2
#DEFINE DM_IN_BUFFER  8

#DEFINE DM_ORIENTATION  1
#DEFINE DM_ORIENT_PORTRAIT  1
#DEFINE DM_ORIENT_LANDSCAPE 2
#DEFINE DM_OFFS_DMFIELDS 41  && DEVMODE dmFields offset
#DEFINE DM_OFFS_ORIENTATION 45  && DEVMODE dmOrientation offset

#DEFINE DOCINFO_SIZE 20

SET PROCEDURE TO gdiplus ADDITIVE
DO declare

LOCAL hPrinterDC

* create device context for the default printer
* setting specified printing page orientation
hPrinterDC = GetPrinterDC(DM_ORIENT_LANDSCAPE)

IF hPrinterDC <> 0
	* pass the printer device context
	* and the name of a valid image file
	DO PrintImageFile WITH hPrinterDC, "C:\...\sample.jpg"

	= DeleteDC(hPrinterDC)
ENDIF
* end of main

PROCEDURE PrintImageFile(hPrinterDC As Number, cImgFile As String)

	* an instance of gdiplusinit should be created before
	* instantiating gdi+ object
	PRIVATE gdiplus
	gdiplus = CREATEOBJECT("gdiplusinit")

	LOCAL oImage As gdiimage, oPrnGraphics As graphics
	
	* create GDIIMAGE object from the image file
	oImage = CREATEOBJECT("gdiimage", cImgFile)
	IF oImage.imgwidth=0
		= MESSAGEBOX("Invalid image file selected!")
		RETURN .F.
	ENDIF

	* create GRAPHICS object from
	* the printer device context
	oPrnGraphics = CREATEOBJECT("graphics", hPrinterDC)
	IF oPrnGraphics.graphics = 0
		= MESSAGEBOX("Failed to create the GRAPHICS object " +;
			"for the printer device context!")
		RETURN .F.
	ENDIF

	* set the unit of measure for the printing page
	* to the UnitDocument, which is 1/300 inch
	oPrnGraphics.SetPageUnit(5)

	* set the scaling factor for the printing page
	* to print the image at its original size
	oPrnGraphics.SetPageScale(300/oImage.imghorres)
	
	LOCAL cDocInfo As String, oDocName as PChar
	oDocName = CREATEOBJECT("PChar", "Printing " + JUSTFNAME(m.cImgFile))
	
	* populate DOCINFO buffer
	cDocInfo = PADR(num2dword(DOCINFO_SIZE) +;
		num2dword(oDocName.GetAddr()), DOCINFO_SIZE, CHR(0))

	= StartDoc(m.hPrinterDC, m.cDocInfo)
	= StartPage(m.hPrinterDC)

	* draw the image on the printer Graphics canvas
	oPrnGraphics.DrawImage(oImage, 10, 10)

	= EndPage(m.hPrinterDC)
	= EndDoc(m.hPrinterDC)

FUNCTION GetPrinterDC(nOrientation As Number) As Number
* returns device context for the default printer

	LOCAL cPrinterName, hPrinter, nErrorCode,;
		oDevmode As PChar, nDevmodeSize, hPrinterDC

	* obtain the default printer name from API call;
	* or use VFP native GETPRINTER() or APRINTERS() functions
	cPrinterName=GetDefaultPrinterName()

	hPrinter=0
	= OpenPrinter(cPrinterName, @hPrinter, 0)
	IF hPrinter = 0
		nErrorCode=GetLastError()
		= MESSAGEBOX("OpenPrinter() failed: " +;
			TRANSFORM(nErrorCode), 48, "Error")
		RETURN 0
	ENDIF

	* first DocumentProperties call is configured
	* to return the required size for DEVMODE buffer
	nDevmodeSize = DocumentProperties(_screen.HWnd, hPrinter,;
		cPrinterName, 0, 0, 0)

	oDevmode = CREATEOBJECT("PChar",;
		REPLICATE(CHR(0),nDevmodeSize))

	* second DocumentProperties call populates
	* the DEVMODE buffer
	= DocumentProperties(_screen.HWnd, hPrinter,;
		cPrinterName, oDevmode.GetAddr(), 0, DM_OUT_BUFFER)

	* the printer handle is not required anymore
	* and can be closed
	= ClosePrinter(hPrinter)

	* switching to the specified page orientation
	* by adjusting the DEVMODE structure
	DO SetPageOrientation WITH oDevMode, m.nOrientation

	* the device context for the default printer
	* is created based on the DEVMODE configured
	* to the sepcified page orientation
	hPrinterDC = CreateDC("winspool", cPrinterName,;
		0, oDevmode.GetAddr())

	IF hPrinterDC = 0
		nErrorCode=GetLastError()
		= MESSAGEBOX("CreateDC() failed: " +;
			TRANSFORM(nErrorCode), 48, "Error")
	ENDIF

RETURN m.hPrinterDC

PROCEDURE SetPageOrientation
PARAMETERS oDevmode As PChar, nOrientation As Number
	
	LOCAL cDevmode, dmFlags
	
	* copy DEVMODE bytes from memory block to string buffer
	cDevmode = oDevmode.GetValue()

	* setting DEVMODE members flag and page orientation value
	dmFlags = buf2word(SUBSTR(cDevmode, DM_OFFS_DMFIELDS, 4))
	dmFlags = BITOR(dmFlags, DM_ORIENTATION)

	cDevmode = STUFF(cDevmode, DM_OFFS_DMFIELDS,;
		4, num2dword(dmFlags))

	cDevmode = STUFF(cDevmode, DM_OFFS_ORIENTATION,;
		2, num2word(nOrientation))

	* copy DEVMODE bytes from string buffer back to memory block
	oDevmode.SetValue(m.cDevmode)

FUNCTION GetDefaultPrinterName() As String
	LOCAL cPrinter, nBufsize
	nBufsize=250
	cPrinter=REPLICATE(CHR(0), nBufsize)
RETURN IIF(GetDefaultPrinter(@cPrinter, @nBufsize)=0, "",;
	SUBSTR(cPrinter, 1, AT(CHR(0),cPrinter)-1))

PROCEDURE declare
	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER DeleteDC IN gdi32 INTEGER hdc
	DECLARE INTEGER StartPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndPage IN gdi32 INTEGER hdc
	DECLARE INTEGER EndDoc IN gdi32 INTEGER hdc
	DECLARE INTEGER StartDoc IN gdi32 INTEGER hdc, STRING lpdi

	DECLARE INTEGER GetDefaultPrinter IN winspool.drv;
		STRING @pszBuffer, INTEGER @pcchBuffer

	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER DocumentProperties IN winspool.drv;
		INTEGER hWnd, INTEGER hPrinter, STRING pDeviceName,;
		INTEGER pDevModeOutput, INTEGER pDevModeInput, INTEGER fMode

	DECLARE INTEGER CreateDC IN gdi32;
		STRING lpszDriver, STRING lpszDevice,;
		INTEGER lpszOutput, INTEGER lpInitData

DEFINE CLASS PChar As Session
PROTECTED hMem

PROCEDURE Init(lcString)
	THIS.hMem = 0
	THIS.setValue(lcString)

PROCEDURE Destroy
	THIS.ReleaseString

FUNCTION GetAddr
RETURN THIS.hMem

FUNCTION GetValue
	LOCAL lnSize, lcBuffer
	lnSize = THIS.getAllocSize()
	lcBuffer = SPACE(lnSize)

	IF THIS.hMem <> 0
		DECLARE RtlMoveMemory IN kernel32 As MemToStr;
			STRING @, INTEGER, INTEGER
		= MemToStr(@lcBuffer, THIS.hMem, lnSize)
	ENDIF
RETURN lcBuffer

FUNCTION GetAllocSize
	DECLARE INTEGER GlobalSize IN kernel32 INTEGER hMem
RETURN Iif(THIS.hMem=0, 0, GlobalSize(THIS.hMem))

PROCEDURE SetValue(lcString)
#DEFINE GMEM_FIXED 0
#DEFINE GMEM_MOVEABLE 2
#DEFINE GMEM_ZEROINIT 0x0040

	THIS.ReleaseString

	DECLARE INTEGER GlobalAlloc IN kernel32 INTEGER, INTEGER
	DECLARE RtlMoveMemory IN kernel32 As StrToMem;
		INTEGER, STRING @, INTEGER

	LOCAL lnSize
	lcString = lcString + Chr(0)
	lnSize = Len(lcString)
	THIS.hMem = GlobalAlloc(GMEM_ZEROINIT, lnSize)
	IF THIS.hMem <> 0
		= StrToMem(THIS.hMem, @lcString, lnSize)
	ENDIF

PROCEDURE ReleaseString
	IF THIS.hMem <> 0
		DECLARE INTEGER GlobalFree IN kernel32 INTEGER
		= GlobalFree (THIS.hMem)
		THIS.hMem = 0
	ENDIF
ENDDEFINE  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[CreateDC](../libraries/gdi32/CreateDC.md)  
[DeleteDC](../libraries/gdi32/DeleteDC.md)  
[DocumentProperties](../libraries/winspool.drv/DocumentProperties.md)  
[EndDoc](../libraries/gdi32/EndDoc.md)  
[EndPage](../libraries/gdi32/EndPage.md)  
[GetDefaultPrinter](../libraries/winspool.drv/GetDefaultPrinter.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[GlobalSize](../libraries/kernel32/GlobalSize.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  
[StartDoc](../libraries/gdi32/StartDoc.md)  
[StartPage](../libraries/gdi32/StartPage.md)  

## Comment:
DEVMODE data for a printer can be obtained by calling either the DocumentProperties or the PrintDlg API function. If required, the latter can display the Print dialog box allowing to adjust the printer job settings manually.  
  
When adjusted accordingly, such DEVMODE structure is used to create a device context (DC) for the printer.  
  
***  

