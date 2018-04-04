[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : UnregisterClass
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Unregisters a window class, freeing the memory required for the class.
***  


## Code examples:
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
BOOL WINAPI UnregisterClass(
  __in      LPCTSTR lpClassName,
  __in_opt  HINSTANCE hInstance
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER UnregisterClass IN user32;
	STRING lpClassName,;
	INTEGER hInstance
  
```  
***  


## Parameters:
lpClassName [in]
Type: LPCTSTR

A null-terminated string or a class atom.

hInstance [in, optional]
Type: HINSTANCE

A handle to the instance of the module that created the class.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The class name must have been registered by a previous call to the RegisterClass or RegisterClassEx function.  
  
Before calling this function, an application must destroy all windows created with the specified class.  
  
All window classes that an application registers are unregistered when it terminates.  
  
***  

