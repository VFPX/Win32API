[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving list of supported paper names (for example, Letter or Legal) for a given printer

## Before you begin:
See also:

* [How to enumerate forms supported by the specified printer](sample_390.md)  

  
***  


## Code:
```foxpro  
#DEFINE DC_PAPERS 0x0002
#DEFINE DC_SIZE 0x0008
#DEFINE DC_VERSION 0x000a
#DEFINE DC_PAPERNAMES 0x0010

DO declare

LOCAL cPrinterName, cBuffer, nCount, nIndex, cPaperName
cPrinterName = GetDefaultPrinter()

cBuffer = REPLICATE(Chr(0), 16384)
nCount = DeviceCapabilities( m.cPrinterName, "LPT1",;
	DC_PAPERNAMES, @cBuffer, 0)

CREATE CURSOR csFormats (papername C(100))

* each string buffer is 64 characters long
* and contains the name of a paper form
FOR nIndex=1 To nCount
	cPaperName = SUBSTR(cBuffer, (nIndex-1)*64+1, 64) + CHR(0)
	cPaperName = SUBSTR(cPaperName, 1, AT(CHR(0), cPaperName)-1)
	
	INSERT INTO csFormats (papername) VALUES ( m.cPaperName )
ENDFOR

SELECT csFormats
GO TOP
BROWSE NORMAL NOWAIT

= MESSAGEBOX(cPrinterName, 64, "Default Printer")
* end of main

FUNCTION GetDefaultPrinter() As String
* returns default printer name from Windows Registry
	LOCAL cBuffer, cPrinter, lcDriver, lcPort
	cBuffer = REPLICATE(CHR(0), 120)

	= GetProfileString("Windows", "Device", ",,,",;
		@cBuffer, Len(cBuffer))
	cBuffer = STRTRAN(cBuffer, Chr(0), "")
RETURN SUBSTR(cBuffer, 1, AT(",", cBuffer, 1)-1)

PROCEDURE declare
	DECLARE INTEGER DeviceCapabilities IN winspool.drv;
		STRING pDevice, STRING pPort, INTEGER fwCapability,;
		STRING @pOutput, INTEGER pDevMode

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize  
```  
***  


## Listed functions:
[DeviceCapabilities](../libraries/winspool.drv/DeviceCapabilities.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  

## Comment:
Function EnumForms returns same information, and in addition for each paper format, the width and the height in thousandths of millimeters.  
  
List of supported paper formats for an average printer:  
* Letter  
* Legal  
* Statement  
* Executive  
* A4  
* A5  
* B5 (JIS)  
* Envelope #10  
* Envelope DL  
* Envelope C6  
* A6  
* Index card 5 x 8 in  
...  
  
***  

