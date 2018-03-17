<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

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

