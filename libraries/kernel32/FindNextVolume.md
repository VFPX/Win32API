[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : FindNextVolume
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../../libraries.md#kernel32)  
***  


#### Continues a volume search started by a call to the FindFirstVolume function.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL FindNextVolume(
	HANDLE hFindVolume,
	LPTSTR lpszVolumeName,
	DWORD cchBufferLength
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER FindNextVolume IN kernel32;
	INTEGER hFindVolume,;
	STRING @lpszVolumeName,;
	LONG cchBufferLength  
```  
***  


## Parameters:
hFindVolume 
[in] Volume search handle returned by a previous call to the FindFirstVolume function. 

lpszVolumeName 
[out] Pointer to a string that receives the unique volume name found. 

cchBufferLength 
[in] Length of the buffer that receives the name, in TCHARs.   
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
See also: FindFirstVolume, FindVolumeClose, FindFirstVolumeMountPoint, GetVolumeInformation   
  
***  

