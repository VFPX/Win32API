<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FileIconInit
Group: Shell Functions - Library: shell32    
***  


#### Reinitializes the system image list.
***  


## Declaration:
```foxpro  
BOOL FileIconInit(
	BOOL fRestoreCache
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FileIconInit IN shell32;
	INTEGER fRestoreCache
  
```  
***  


## Parameters:
```txt  
fRestoreCache
[in] TRUE to restore the system image cache from disk; FALSE otherwise.  
```  
***  


## Return value:
TRUE if the cache was successfully refreshed, FALSE if the initialization failed.
  
***  


## Comments:
If you are manually handling imagelists, you must call FileIconInit in response to a WM_SETTINGCHANGE message, when the SPI_SETNONCLIENTMETRICS flag is set, or when the WindowMetrics values change.  
  
***  

