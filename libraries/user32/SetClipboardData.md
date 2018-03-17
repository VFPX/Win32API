<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetClipboardData
Group: Clipboard - Library: user32    
***  


#### The SetClipboardData function places data on the clipboard in a specified clipboard format
***  


## Code examples:
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  

## Declaration:
```foxpro  
HANDLE SetClipboardData(
    UINT  uFormat,	// clipboard format
    HANDLE  hData 	// data handle
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetClipboardData IN user32;
	INTEGER wFormat,;
	INTEGER hMem
  
```  
***  


## Parameters:
```txt  
uFormat
Specifies a clipboard format

hData
Identifies the data in the specified format  
```  
***  


## Return value:
If the function succeeds, the return value is the handle of the data  
***  

