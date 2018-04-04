[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DrawIcon
Group: [Icon](../../functions_group.md#Icon)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Draws an icon or cursor into the specified device context.
***  


## Code examples:
[Drawing standard Windows icons](../../samples/sample_112.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Drawing icons associated with the VFP main window](../../samples/sample_202.md)  
[Drawing cursors for the classes defined by the system (preregistered): BUTTON, EDIT, LISTBOX etc.](../../samples/sample_203.md)  

## Declaration:
```foxpro  
BOOL DrawIcon(
  HDC hDC,      // handle to DC
  int X,        // x-coordinate of upper-left corner
  int Y,        // y-coordinate of upper-left corner
  HICON hIcon   // handle to icon
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT DrawIcon IN user32;
	INTEGER hDC,;
	INTEGER X,;
	INTEGER Y,;
	INTEGER hIcon  
```  
***  


## Parameters:
hDC 
[in] Handle to the device context into which the icon or cursor will be drawn. 

X 
[in] Specifies the logical x-coordinate of the upper-left corner of the icon. 

Y 
[in] Specifies the logical y-coordinate of the upper-left corner of the icon. 

hIcon 
[in] Handle to the icon to be drawn.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

