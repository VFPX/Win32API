<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Using the CopyFile

## Before you begin:
See also:

* [Copying files as a transacted operation](sample_540.md)  
* [Displaying standard progress dialog box when copying files](sample_508.md)  
* [Deleting file into the Recycle Bin](sample_321.md)  

  
***  


## Code:
```foxpro  
DECLARE INTEGER CopyFile IN kernel32;
	STRING lpExistingFileName,;
	STRING lpNewFileName,;
	INTEGER bFailIfExists

? CopyFile("C:\Autoexec.bat", "C:\Autoexec.cpy", 0)  
```  
***  


## Listed functions:
[CopyFile](../libraries/kernel32/CopyFile.md)  
