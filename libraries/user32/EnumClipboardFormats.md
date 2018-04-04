[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumClipboardFormats
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
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
format
Specifies a clipboard format that is known to be available  
***  


## Return value:
If the function succeeds, the return value is the clipboard format that follows the specified format  
***  


## Comments:
Except this one, most Enum functions -- like EnumFonts, EnumPrinters etc. -- can not be implemented in VFP. At least I don"t know how to pass a reference to a enumerating procedure  
  
***  

