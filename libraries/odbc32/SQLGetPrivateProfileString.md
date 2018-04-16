[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetPrivateProfileString
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetPrivateProfileString gets a list of names of values or data corresponding to a value of the system information.
***  


## Code examples:
[How to retrieve list of system DSNs (Data Source Name) with parameters](../../samples/sample_375.md)  

## Declaration:
```foxpro  
int SQLGetPrivateProfileString(
	LPCSTR lpszSection,
	LPCSTR lpszEntry,
	LPCSTR lpszDefault,
	LPCSTR RetBuffer,
	INT cbRetBuffer,
	LPCSTR lpszFilename
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLGetPrivateProfileString IN odbccp32;
	STRING    lpszSection,;
	STRING    lpszEntry,;
	STRING    lpszDefault,;
	STRING  @ RetBuffer,;
	INTEGER   cbRetBuffer,;
	STRING    lpszFilename
  
```  
***  


## Parameters:
lpszSection 
[Input]
Points to a null-terminated string that specifies the section containing the key name. 

lpszEntry 
[Input]
Points to the null-terminated string containing the key name whose associated string is to be retrieved. 

lpszDefault 
[Input]
Points to a null-terminated string that specifies the default value for the given key if the key cannot be found in the initialization file.

RetBuffer 
[Output]
Points to the buffer that receives the retrieved string.

cbRetBuffer 
[Input]
Specifies the size, in characters, of the buffer pointed to by the RetBuffer argument. 

lpszFilename 
[Output]
Points to a null-terminated string that names the initialization file.   
***  


## Return value:
SQLGetPrivateProfileString returns an integer value that indicates the number of characters read.  
***  


## Comments:
MSDN: SQLGetPrivateProfileString is provided as a simple way to port drivers and driver setup DLLs from Microsoft&reg; Windows&reg; to Microsoft Windows NT&reg;/Windows 2000.   
  
Calls to GetPrivateProfileString that retrieve a profile string from the Odbc.ini file should be replaced with calls to SQLGetPrivateProfileString. SQLGetPrivateProfileString calls functions in the Win32&reg; API to retrieve the requested names of values or data corresponding to a value of the Odbc.ini subkey of the system information.  
  
The configuration mode (as set by SQLSetConfigMode) indicates where the Odbc.ini entry listing DSN values is in the system information.   
  
If the DSN is a User DSN (the configuration mode is USERDSN_ONLY), the function reads from the Odbc.ini entry in HKEY_CURRENT_USER. If the DSN is a System DSN (SYSTEMDSN_ONLY), the function reads from the Odbc.ini entry in HKEY_LOCAL_MACHINE. If the configuration mode is BOTHDSN, HKEY_CURRENT_USER is tried, and if it fails, HKEY_LOCAL_MACHINE is used.  
  
***  

