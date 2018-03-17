<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : SetVolumeMountPoint
Group: File System - Library: kernel32    
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
```txt  
lpszVolumeMountPoint
[in] Pointer to a string that indicates the volume mount point where the volume is to be mounted.

lpszVolumeName
[in] Pointer to a string that indicates the volume to be mounted.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
Handle this function with care.  
  
This function works similar to the <a href="http://support.microsoft.com/?kbid=205524">MOUNTVOL.EXE</a> utility -- <Em>creates, deletes, or lists a volume mount point</Em>.   
<div class="precode">MOUNTVOL [drive:]path VolumeName  
MOUNTVOL [drive:]path /D  
MOUNTVOL [drive:]path /L  
MOUNTVOL [drive:]path /P  
MOUNTVOL /R  
MOUNTVOL /N  
MOUNTVOL /E  
</div>  
  
***  

