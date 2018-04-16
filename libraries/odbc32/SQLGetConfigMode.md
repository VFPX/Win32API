[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLGetConfigMode
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### Retrieves the configuration mode that indicates where the Odbc.ini entry listing DSN values is in the system information.

***  


## Code examples:
[How to retrieve list of system DSNs (Data Source Name) with parameters](../../samples/sample_375.md)  

## Declaration:
```foxpro  
BOOL SQLGetConfigMode(
	UWORD * pwConfigMode);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLGetConfigMode IN odbccp32;
	LONG @ pwConfigMode  
```  
***  


## Parameters:
pwConfigMode 
[out] Pointer to the buffer containing the configuration mode.  
***  


## Return value:
The function returns TRUE if it is successful, FALSE if it fails.  
***  


## Comments:
The value in *pwConfigMode* can be:   
* ODBC_USER_DSN  
* ODBC_SYSTEM_DSN  
* ODBC_BOTH_DSN   
  
See also [SQLSetConfigMode](SQLSetConfigMode.md) function.  
  
***  

