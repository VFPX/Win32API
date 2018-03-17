<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : CopyIcon
Group: Icon - Library: user32    
***  


#### Copies the specified icon from another module to the current module.
***  


## Code examples:
[Storing screen shot of a form to bitmap file](../../samples/sample_187.md)  

## Declaration:
```foxpro  
HICON CopyIcon(
	HICON hIcon
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CopyIcon IN user32 INTEGER hIcon  
```  
***  


## Parameters:
```txt  
hIcon
[in] Handle to the icon to be copied.  
```  
***  


## Return value:
If the function succeeds, the return value is a handle to the duplicate icon.  
***  


## Comments:
The CopyIcon function enables an application or dynamic-link library (DLL) to get its own handle to an icon owned by another module. If the other module is freed, the application icon will still be able to use the icon.   
  
Before closing, an application must call the DestroyIcon function to free any system resources associated with the icon.  
  
See also: LoadIcon, DrawIcon.  
  
***  

