[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving information specific to the current Time Zone

## Code:
```foxpro  
*| typedef struct _TIME_ZONE_INFORMATION {
*|     LONG       Bias;                  0        4
*|     WCHAR      StandardName[ 32 ];    4       64
*|     SYSTEMTIME StandardDate;         68       16
*|     LONG       StandardBias;         84        4
*|     WCHAR      DaylightName[ 32 ];   88       64
*|     SYSTEMTIME DaylightDate;        152       16
*|     LONG       DaylightBias;        168        4
*| } TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION; total 172 bytes
#DEFINE TIME_ZONE_SIZE  172
DO decl

LOCAL cTimeZone, cTimeZone_, nId
cTimeZone = Repli(Chr(0), TIME_ZONE_SIZE)

? "*** Retrieving current TimeZone info..."
nId = GetTimeZoneInformation(@cTimeZone)
= ShowTimeZoneInfo(cTimeZone)

?
? "*** Changing bias and standard name parameters..."
LOCAL nNewBias, cStandardName, cDaylightName
nNewBias = 301
*cStandardName = PADR(StrConv("Scarborough Standard",5),64,Chr(0))
cStandardName = PADR("My City Standard", 64, Chr(0))
cDaylightName = PADR("My City Daylight", 64, Chr(0))
cTimeZone_ = num2dword(nNewBias) + cStandardName +;
	SUBSTR(cTimeZone, 69, 20) +;
	cDaylightName +;
	SUBSTR(cTimeZone, 153)

= SetTimeZoneInformation(cTimeZone_) && setting
cTimeZone_ = Repli(Chr(0), TIME_ZONE_SIZE)  && clearing buffer
= GetTimeZoneInformation(@cTimeZone_) && re-populating buffer
= ShowTimeZoneInfo(cTimeZone_)

?
? "*** Back to old settings..."
= SetTimeZoneInformation(cTimeZone)
cTimeZone = Repli(Chr(0), TIME_ZONE_SIZE)
= GetTimeZoneInformation(@cTimeZone)
= ShowTimeZoneInfo(cTimeZone)
* end of main

FUNCTION GetTimeZoneType(nId)
#DEFINE TIME_ZONE_ID_UNKNOWN     0
#DEFINE TIME_ZONE_ID_STANDARD    1
#DEFINE TIME_ZONE_ID_DAYLIGHT    2
	DO CASE
	CASE nId = TIME_ZONE_ID_STANDARD
		RETURN "StandardDate member"
	CASE nId = TIME_ZONE_ID_DAYLIGHT
		RETURN "DaylightDate member"
	CASE nId = TIME_ZONE_ID_UNKNOWN
		RETURN "The system cannot determine the current time zone"
	OTHER
		RETURN "The Time Zone ID is invalid"
	ENDCASE

PROCEDURE ShowTimeZoneInfo(cTimeZone)
	? "Bias (minutes between UTC and local):", buf2dword(SUBSTR(cTimeZone, 1,4))
	? "Standard Bias:", buf2dword(SUBSTR(cTimeZone, 85,4))
	? "Daylight Bias:", buf2dword(SUBSTR(cTimeZone, 169,4))
	? "Standard name:", STRTRAN(SUBSTR(cTimeZone, 5,32), Chr(0),"")
	? "Daylight name:", STRTRAN(SUBSTR(cTimeZone, 89,32), Chr(0),"")
	? "Standard Date:",;
		buf2word(SUBSTR(cTimeZone,69,2)),;
		buf2word(SUBSTR(cTimeZone,71,2)),;
		buf2word(SUBSTR(cTimeZone,73,2)),;
		buf2word(SUBSTR(cTimeZone,75,2)),;
		buf2word(SUBSTR(cTimeZone,77,2)),;
		buf2word(SUBSTR(cTimeZone,79,2))
	? "Daylight Date:",;
		buf2word(SUBSTR(cTimeZone,153,2)),;
		buf2word(SUBSTR(cTimeZone,155,2)),;
		buf2word(SUBSTR(cTimeZone,157,2)),;
		buf2word(SUBSTR(cTimeZone,159,2)),;
		buf2word(SUBSTR(cTimeZone,161,2)),;
		buf2word(SUBSTR(cTimeZone,163,2))

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION buf2word(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
       Asc(SUBSTR(lcBuffer, 2,1)) * 256

FUNCTION num2dword(lnValue)
#DEFINE m0  256
#DEFINE m1  65536
#DEFINE m2  16777216
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
RETURN Chr(MOD(m.lnValue,256)) + CHR(INT(m.lnValue/256))

PROCEDURE decl
	DECLARE INTEGER GetTimeZoneInformation IN kernel32;
		STRING @lpTimeZoneInformation

	DECLARE INTEGER SetTimeZoneInformation IN kernel32;
		STRING lpTimeZoneInformation  
```  
***  


## Listed functions:
[GetTimeZoneInformation](../libraries/kernel32/GetTimeZoneInformation.md)  
[SetTimeZoneInformation](../libraries/kernel32/SetTimeZoneInformation.md)  
