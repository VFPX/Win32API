<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : DragFinish
Group: Shell Functions - Library: shell32    
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
```txt  
hDrop
Identifier of the structure that describes dropped files. This handle is retrieved from the wParam parameter of the WM_DROPFILES message.  
```  
***  


## Return value:
No return value.  
***  

