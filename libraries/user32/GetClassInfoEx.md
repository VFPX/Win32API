<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetClassInfoEx
Group: Window Class - Library: user32    
***  


#### The GetClassInfoEx function retrieves information about a window class, including a handle to the small icon associated with the window class.
***  


## Code examples:
[Drawing icons associated with the VFP main window](../../samples/sample_202.md)  

## Declaration:
```foxpro  
BOOL GetClassInfoEx(
  HINSTANCE hinst,    // handle to application instance
  LPCTSTR lpszClass,  // class name
  LPWNDCLASSEX lpwcx  // class data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetClassInfoEx IN user32;
	INTEGER  hinst,;
	STRING   lpszClass,;
	STRING @ lpwcx  
```  
***  


## Parameters:
```txt  
hinst
[in] Handle to the instance of the application that created the class. To retrieve information about classes defined by the system (such as buttons or list boxes), set this parameter to NULL.

lpszClass
[in] Pointer to a null-terminated string containing the class name.

lpwcx
[out] Pointer to a WNDCLASSEX structure that receives the information about the class.  
```  
***  


## Return value:
If the function finds a matching class and successfully copies the data, the return value is nonzero.  
***  


## Comments:
Check GetClassLong function as an alternative way to retrieve most class window parameters.  
  
***  

