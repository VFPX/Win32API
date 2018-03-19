
## Function name : IsChild
Group: Window - Library: user32    
***  


#### The IsChild function tests whether a window is a child window or descendant window of a specified parent window
***  


## Code examples:
[Using IsChild() for testing ThisForm.ShowWindow property](../../samples/sample_207.md)  

## Declaration:
```foxpro  
BOOL IsChild(
    HWND  hWndParent,	// handle of parent window
    HWND  hWnd 	// handle of window to test
   );  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER IsChild IN user32;
	INTEGER hWndParent,;
	INTEGER hwnd  
```  
***  


## Parameters:
hWndParent
Identifies the parent window. 

hWnd
Identifies the window to be tested  
***  


## Return value:
If the window is a child or descendant window of the specified parent window, the return value is TRUE  
***  

