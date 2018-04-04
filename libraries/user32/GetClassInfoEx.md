[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetClassInfoEx
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
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
hinst 
[in] Handle to the instance of the application that created the class. To retrieve information about classes defined by the system (such as buttons or list boxes), set this parameter to NULL. 

lpszClass 
[in] Pointer to a null-terminated string containing the class name. 

lpwcx 
[out] Pointer to a WNDCLASSEX structure that receives the information about the class.   
***  


## Return value:
If the function finds a matching class and successfully copies the data, the return value is nonzero.  
***  


## Comments:
Check GetClassLong function as an alternative way to retrieve most class window parameters.  
  
***  

