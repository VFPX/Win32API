[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : EnumProcesses
Group: [Performance Monitoring](../../functions_group.md#Performance_Monitoring)  -  Library: [psapi](../../Libraries.md#psapi)  
***  


#### The EnumProcesses function retrieves the process identifier for each process object in the system.
***  


## Code examples:
[Enumerating Processes -- WinNT](../../samples/sample_162.md)  

## Declaration:
```foxpro  
BOOL EnumProcesses(
  DWORD *lpidProcess,  // array of process identifiers
  DWORD cb,            // size of array
  DWORD *cbNeeded      // number of bytes returned
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER EnumProcesses IN psapi;
	STRING  @ lpidProcess,;
	INTEGER   cb,;
	INTEGER @ cbNeeded  
```  
***  


## Parameters:
lpidProcess 
[out] Pointer to an array that receives the list of process identifiers. 

cb 
[in] Specifies the size, in bytes, of the lpidProcess array. 

cbNeeded 
[out] Receives the number of bytes returned in the lpidProcess array.   
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

