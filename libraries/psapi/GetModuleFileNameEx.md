[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetModuleFileNameEx
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### The GetModuleFileNameEx function retrieves the fully qualified path for the specified module.
***  


## Code examples:
[Enumerating Processes -- WinNT](../../samples/sample_162.md)  

## Declaration:
```foxpro  
DWORD GetModuleFileNameEx(
  HANDLE hProcess,    // handle to process
  HMODULE hModule,    // handle to module
  LPTSTR lpFilename,  // path buffer
  DWORD nSize         // maximum characters to retrieve
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetModuleFileNameEx IN psapi;
	INTEGER hProcess,;
	INTEGER hModule,;
	STRING ModuleName,;
	INTEGER nSize  
```  
***  


## Parameters:
hProcess 
[in] Handle to the process that contains the module. 

hModule 
[in] Handle to the module. 

lpFilename 
[out] Pointer to the buffer that receives the fully qualified path to the module.

nSize 
[in] Specifies the maximum number of characters to copy to the lpFilename buffer.   
***  


## Return value:
If the function succeeds, the return value specifies the length of the string copied to the buffer. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

