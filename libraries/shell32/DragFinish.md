[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DragFinish
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### Releases memory that the system allocated for use in transferring file names to the application.
***  


## Code examples:
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  

## Declaration:
```foxpro  
VOID DragFinish(
	HDROP hDrop
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE DragFinish IN shell32;
	INTEGER hDrop  
```  
***  


## Parameters:
hDrop
Identifier of the structure that describes dropped files. This handle is retrieved from the wParam parameter of the WM_DROPFILES message.   
***  


## Return value:
No return value.  
***  

