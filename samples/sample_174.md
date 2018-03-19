[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Listing device drivers in the system: load addresses, names

## Code:
```foxpro  
DO declare

LOCAL lcBuffer, lnAllocated, lnBytesNeeded, ii,;
	lnLoadAddr, lcBaseName, lcFullName

lnBytesNeeded = 0

* MSDN:
* It is a good idea to give EnumDeviceDrivers a large array
* of LPVOID values, because it is hard to predict
* how many device drivers there will be at the time
* you call EnumDeviceDrivers.

lnAllocated = 16384
lcBuffer = Repli(Chr(0), lnAllocated)

IF EnumDeviceDrivers(@lcBuffer, lnAllocated, @lnBytesNeeded) <> 0
	lcBuffer = Left(lcBuffer, lnBytesNeeded)

	* resulting cursor
	CREATE CURSOR csResult (drivername C(30),;
		loadaddr N(12), fullname C(250))

	FOR ii=1 TO lnBytesNeeded/4
		lnLoadAddr = buf2dword(SUBSTR(lcBuffer, (ii-1)*4+1, 4))

		* retrieving the base name
		lcBaseName = SPACE(50)
		= GetDeviceDriverBaseName(lnLoadAddr,;
			@lcBaseName, Len(lcBaseName))
		lcBaseName = Left(lcBaseName, AT(Chr(0),lcBaseName)-1)
		
		* retrieving the fully qualified path for the driver
		lcFullName = SPACE(250)
		= GetDeviceDriverFileName(lnLoadAddr,;
			@lcFullName, Len(lcFullName))
		lcFullName = Left(lcFullName, AT(Chr(0),lcFullName)-1)

		INSERT INTO csResult VALUES (;
			lcBaseName, lnLoadAddr, lcFullName)
	ENDFOR
	
	GO TOP
	BROW NORMAL NOWAIT
ENDIF

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	Asc(SUBSTR(lcBuffer, 2,1)) * 256 +;
	Asc(SUBSTR(lcBuffer, 3,1)) * 65536 +;
	Asc(SUBSTR(lcBuffer, 4,1)) * 16777216

PROCEDURE declare
	DECLARE INTEGER EnumDeviceDrivers IN psapi;
		STRING @lpImageBase, INTEGER cb, INTEGER @lpcbNeeded

	DECLARE INTEGER GetDeviceDriverBaseName IN psapi;
		INTEGER ImageBase, STRING @lpBaseName, INTEGER nSize

	DECLARE INTEGER GetDeviceDriverFileName IN psapi;
		INTEGER ImageBase, STRING @lpFilename, INTEGER nSize  
```  
***  


## Listed functions:
[EnumDeviceDrivers](../libraries/psapi/EnumDeviceDrivers.md)  
[GetDeviceDriverBaseName](../libraries/psapi/GetDeviceDriverBaseName.md)  
[GetDeviceDriverFileName](../libraries/psapi/GetDeviceDriverFileName.md)  
