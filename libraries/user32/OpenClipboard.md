[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : OpenClipboard
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The OpenClipboard function opens the clipboard for examination and prevents other applications from modifying the clipboard content
***  


## Code examples:
[Testing Clipboard functions: emptying the clipboard](../../samples/sample_028.md)  
[Enumerating data formats currently available on the clipboard](../../samples/sample_032.md)  
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Storing content of the Clipboard to a bitmap file](../../samples/sample_189.md)  
[Getting a bit more than the _CLIPTEXT offers](../../samples/sample_278.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Converting Unicode data from the Clipboard to a character string using a given code page](../../samples/sample_316.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[GDI+: Storing content of the Clipboard to a bitmap file](../../samples/sample_475.md)  
[Monitoring clipboard content changes (VFP9)](../../samples/sample_601.md)  

## Declaration:
```foxpro  
BOOL OpenClipboard(
  HWND hWndNewOwner   // handle to window
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER OpenClipboard IN user32;
	INTEGER hwnd  
```  
***  


## Parameters:
hWndNewOwner 
[in] Handle to the window to be associated with the open clipboard. If this parameter is NULL, the open clipboard is associated with the current task.   
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
An application should call the CloseClipboard function after every successful call to OpenClipboard.   
  
***  

