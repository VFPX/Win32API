[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetClipCursor
Group: [Cursor](../../functions_group.md#Cursor)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the screen coordinates of the rectangular area to which the cursor is confined.
***  


## Code examples:
[Retrieving the rectangle area where the mouse cursor is confined](../../samples/sample_074.md)  
[Clipping mouse cursor area](../../samples/sample_080.md)  

## Declaration:
```foxpro  
BOOL GetClipCursor(
	LPRECT  lpRect 	// address of structure for rectangle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetClipCursor IN user32 STRING @ lpRect  
```  
***  


## Parameters:
lpRect
Points to a RECT structure that receives the screen coordinates of the confining rectangle.  
***  


## Return value:
If the function succeeds, the return value is TRUE.
  
***  

