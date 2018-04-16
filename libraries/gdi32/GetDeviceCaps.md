[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDeviceCaps
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The GetDeviceCaps function retrieves device-specific information for the specified device.
***  


## Code examples:
[How to view icons stored in executable files (Icon Viewer) - II](../../samples/sample_019.md)  
[Retrieving graphic capabilities of default printer](../../samples/sample_155.md)  
[How to print FoxPro form](../../samples/sample_158.md)  
[Converting twips to pixels and vice versa](../../samples/sample_161.md)  
[Retrieving graphic capabilities of your display](../../samples/sample_188.md)  
[How to print a bitmap file](../../samples/sample_211.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Subclassing CommandButton control to create BackColor property](../../samples/sample_392.md)  
[Vertical Label control](../../samples/sample_398.md)  
[Storing screen shot of a form to enhanced metafile (*.emf)](../../samples/sample_402.md)  
[Copying picture of the active form to the Clipboard using Enhanced Metafile API functions](../../samples/sample_404.md)  
[How to print picture stored in enhanced-format metafile (*.emf)](../../samples/sample_405.md)  
[How to print FoxPro form -- II](../../samples/sample_406.md)  
[Displaying the associated icons and descriptions for files and folders](../../samples/sample_530.md)  
[How to find which fonts Windows uses for drawing captions, menus and message boxes](../../samples/sample_556.md)  

## Declaration:
```foxpro  
int GetDeviceCaps(
  HDC hdc,     // handle to DC
  int nIndex   // index of capability
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetDeviceCaps IN gdi32;
	INTEGER hdc,;
	INTEGER nIndex  
```  
***  


## Parameters:
hdc 
[in] Handle to the DC. 

nIndex 
[in] Specifies the item to return. This parameter can be one of the predefined values (see examples).  
***  


## Return value:
The return value specifies the value of the desired item.  
***  


## Comments:
See also: [SYSMETRIC()](http://msdn.microsoft.com/en-us/library/39ddf2h2(VS.80).aspx)  

***  

