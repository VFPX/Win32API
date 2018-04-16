[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DllInstall
Group: [Shell Lightweight Utility APIs -- misc. functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_misc._functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Handles installation and setup for a dynamic-link library (DLL). 
***  


## Declaration:
```foxpro  
HRESULT DllInstall(
	BOOL bInstall,
	LPCWSTR pszCmdLine
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DllInstall IN shlwapi;
	INTEGER bInstall,;
	STRING  pszCmdLine
  
```  
***  


## Parameters:
bInstall
Value that is set to TRUE if the DLL is being installed, or FALSE if it is being uninstalled. 

pszCmdLine
String passed in by regsvr32 that indicates which setup procedure to use.
  
***  


## Return value:
Returns NOERROR (0) if successful, or an OLE-defined error value otherwise.   
***  


## Comments:
Minimum operating systems: Windows 2000, Windows NT 4.0 with Internet Explorer 4.0, Windows 98.  
  
To use DllInstall with regsvr32, add a "/i" flag followed by a colon (:) and a string. The string will be passed to DllInstall as the pszCmdLine parameter. If you omit the colon and string, pszCmdLine will be set to NULL. The following example would be used to install a DLL:   
  
```dos
regsvr32 /i:"Install_1" dllname.dll
```

  
  
***  

