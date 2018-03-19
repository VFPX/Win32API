[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Power capabilities of the system: battery, UPS, sleep and hibernation modes, processor throttling

## Code:
```foxpro  
DECLARE INTEGER GetPwrCapabilities IN powrprof;
	STRING @lpSystemPowerCapabilities

*|typedef struct {
*|  BOOLEAN PowerButtonPresent;                 0:1
*|  BOOLEAN SleepButtonPresent;                 1:1
*|  BOOLEAN LidPresent;                         2:1
*|  BOOLEAN SystemS1;                           3:1
*|  BOOLEAN SystemS2;                           4:1
*|  BOOLEAN SystemS3;                           5:1
*|  BOOLEAN SystemS4;                           6:1
*|  BOOLEAN SystemS5;                           7:1
*|  BOOLEAN HiberFilePresent;                   8:1
*|  BOOLEAN FullWake;                           9:1
*|  BOOLEAN VideoDimPresent;                   10:1
*|  BOOLEAN ApmPresent;                        11:1
*|  BOOLEAN UpsPresent;                        12:1
*|  BOOLEAN ThermalControl;                    13:1
*|  BOOLEAN ProcessorThrottle;                 14:1
*|  UCHAR ProcessorMinThrottle;                15:1
*|  UCHAR ProcessorMaxThrottle;                16:1
*|  UCHAR spare2[4];                           17:4
*|  BOOLEAN DiskSpinDown;                      21:1
*|  UCHAR spare3[8];                           22:8
*|  BOOLEAN SystemBatteriesPresent;            30:1
*|  BOOLEAN BatteriesAreShortTerm;             31:1
*|  BATTERY_REPORTING_SCALE BatteryScale[3];   32:3
*|  SYSTEM_POWER_STATE AcOnLineWake;           35:1
*|  SYSTEM_POWER_STATE SoftLidWake;            36:1
*|  SYSTEM_POWER_STATE RtcWake;                37:1
*|  SYSTEM_POWER_STATE MinDeviceWakeState;     38:1
*|  SYSTEM_POWER_STATE DefaultLowLatencyWake;  39:1
*|} SYSTEM_POWER_CAPABILITIES, *PSYSTEM_POWER_CAPABILITIES; total 40 bytes

PRIVATE cBuffer
cBuffer = Repli(Chr(0), 256)
IF GetPwrCapabilities(@cBuffer) = 0
	? "Error calling API function."
	RETURN
ENDIF

CREATE CURSOR csResult (varname C(70), varvalue C(100))

= _add("Power Button is present", 1)
= _add("Sleep Button is present", 2)
= _add("There is a lid switch", 3)
= _add("The system supports S1 slip state", 4)
= _add("The system supports S2 slip state", 5)
= _add("The system supports S3 slip state", 6)
= _add("The system supports S4 slip state", 7)
= _add("The system supports S5 slip state", 8)
= _add("The system hibernation file is present", 9)
= _add("The system supports wake capabilities", 10)
= _add("The system supports video display dimming capabilities", 11)
= _add("The system supports APM BIOS power management features", 12)
= _add("An uninterruptible power supply (UPS) is present", 13)
= _add("The system supports thermal zones", 14)

= _add("The system supports processor throttling", 15)
= _add("Min % level of processor throttling supported", 16)
= _add("Max % level of processor throttling supported", 17)

= _add("Turning off hard disks is supported", 22)
= _add("One or more batteries in the system", 31)
= _add("Short-term batteries are in use", 32)

GO TOP
BROW NORMAL NOWAIT
* end of main

PROCEDURE _add(cName, nOffs)
	LOCAL cValue
	cValue = LTRIM(STR(Asc(SUBSTR(cBuffer, nOffs, 1))))
	INSERT INTO csResult VALUES (m.cName, m.cValue)

PROCEDURE _add1(cName, cValue)
	INSERT INTO csResult VALUES (m.cName, m.cValue)

FUNCTION pws(nIndex)
*|typedef enum _SYSTEM_POWER_STATE
*|{
*|  PowerSystemUnspecified = 0,
*|  PowerSystemWorking = 1,
*|  PowerSystemSleeping1 = 2,
*|  PowerSystemSleeping2 = 3,
*|  PowerSystemSleeping3 = 4,
*|  PowerSystemHibernate = 5,
*|  PowerSystemShutdown = 6,
*|  PowerSystemMaximum = 7
*|} SYSTEM_POWER_STATE, *PSYSTEM_POWER_STATE;

	DO CASE
	CASE nIndex = 1
		RETURN "System power state S0"
	CASE nIndex = 2
		RETURN "System power state S1"
	CASE nIndex = 3
		RETURN "System power state S2"
	CASE nIndex = 4
		RETURN "System power state S3"
	CASE nIndex = 5
		RETURN "System power state S4 (HIBERNATE)"
	CASE nIndex = 6
		RETURN "System power state S5 (OFF)"
	CASE nIndex = 7
		RETURN "Maximum enumeration value"
	ENDCASE
RETURN "A lid-open event does not wake the system"  
```  
***  


## Listed functions:
[GetPwrCapabilities](../libraries/powrprof/GetPwrCapabilities.md)  

## Comment:
With this code you can define is your system is currently running using a battery, and whether this battery is a UPS (uninterruptible power supply) short-term battery or a regular portable computer battery.   
  
Another Power Management function that I would recommend is the GetSystemPowerStatus.  
  
***  

