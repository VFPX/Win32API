<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DrawText
Group: Font and Text - Library: user32    
***  


#### The DrawText function draws formatted text in the specified rectangle. It formats the text according to the specified method (expanding tabs, justifying characters, breaking lines, and so forth). 
***  


## Code examples:
[Using the DrawText function](../../samples/sample_303.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  

## Declaration:
```foxpro  
int DrawText(
  HDC hDC,          // handle to DC
  LPCTSTR lpString, // text to draw
  int nCount,       // text length
  LPRECT lpRect,    // formatting dimensions
  UINT uFormat      // text-drawing options
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DrawText IN user32;
	INTEGER   hDC,;
	STRING    lpString,;
	INTEGER   nCount,;
	STRING  @ lpRect,;
	INTEGER   uFormat  
```  
***  


## Parameters:
```txt  
hDC
[in] Handle to the device context.

lpString
[in] Pointer to the string that specifies the text to be drawn.

nCount
[in] Specifies the length of the string.

lpRect
[in/out] Pointer to a RECT structure that contains the rectangle (in logical coordinates) in which the text is to be formatted.

uFormat
[in] Specifies the method of formatting the text.

  
```  
***  


## Return value:
If the function succeeds, the return value is the height of the text in logical units.
If the function fails, the return value is zero.  
***  


## Comments:
See also: TextOut, CreateFont   
  
***  

