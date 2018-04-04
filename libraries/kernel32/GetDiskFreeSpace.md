[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : GetDiskFreeSpace
Group: [File System](../../functions_group.md#File_System)  -  Library: [kernel32](../../Libraries.md#kernel32)  
***  


#### [Obsolete] Retrieves information about the specified disk, including the amount of free space on the disk.

***  


## Code examples:
[Obtaining physical parameters for a drive: sectors, clusters, cylinders...](../../samples/sample_101.md)  
[Disk in drive A:](../../samples/sample_319.md)  
[Detecting changes in connections to removable drives (VFP9)](../../samples/sample_573.md)  

## Declaration:
```foxpro  
BOOL GetDiskFreeSpace(
  LPCTSTR lpRootPathName,          // root path
  LPDWORD lpSectorsPerCluster,     // sectors per cluster
  LPDWORD lpBytesPerSector,        // bytes per sector
  LPDWORD lpNumberOfFreeClusters,  // free clusters
  LPDWORD lpTotalNumberOfClusters  // total clusters
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE SHORT GetDiskFreeSpace IN kernel32;
	STRING lpRootPathName,;
	INTEGER @ lpSectorsPerCluster,;
	INTEGER @ lpBytesPerSector,;
	INTEGER @ lpNumberOfFreeClusters,;
	INTEGER @ lpTotalNumberOfClusters  
```  
***  


## Parameters:
lpRootPathName 
[in] Pointer to a null-terminated string that specifies the root directory of the disk to return information about. 

lpSectorsPerCluster 
[out] Pointer to a variable for the number of sectors per cluster. 

lpBytesPerSector 
[out] Pointer to a variable for the number of bytes per sector. 

lpNumberOfFreeClusters 
[out] Pointer to a variable for the total number of free clusters on the disk that are available to the user associated with the calling thread.  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
The GetDiskFreeSpace function cannot report volume sizes that are greater than 2 GB. To ensure that your application works with large capacity hard drives, use the GetDiskFreeSpaceEx function.   
  
***  

