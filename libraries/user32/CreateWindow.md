[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateWindow
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The CreateWindow function creates an overlapped, pop-up, or child window.

To use extended window styles in addition to the styles supported by CreateWindow, use the CreateWindowEx function.
***  


## Code examples:
[Placing a button on the VFP form as a new child window](../../samples/sample_274.md)  

## Declaration:
```foxpro  
HWND CreateWindow(
  LPCTSTR lpClassName,  // registered class name
  LPCTSTR lpWindowName, // window name
  DWORD dwStyle,        // window style
  int x,                // horizontal position of window
  int y,                // vertical position of window
  int nWidth,           // window width
  int nHeight,          // window height
  HWND hWndParent,      // handle to parent or owner window
  HMENU hMenu,          // menu handle or child identifier
  HINSTANCE hInstance,  // handle to application instance
  LPVOID lpParam        // window-creation data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateWindow IN user32;
	STRING  lpClassName,;
	STRING  lpWindowName,;
	INTEGER dwStyle,;
	INTEGER x,;
	INTEGER y,;
	INTEGER nWidth,;
	INTEGER nHeight,;
	INTEGER hWndParent,;
	INTEGER hMenu,;
	INTEGER hInstance,;
	INTEGER lpParam
  
```  
***  


## Parameters:
lpClassName 
[in] Pointer to a null-terminated string or a class atom.

lpWindowName 
[in] Pointer to a null-terminated string that specifies the window name. 

dwStyle 
[in] Specifies the style of the window being created. 

x 
[in] Specifies the initial horizontal position of the window. 

y 
[in] Specifies the initial vertical position of the window. 

nWidth 
[in] Specifies the width, in device units, of the window. 

nHeight 
[in] Specifies the height, in device units, of the window. 

hWndParent 
[in] Handle to the parent or owner window of the window being created. 

hMenu 
[in] Handle to a menu, or specifies a child-window identifier depending on the window style. 

hInstance 
Handle to the instance of the module to be associated with the window. 

lpParam 
[in] Pointer to a value to be passed to the window through the CREATESTRUCT structure passed in the lParam parameter the WM_CREATE message.   
***  


## Return value:
If the function succeeds, the return value is a handle to the new window.  
***  


## Comments:
<b>WinMe</b>: there is no entry point for this function in the User32 module.  
  
***  

