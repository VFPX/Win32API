[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve configuration data for a specified printer stored in the registry (PrinterDriverData key)

## Before you begin:
EnumPrinterData retrieves printer configuration data set by the SetPrinterData function. A printer"s configuration data consists of a set of named and typed values.  
  
***  


## Code:
```foxpro  
#DEFINE ERROR_SUCCESS  0
#DEFINE ERROR_NO_MORE_ITEMS  259
#DEFINE ERROR_MORE_DATA      234

#DEFINE REG_SZ       1  && string
#DEFINE REG_BINARY   3
#DEFINE REG_DWORD    4
#DEFINE REG_MULTI_SZ 7  && array of strings

DO decl

PRIVATE cPrinter, hPrinter
cPrinter = GetPrnName()

hPrinter = 0
IF OpenPrinter(cPrinter, @hPrinter, 0) = 0
	? "Unable to get printer handle for [" + cPrinter + "]"
	RETURN
ENDIF

LOCAL lnIndex, lcValueName, lnValueName, lnValueType,;
	lcBuffer, lnBufsize, lnResult, lcValue

CREATE CURSOR csResult ( valuename C(30), value2str C(50),;
	binvalue M, valuetype I, bufsize I)

lnIndex = 0
DO WHILE .T.
	lcValueName = Repli(Chr(0), 100)
	STORE 0 TO lnValueName, lnValueType, lnBufsize
	lcBuffer = Repli(Chr(0), 4096)

	lnResult = EnumPrinterData(hPrinter, lnIndex,;
		@lcValueName, Len(lcValueName), @lnValueName,;
		@lnValueType, @lcBuffer, Len(lcBuffer), @lnBufsize)

	IF lnResult = ERROR_NO_MORE_ITEMS
		EXIT
	ENDIF

	lcValueName = SUBSTR(lcValueName, 1, AT(Chr(0),lcValueName)-1)
	lcBuffer = SUBSTR(lcBuffer, 1, lnBufsize)

	DO CASE
	CASE INLIST(lnValueType, REG_SZ, REG_MULTI_SZ)
		lcValue = SUBSTR(lcBuffer, 1, AT(Chr(0),lcBuffer)-1)
	CASE lnValueType = REG_BINARY
		lcValue = LTRIM(STR(lnBufsize)) + " bytes of binary data"
	CASE lnValueType = REG_DWORD
		lcValue = LTRIM(STR(buf2dword(lcBuffer)))
	ENDCASE

	INSERT INTO csResult (valuename, valuetype, bufsize, value2str);
		VALUES (lcValueName, lnValueType, lnBufsize, lcValue)

	IF lnValueType = REG_BINARY
		UPDATE csResult SET binvalue = lcBuffer WHERE valuename == m.lcValueName
	ENDIF
	lnIndex = lnIndex + 1
ENDDO

= ClosePrinter(hPrinter)
GO TOP
BROWSE NORMAL NOWAIT
* end of main

FUNCTION GetPrnName
* returns default printer name from registry
	LOCAL lcBuffer, lnPos
	lcBuffer = Repli(Chr(0), 120)
	= GetProfileString("Windows", "Device", ",,,",;
		@lcBuffer, Len(lcBuffer))
	lcBuffer = STRTRAN(lcBuffer, Chr(0), "")
	lnPos = AT(",", lcBuffer, 1)
RETURN SUBSTR(lcBuffer, 1, lnPos-1)

PROCEDURE decl
	DECLARE INTEGER EnumPrinterData IN winspool.drv;
		INTEGER hPrinter, INTEGER dwIndex, STRING @pValueName,;
		INTEGER cbValueName, INTEGER @pcbValueName, INTEGER @pType,;
		STRING @pData, INTEGER cbData, INTEGER @pcbData

	DECLARE INTEGER OpenPrinter IN winspool.drv;
		STRING pPrinterName, INTEGER @phPrinter, INTEGER pDefault

	DECLARE INTEGER ClosePrinter IN winspool.drv INTEGER hPrinter
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER GetProfileString IN kernel32;
		STRING lpApp, STRING lpKey, STRING lpDefault,;
		STRING @lpReturnedString, INTEGER nSize

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[ClosePrinter](../libraries/winspool.drv/ClosePrinter.md)  
[EnumPrinterData](../libraries/winspool.drv/EnumPrinterData.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
[GetProfileString](../libraries/kernel32/GetProfileString.md)  
[OpenPrinter](../libraries/winspool.drv/OpenPrinter.md)  
