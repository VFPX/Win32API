[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to get the path to a Special Folder

## Before you begin:
This code shows how to obtain path to special folders like *My Documents, My Pictures, Start Menu, Startup, Favourites, Recent files* and others.  

See also:

* [Browsing Windows Known Folders (Special Folders)](sample_576.md)  
* [Obtaining the System and Windows folder names](sample_005.md)  
  
***  


## Code:
```foxpro  
#DEFINE CSIDL_ALTSTARTUP 0x001d
#DEFINE CSIDL_APPDATA 0x001a
#DEFINE CSIDL_BITBUCKET 0x000a
#DEFINE CSIDL_COMMON_ALTSTARTUP 0x001e
#DEFINE CSIDL_COMMON_DESKTOPDIR 0x0019
#DEFINE CSIDL_COMMON_FAVORITES 0x001f
#DEFINE CSIDL_COMMON_PROGRAMS 0x0017
#DEFINE CSIDL_COMMON_STARTMENU 0x0016
#DEFINE CSIDL_COMMON_STARTUP 0x0018
#DEFINE CSIDL_CONTROLS 0x0003
#DEFINE CSIDL_COOKIES 0x0021
#DEFINE CSIDL_DESKTOP 0x0000
#DEFINE CSIDL_DESKTOPDIRECTORY 0x0010
#DEFINE CSIDL_DRIVES 0x0011
#DEFINE CSIDL_FAVORITES 0x0006
#DEFINE CSIDL_FONTS 0x0014
#DEFINE CSIDL_HISTORY 0x0022
#DEFINE CSIDL_INTERNET 0x0001
#DEFINE CSIDL_INTERNET_CACHE 0x0020
#DEFINE CSIDL_NETHOOD 0x0013
#DEFINE CSIDL_NETWORK 0x0012
#DEFINE CSIDL_PERSONAL 0x0005
#DEFINE CSIDL_PRINTERS 0x0004
#DEFINE CSIDL_PRINTHOOD 0x001b
#DEFINE CSIDL_PROGRAMS 0x0002
#DEFINE CSIDL_RECENT 0x0008
#DEFINE CSIDL_SENDTO 0x0009
#DEFINE CSIDL_STARTMENU 0x000b
#DEFINE CSIDL_STARTUP 0x0007
#DEFINE CSIDL_TEMPLATES 0x0015

DECLARE SHORT SHGetFolderPath IN shell32;
	INTEGER hwndOwner, INTEGER nFolder,;
	INTEGER hToken, INTEGER dwFlags,;
	STRING @pszPath

CREATE CURSOR csResult (;
	csidl I, path0 C(100), path1 C(100))

* all special CSIDLs are in 0xff range
FOR nIndex=-1 TO 255
	= GetPath(nIndex)
ENDFOR

GO TOP
BROWSE NORMAL NOWAIT
* end of main

PROCEDURE GetPath(nCSIDL)
#DEFINE MAX_PATH 260
#DEFINE SHGFP_TYPE_CURRENT 0 && returns current path
#DEFINE SHGFP_TYPE_DEFAULT 1 && returns default path
#DEFINE CSIDL_FLAG_PER_USER_INIT 0x0800
#DEFINE CSIDL_FLAG_NO_ALIAS 0x1000
#DEFINE CSIDL_FLAG_DONT_VERIFY 0x4000
#DEFINE CSIDL_FLAG_CREATE 0x8000
#DEFINE CSIDL_FLAG_MASK 0xff00

	LOCAL nFlag, nToken, cBuffer, nResult, cPath0, cPath1
	STORE "" To cPath0, cPath1

	nFlag = BitOr(nCSIDL, CSIDL_FLAG_PER_USER_INIT)
*	nToken = -1 && default user
	nToken = 0 && current user
	
	cBuffer = Repli(Chr(0), MAX_PATH)
	IF SHGetFolderPath(0, nFlag, nToken,;
		SHGFP_TYPE_CURRENT, @cBuffer) = 0
		cPath0 = STRTRAN(cBuffer, Chr(0), "")
	ENDIF

	cBuffer = Repli(Chr(0), MAX_PATH)
	IF SHGetFolderPath(0, nFlag, nToken,;
		SHGFP_TYPE_DEFAULT, @cBuffer) = 0
		cPath1 = STRTRAN(cBuffer, Chr(0), "")
	ENDIF

	IF Not EMPTY(cPath0 + cPath1)
		INSERT INTO csResult VALUES (;
			nCSIDL, cPath0, cPath1)
	ENDIF  
```  
***  


## Listed functions:
[SHGetFolderPath](../libraries/shell32/SHGetFolderPath.md)  

## Comment:
For Windows versions 98, NT4 the SHGetFolderPath is obtained through SHFolder.dll, not through Shell32.dll.   
  
SHFolder.dll continues to be included for backward compatibility, though the function is now implemented in Shell32.dll.  
  
CSIDL values provide a unique system-independent way to identify special folders used frequently by applications, but which may not have the same name or location on any given system. For example, the system folder may be "C:\Windows" on one system and "C:\Winnt" on another.  
  
As of Windows Vista, these values have been replaced by KNOWNFOLDERID values.  
  
<a href="http://msdn.microsoft.com/en-us/library/bb762494(v=vs.85).aspx">CSIDL list</a>.  
  
***  

