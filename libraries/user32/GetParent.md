<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetParent
Group: Window - Library: user32    
***  


#### The GetParent function retrieves a handle to the specified window"s parent or owner. To retrieve a handle to a specified ancestor, use the GetAncestor function.
***  


## Code examples:
[Simple Window Viewer](../../samples/sample_057.md)  
[Terminating all running applications from a VFP program](../../samples/sample_243.md)  
[The window and its ancestors](../../samples/sample_266.md)  

## Declaration:
```foxpro  
HWND GetParent(
  HWND hWnd   // handle to child window
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetParent IN user32;
	INTEGER hwnd  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window whose parent window handle is to be retrieved.  
```  
***  


## Return value:
If the window is a child window, the return value is a handle to the parent window. If the window is a top-level window, the return value is a handle to the owner window. If the window is a top-level unowned window or if the function fails, the return value is NULL.   
***  

