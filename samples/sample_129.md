[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating the subkeys of a user-specific key

## Code:
```foxpro  
#DEFINE ERROR_SUCCESS             0
#DEFINE KEY_READ             131097
#DEFINE KEY_ALL_ACCESS       983103

* SHREGENUM_FLAGS
#DEFINE SHREGENUM_DEFAULT   0
#DEFINE SHREGENUM_HKCU      1  && current user
#DEFINE SHREGENUM_HKLM     16  && local machine
#DEFINE SHREGENUM_BOTH     17

DO decl
	
hKey = 0
lnResult = SHRegOpenUSKey ("Software", KEY_READ, 0, @hKey, 0)

IF lnResult <> ERROR_SUCCESS
	* 127 = ERROR_PROC_NOT_FOUND - means that path not found
	? "Error code:", GetLastError()
	RETURN
ENDIF

CREATE CURSOR cs (keyname C(100))
dwIndex = 0

DO WHILE .T.
	lnNameSize = 250
	lcName = Repli (Chr(0), lnNameSize)

	IF SHRegEnumUSKey (hKey, dwIndex,;
		@lcName, @lnNameSize, SHREGENUM_HKCU) = ERROR_SUCCESS

		INSERT INTO cs VALUES (Left(lcName, lnNameSize))
		dwIndex = dwIndex + 1
	ELSE
		EXIT
	ENDIF
ENDDO
= SHRegCloseUSKey (hKey)

SELECT cs
INDEX ON keyname TAG keyname
GO TOP
BROW NORMAL NOWAIT
* end of main

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER SHRegOpenUSKey IN shlwapi;
    	STRING    pszPath,;
    	INTEGER   samDesired,;
    	INTEGER   hRelativeUSKey,;
    	INTEGER @ phNewUSKey,;
    	SHORT     fIgnoreHKCU

	DECLARE INTEGER SHRegCloseUSKey IN shlwapi INTEGER hUSKey

	DECLARE INTEGER SHRegEnumUSKey IN shlwapi;
    	INTEGER   hUSKey,;
    	INTEGER   dwIndex,;
    	STRING  @ pszName,;
    	INTEGER @ pcchName,;
    	INTEGER   enumRegFlags  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[SHRegCloseUSKey](../libraries/shlwapi/SHRegCloseUSKey.md)  
[SHRegEnumUSKey](../libraries/shlwapi/SHRegEnumUSKey.md)  
[SHRegOpenUSKey](../libraries/shlwapi/SHRegOpenUSKey.md)  

## Comment:
Try some other path values, e.g. "Software\Microsoft"  
  
***  

