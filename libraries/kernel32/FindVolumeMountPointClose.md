[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindVolumeMountPointClose
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Closes the specified mount-point search handle.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL FindVolumeMountPointClose(
	HANDLE hFindVolumeMountPoint
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindVolumeMountPointClose IN kernel32;
	INTEGER hFindVolumeMountPoint
  
```  
***  


## Parameters:
hFindVolumeMountPoint 
[in] Mount-point search handle to close. This handle must have been previously opened by the FindFirstVolumeMountPoint function.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

