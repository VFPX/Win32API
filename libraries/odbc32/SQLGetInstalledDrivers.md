[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetInstalledDrivers
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLGetInstalledDrivers reads the [ODBC Drivers] section of the system information and returns a list of descriptions of the installed drivers.
***  


## Code examples:
[List of ODBC drivers installed (read from the [ODBC Drivers] section)](../../samples/sample_378.md)  

## Declaration:
```foxpro  
BOOL SQLGetInstalledDrivers(
	LPSTR lpszBuf,
	WORD  cbBufMax,
	WORD * pcbBufOut);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLGetInstalledDrivers IN odbccp32;
	STRING  @ lpszBuf,;
	INTEGER   cbBufMax,;
	INTEGER @ pcbBufOut
  
```  
***  


## Parameters:
lpszBuf 
[Output]
List of descriptions of the installed drivers. 

cbBufMax 
[Input]
Length of lpszBuf. 

pcbBufOut 
[Output]
Total number of bytes (excluding the null-termination byte) returned in lpszBuf.   
***  


## Return value:
The function returns TRUE if it is successful.  
***  


## Comments:
[My Computer\HKEY_LOCAL_MACHINE\SOFTWARE\ODBC\ODBCINST.INI\ODBC Drivers]  
  
***  

