<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetConsoleWindow
Group: Console - Library: kernel32    
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
```txt  
This function has no parameters.   
```  
***  


## Return value:
The return value is a handle to the window used by the console associated with the calling process or NULL if there is no such associated console.  
***  

