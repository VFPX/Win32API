[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DragQueryPoint
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Retrieves the position of the mouse pointer at the time a file was dropped during a drag-and-drop operation.
***  


## Code examples:
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  

## Declaration:
```foxpro  
BOOL DragQueryPoint(
	HDROP hDrop,
	LPPOINT lppt
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DragQueryPoint IN shell32;
	INTEGER  hDrop,;
	STRING @ lppt
  
```  
***  


## Parameters:
hDrop
Identifier of the structure that describes the dropped file. 

lppt
Address of a POINT structure that the function fills with the coordinates of the mouse pointer at the time the file was dropped.   
***  


## Return value:
Returns nonzero if the drop occurred in the client area of the window, or zero if the drop did not occur in the client area of the window.   
***  


## Comments:
The window for which coordinates are returned is the window that received the WM_DROPFILES message.   
  
See also: [DragAcceptFiles](../user32/DragAcceptFiles.md), [DragQueryFile](../shell32/DragQueryFile.md).  
  
***  

