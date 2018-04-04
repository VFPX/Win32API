[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateDC
Group: [Device Context](../../functions_group.md#Device_Context)  -  Library: [gdi32](../../Libraries.md#gdi32)  
***  


#### The CreateDC function creates a device context (DC) for a device using the specified name.
***  


## Code examples:
[Creating a device context for the specified printer](../../samples/sample_145.md)  
[Printing text with the Escape function](../../samples/sample_357.md)  
[Printing Image File, programmatically set print page orientation to landscape](../../samples/sample_555.md)  

## Declaration:
```foxpro  
HDC CreateDC(
  LPCTSTR lpszDriver,        // driver name
  LPCTSTR lpszDevice,        // device name
  LPCTSTR lpszOutput,        // not used; should be NULL
  CONST DEVMODE* lpInitData  // optional printer data
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER CreateDC IN gdi32;
	STRING lpszDriver,;
	STRING lpszDevice,;
	INTEGER lpszOutput,;
	INTEGER lpInitData  
```  
***  


## Parameters:
lpszDriver
For various Windows this parameter can be NULL, or can contain a null-terminated string.

lpszDevice 
[in] Pointer to a null-terminated character string that specifies the name of the specific output device being used.

lpszOutput 
This parameter is ignored for Win32-based applications, and should be set to NULL. 

lpInitData 
[in] Pointer to a DEVMODE structure containing device-specific initialization data for the device driver.  
***  


## Return value:
If the function succeeds, the return value is the handle to a DC for the specified device. If the function fails, the return value is NULL. 
  
***  


## Comments:
The W2K Programming: the first way to obtain a printer device context is to use CreateDC function. The second way is to call PrintDlgEx function, which displays the Print common dialog box that allows the user to set various printing options.  
  
***  

