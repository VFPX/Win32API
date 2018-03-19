[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

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

