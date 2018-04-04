[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumProcessModules
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### The EnumProcessModules function retrieves a handle for each module in the specified process.
***  


## Code examples:
[Enumerating Processes -- WinNT](../../samples/sample_162.md)  

## Declaration:
```foxpro  
BOOL EnumProcessModules(
  HANDLE hProcess,      // handle to process
  HMODULE *lphModule,   // array of module handles
  DWORD cb,             // size of array
  LPDWORD lpcbNeeded    // number of bytes required
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumProcessModules IN psapi;
	INTEGER   hProcess,;
	STRING  @ lphModule,;
	INTEGER   cb,;
	INTEGER @ cbNeeded  
```  
***  


## Parameters:
hProcess 
[in] Handle to the process. 

lphModule 
[out] Pointer to the array that receives the list of module handles. 

cb 
[in] Specifies the size, in bytes, of the lphModule array. 

lpcbNeeded 
[out] Receives the number of bytes required to store all module handles in the lphModule array.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

