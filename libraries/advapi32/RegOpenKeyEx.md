[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegOpenKeyEx
Group: [Registry](../../functions_group.md#Registry)  -  Library: [advapi32](../../Libraries.md#advapi32)  
***  


#### The RegOpenKeyEx function opens the specified registry key.
***  


## Code examples:
[Reading VFP settings from the Windows Registry](../../samples/sample_131.md)  
[How to save registry key including its subkeys and values to a file](../../samples/sample_135.md)  
[Obtaining current Internet Explorer browser version and UserAgent](../../samples/sample_142.md)  
[Saving local machine ODBC Registry Entries to XML file](../../samples/sample_379.md)  
[How to obtain Content-Type value for a file type from the System Registry](../../samples/sample_468.md)  
[Class library providing access to the System Registry](../../samples/sample_472.md)  

## Declaration:
```foxpro  
LONG RegOpenKeyEx(
  HKEY hKey,         // handle to open key
  LPCTSTR lpSubKey,  // subkey name
  DWORD ulOptions,   // reserved
  REGSAM samDesired, // security access mask
  PHKEY phkResult    // handle to open key
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegOpenKeyEx IN advapi32;
	INTEGER   hKey,;
	STRING    lpSubKey,;
	INTEGER   ulOptions,;
	INTEGER   samDesired,;
	INTEGER @ phkResult  
```  
***  


## Parameters:
hKey 
[in] Handle to a currently open key or a predefined reserved handle value.

lpSubKey 
[in] Pointer to a null-terminated string containing the name of the subkey to open. 

ulOptions 
Reserved; must be zero. 

samDesired 
[in] An access mask that specifies the desired access rights to the key. 

phkResult 
[out] Pointer to a variable that receives a handle to the opened key.  
***  


## Return value:
If the function succeeds, the return value is 0 (ERROR_SUCCESS). Otherwise, the return value is a nonzero error code.
  
***  


## Comments:
When you no longer need the handle returned by this function, call the RegCloseKey function to close it.  
  
* * *  
June 2, 2010. Contributed by <Em>Igor Nikiforov</Em>:  
  
Under Windows 2008 Server 64-bit, a call to RegOpenKeyEx returns error code 2 (ERROR_FILE_NOT_FOUND) for some keys.  
  
Example:  
```foxpro
RegOpenKeyEx(HKEY_LOCAL_MACHINE ,;   
	[SOFTWARE\Microsoft\Windows\CurrentVersion\Installer\ ... ;  
	... \InstallProperties], 0, ;  
	KEY_READ, @hKey)
```

Changing <Em>samDesired</Em> input parameter from KEY_READ to ( KEY_READ | ***KEY_WOW64_64KEY*** ) resolves the issue.  
  
```foxpro
RegOpenKeyEx(HKEY_LOCAL_MACHINE , ;  
	[SOFTWARE\Microsoft\Windows\CurrentVersion\Installer\ ... ;  
	... \InstallProperties], 0, ;  
	BITOR(KEY_READ, KEY_WOW64_64KEY), @hKey)
```
Find more in <a href="http://msdn.microsoft.com/en-us/library/ms724878(VS.85).aspx">Registry Key Security and Access Rights</a> article on MSDN web site.  
  
***  

