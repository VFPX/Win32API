<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLSetConfigMode
Group: ODBC API - Library: odbc32    
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
```txt  
wConfigMode
[in] The installer configuration mode.  
```  
***  


## Return value:
The function returns TRUE if it is successful, FALSE if it fails.  
***  


## Comments:
The value in <Em>wConfigMode</Em> can be:   
<LI>ODBC_USER_DSN  
<LI>ODBC_SYSTEM_DSN  
<LI>ODBC_BOTH_DSN   
  
See also SQLGetConfigMode function.  
  
***  

