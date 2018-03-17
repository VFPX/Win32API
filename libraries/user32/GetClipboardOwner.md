<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClipboardOwner
Group: Clipboard - Library: user32    
***  


#### The GetClipboardOwner function retrieves the window handle of the current owner of the clipboard
***  


## Code examples:
[Who owns the Windows Clipboard](../../samples/sample_029.md)  

## Declaration:
```foxpro  
HWND GetClipboardOwner(VOID)  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClipboardOwner IN user32  
```  
***  


## Parameters:
```txt  
This function has no parameters  
```  
***  


## Return value:
If the function succeeds, the return value is the handle of the window that owns the clipboard  
***  

