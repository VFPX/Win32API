[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : PathBuildRoot
Group: [Shell Lightweight Utility APIs -- Path Functions](../../functions_group.md#Shell_Lightweight_Utility_APIs_--_Path_Functions)  -  Library: [shlwapi](../../Libraries.md#shlwapi)  
***  


#### Creates a root path from a given drive number.
***  


## Code examples:
[Using Path functions from Shell Lightweight Utility APIs (shlapi.dll)](../../samples/sample_178.md)  

## Declaration:
```foxpro  
LPTSTR PathBuildRoot(
    LPTSTR szRoot,
    int iDrive
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER PathBuildRoot IN shlwapi;
	STRING  @ szRoot,;
	INTEGER   iDrive  
```  
***  


## Parameters:
szRoot 
[out] Pointer to a string that receives the constructed root path. This buffer must be at least four characters in size. 

iDrive 
[in] Integer that indicates the desired drive number. It should be between 0 and 25.   
***  


## Return value:
Returns the address of the constructed root path. If the call fails for any reason (for example, an invalid drive number), szRoot is returned unchanged.  
***  

