[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : LoadIcon
Group: [Icon](../../functions_group.md#Icon)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Loads the specified icon resource from the executable (.exe) file associated with an application instance.

***  


## Code examples:
[Drawing standard Windows icons](../../samples/sample_112.md)  
[How to view icons stored in executable files (Icon Viewer)](../../samples/sample_113.md)  

## Declaration:
```foxpro  
HICON LoadIcon(
  HINSTANCE hInstance, // handle to application instance
  LPCTSTR lpIconName   // name string or resource identifier
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER LoadIcon IN user32;
	INTEGER hInstance,;
	INTEGER lpIconName  
```  
***  


## Parameters:
hInstance 
[in] Handle to an instance of the module whose executable file contains the icon to be loaded. This parameter must be NULL when a standard icon is being loaded. 

lpIconName 
[in] Pointer to a null-terminated string that contains the name of the icon resource to be loaded.  
***  


## Return value:
If the function succeeds, the return value is a handle to the newly loaded icon.
If the function fails, the return value is NULL. 
  
***  


## Comments:
This function has been superseded by the LoadImage function.  
  
Do not use DestroyIcon() to release created handle. A shared icon (this is the one) is valid as long as the module from which it was loaded remains in memory. Same for LoadImage and CopyImage.  
  
***  

