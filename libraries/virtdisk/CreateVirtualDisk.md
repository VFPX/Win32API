[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : CreateVirtualDisk
Group: [Virtual Hard Disk (Win7)](../../functions_group.md#Virtual_Hard_Disk_(Win7))  -  Library: [virtdisk](../../Libraries.md#virtdisk)  
***  


#### Creates a virtual hard disk (VHD) image file, either using default parameters or using an existing virtual disk or physical disk.
***  


## Declaration:
```foxpro  
DWORD CreateVirtualDisk(
	__in   PVIRTUAL_STORAGE_TYPE VirtualStorageType,
	__in   PCWSTR Path,
	__in   VIRTUAL_DISK_ACCESS_MASK VirtualDiskAccessMask,
	__in   PSECURITY_DESCRIPTOR SecurityDescriptor,
	__in   CREATE_VIRTUAL_DISK_FLAG Flags,
	__in   ULONG ProviderSpecificFlags,
	__in   PCREATE_VIRTUAL_DISK_PARAMETERS Parameters,
	__in   LPOVERLAPPED Overlapped,
	__out  PHANDLE Handle
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG CreateVirtualDisk IN virtdisk;
	STRING @VirtualStorageType,;
	STRING ImageFilePath,;
	INTEGER VirtualDiskAccessMask,;
	INTEGER SecurityDescriptor,;
	INTEGER VirtualDiskFlags,;
	LONG ProviderSpecificFlags,;
	STRING @VirtualDiskParameters,;
	INTEGER Overlapped,;
	INTEGER @Handle  
```  
***  


## Parameters:
VirtualStorageType [in]
A pointer to a VIRTUAL_STORAGE_TYPE structure that contains the desired disk type and vendor information.

Path [in]
A pointer to a valid string that represents the path to the new virtual disk image file.

VirtualDiskAccessMask [in]
The VIRTUAL_DISK_ACCESS_MASK value to use when opening the newly created virtual disk file.

SecurityDescriptor [in]
An optional pointer to a SECURITY_DESCRIPTOR to apply to the virtual disk image file. If this parameter is NULL, the parent directory"s security descriptor will be used.

Flags [in]
Creation flags, which must be a valid combination of the CREATE_VIRTUAL_DISK_FLAG enumeration.

ProviderSpecificFlags [in]
Flags specific to the type of virtual disk being created. May be zero if none are required.

Parameters [in]
A pointer to a valid CREATE_VIRTUAL_DISK_PARAMETERS structure that contains creation parameter data.

Overlapped [in]
An optional pointer to a valid OVERLAPPED structure if asynchronous operation is desired.

Handle [out]
A pointer to the handle object that represents the newly created virtual disk.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0) and the Handle parameter contains a valid pointer to the new virtual disk object.  
***  


## Comments:
Quote: SizeOf(CREATE_VIRTUAL_DISK_PARAMETERS) = 44 and I think it should be 48 since the Union is not anonymous...  
  
Structures and unions are subject to alignment considerations...  
  
(CREATE | OPEN) -> ATTACH -> USE -> DETACH  
  
See also: [OpenVirtualDisk](../virtdisk/OpenVirtualDisk.md), [AttachVirtualDisk](../virtdisk/AttachVirtualDisk.md).  
  
***  

