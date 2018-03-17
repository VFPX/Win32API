<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClientRect
Group: Window - Library: user32    
***  


#### Retrieves the coordinates of a window"s client area.
***  


## Code examples:
[Comparing dimensions of the VFP main window with _SCREEN properties](../../samples/sample_078.md)  
[Retrieving geometrical parameters of the system desktop window](../../samples/sample_092.md)  

## Declaration:
```foxpro  
BOOL GetClientRect(
  HWND hWnd,      // handle to window
  LPRECT lpRect   // client coordinates
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetClientRect IN user32;
	INTEGER  hwnd,;
	STRING @ lpRect  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window whose client coordinates are to be retrieved.

lpRect
[out] Pointer to a RECT structure that receives the client coordinates. The left and top members are zero. The right and bottom members contain the width and height of the window.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

