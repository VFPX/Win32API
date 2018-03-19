[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to save registry key including its subkeys and values to a file

## Code:
```foxpro  
#DEFINE ERROR_SUCCESS 0
#DEFINE KEY_READ  0x20019
#DEFINE KEY_ALL_ACCESS  0xF003F
#DEFINE HKEY_CURRENT_USER  0x80000001

DO decl

hKey = 0
lcKey = "Software\Microsoft\VisualFoxPro"
lcTargetFile = "c:\temp\regdata.txt"

IF RegOpenKeyEx (HKEY_CURRENT_USER, lcKey,;
	0, KEY_ALL_ACCESS, @hKey) <> ERROR_SUCCESS
	? "Error opening registry key"
	RETURN
ENDIF

lnResult = RegSaveKey (hKey, lcTargetFile, 0)
IF lnResult <> ERROR_SUCCESS
	*    3 = ERROR_PATH_NOT_FOUND
	*   21 = ERROR_NOT_READY
	*  120 = ERROR_CALL_NOT_IMPLEMENTED
	*  183 = ERROR_ALREADY_EXISTS
	* 1314 = ERROR_PRIVILEGE_NOT_HELD
	? "Error code:", lnResult
ENDIF
= RegCloseKey (hKey)

PROCEDURE  decl
	DECLARE INTEGER GetLastError IN kernel32

	DECLARE INTEGER RegCloseKey IN advapi32 INTEGER hKey

	DECLARE INTEGER RegOpenKeyEx IN advapi32;
		INTEGER   hKey,;
		STRING    lpSubKey,;
		INTEGER   ulOptions,;
		INTEGER   samDesired,;
		INTEGER @ phkResult

	DECLARE INTEGER RegSaveKey IN advapi32;
		INTEGER hKey,;
		STRING  lpFile,;
		INTEGER lpSecurityAttributes  
```  
***  


## Listed functions:
[GetLastError](../libraries/kernel32/GetLastError.md)  
[RegCloseKey](../libraries/advapi32/RegCloseKey.md)  
[RegOpenKeyEx](../libraries/advapi32/RegOpenKeyEx.md)  
[RegSaveKey](../libraries/advapi32/RegSaveKey.md)  
