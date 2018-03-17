<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# How to empty the Recycle Bin

## Before you begin:
![](../images/recyclebin.png)  

See also:

* [Deleting file into the Recycle Bin](sample_321.md)  
* [How to retrieve number of objects in the Recycle Bin](sample_302.md)  
* [How to remove a directory that is not empty](sample_541.md)  
* [Displaying standard progress dialog box when copying files](sample_508.md)  
  
***  


## Code:
```foxpro  
#DEFINE S_OK    0
#DEFINE SHERB_DEFAULT         0
#DEFINE SHERB_NOCONFIRMATION  1
#DEFINE SHERB_NOPROGRESSUI    2
#DEFINE SHERB_NOSOUND         4

	DECLARE INTEGER SHEmptyRecycleBin IN shell32;
		INTEGER hwnd, STRING pszRootPath, LONG dwFlags

	= SHEmptyRecycleBin (0, "C:", SHERB_DEFAULT)  
```  
***  


## Listed functions:
[SHEmptyRecycleBin](../libraries/shell32/SHEmptyRecycleBin.md)  
