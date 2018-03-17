<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : OpenVirtualDisk
Group: Virtual Hard Disk (Win7) - Library: virtdisk    
***  


#### Opens a virtual hard disk (VHD) for use.
***  


## Declaration:
```foxpro  
DWORD OpenVirtualDisk(
	__in   PVIRTUAL_STORAGE_TYPE VirtualStorageType,
	__in   PCWSTR Path,
	__in   VIRTUAL_DISK_ACCESS_MASK VirtualDiskAccessMask,
	__in   OPEN_VIRTUAL_DISK_FLAG Flags,
	__in   POPEN_VIRTUAL_DISK_PARAMETERS Parameters,
	__out  PHANDLE Handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG OpenVirtualDisk IN virtdisk;
	STRING @VirtualStorageType,;
	STRING ImageFilePath,;
	INTEGER VirtualDiskAccessMask,;
	INTEGER VirtualDiskFlags,;
	STRING @VirtualDiskParameters,;
	INTEGER @Handle  
```  
***  


## Parameters:
```txt  
VirtualStorageType [in]
A pointer to a valid VIRTUAL_STORAGE_TYPE structure.

Path [in]
A pointer to a valid path to the virtual disk image to open.

VirtualDiskAccessMask [in]
A valid value of the VIRTUAL_DISK_ACCESS_MASK enumeration.

Flags [in]
A valid combination of values of the OPEN_VIRTUAL_DISK_FLAG enumeration.

Parameters [in]
An optional pointer to a valid OPEN_VIRTUAL_DISK_PARAMETERS structure. Can be NULL.

Handle [out]
A pointer to the handle object that represents the open virtual disk.  
```  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0) and the Handle parameter contains a valid pointer to the new virtual disk object.  
***  


## Comments:
Minimum supported client: Windows 7  
  
When an application is finished using the object handle returned in the Handle parameter, use the CloseHandle function to close the handle.  
  
See also: CreateVirtualDisk, AttachVirtualDisk   
  
***  

