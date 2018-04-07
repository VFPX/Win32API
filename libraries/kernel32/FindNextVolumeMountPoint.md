[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindNextVolumeMountPoint
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Continues a volume mount point search started by a call to the FindFirstVolumeMountPoint function. 
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL FindNextVolumeMountPoint(
	HANDLE hFindVolumeMountPoint,
	LPTSTR lpszVolumeMountPoint,
	DWORD cchBufferLength
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextVolumeMountPoint IN kernel32;
	INTEGER hFindVolumeMountPoint,;
	STRING @lpszVolumeMountPoint,;
	LONG cchBufferLength
  
```  
***  


## Parameters:
hFindVolumeMountPoint 
[in] Mount-point search handle returned by a previous call to the FindFirstVolumeMountPoint function. 

lpszVolumeMountPoint 
[out] Pointer to a string that receives the name of the volume mount point found. 

cchBufferLength 
[in] Length of the buffer that receives the names, in TCHARs.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: [FindVolumeMountPointClose](../kernel32/FindVolumeMountPointClose.md).  
  
***  

