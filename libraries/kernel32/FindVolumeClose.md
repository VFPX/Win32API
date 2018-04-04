[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindVolumeClose
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Closes the specified volume search handle created with the FindFirstVolume and FindNextVolume call.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL FindVolumeClose(
	HANDLE hFindVolume
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindVolumeClose IN kernel32;
	INTEGER hFindVolume
  
```  
***  


## Parameters:
hFindVolume 
[in] Volume search handle to close. This handle must have been previously opened by the FindFirstVolume function.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

