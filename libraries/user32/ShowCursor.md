[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ShowCursor
Group: [Cursor](../../functions_group.md#Cursor)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The ShowCursor function displays or hides the cursor.
***  


## Code examples:
[Hiding mouse cursor](../../samples/sample_139.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  

## Declaration:
```foxpro  
int ShowCursor(
  BOOL bShow   // cursor visibility
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ShowCursor IN user32 INTEGER bShow  
```  
***  


## Parameters:
bShow 
[in] Specifies whether the internal display counter is to be incremented or decremented. If bShow is TRUE, the display count is incremented by one. If bShow is FALSE, the display count is decremented by one.  
***  


## Return value:
The return value specifies the new display counter.  
***  

