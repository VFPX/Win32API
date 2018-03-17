<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : WindowProc
Group: Window Procedure - Library: kernel32    
***  


#### The WindowProc function is an application-defined function that processes messages sent to a window. The WNDPROC type defines a pointer to this callback function. WindowProc is a placeholder for the application-defined function name.
***  


## Code examples:
[Dragging files from Explorer window and dropping them on FoxPro control (requires VFP9)](../../samples/sample_323.md)  
[How to block the PrintScreen key](../../samples/sample_489.md)  
[Adding user-defined items to the Control Menu of VFP form (requires VFP9)](../../samples/sample_512.md)  

## Declaration:
```foxpro  
LRESULT CALLBACK WindowProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);  
```  
***  


## FoxPro declaration:
```foxpro  
No VFP declaration available  
```  
***  


## Parameters:
```txt  
hwnd
[in] Handle to the window.

uMsg
[in] Specifies the message.

wParam
[in] Specifies additional message information.

lParam
[in] Specifies additional message information.  
```  
***  


## Return value:
The return value is the result of the message processing and depends on the message sent.  
***  

