[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FileIconInit
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
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
fRestoreCache
[in] TRUE to restore the system image cache from disk; FALSE otherwise.  
***  


## Return value:
TRUE if the cache was successfully refreshed, FALSE if the initialization failed.
  
***  


## Comments:
If you are manually handling imagelists, you must call FileIconInit in response to a WM_SETTINGCHANGE message, when the SPI_SETNONCLIENTMETRICS flag is set, or when the WindowMetrics values change.  
  
***  

