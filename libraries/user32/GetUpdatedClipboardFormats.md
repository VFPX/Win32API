[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetUpdatedClipboardFormats
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the currently supported clipboard formats.
***  


## Declaration:
```foxpro  
BOOL WINAPI GetUpdatedClipboardFormats(
  _Out_  PUINT lpuiFormats,
  _In_   UINT cFormats,
  _Out_  PUINT pcFormatsOut
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetUpdatedClipboardFormats IN user32;
	STRING @lpuiFormats,;
	INTEGER cFormats,;
	INTEGER @pcFormatsOut  
```  
***  


## Parameters:
lpuiFormats [out]
Type: PUINT
An array of clipboard formats. Each element of the array is a DWORD.

cFormats [in]
Type: UINT
The number of entries in the array pointed to by lpuiFormats.

pcFormatsOut [out]
Type: PUINT
The actual number of clipboard formats in the array pointed to by lpuiFormats.  
***  


## Return value:
The function returns TRUE if successful; otherwise, FALSE.  
***  


## Comments:
If I am not mistaken, this is clipboard format enumeration performed in a single call, rather than via multiple EnumClipboardFormats calls.  
  
See also: [EnumClipboardFormats](../user32/EnumClipboardFormats.md), [CountClipboardFormats](../user32/CountClipboardFormats.md), [IsClipboardFormatAvailable](../user32/IsClipboardFormatAvailable.md).  
  
***  

