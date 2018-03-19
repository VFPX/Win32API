[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Get the power status of your laptop computer

## Before you begin:
This code sample helps to find whether the system is running on AC or DC power, whether the battery is currently charging, and how much battery life remains.  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetSystemPowerStatus IN kernel32;
	STRING @lpSystemPowerStatus

*|typedef struct _SYSTEM_POWER_STATUS {
*|  BYTE ACLineStatus;         0:1
*|  BYTE BatteryFlag;          1:1
*|  BYTE BatteryLifePercent;   2:1
*|  BYTE Reserved1;            3:1
*|  DWORD BatteryLifeTime;     4:4
*|  DWORD BatteryFullLifeTime; 8:4
*|} SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS; total 12 bytes

LOCAL cBuffer
cBuffer = Repli(Chr(0), 12)
IF GetSystemPowerStatus(@cBuffer) = 0
	RETURN
ENDIF

LOCAL nStatus, nBattery
nStatus = Asc(SUBSTR(cBuffer,1,1))
nBattery = Asc(SUBSTR(cBuffer,2,1))

? "AC power status: "
DO CASE
CASE nStatus = 0
	?? "offline"
CASE nStatus = 1
	?? "online"
OTHER
	?? "unknown"
ENDCASE

? "Battery flag: "
DO CASE
CASE nBattery = 1
	?? "high"
CASE nBattery = 2
	?? "low"
CASE nBattery = 4
	?? "critical"
CASE nBattery = 8
	?? "charging"
CASE nBattery = 128
	?? "no system battery"
OTHER
	?? "unknown"
ENDCASE

IF nBattery <= 8
	? "Battery remaining, %:", Asc(SUBSTR(cBuffer,3,1))
	? "Battery remaining, sec:", buf2dword(SUBSTR(cBuffer,5,4))
	? "Battery full time, sec:", buf2dword(SUBSTR(cBuffer,9,4))
ENDIF
* end of main

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[GetSystemPowerStatus](../libraries/kernel32/GetSystemPowerStatus.md)  
