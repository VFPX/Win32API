[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetIconInfo
Group: [Icon](../../functions_group.md#Icon)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetIconInfo function retrieves information about the specified icon or cursor.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[Retrieving information about the specified icon](../../samples/sample_206.md)  
[Converting image file to .ICO file](../../samples/sample_503.md)  

## Declaration:
```foxpro  
BOOL GetIconInfo(
  HICON hIcon,          // icon handle
  PICONINFO piconinfo   // icon structure
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetIconInfo IN user32;
	INTEGER   hIcon,;
	STRING  @ piconinfo  
```  
***  


## Parameters:
hIcon 
[in] Handle to the icon or cursor. 

piconinfo 
[out] Pointer to an ICONINFO structure. The function fills in the structure"s members.   
***  


## Return value:
If the function succeeds, the return value is nonzero and the function fills in the members of the specified ICONINFO structure. If the function fails, the return value is zero.   
***  


## Comments:
See also: [ExtractIcon](../shell32/ExtractIcon.md), [SHGetStockIconInfo](../shell32/SHGetStockIconInfo.md).  
  
***  

