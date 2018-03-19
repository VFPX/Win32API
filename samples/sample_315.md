[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving Network Provider information

## Code:
```foxpro  
#DEFINE NO_ERROR  0

*|typedef struct _NETINFOSTRUCT{
*|  DWORD cbStructure;        0:4
*|  DWORD dwProviderVersion;  4:4
*|  DWORD dwStatus;           8:4
*|  DWORD dwCharacteristics;  12:4
*|  ULONG_PTR dwHandle;       16:4
*|  WORD wNetType;            20:4
*|  DWORD dwPrinters;         24:4
*|  DWORD dwDrives;           28:4
*|} NETINFOSTRUCT, *LPNETINFOSTRUCT; total = 32 bytes

#DEFINE NETINFO_SIZE  32

	DECLARE INTEGER WNetGetNetworkInformation IN mpr;
		STRING lpProvider, STRING @lpNetInfoStruct
	
	LOCAL lcProvider, lcBuffer, lnResult

	lcProvider = "Microsoft Windows Network"
	lcBuffer = Chr(NETINFO_SIZE) + Repli(Chr(0), NETINFO_SIZE-1)

	lnResult = WNetGetNetworkInformation (lcProvider, @lcBuffer)
	IF lnResult <> NO_ERROR
	* ERROR_BAD_PROVIDER = 1204
		? "Error code:", lnResult
	ELSE
		CREATE CURSOR csResult (paramname C(30), paramvalue C(20))

		_add ("Provider Version", buf2dword(SUBSTR(lcBuffer, 5,4)))
		_add ("Software status", buf2dword(SUBSTR(lcBuffer, 9,4)))
		_add ("Software characteristics", buf2dword(SUBSTR(lcBuffer, 13,4)))
		_add ("Instance handle", buf2dword(SUBSTR(lcBuffer, 17,4)))
		_add ("Network type", buf2dword(SUBSTR(lcBuffer, 21,4)))
		_add ("Printer flags", buf2dword(SUBSTR(lcBuffer, 25,4)))
		_add ("Drives flags", buf2dword(SUBSTR(lcBuffer, 29,4)))
		
		GO TOP
		BROW NORMAL NOWAIT
	ENDIF

PROCEDURE _add (lcName, lnValue)
	INSERT INTO csResult VALUES (lcName, LTRIM(STR(lnvalue)))

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[WNetGetNetworkInformation](../libraries/mpr/WNetGetNetworkInformation.md)  
