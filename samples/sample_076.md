[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Saving available locale records into a cursor

## Note that this document contains some links to the old news2news website which does not work at the moment. This material will be available sometime in the future.

## Before you begin:
See also:

<!-- Anatoliy --> 
* [LanguageBar ActiveX control](?solution=7)  
* [Retrieving national language settings](sample_077.md)  
* [Switching between keyboard layouts](sample_275.md)  
  
***  


## Code:
```foxpro  
* some LOCALE constants
#DEFINE LOCALE_ILANGUAGE                1   && language id
#DEFINE LOCALE_SLANGUAGE                2   && localized name of language
#DEFINE LOCALE_SENGLANGUAGE          4097   && English name of language
#DEFINE LOCALE_SABBREVLANGNAME          3   && abbreviated language name
#DEFINE LOCALE_SNATIVELANGNAME          4   && native name of language
#DEFINE LOCALE_ICOUNTRY                 5   && country code
#DEFINE LOCALE_SCOUNTRY                 6   && localized name of country
#DEFINE LOCALE_SENGCOUNTRY           4098   && English name of country
#DEFINE LOCALE_SABBREVCTRYNAME          7   && abbreviated country name
#DEFINE LOCALE_SNATIVECTRYNAME          8   && native name of country
#DEFINE LOCALE_IDEFAULTLANGUAGE         9   && default language id
#DEFINE LOCALE_IDEFAULTCOUNTRY         10   && default country code
#DEFINE LOCALE_IDEFAULTCODEPAGE        11   && default oem code page
#DEFINE LOCALE_IDEFAULTANSICODEPAGE  4100   && default ansi code page
#DEFINE LOCALE_IDEFAULTMACCODEPAGE   4113   && default mac code page

#DEFINE LOCALE_ILDATE                  34   && long date format ordering
#DEFINE LOCALE_ILZERO                  18   && leading zeros for decimal
#DEFINE LOCALE_IMEASURE                13   && 0 = metric, 1 = US
#DEFINE LOCALE_IMONLZERO               39   && leading zeros in month field
#DEFINE LOCALE_INEGCURR                28   && negative currency mode
#DEFINE LOCALE_INEGSEPBYSPACE          87   && mon sym sep by space from neg amt
#DEFINE LOCALE_INEGSIGNPOSN            83   && negative sign position

#DEFINE LOCALE_SDAYNAME1   0x0000002A
#DEFINE LOCALE_SMONTHNAME1  0x00000038
* there are at least 216 LOCALE constants

DECLARE INTEGER GetLocaleInfo IN kernel32;
	INTEGER Locale, INTEGER LCType,;
	STRING @lpLCData, INTEGER cchData

CREATE CURSOR cs (;
	locale    N(6),;
	langid    C( 4),;
	llnagname C(30),;
	elangname C(30),;
	alangname C( 3),;
	nlangname C(30),;
	ccode     C( 3),;
	lcname    C(30),;
	ecname    C(30),;
	acname    C( 3),;
	ncname    C(30),;
	dlangid   C( 4),;
	dccode    C( 3),;
	doemcp    C( 5),;
	dansicp   C( 5),;
	dmaccp    C( 5),;
	ldtfmt    C( 2),;
	ldzeros   C( 2),;
	metrics   C( 2),;
	monzero   C( 2),;
	necurr    C( 2),;
	negsep    C( 2),;
	negsign   C( 2),;
	sdayname1 C(10),;
	smonname1 C(20);
)
	
* scan top 0x10000 codes
* under WinNT 4.0 it returns 138 records
* WinMe -- 164 records
FOR ii=0 TO 65535
	= SaveLInfo(ii)
ENDFOR

SELECT cs
GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE SaveLInfo(lnLocale)
* saves one local record for the locale
	IF Len(GetLInfo(lnLocale, LOCALE_ILANGUAGE)) = 0
	* exit if no information exists for this locale id
		RETURN
	ENDIF
	
	INSERT INTO cs VALUES (;
		lnLocale,;
		GetLInfo(lnLocale, LOCALE_ILANGUAGE),;
		GetLInfo(lnLocale, LOCALE_SLANGUAGE),;
		GetLInfo(lnLocale, LOCALE_SENGLANGUAGE),;
		GetLInfo(lnLocale, LOCALE_SABBREVLANGNAME),;
		GetLInfo(lnLocale, LOCALE_SNATIVELANGNAME),;
		GetLInfo(lnLocale, LOCALE_ICOUNTRY),;
		GetLInfo(lnLocale, LOCALE_SCOUNTRY),;
		GetLInfo(lnLocale, LOCALE_SENGCOUNTRY),;
		GetLInfo(lnLocale, LOCALE_SABBREVCTRYNAME),;
		GetLInfo(lnLocale, LOCALE_SNATIVECTRYNAME),;
		GetLInfo(lnLocale, LOCALE_IDEFAULTLANGUAGE),;
		GetLInfo(lnLocale, LOCALE_IDEFAULTCOUNTRY),;
		GetLInfo(lnLocale, LOCALE_IDEFAULTCODEPAGE),;
		GetLInfo(lnLocale, LOCALE_IDEFAULTANSICODEPAGE),;
		GetLInfo(lnLocale, LOCALE_IDEFAULTMACCODEPAGE),;
		GetLInfo(lnLocale, LOCALE_ILDATE),;
		GetLInfo(lnLocale, LOCALE_ILZERO),;
		GetLInfo(lnLocale, LOCALE_IMEASURE),;
		GetLInfo(lnLocale, LOCALE_IMONLZERO),;
		GetLInfo(lnLocale, LOCALE_INEGCURR),;
		GetLInfo(lnLocale, LOCALE_INEGSEPBYSPACE),;
		GetLInfo(lnLocale, LOCALE_INEGSIGNPOSN),;
		GetLInfo(lnLocale, LOCALE_SDAYNAME1),;
		GetLInfo(lnLocale, LOCALE_SMONTHNAME1);
	)
RETURN

PROCEDURE GetLInfo(nLocale, nType)
* retrieves value for specified locale and type
	cBuffer = REPLICATE(CHR(0), 250)
	nLength = GetLocaleInfo(nLocale, nType, @cBuffer, LEN(cBuffer))
RETURN IIF(nLength > 0, SUBSTR(cBuffer, 1, nLength), "")  
```  
***  


## Listed functions:
[GetLocaleInfo](../libraries/kernel32/GetLocaleInfo.md)  

## Comment:
This code retrieves all locale records available on your system.  
  
At this point I do not know how to create a call-back procedure within VFP (if it is really possible), so the only replacing option is to scan a wide range of could-be locale values.  
  
***  

