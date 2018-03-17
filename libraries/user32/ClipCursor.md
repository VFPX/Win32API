<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : ClipCursor
Group: Cursor - Library: user32    
***  


#### Confines the cursor to a rectangular area on the screen.
***  


## Code examples:
[Clipping mouse cursor area](../../samples/sample_080.md)  

## Declaration:
```foxpro  
BOOL ClipCursor(
  CONST RECT *lpRect  // screen coordinates
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT ClipCursor IN user32 STRING lpRect  
```  
***  


## Parameters:
```txt  
lpRect
[in] Pointer to the RECT structure that contains the screen coordinates of the upper-left and lower-right corners of the confining rectangle.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

