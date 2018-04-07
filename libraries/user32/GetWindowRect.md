[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetWindowRect
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves the dimensions of the bounding rectangle of the specified window.

***  


## Code examples:
[Listing child windows for the Windows desktop](../../samples/sample_027.md)  
[Scanning a hierarchy of child windows down from the Windows Desktop](../../samples/sample_045.md)  
[Comparing dimensions of the VFP main window with _SCREEN properties](../../samples/sample_078.md)  
[GetFocus returns a HWND value](../../samples/sample_090.md)  
[How to copy the image of a form to the Clipboard using Bitmap API functions](../../samples/sample_091.md)  
[Retrieving geometrical parameters of the system desktop window](../../samples/sample_092.md)  
[How to create transparent areas inside a form -- punching holes in the form](../../samples/sample_126.md)  
[An alternative way of setting Form.Closable to False](../../samples/sample_127.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  
[Retrieving top-child window for the VFP form](../../samples/sample_209.md)  
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[GDI+: saving image of FoxPro form to graphics file (BMP, GIF, JPG, PNG, TIF)](../../samples/sample_454.md)  
[GDI+: sending image of FoxPro form to printer](../../samples/sample_455.md)  
[GDI+: copying to the Clipboard (a) image of active FoxPro window/form, (b) image file](../../samples/sample_457.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  

## Declaration:
```foxpro  
BOOL GetWindowRect(
	HWND hWnd,      // handle to window
	LPRECT lpRect   // window coordinates
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowRect IN user32;
	INTEGER hWindow,;
	STRING @lpRect  
```  
***  


## Parameters:
hWnd 
[in] Handle to the window. 

lpRect 
[out] Pointer to a RECT structure that receives the screen coordinates of the upper-left and lower-right corners of the window. 
  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [GetClientRect](../user32/GetClientRect.md), [ScreenToClient](../user32/ScreenToClient.md), [SetWindowPos](../user32/SetWindowPos.md).  
  
***  

