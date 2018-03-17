<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : RegisterClipboardFormat
Group: Clipboard - Library: user32    
***  


#### The RegisterClipboardFormat function registers a new clipboard format. This format can then be used as a valid clipboard format. 
***  


## Code examples:
[Retrieving names for the registered clipboard formats](../../samples/sample_268.md)  
[Getting a bit more than the _CLIPTEXT offers](../../samples/sample_278.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  

## Declaration:
```foxpro  
UINT RegisterClipboardFormat(
  LPCTSTR lpszFormat   // name of new format
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegisterClipboardFormat IN user32;
	STRING lpszFormat  
```  
***  


## Parameters:
```txt  
lpszFormat
[in] Pointer to a null-terminated string that names the new format.  
```  
***  


## Return value:
If the function succeeds, the return value identifies the registered clipboard format. Otherwise the result is zero.  
***  


## Comments:
Registered clipboard formats are identified by values in the range 0xC000 through 0xFFFF. If a registered format with the specified name already exists, a new format is not registered and the return value identifies the existing format.   
  
***  

