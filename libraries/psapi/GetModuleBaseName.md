[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetModuleBaseName
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### The GetModuleBaseName function retrieves the base name of the specified module.
***  


## Code examples:
[Enumerating Processes -- WinNT](../../samples/sample_162.md)  

## Declaration:
```foxpro  
DWORD GetModuleBaseName(
  HANDLE hProcess,    // handle to process
  HMODULE hModule,    // handle to module
  LPTSTR lpBaseName,  // base name buffer
  DWORD nSize         // maximum characters to retrieve
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetModuleBaseName IN psapi;
	INTEGER  hProcess,;
	INTEGER  hModule,;
	STRING @ lpBaseName,;
	INTEGER  nSize  
```  
***  


## Parameters:
hProcess 
[in] Handle to the process that contains the module. 

hModule 
[in] Handle to the module. 

lpBaseName 
[out] Pointer to the buffer that receives the base name of the module. 

nSize 
[in] Specifies the maximum number of characters to copy to the lpBaseName buffer.   
***  


## Return value:
If the function succeeds, the return value specifies the length of the string copied to the buffer. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

