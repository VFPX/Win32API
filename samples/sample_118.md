[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Extracting the name and extension parts of a path string

## Code:
```foxpro  
DECLARE SHORT GetFileTitle IN Comdlg32;
	STRING   lpszFile,;
	STRING @ lpszTitle,;
	INTEGER  cbBuf

lpszFile = "c:\Program Files\NetLab\AddressBook.dat"
lpszTitle = SPACE(250)

* for this path the return is "addressbook.dat"

IF GetFileTitle (lpszFile, @lpszTitle, Len(lpszTitle)) = 0
	lpszTitle = LEFT (lpszTitle, AT(Chr(0),lpszTitle)-1)
	? lpszTitle
ENDIF  
```  
***  


## Listed functions:
[GetFileTitle](../libraries/comdlg32/GetFileTitle.md)  

## Comment:
The path string should be valid Win32 name. Although that does not mean that the file should exist.  
  
***  

