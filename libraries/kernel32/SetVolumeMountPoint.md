[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : SetVolumeMountPoint
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### Mounts the specified volume at the specified volume mount point.
***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL SetVolumeMountPoint(
	LPCTSTR lpszVolumeMountPoint,
	LPCTSTR lpszVolumeName
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER SetVolumeMountPoint IN kernel32;
	STRING lpszVolumeMountPoint,;
	STRING lpszVolumeName  
```  
***  


## Parameters:
lpszVolumeMountPoint 
[in] Pointer to a string that indicates the volume mount point where the volume is to be mounted.

lpszVolumeName 
[in] Pointer to a string that indicates the volume to be mounted.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Handle this function with care.  
  
This function works similar to the MOUNTVOL.EXE utility -- <Em>creates, deletes, or lists a volume mount point</Em>.   
```dos
MOUNTVOL [drive:]path VolumeName  
MOUNTVOL [drive:]path /D  
MOUNTVOL [drive:]path /L  
MOUNTVOL [drive:]path /P  
MOUNTVOL /R  
MOUNTVOL /N  
MOUNTVOL /E
```

***  

