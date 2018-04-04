[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EmptyClipboard
Group: [Clipboard](../../functions_group.md#Clipboard)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The EmptyClipboard function empties the clipboard and frees handles to data in the clipboard
***  


## Code examples:
[Testing Clipboard functions: emptying the clipboard](../../samples/sample_028.md)  
[Placing an arbitrary rectangular area of main VFP window on the Clipboard](../../samples/sample_081.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Bitmap Class for Visual FoxPro application](../../samples/sample_295.md)  
[Passing data records between VFP applications via the Clipboard](../../samples/sample_346.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  

## Declaration:
```foxpro  
BOOL EmptyClipboard(VOID)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EmptyClipboard  IN user32  
```  
***  


## Parameters:
This function has no parameters  
***  


## Return value:
If the function succeeds, the return value is TRUE  
***  


## Comments:
Before calling EmptyClipboard, an application must open the clipboard by using the OpenClipboard function  
  
***  

