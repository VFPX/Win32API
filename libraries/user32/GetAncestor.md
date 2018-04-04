[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetAncestor
Group: [Window](../../functions_group.md#Window)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetAncestor function retrieves the handle to the ancestor of the specified window.
***  


## Code examples:
[The window and its ancestors](../../samples/sample_266.md)  

## Declaration:
```foxpro  
HWND GetAncestor(
  HWND hwnd,    // handle to window
  UINT gaFlags  // ancestor
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetAncestor IN user32;
	INTEGER hwnd,;
	INTEGER gaFlags  
```  
***  


## Parameters:
hwnd 
[in] Handle to the window whose ancestor is to be retrieved. If this parameter is the desktop window, the function returns NULL. 

gaFlags 
[in] Specifies the ancestor to be retrieved.   
***  


## Return value:
The return value is the handle to the ancestor window.  
***  

