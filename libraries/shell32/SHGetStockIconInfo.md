[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SHGetStockIconInfo
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves information about system-defined Shell icons.
***  


## Code examples:
[Windows Shell Icons displayed and exported to ICO files (Vista)](../../samples/sample_575.md)  

## Declaration:
```foxpro  
HRESULT SHGetStockIconInfo(
           SHSTOCKICONID siid,
           UINT uFlags,
  __inout  SHSTOCKICONINFO *psii
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SHGetStockIconInfo IN shell32;
	INTEGER siid,;
	LONG uFlags,;
	INTEGER psii  
```  
***  


## Parameters:
siid
One of the values from the SHSTOCKICONID enumeration that specifies which icon should be retrieved.

uFlags
A combination of zero or more of the following flags that specify which information is requested.

psii [in, out]
A pointer to a SHSTOCKICONINFO structure.  
***  


## Return value:
If the method succeeds, it returns S_OK (0). Otherwise, it returns an HRESULT error code.  
***  


## Comments:
If this function returns an icon handle in the hIcon member of the SHSTOCKICONINFO structure pointed to by psii, you are responsible for freeing the icon with DestroyIcon when you no longer need it.  
  
See also: [ExtractIcon](../shell32/ExtractIcon.md), [ExtractAssociatedIcon](../shell32/ExtractAssociatedIcon.md), [GetIconInfo](../user32/GetIconInfo.md).  
  
***  

