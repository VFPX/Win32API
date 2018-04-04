[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateWindowEx
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the CreateWindow function
***  


## Code examples:
[Creating a window using CreateWindowEx function](../../samples/sample_050.md)  
[Placing a button on the VFP form as a new child window](../../samples/sample_274.md)  
[Splash Screen for the VFP application](../../samples/sample_294.md)  
[Using Common Controls: the Header Control](../../samples/sample_298.md)  
[Placing On-screen Alert on top of all windows](../../samples/sample_504.md)  
[How to make a VFP form fading out when released (GDI+ version)](../../samples/sample_527.md)  
[How to make a VFP form fading out when released (GDI version)](../../samples/sample_528.md)  
[Displaying hypertext links with the SysLink control (VFP9, Comctl32.dll)](../../samples/sample_559.md)  
[Using Month Calendar Control (VFP9, Comctl32.dll)](../../samples/sample_560.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
HWND CreateWindowEx(
  DWORD dwExStyle,      // extended window style
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
DECLARE INTEGER CreateWindowEx IN user32;
	INTEGER dwExStyle,;
	STRING lpClassName,;
	STRING lpWindowName,;
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
dwExStyle 
[in] Specifies the extended window style of the window being created

lpClassName 
[in] Pointer to a null-terminated string or a class atom created by a previous call to the RegisterClass or RegisterClassEx function

lpWindowName 
[in] Pointer to a null-terminated string that specifies the window name

dwStyle 
[in] Specifies the style of the window being created

x, y
[in] Specifies the initial position of the window

nWidth, nHeight
[in] Specifies the width and the height, in device units, of the window

hWndParent 
[in] Handle to the parent or owner window of the window being created

hMenu 
[in] Handle to a menu, or specifies a child-window identifier, depending on the window style

hInstance 
[in] Handle to the instance of the module to be associated with the window

lpParam 
[in] Pointer to a value to be passed to the window  
***  


## Return value:
If the function succeeds, the return value is a handle to the new window  
***  


## Comments:
Through this function you can get a valid HWND and HDC (device context) values, which give you a great control over the created window. Comparing to this the windows, which you can create using the native DEFINE WINDOW, are "windowless"  
  
***  

