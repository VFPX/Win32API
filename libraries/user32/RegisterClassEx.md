[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : RegisterClassEx
Group: [Window Class](../../functions_group.md#Window_Class)  -  Library: [user32](../../Libraries.md#user32)  
***  


#### Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
***  


## Code examples:
[Displaying dimmed window behind VFP top-level form](../../samples/sample_578.md)  

## Declaration:
```foxpro  
ATOM WINAPI RegisterClassEx(
  __in  const WNDCLASSEX *lpwcx
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER RegisterClassEx IN user32;
	INTEGER lpwcx  
```  
***  


## Parameters:
lpwcx [in]
Type: const WNDCLASSEX*

A pointer to a WNDCLASSEX structure. You must fill the structure with the appropriate class attributes before passing it to the function.  
***  


## Return value:
If the function succeeds, the return value is a class atom that uniquely identifies the class being registered. If the function fails, the return value is zero.  
***  


## Comments:
See also: [UnregisterClass](../user32/UnregisterClass.md), [GlobalGetAtomName](../kernel32/GlobalGetAtomName.md).  
  
***  

