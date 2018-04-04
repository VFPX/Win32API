[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLCreateDataSource
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
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
hwnd 
[Input]
Parent window handle. 

lpszDS 
[Input]
Data source name. lpszDS can be a null pointer or an empty string.   
***  


## Return value:
Returns TRUE if the data source is created.  
***  

