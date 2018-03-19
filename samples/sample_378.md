[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# List of ODBC drivers installed (read from the [ODBC Drivers] section)

## Before you begin:
[My Computer\HKEY_LOCAL_MACHINE\SOFTWARE\ODBC\ODBCINST.INI\ODBC Drivers]  
  
***  


## Code:
```foxpro  
LOCAL cBuffer, nBufsize, ii, ch, cName
nBufsize = 16384
cBuffer = Repli(Chr(0), nBufsize)

DECLARE INTEGER SQLGetInstalledDrivers IN odbccp32;
	STRING @lpszBuf, INTEGER cbBufMax, INTEGER @pcbBufOut

IF SQLGetInstalledDrivers(@cBuffer, nBufsize, @nBufsize) = 0
	RETURN
ENDIF

CREATE CURSOR csResult (drvname C(100))
cBuffer = SUBSTR(cBuffer,1,nBufsize)
cName = ""

FOR ii=1 TO nBufsize
	ch = SUBSTR(cBuffer, ii,1)
	IF ch = Chr(0)
		INSERT INTO csResult VALUES (m.cName)
		cName = ""
	ELSE
		cName = cName + ch
	ENDIF
ENDFOR
GO TOP
BROWSE NORMAL NOWAIT  
```  
***  


## Listed functions:
[SQLGetInstalledDrivers](../libraries/odbc32/SQLGetInstalledDrivers.md)  
