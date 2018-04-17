[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving list of all active RAS connections

## Code:
```foxpro  
DECLARE INTEGER RasEnumConnections IN rasapi32;
	STRING @lprasconn, INTEGER @lpcb,;
	INTEGER @lpcConnections

#DEFINE RAS_MaxEntryName   256
#DEFINE RAS_MaxDeviceName  128
#DEFINE RAS_MaxDeviceType  16
#DEFINE MAX_PATH           260

* RASCONN structure
* http://msdn.microsoft.com/en-us/library/aa376725(v=vs.85).aspx

*|typedef struct _RASCONN {
*|  DWORD    dwSize;      0:4
*|  HRASCONN hrasconn;    4:8
*|  TCHAR    szEntryName[RAS_MaxEntryName + 1];   256+1
*|  TCHAR    szDeviceType[RAS_MaxDeviceType + 1];  16+1
*|  TCHAR    szDeviceName[RAS_MaxDeviceName + 1]; 128+1
*|} RASCONN; 8 + 257 + 17 + 129 = 411 --> 412

#DEFINE RASCONN_SIZE 412

LOCAL lcBuffer, lnBufsize, lnCount, lnResult

lnBufsize = RASCONN_SIZE * 256
lnCount = 0
lcBuffer = num2dword(RASCONN_SIZE) +;
	REPLICATE(CHR(0), lnBufsize-4)

lnResult = RasEnumConnections(@lcBuffer,;
	@lnBufsize, @lnCount)

IF lnResult <> 0
	? "Error code:", lnResult
	RETURN
ENDIF

IF lnCount = 0
	? "No RAS Connections found."
	RETURN
ENDIF

LOCAL lnSubsize, lnIndex, lcSubstr,;
	lcEntryName, lcDevType, lcDevName

lnSubsize = lnBufsize/lnCount

CREATE CURSOR csResult (idx N(5), entryname C(255),;
	devtype C(20), devname C(128))

FOR lnIndex=1 TO lnCount
	lcSubstr = SUBSTR(lcBuffer,;
		lnSubsize * (lnIndex-1) + 1, lnSubsize)

	lcEntryName = STRTRAN(SUBSTR(lcSubstr, 9, 256), CHR(0),"")
	lcDevType = STRTRAN(SUBSTR(lcSubstr, 266, 17), CHR(0),"")
	lcDevName = STRTRAN(SUBSTR(lcSubstr, 284, 128), CHR(0),"")
	
	INSERT INTO csResult;
	VALUES (lnIndex, lcEntryName, lcDevType, lcDevName)

ENDFOR

FUNCTION  num2dword (lnValue)
#DEFINE m0       256
#DEFINE m1     65536
#DEFINE m2  16777216
	LOCAL b0, b1, b2, b3
	b3 = Int(lnValue/m2)
	b2 = Int((lnValue - b3*m2)/m1)
	b1 = Int((lnValue - b3*m2 - b2*m1)/m0)
	b0 = Mod(lnValue, m0)
RETURN Chr(b0)+Chr(b1)+Chr(b2)+Chr(b3)  
```  
***  


## Listed functions:
[RasEnumConnections](../libraries/rasapi32/RasEnumConnections.md)  

 
  
***  

