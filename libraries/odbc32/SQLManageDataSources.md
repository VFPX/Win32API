<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SQLManageDataSources
Group: ODBC API - Library: odbc32    
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
```txt  
hwnd
[Input]
Parent window handle.  
```  
***  


## Return value:
SQLManageDataSources returns FALSE if hwnd is not a valid window handle.  
***  

