<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetUpdatedClipboardFormats
Group: Clipboard - Library: user32    
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
```txt  
lpuiFormats [out]
Type: PUINT
An array of clipboard formats. Each element of the array is a DWORD.

cFormats [in]
Type: UINT
The number of entries in the array pointed to by lpuiFormats.

pcFormatsOut [out]
Type: PUINT
The actual number of clipboard formats in the array pointed to by lpuiFormats.  
```  
***  


## Return value:
The function returns TRUE if successful; otherwise, FALSE.  
***  


## Comments:
If I am not mistaken, this is clipboard format enumeration performed in a single call, rather than via multiple EnumClipboardFormats calls.  
  
See also: EnumClipboardFormats, CountClipboardFormats, IsClipboardFormatAvailable    
  
***  

