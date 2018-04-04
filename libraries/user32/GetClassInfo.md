[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetClassInfo
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### The GetClassInfo function retrieves information about a window class. 
***  


## Code examples:
[Retrieving Window Class information for the VFP window](../../samples/sample_201.md)  
[Drawing cursors for the classes defined by the system (preregistered): BUTTON, EDIT, LISTBOX etc.](../../samples/sample_203.md)  
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
BOOL GetClassInfo(
  HINSTANCE hInstance,    // handle to application instance
  LPCTSTR lpClassName,    // class name
  LPWNDCLASS lpWndClass   // class data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClassInfo IN user32;
	INTEGER  hInstance,;
	STRING   lpClassName,;
	STRING @ lpWndClass  
```  
***  


## Parameters:
hInstance 
[in] Handle to the instance of the application that created the class. To retrieve information about classes defined by the system (such as buttons or list boxes), set this parameter to NULL. 

lpClassName 
[in] Pointer to a null-terminated string containing the class name. 

lpWndClass 
[out] Pointer to a WNDCLASS structure that receives the information about the class.   
***  


## Return value:
If the function finds a matching class and successfully copies the data, the return value is nonzero. If the function fails, the return value is zero.   
***  


## Comments:
Check GetClassLong function as an alternative way to retrieve most class window parameters.  
  
***  

