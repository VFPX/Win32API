<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : UnregisterClass
Group: Window Class - Library: user32    
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
```txt  
lpClassName [in]
Type: LPCTSTR

A null-terminated string or a class atom.

hInstance [in, optional]
Type: HINSTANCE

A handle to the instance of the module that created the class.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The class name must have been registered by a previous call to the RegisterClass or RegisterClassEx function.  
  
Before calling this function, an application must destroy all windows created with the specified class.  
  
All window classes that an application registers are unregistered when it terminates.  
  
***  

