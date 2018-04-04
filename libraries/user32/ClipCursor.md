[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ClipCursor
Group: [Cursor](../../functions_group.md#Cursor)  -  Library: [user32](../../Libraries.md#user32)  
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
lpRect 
[in] Pointer to the RECT structure that contains the screen coordinates of the upper-left and lower-right corners of the confining rectangle.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

