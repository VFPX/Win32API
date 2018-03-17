<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : FindVolumeMountPointClose
Group: File System - Library: kernel32    
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
```txt  
hFindVolumeMountPoint
[in] Mount-point search handle to close. This handle must have been previously opened by the FindFirstVolumeMountPoint function.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  

