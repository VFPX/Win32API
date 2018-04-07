[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : ExtractAssociatedIcon
Group: [Icon](../../functions_group.md#Icon)  -  Library: [shell32](../../Libraries.md#shell32)  
***  


#### The ExtractAssociatedIcon function returns a handle to an indexed icon found in a file or an icon found in an associated executable file.
***  


## Code examples:
[Retrieving information about the specified icon](../../samples/sample_206.md)  
[Displaying icons in the system tray (VFP9)](../../samples/sample_235.md)  
[Using FoxTray ActiveX control: System Tray Icon and menu attached to VFP form](../../samples/sample_336.md)  
[GDI+: custom Clock Control](../../samples/sample_597.md)  

## Declaration:
```foxpro  
HICON ExtractAssociatedIcon(
  HINSTANCE hInst,    // application instance handle
  LPTSTR lpIconPath,  // file name
  LPWORD lpiIcon      // icon index
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER ExtractAssociatedIcon IN shell32;
	INTEGER   hInst,;
	STRING    lpIconPath,;
	INTEGER @ lpiIcon  
```  
***  


## Parameters:
hInst 
[in] Specifies the instance of the application calling the function. 

lpIconPath 
[in] Pointer to a string that specifies the full path and file name of the file that contains the icon. 

lpiIcon 
[in] Pointer to a WORD that specifies the index of the icon whose handle is to be obtained.   
***  


## Return value:
If the function succeeds, the return value is an icon handle. If the function fails, the return value is NULL.   
***  


## Comments:
See also: [ExtractIcon](../shell32/ExtractIcon.md).  
  
***  

