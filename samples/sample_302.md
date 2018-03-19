[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to retrieve the number of objects stored in the Recycle Bin

## Before you begin:
![](../images/recyclebin.png)  

See also:

* [Deleting file into the Recycle Bin](sample_321.md)  
* [How to empty the Recycle Bin](sample_301.md)  
* [How to remove a directory that is not empty](sample_541.md)  
* [Displaying standard progress dialog box when copying files](sample_508.md)  

  
***  


## Code:
```foxpro  
#DEFINE S_OK 0

*|typedef struct _SHQUERYRBINFO{
*|    DWORD cbSize;
*|    #if !defined(_MAC) || defined (_MAC_INT_64)
*|        __int64 i64Size;
*|        __int64 i64NumItems;
*|    #else
*|        DWORDLONG i64Size;
*|        DWORDLONG i64NumItems;
*|    #endif
*|} SHQUERYRBINFO, *LPSHQUERYRBINFO; total bytes = 20

	LOCAL lcBuffer
	lcBuffer = Chr(20) + Repli(Chr(0), 19)

	DECLARE INTEGER SHQueryRecycleBin IN shell32;
		STRING pszRootPath, STRING @pSHQueryRBInfo

	IF SHQueryRecycleBin ("C:", @lcBuffer) = S_OK
		?"*** The Recycle Bin:"

		? "Total size of all objects, bytes:",;
			buf2i64(SUBSTR(lcBuffer, 5,8))

		? "Total number of objects:",;
			buf2i64(SUBSTR(lcBuffer, 13,8))
	ENDIF
RETURN

FUNCTION  buf2dword (lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)

FUNCTION  buf2i64 (lcBuffer)
#DEFINE BITSHIFT32 0x100000000
RETURN buf2dword(SUBSTR(lcBuffer, 1,4)) +;
	BITSHIFT32 * buf2dword(SUBSTR(lcBuffer, 5,4))  
```  
***  


## Listed functions:
[SHQueryRecycleBin](../libraries/shell32/SHQueryRecycleBin.md)  
