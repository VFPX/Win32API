[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Retrieving the names of all sections in an initialization file

## Code:
```foxpro  
DO decl

LOCAL lnBufferSize, lcBuffer, lnReturn
lnBufferSize = 16384
lcBuffer = Repli(Chr(0), lnBufferSize)

*lnBufferSize = GetPrivateProfileSectionNames(@lcBuffer,;
				lnBufferSize, "c:\winnt\win.ini")

*lnBufferSize = GetPrivateProfileSectionNames(@lcBuffer,;
				lnBufferSize, "win.ini")

lnBufferSize = GetPrivateProfileSectionNames(@lcBuffer,;
				lnBufferSize, "c:\windows\desktop.ini")

*lnBufferSize = GetPrivateProfileSectionNames(@lcBuffer,;
				lnBufferSize, "c:\i386\display\disk_01\setup.ini")

lcBuffer = Left(lcBuffer, lnBufferSize) + Chr(0)

LOCAL ii, lcSubstr, ch
lcSubstr = ""
CREATE CURSOR csResult (section C(50))

FOR ii=1 TO lnBufferSize
	ch = SUBSTR(lcBuffer, ii,1)
	IF ch = Chr(0)
		IF Not Empty(lcSubstr)
			INSERT INTO csResult VALUES (m.lcSubstr)
			lcSubstr = ""
		ENDIF
	ELSE
		lcSubstr = lcSubstr + ch
	ENDIF
ENDFOR

SELECT csResult
GO TOP
BROWSE NORMAL NOWAIT

PROCEDURE  decl
	DECLARE INTEGER GetPrivateProfileSectionNames IN kernel32;
		STRING @lpszReturnBuffer, INTEGER nSize, STRING lpFileName  
```  
***  


## Listed functions:
[GetPrivateProfileSectionNames](../libraries/kernel32/GetPrivateProfileSectionNames.md)  

## Comment:
Calls to profile functions might be mapped to the registry instead of to the initialization files. That means when reading the Win.INI with this function, you may actually read the Windows Registry instead  
  
***  

