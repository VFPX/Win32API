[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DragAcceptFiles
Group: [Shell Functions](../../functions_group.md#Shell_Functions)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Registers whether a window accepts dropped files.
***  


## Code examples:
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  

## Declaration:
```foxpro  
VOID DragAcceptFiles(
	HWND hWnd,
	BOOL fAccept
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE DragAcceptFiles IN Shell32;
	INTEGER hWnd,;
	INTEGER fAccept  
```  
***  


## Parameters:
hWnd
Identifier of the window that is registering whether it will accept dropped files. 

fAccept
Value that indicates if the window identified by the hWnd parameter accepts dropped files.  
***  


## Return value:
No return value. 
  
***  


## Comments:
An application that calls DragAcceptFiles with the fAccept parameter set to TRUE has identified itself as able to process the WM_DROPFILES message from File Manager.   
  
***  

