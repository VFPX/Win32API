
## Function name : GetCursorInfo
Group: Cursor - Library: user32    
***  


#### Retrieves information about the global cursor.
***  


## Code examples:
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  

## Declaration:
```foxpro  
BOOL GetCursorInfo(
	PCURSORINFO pci
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetCursorInfo IN user32 STRING @pci  
```  
***  


## Parameters:
pci
[out] Pointer to a CURSORINFO structure that receives the information. Note that you must set CURSORINFO.cbSize to sizeof(CURSORINFO) before calling this function.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The CURSORINFO structure contains global cursor information: cursor state, handle, position.  
  
See also: ShowCursor.  
  
***  

