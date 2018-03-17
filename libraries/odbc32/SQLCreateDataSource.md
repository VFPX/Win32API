<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLCreateDataSource
Group: ODBC API - Library: odbc32    
***  


#### SQLCreateDataSource displays a dialog box with which the user can add a data source.
***  


## Code examples:
[How to display a dialog box with which the user can add a data source (DSN)](../../samples/sample_380.md)  

## Declaration:
```foxpro  
BOOL SQLCreateDataSource(
	HWND hwnd,
	LPSTR lpszDS
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLCreateDataSource IN odbccp32;
	INTEGER hwnd,;
	STRING  lpszDS
  
```  
***  


## Parameters:
```txt  
hwnd
[Input]
Parent window handle.

lpszDS
[Input]
Data source name. lpszDS can be a null pointer or an empty string.  
```  
***  


## Return value:
Returns TRUE if the data source is created.  
***  

