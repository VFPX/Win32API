[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating forms supported by a specified printer

## Before you begin:
![](../)  

Function EnumForms returns a collection of FORM_INFO_1 structures, each member containing name, width and height (in thousandths of millimeters) for a supported form.  

Function DeviceCapabilities returns form names only.  

See also:

* [Retrieving the number of print jobs queued for a printer](sample_367.md)  
  
***  


## Code:
```foxpro  
#DEFINE FORM_INFO_SIZE 32
#DEFINE MM_TO_INCH 0.0393700787
#DEFINE INCH_TO_UNITDOCUMENT 300

DO declare

PRIVATE nBuffer, nBufsize, nNeeded, cBuffer
LOCAL hPrinter, cPrinter, nCount, nIndex, cInfo
cPrinter = GetPrnName()

hPrinter = 0
IF OpenPrinter(cPrinter, @hPrinter, 0) = 0
	? "Unable to retrieve printer handle"
	RETURN
ENDIF

nBufsize = 16384
nBuffer = GlobalAlloc(0, nBufsize)
STORE 0 TO nNeeded, nCount

IF EnumForms(hPrinter, 1, nBuffer, nBufsize, @nNeeded, @nCount) = 0
	? "Error:", GetLastError()
ELSE
	cBuffer = REPLICATE(Chr(0), nBufsize)
	= Mem2Str(@cBuffer, nBuffer, nBufsize)

	CREATE CURSOR csResult (;
		formflags I, dmpaper_id I, formname C(64),;
		formwidth_mm I, formheight_mm I,;
		formwidth_inch N(12,4), formheight_inch N(12,4),;
		formwidth_unit I, formheight_unit I;
		)

	FOR nIndex=0 TO nCount-1
		cInfo = SUBSTR(cBuffer, nIndex*FORM_INFO_SIZE+1, FORM_INFO_SIZE)
		DO ParseInfo WITH cInfo, nIndex
	ENDFOR

	GO TOP
	BROW NORMAL NOWAIT
ENDIF
= GlobalFree(nBuffer)
= ClosePrinter(hPrinter)
* end of main

PROCEDURE ParseInfo(cInfo, nFormIndex)
	LOCAL nFlags, nName, cName, nWidth, nHeight

	nFlags = buf2dword(SUBSTR(cInfo, 1,4))
	nName = buf2dword(SUBSTR(cInfo, 5,4))
	nWidth = buf2dword(SUBSTR(cInfo, 9,4))
	nHeight = buf2dword(SUBSTR(cInfo,13,4))

	cName = ""
	IF nName <> 0
		nOffs = nName - nBuffer + 1
		DO WHILE nOffs < nBufsize
			ch = SUBSTR(cBuffer,nOffs,1)
			IF ch = Chr(0)
				EXIT
			ENDIF
			cName = cName + ch
			nOffs = nOffs + 1
		ENDDO
	ENDIF

	INSERT INTO csResult (;
		formflags, dmpaper_id, formname,;
		formwidth_mm, formheight_mm,;
		formwidth_inch, formheight_inch,;
		formwidth_unit, formheight_unit;
	) VALUES (m.nFlags, m.nFormIndex+1, m.cName,;
		m.nWidth/1000, m.nHeight/1000,;
		(m.nWidth/1000) * MM_TO_INCH, (m.nHeight/1000) * MM_TO_INCH,;
		(m.nWidth/1000) * MM_TO_INCH * INCH_TO_UNITDOCUMENT,;
			(m.nHeight/1000) * MM_TO_INCH * INCH_TO_UNITDOCUMENT;
		)

FUNCTION GetPrnName
* returns default printer name from the Registry
	LOCAL lcBuffer, lcPrinter, lcDriver, lcPort
	lcBuffer = REPLICATE(Chr(0), 120)
	= GetProfileString("Windows", "Device", ",,,",;
		@lcBuffer, LEN(lcBuffer))
	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
RETURN SUBSTR(lcBuffer, 1, AT(",", lcBuffer, 1)-1)

PROCEDURE declare
	DECLARE INTEGER EnumForms IN winspool.drv;
		INTEGER hPrinter, INTEGER lvl, INTEGER pForm,;
		INTEGER cbBuf, INTEGER @pcbNeeded, INTEGER @pcReturned

	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER GetLastError IN kernel32
	DECLARE INTEGER GlobalFree IN kernel32 INTEGER hMem

	DECLARE INTEGER GlobalAlloc IN kernel32;
		INTEGER wFlags, INTEGER dwBytes

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

	DECLARE RtlMoveMemory IN kernel32 As Mem2Str;
		STRING @Dest, INTEGER Src, INTEGER nLength

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)), 8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[EnumForms](../libraries/winspool.drv/EnumForms.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[GlobalAlloc](../libraries/kernel32/GlobalAlloc.md)  
[GlobalFree](../libraries/kernel32/GlobalFree.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  

## Comment:
The code sample enumerates formats for the default printer. Set the value of m.cPrinter to a valid printer name to run the enumeration for that printer.  
  
The output cursor contains the width and the heights of each format in millimeters, inches and Document Units (1/300 inch).  
  
***  

