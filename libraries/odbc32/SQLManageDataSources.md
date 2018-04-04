[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SQLManageDataSources
Group: [ODBC API](../../functions_group.md#ODBC_API)  -  Library: [odbc32](../../Libraries.md#odbc32)  
***  


#### SQLManageDataSources displays a dialog box with which users can set up, add, and delete data sources in the system information.
***  


## Code examples:
[How to display a dialog box with which the user can add a data source (DSN)](../../samples/sample_380.md)  

## Declaration:
```foxpro  
BOOL SQLManageDataSources(
	HWND hwnd
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SQLManageDataSources IN odbccp32;
	INTEGER hwnd  
```  
***  


## Parameters:
hwnd 
[Input]
Parent window handle.  
***  


## Return value:
SQLManageDataSources returns FALSE if hwnd is not a valid window handle.  
***  

