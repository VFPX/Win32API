[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Enumerating the subkeys for a given registry key

## Code:
```foxpro  
#DEFINE ERROR_SUCCESS  0
#DEFINE HKEY_CLASSES_ROOT 0x80000000
#DEFINE HKEY_CURRENT_USER 0x80000001
#DEFINE HKEY_LOCAL_MACHINE 0x80000002
#DEFINE HKEY_USERS 0x80000003
#DEFINE HKEY_PERFORMANCE_DATA 0x80000004
#DEFINE HKEY_CURRENT_CONFIG 0x80000005
#DEFINE HKEY_DYN_DATA  0x80000006

	DO decl
	CREATE CURSOR csKeys (topkey C(30), subkey C(50))
	
*	= enumKeys ("HKEY_CLASSES_ROOT", HKEY_CLASSES_ROOT)
	= enumKeys ("HKEY_CURRENT_USER", HKEY_CURRENT_USER)
	= enumKeys ("HKEY_LOCAL_MACHINE", HKEY_LOCAL_MACHINE)
*	= enumKeys ("HKEY_USERS", HKEY_USERS)
*	= enumKeys ("HKEY_PERFORMANCE_DATA", HKEY_PERFORMANCE_DATA)
*	= enumKeys ("HKEY_CURRENT_CONFIG", HKEY_CURRENT_CONFIG)
*	= enumKeys ("HKEY_DYN_DATA", HKEY_DYN_DATA)

	SELECT csKeys
	INDEX ON topkey+subkey TAG subkey
	GO TOP
	BROWSE NORMAL NOWAIT

PROCEDURE  enumKeys (lcTopKey, hTopKey)
	LOCAL lnIndex, lcName, lnNameLen
	lnIndex = 0

	DO WHILE .T.
		lnNameLen = 250
		lcName = Repli (Chr(0), lnNameLen)

		IF SHEnumKeyEx (hTopKey, lnIndex, @lcName, @lnNameLen) = ERROR_SUCCESS
			INSERT INTO csKeys VALUES (lcTopKey, Left (lcName, lnNameLen))
		ELSE
			EXIT
		ENDIF
		lnIndex = lnIndex + 1
	ENDDO
RETURN

PROCEDURE  decl
	DECLARE INTEGER SHEnumKeyEx IN shlwapi;
    	INTEGER   hkey,;
    	INTEGER   dwIndex,;
    	STRING  @ pszName,;
    	INTEGER @ pcchName  
```  
***  


## Listed functions:
[SHEnumKeyEx](../libraries/shlwapi/SHEnumKeyEx.md)  
