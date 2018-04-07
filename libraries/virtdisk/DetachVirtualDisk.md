[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : DetachVirtualDisk
Group: [Virtual Hard Disk (Win7)](../../functions_group.md#Virtual_Hard_Disk_(Win7))  -  Library: [virtdisk](../../Libraries.md#virtdisk)  
***  


#### Detaches a virtual hard disk (VHD) by locating an appropriate VHD provider to accomplish the operation.
***  


## Declaration:
```foxpro  
DWORD DetachVirtualDisk(
	__in  HANDLE VirtualDiskHandle,
	__in  DETACH_VIRTUAL_DISK_FLAG Flags,
	__in  ULONG ProviderSpecificFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG DetachVirtualDisk IN virtdisk;
	INTEGER VirtualDiskHandle,;
	INTEGER VirtualDiskFlags,;
	LONG ProviderSpecificFlags  
```  
***  


## Parameters:
VirtualDiskHandle [in]
A handle to an open virtual disk, which must have been opened using the VIRTUAL_DISK_ACCESS_DETACH flag.

Flags [in]
A valid combination of values of the DETACH_VIRTUAL_DISK_FLAG enumeration.

ProviderSpecificFlags [in]
Flags specific to the type of virtual disk being detached. May be zero if none are required.  
***  


## Return value:
If the function succeeds, the return value is ERROR_SUCCESS (0).  
***  


## Comments:
See also: [AttachVirtualDisk](../virtdisk/AttachVirtualDisk.md), [OpenVirtualDisk](../virtdisk/OpenVirtualDisk.md).  
  
***  

