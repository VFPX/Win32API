[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DestroyWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The DestroyWindow function destroys the specified window. The function sends WM_DESTROY and WM_NCDESTROY messages to the window to deactivate it and remove the keyboard focus from it.
***  


## Code examples:
[Placing a button on the VFP form as a new child window](../../samples/sample_274.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[Using Video Capture: displaying on FoxPro form frames and previewing video obtained from a digital camera](../../samples/sample_437.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying hypertext links with the SysLink control (VFP9, Comctl32.dll)](../../samples/sample_559.md)  
[Using Month Calendar Control (VFP9, Comctl32.dll)](../../samples/sample_560.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
BOOL DestroyWindow(
  HWND hWnd   // handle to window to destroy
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER DestroyWindow IN user32;
	INTEGER hWnd  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window to be destroyed.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [EndTask](../user32/EndTask.md), [PostMessage](../user32/PostMessage.md).  
  
***  

