[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)

## Code:
```foxpro  
DO decl

LOCAL lcComponent, lcFullPath, lnPointer
lcFullPath = "C:\Program Files\Microsoft Office\Office\Binder.exe"

? "Source path string:", lcFullPath

? "File exists:", Iif(PathFileExists(lcFullPath)=0, "No","Yes")
? "Path is directory:", Iif(PathIsDirectory(lcFullPath)=0, "No","Yes")

* e.g. "prgs\tx0.prg"
? "Path is relative:", Iif(PathIsRelative(lcFullPath)=0, "No", "Yes")

* e.g. "C:\"
? "Path is root:", Iif(PathIsRoot(lcFullPath)=0, "No", "Yes")

* e.g. "https://github.com/VFPX/Win32API/tree/master/downloads/"
? "Path is URL:", Iif(PathIsURL(lcFullPath)=0, "No", "Yes")

* any mapped network drive, or a network name like "\\prnserver"
? "A network resource:", Iif(PathIsNetworkPath(lcFullPath)=0, "No","Yes")

? "File name:", PathFindFileName(lcFullPath)
? "File extension:", PathFindExtension(lcFullPath)

lcComponent = lcFullPath
= PathRenameExtension (@lcComponent, ".inf")
? "With extension replaced:", lcComponent

* Returns 0 through 25 (corresponding to "A" through "Z")
* if the path has a drive letter, or -1 otherwise
? "Drive number:", PathGetDriveNumber(lcFullPath)

? "Root directories: "
FOR ii=0 TO 25
	lcComponent = SPACE(250)
	IF PathBuildRoot(@lcComponent, ii) <> 0
		?? Left(lcComponent, AT(Chr(0), lcComponent)-1)+" "
	ENDIF
ENDFOR

PROCEDURE  decl
	DECLARE STRING  PathFindFileName IN shlwapi STRING pPath
	DECLARE INTEGER PathFileExists IN shlwapi STRING pszPath
	DECLARE INTEGER PathIsDirectory IN shlwapi STRING pszPath
	DECLARE INTEGER PathIsRelative IN shlwapi STRING pszPath
	DECLARE INTEGER PathIsRoot IN shlwapi STRING pszPath
	DECLARE INTEGER PathIsURL IN shlwapi STRING pszPath
	DECLARE INTEGER PathIsNetworkPath IN shlwapi STRING pszPath
	DECLARE STRING  PathFindExtension IN shlwapi STRING pPath
	DECLARE INTEGER PathGetDriveNumber IN shlwapi STRING lpsz

	DECLARE INTEGER PathRenameExtension IN shlwapi;
		STRING @pszPath, STRING pszExt

	DECLARE INTEGER PathBuildRoot IN shlwapi;
		STRING @szRoot, INTEGER iDrive  
```  
***  


## Listed functions:
[PathBuildRoot](../libraries/shlwapi/PathBuildRoot.md)  
[PathFileExists](../libraries/shlwapi/PathFileExists.md)  
[PathFindExtension](../libraries/shlwapi/PathFindExtension.md)  
[PathFindFileName](../libraries/shlwapi/PathFindFileName.md)  
[PathGetDriveNumber](../libraries/shlwapi/PathGetDriveNumber.md)  
[PathIsDirectory](../libraries/shlwapi/PathIsDirectory.md)  
[PathIsNetworkPath](../libraries/shlwapi/PathIsNetworkPath.md)  
[PathIsRelative](../libraries/shlwapi/PathIsRelative.md)  
[PathIsRoot](../libraries/shlwapi/PathIsRoot.md)  
[PathIsURL](../libraries/shlwapi/PathIsURL.md)  
[PathRenameExtension](../libraries/shlwapi/PathRenameExtension.md)  
