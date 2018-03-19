[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# One more way to retrieve environment strings

## Before you begin:
See also:

* [Creating INI file and adding strings to it](sample_137.md)  
* [Reading and setting Environment variables](sample_152.md)  
* [Storing environment strings in cursor ](sample_089.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER ExpandEnvironmentStrings IN kernel32;
	STRING   lpSrc,;
	STRING @ lpDst,;
	INTEGER  nSize

? "COMPSPEC=",     getVar ("%comspec%")
? "COMPUTERNAME=", getVar ("%computername%")
? "USERDOMAIN=",   getVar ("%userdomain%")
? "USERNAME=",     getVar ("%username%")
? "USERPROFILE=",  getVar ("%userprofile%")
? "SYSTEMROOT=",   getVar ("%systemroot%")
? "TEMP=",         getVar ("%temp%")
? "TMP=",          getVar ("%tmp%")
? "PATH=",         getVar ("%path%")

FUNCTION  getVar (lcVarname)
	LOCAL lnBufferSize, lcResult
	lnBufferSize = 2048
	lcResult = SPACE(lnBufferSize)
	lnResult = ExpandEnvironmentStrings (lcVarname, @lcResult, lnBufferSize)
RETURN IIF(lnResult > 0, LEFT(lcResult, AT(Chr(0), lcResult)-1), "#nothing#")  
```  
***  


## Listed functions:
[ExpandEnvironmentStrings](../libraries/kernel32/ExpandEnvironmentStrings.md)  

## Comment:
If there is no corresponding environment variable, this function returns the input parameter unchanged.  
  
***  

