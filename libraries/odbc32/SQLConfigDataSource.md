[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLConfigDataSource
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLConfigDataSource adds, modifies, or deletes data sources.
***  


## Code examples:
[Adding an ODBC data source with the SQLConfigDataSource; use automatic or interactive mode](../../samples/sample_381.md)  

## Declaration:
```foxpro  
BOOL SQLConfigDataSource(
	HWND hwndParent,
	WORD fRequest,
	LPCSTR lpszDriver,
	LPCSTR lpszAttributes
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLConfigDataSource IN odbccp32;
	INTEGER hwndParent,;
	INTEGER fRequest,;
	STRING  lpszDriver,;
	STRING  lpszAttributes
  
```  
***  


## Parameters:
hwndParent 
[in]
Parent window handle. The function will not display any dialog boxes if the handle is null. 

fRequest 
[in]
Type of request -- a predefined value. 

lpszDriver 
[in]
Driver description (usually the name of the associated DBMS) presented to users instead of the physical driver name. 

lpszAttributes 
[in]
List of attributes in the form of keyword-value pairs.   
***  


## Return value:
The function returns TRUE if it is successful.  
***  


## Comments:
When SQLConfigDataSource returns FALSE, an associated *pfErrorCode value can be obtained by calling SQLInstallerError.  
  
***  

