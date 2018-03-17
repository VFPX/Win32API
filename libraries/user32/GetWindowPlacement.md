<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetWindowPlacement
Group: Window - Library: user32    
***  


#### The GetWindowPlacement function retrieves the show state and the restored, minimized, and maximized positions of the specified window. 
***  


## Code examples:
[Obtaining some properties for the Windows desktop using the GetWindowPlacement function](../../samples/sample_263.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
BOOL GetWindowPlacement(
  HWND hWnd,                // handle to window
  WINDOWPLACEMENT *lpwndpl  // position data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetWindowPlacement IN user32;
	INTEGER   hWnd,;
	STRING  @ lpwndpl  
```  
***  


## Parameters:
```txt  
hWnd
[in] Handle to the window.

lpwndpl
[out] Pointer to the WINDOWPLACEMENT structure that receives the show state and position information.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Before calling this function set the length member of WINDOWPLACEMENT to sizeof(WINDOWPLACEMENT).   
  
***  

