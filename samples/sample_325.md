[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the name and type of all available RAS-capable devices

## Code:
```foxpro  
DECLARE INTEGER RasEnumDevices IN rasapi32;
	STRING @lpRasDevInfo, INTEGER @lpcb, INTEGER @lpcDevices

#DEFINE RAS_MaxDeviceName  128
#DEFINE RAS_MaxDeviceType  16

* RASDEVINFO structure
*|typedef struct tagRASDEVINFO {
*|  DWORD    dwSize;                                 0:4
*|  TCHAR    szDeviceType[RAS_MaxDeviceType + 1];  4:17
*|  TCHAR    szDeviceName[RAS_MaxDeviceName + 1]; 21:128
*|} RASDEVINFO; total bytes = 150

LOCAL lcBuffer, lnBufsize, lnCount, lnResult, lnSubsize
STORE 0 TO lnBufsize, lnCount

* obtaining the size of the buffer that should be passed in
= RasEnumDevices(0, @lnBufsize, @lnCount)
IF lnCount = 0
	? "No RAS Devices found."
	RETURN
ENDIF

lnSubsize = lnBufsize/lnCount && buffer size per device
lcBuffer = num2dword(lnSubsize) + Repli(Chr(0), lnBufsize-4)

lnResult = RasEnumDevices(@lcBuffer, @lnBufsize, @lnCount)
IF lnResult <> 0
* 603 = ERROR_BUFFER_TOO_SMALL
* 632
	? "Error code:", lnResult
	RETURN
ENDIF

LOCAL lnIndex, lnOffset, lcSubstr, lcDevType, lcDevName
CREATE CURSOR csResult (idx N(5), devtype C(20), devname C(128))

FOR lnIndex=1 TO lnCount
	lnOffset = lnSubsize * (lnIndex-1) + 1
	lcSubstr = SUBSTR(lcBuffer, lnOffset, lnSubsize)

	lcDevType = STRTRAN(SUBSTR(lcSubstr, 5, 17), Chr(0),"")
	lcDevName = STRTRAN(SUBSTR(lcSubstr, 22, 128), Chr(0),"")

	INSERT INTO csResult VALUES (lnIndex, lcDevType, lcDevName)
ENDFOR

SELECT csResult
GO TOP
BROWSE NORMAL NOWAIT

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
[RasEnumDevices](../libraries/rasapi32/RasEnumDevices.md)  

## Comment:
Allows to identify modem installed.  
  
***  

