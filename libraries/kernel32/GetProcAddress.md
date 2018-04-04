[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetProcAddress
Group: [Dynamic-Link Library](../../functions_group.md#Dynamic-Link_Library)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Retrieves the address of an exported function or variable from the specified dynamic-link library (DLL).

***  


## Code examples:
[Retrieving a handle to DLL and address of an exported function in it](../../samples/sample_085.md)  

## Declaration:
```foxpro  
FARPROC GetProcAddress(
  HMODULE hModule,    // handle to DLL module
  LPCSTR lpProcName   // function name
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetProcAddress IN kernel32;
	INTEGER hModule,;
	STRING lpProcName  
```  
***  


## Parameters:
hModule 
[in] Handle to the DLL module that contains the function or variable.

lpProcName 
[in] Pointer to a null-terminated string containing the function or variable name, or the function"s ordinal value. If this parameter is an ordinal value, it must be in the low-order word; the high-order word must be zero.  
***  


## Return value:
If the function succeeds, the return value is the address of the exported function or variable.  
***  

