<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetWindowInfo
Group: Window - Library: user32    
***  


#### The GetWindowInfo function retrieves information about the specified window.
***  


## Code examples:
[Scanning the hierarchy of child windows down from the main VFP window](../../samples/sample_261.md)  

## Declaration:
```foxpro  
BOOL GetWindowInfo(
  HWND hwnd,       // handle to window
  PWINDOWINFO pwi  // window information
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowInfo IN user32;
	INTEGER   hwnd,;
	STRING  @ pwi  
```  
***  


## Parameters:
```txt  
hwnd
[in] Handle to the window whose information is to be retrieved.

pwi
[out] Pointer to a WINDOWINFO structure to receive the information.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

