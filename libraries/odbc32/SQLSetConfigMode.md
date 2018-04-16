[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLSetConfigMode
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### Sets the configuration mode that indicates where the Odbc.ini entry listing DSN values is in the system information.

***  


## Code examples:
[How to retrieve list of system DSNs (Data Source Name) with parameters](../../samples/sample_375.md)  

## Declaration:
```foxpro  
BOOL SQLSetConfigMode(
	UWORD wConfigMode);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLSetConfigMode IN odbccp32;
	LONG wConfigMode  
```  
***  


## Parameters:
wConfigMode 
[in] The installer configuration mode.  
***  


## Return value:
The function returns TRUE if it is successful, FALSE if it fails.  
***  


## Comments:
The value in *wConfigMode* can be:   
* ODBC_USER_DSN  
* ODBC_SYSTEM_DSN  
* ODBC_BOTH_DSN   
  
See also [SQLGetConfigMode](SQLGetConfigMode.md) function.  
  
***  

