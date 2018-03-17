<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : EnumClipboardFormats
Group: Clipboard - Library: user32    
***  


#### The EnumClipboardFormats function lets you enumerate the data formats that are currently available on the clipboard
***  


## Code examples:
[Enumerating data formats currently available on the clipboard](../../samples/sample_032.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[Monitoring clipboard content changes (VFP9)](../../samples/sample_601.md)  

## Declaration:
```foxpro  
UINT EnumClipboardFormats(
  UINT format   // available clipboard format
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumClipboardFormats IN user32;
	INTEGER wFormat  
```  
***  


## Parameters:
```txt  
format
Specifies a clipboard format that is known to be available  
```  
***  


## Return value:
If the function succeeds, the return value is the clipboard format that follows the specified format  
***  


## Comments:
Except this one, most Enum functions -- like EnumFonts, EnumPrinters etc. -- can not be implemented in VFP. At least I don"t know how to pass a reference to a enumerating procedure  
  
***  

