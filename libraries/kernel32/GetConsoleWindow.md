[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetConsoleWindow
Group: [Console](../../functions_group.md#Console)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### The GetConsoleWindow function retrieves the window handle used by the console associated with the calling process.
***  


## Code examples:
[Saying "Hello World!" with VFP and WinAPI](../../samples/sample_119.md)  
[Creating a console window for Visual FoxPro application](../../samples/sample_474.md)  

## Declaration:
```foxpro  
HWND GetConsoleWindow(void);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetConsoleWindow IN kernel32  
```  
***  


## Parameters:
This function has no parameters.   
***  


## Return value:
The return value is a handle to the window used by the console associated with the calling process or NULL if there is no such associated console.  
***  

