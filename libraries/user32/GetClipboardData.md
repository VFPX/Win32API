<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClipboardData
Group: Clipboard - Library: user32    
***  


#### The GetClipboardData function retrieves data from the clipboard in a specified format. The clipboard must have been opened previously.
***  


## Code examples:
[Enumerating data formats currently available on the clipboard](../../samples/sample_032.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Getting a bit more than the _CLIPTEXT offers](../../samples/sample_278.md)  
[Converting Unicode data from the Clipboard to a character string using a given code page](../../samples/sample_316.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[GDI+: Storing content of the Clipboard to a bitmap file](../../samples/sample_475.md)  

## Declaration:
```foxpro  
HANDLE GetClipboardData(
  UINT uFormat   // clipboard format
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClipboardData IN user32;
	INTEGER uFormat  
```  
***  


## Parameters:
```txt  
uFormat
[in] Specifies a clipboard format.  
```  
***  


## Return value:
If the function succeeds, the return value is the handle to a clipboard object in the specified format, otherwise it is NULL.  
***  


## Comments:
An application can enumerate the available formats in advance by using the EnumClipboardFormats function.  
  
***  

