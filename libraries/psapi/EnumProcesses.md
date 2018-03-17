<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : EnumProcesses
Group: Performance Monitoring - Library: psapi    
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
```txt  
lpidProcess
[out] Pointer to an array that receives the list of process identifiers.

cb
[in] Specifies the size, in bytes, of the lpidProcess array.

cbNeeded
[out] Receives the number of bytes returned in the lpidProcess array.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero. If the function fails, the return value is zero.  
***  


## Comments:
Windows NT/2000/XP: Included in Windows NT 4.0 and later.  
Windows 95/98/Me: Unsupported.  
  
***  

