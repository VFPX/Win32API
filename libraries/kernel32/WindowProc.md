[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : WindowProc
Group: [Window Procedure](../../functions_group.md#Window_Procedure)  -  Library: [kernel32](../../Libraries.md#kernel32)  
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
hwnd 
[in] Handle to the window. 

uMsg 
[in] Specifies the message. 

wParam 
[in] Specifies additional message information. 

lParam 
[in] Specifies additional message information.  
***  


## Return value:
The return value is the result of the message processing and depends on the message sent.  
***  

