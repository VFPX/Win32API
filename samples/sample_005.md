<link rel="stylesheet" type="text/css" href="../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

# Obtaining the System and Windows folder names

## Before you begin:
See also: 

* [How to get Special Folders paths](sample_415.md)  
* [Browsing Windows Known Folders (Special Folders)](sample_576.md)  
* [Retrieving default spooling directory](sample_005.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER GetWindowsDirectory IN kernel32;
	STRING @lpBuffer, INTEGER nSize

DECLARE INTEGER GetSystemDirectory IN kernel32;
	STRING @ lpBuffer, INTEGER nSize

LOCAL lpBuffer, nSizeRet

lpBuffer = SPACE (250)
nSizeRet = GetSystemDirectory(@lpBuffer, Len(lpBuffer))
lpBuffer = SUBSTR (lpBuffer, 1, nSizeRet)
? lpBuffer

lpBuffer = SPACE (250)
nSizeRet = GetWindowsDirectory(@lpBuffer, Len(lpBuffer))
lpBuffer = SUBSTR (lpBuffer, 1, nSizeRet)
? lpBuffer  
```  
***  


## Listed functions:
[GetSystemDirectory](../libraries/kernel32/GetSystemDirectory.md)  
[GetWindowsDirectory](../libraries/kernel32/GetWindowsDirectory.md)  

## Comment:
? GetEnv("windir")  
  
***  

