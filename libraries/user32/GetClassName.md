<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClassName
Group: Window Class - Library: user32    
***  


#### The GetClassName function retrieves the name of the class to which the specified window belongs.
***  


## Code examples:
[Listing child windows for the Windows desktop](../../samples/sample_027.md)  
[Simple Window Viewer](../../samples/sample_057.md)  
[Retrieving information about the main VFP window](../../samples/sample_111.md)  
[Retrieving Window Class information for the VFP window](../../samples/sample_201.md)  
[Drawing icons associated with the VFP main window](../../samples/sample_202.md)  

## Declaration:
```foxpro  
int GetClassName(
  HWND hWnd,           // handle to window
  LPTSTR lpClassName,  // class name
  int nMaxCount        // size of class name buffer
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClassName IN user32;
	INTEGER   hWnd,;
	STRING  @ lpClassName,;
	INTEGER   nMaxCount  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window and, indirectly, the class to which the window belongs.

lpClassName
[out] Pointer to the buffer that is to receive the class name string.

nMaxCount
[in] Specifies the length, in TCHARs, of the buffer pointed to by the lpClassName parameter.  
```  
***  


## Return value:
If the function succeeds, the return value is the number of TCHARs copied to the specified buffer. If the function fails, the return value is zero.  
***  

