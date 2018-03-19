[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving names for the registered clipboard formats

## Code:
```foxpro  
DO decl

LOCAL lcBuffer, lnResult, hFormat, ii, lcName
#DEFINE cmBufsize  250

* registering a new format
hFormat = RegisterClipboardFormat ("NewlyRegisteredFormat")
? "New format registered:", hFormat

CREATE CURSOR csResult (id N(6), name C(250))

* Registered clipboard formats are identified by values
* in the range 0xC000 through 0xFFFF

FOR ii=49152 TO 65535
	lcBuffer = Repli(Chr(0), cmBufsize)
	lnResult = GetClipboardFormatName (ii, @lcBuffer, cmBufsize)

	IF lnResult <> 0
		lcName = Left(lcBuffer, lnResult)
		INSERT INTO csResult VALUES (ii, lcName)
	ENDIF
ENDFOR

IF hFormat <> 0
	LOCATE ALL FOR id = hFormat
ELSE
	GO TOP
ENDIF
BROWSE NORMAL NOWAIT

PROCEDURE  decl
	DECLARE INTEGER GetClipboardFormatName IN user32;
		INTEGER format, STRING @lpszFormatName,;
		INTEGER cchMaxCount

	DECLARE INTEGER RegisterClipboardFormat IN user32;
		STRING lpszFormat  
```  
***  


## Listed functions:
[GetClipboardFormatName](../libraries/user32/GetClipboardFormatName.md)  
[RegisterClipboardFormat](../libraries/user32/RegisterClipboardFormat.md)  

## Comment:
Registered clipboard formats are identified by values in the range 0xC000 through 0xFFFF.   
  
Under my WinMe system this example returns valid names as long as some garbage. Or it just seems like a garbage for me? After all this is another system nook where something can be stored until next reboot or shutdown.  
  
The RegisterClipboardFormat is one-way road -- from a given name to a number within the [0xC000..0xFFFF] range. Though it takes no time to scan the range to define whether a cliboard format name is already registered.  
  
***  

