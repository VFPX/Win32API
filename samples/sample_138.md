[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# How to find the application associated with a file name

## Before you begin:
See also:

* [Finding the application, icon and friendly names associated with a file name](sample_584.md)  
* [Displaying the associated icons and descriptions for files and folders](sample_530.md)  
* [How to view system icons for the classes installed on the local machine](sample_544.md)  
* [How to obtain Content-Type value for a file type from the System Registry](sample_468.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER FindExecutable IN shell32;
	STRING lpFile, STRING lpDir, STRING @lpResult

lcResult = SPACE(250)

IF FindExecutable ("c:\MyDocuments\daily.doc", "", @lcResult) > 32
	lcResult = ALLTRIM(STRTRAN(lcResult, Chr(0), " "))
	? lcResult
ELSE
	*    2 = ERROR_FILE_NOT_FOUND
	*    3 = ERROR_PATH_NOT_FOUND
	*   21 = ERROR_NOT_READY
	*  123 = ERROR_INVALID_NAME
	*  127 = ERROR_PROC_NOT_FOUND
	* 1008 = ERROR_NO_TOKEN

	DECLARE INTEGER GetLastError IN kernel32
	? "Error code:", GetLastError()
ENDIF  
```  
***  


## Listed functions:
[FindExecutable](../libraries/shell32/FindExecutable.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  

## Comment:
Normally this code returns a path to the Microsoft Word, or to any application associated with DOC files.   
  
Note that the source file -- in the sample code "c:\MyDocuments\daily.doc" -- must exists, even if a dummy file of zero size.  
  
Unlike the FindExecutable, another API function the AssocQueryString retrieves file associations without relying on names of physical files.  
  
***  

