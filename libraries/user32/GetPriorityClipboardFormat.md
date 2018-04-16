[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetPriorityClipboardFormat
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetPriorityClipboardFormat function retrieves the first available clipboard format in the specified list.
***  


## Code examples:
[Number of clipboard formats available](../../samples/sample_031.md)  

## Declaration:
```foxpro  
int GetPriorityClipboardFormat(
	UINT* paFormatPriorityList,
	int cFormats
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetPriorityClipboardFormat IN user32;
	STRING  @ paFormatPriorityList,;
	INTEGER   cFormats  
```  
***  


## Parameters:
paFormatPriorityList
[in] Pointer to an array of unsigned integers identifying clipboard formats, in priority order.

cFormats
[in] Specifies the number of entries in the paFormatPriorityList array.  
***  


## Return value:
If the function succeeds, the return value is the first clipboard format in the list for which data is available. If the clipboard is empty, the return value is NULL. If the clipboard contains data, but not in any of the specified formats, the return value is �1.  
***  


