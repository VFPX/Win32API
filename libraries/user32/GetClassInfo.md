<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClassInfo
Group: Window Class - Library: user32    
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
```txt  
hInstance
[in] Handle to the instance of the application that created the class. To retrieve information about classes defined by the system (such as buttons or list boxes), set this parameter to NULL.

lpClassName
[in] Pointer to a null-terminated string containing the class name.

lpWndClass
[out] Pointer to a WNDCLASS structure that receives the information about the class.  
```  
***  


## Return value:
If the function finds a matching class and successfully copies the data, the return value is nonzero. If the function fails, the return value is zero.   
***  


## Comments:
Check GetClassLong function as an alternative way to retrieve most class window parameters.  
  
***  

