[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetParent
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The SetParent function changes the parent window of the specified child window.
***  


## Code examples:
[How to activate Windows Calculator](../../samples/sample_026.md)  
[Confining Windows calculator inside the VFP main window](../../samples/sample_245.md)  
[Running a regular FoxPro form while main VFP window is minimized](../../samples/sample_246.md)  

## Declaration:
```foxpro  
HWND SetParent(
  HWND hWndChild,      // handle to window
  HWND hWndNewParent   // new parent window
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetParent IN user32;
	INTEGER hWndChild,;
	INTEGER hWndNewParent  
```  
***  


## Parameters:
hWndChild 
[in] Handle to the child window. 

hWndNewParent 
[in] Handle to the new parent window.   
***  


## Return value:
If the function succeeds, the return value is a handle to the previous parent window. If the function fails, the return value is NULL.  
***  

