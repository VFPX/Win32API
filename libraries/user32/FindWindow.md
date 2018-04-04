[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Retrieves a handle to the top-level window whose class name and window name match the specified strings.
***  


## Code examples:
[How to activate Windows Calculator](../../samples/sample_026.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Setting properties of the window: caption and user-defined value](../../samples/sample_182.md)  
[How to start the screen saver and how to find whether the screen saver is active](../../samples/sample_196.md)  
[Confining Windows calculator inside the VFP main window](../../samples/sample_245.md)  
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  
[How to block the ALT+TAB shortcut (WinXP)](../../samples/sample_432.md)  
[Accessing Adobe Reader 7.0 main menu from VFP application](../../samples/sample_495.md)  
[Obtaining names and positions for shortcuts located on the Windows Desktop](../../samples/sample_579.md)  
[Moving shortcut to a specified position on the Windows Desktop](../../samples/sample_581.md)  

## Declaration:
```foxpro  
HWND FindWindow(
  LPCTSTR lpClassName,  // class name
  LPCTSTR lpWindowName  // window name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindWindow IN user32;
	STRING lpClassName,;
	STRING lpWindowName  
```  
***  


## Parameters:
lpClassName 
[in] Pointer to a null-terminated string that specifies the class name.

lpWindowName 
[in] Pointer to a null-terminated string that specifies the window name (the window"s title).   
***  


## Return value:
If the function succeeds, the return value is a handle to the window that has the specified class name and window name. If the function fails, the return value is NULL.  
***  

