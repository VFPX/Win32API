<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DrawCaption
Group: Painting and Drawing - Library: user32    
***  


#### The DrawCaption function draws a window caption.
***  


## Code examples:
[Drawing a window caption using the DrawCaption routine](../../samples/sample_238.md)  

## Declaration:
```foxpro  
BOOL DrawCaption(
  HWND hwnd,    // handle to window
  HDC hdc,      // handle to device context
  LPCRECT lprc, // rectangle to draw into
  UINT uFlags   // drawing options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawCaption IN user32;
	INTEGER hwnd,;
	INTEGER hdc,;
	STRING  lprc,;
	INTEGER uFlags  
```  
***  


## Parameters:
```txt  
hwnd
[in] Handle to a window that supplies text and an icon for the window caption.

hdc
[in] Handle to a device context. The function draws the window caption into this device context.

lprc
[in] Pointer to a RECT structure that specifies the bounding rectangle for the window caption.

uFlags
[in] Specifies drawing options.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

