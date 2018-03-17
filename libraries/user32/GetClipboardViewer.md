<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClipboardViewer
Group: Clipboard - Library: user32    
***  


#### The GetClipboardViewer function retrieves the handle of the first window in the clipboard viewer chain
***  


## Code examples:
[Who is the first in viewing the Clipboard](../../samples/sample_030.md)  

## Declaration:
```foxpro  
HWND GetClipboardViewer(VOID)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClipboardViewer IN user32  
```  
***  


## Parameters:
```txt  
This function has no parameters  
```  
***  


## Return value:
If the function succeeds, the return value is the handle of the first window in the clipboard viewer chain  
***  

