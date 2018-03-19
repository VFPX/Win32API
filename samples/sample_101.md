[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Obtaining physical parameters for a drive: sectors, clusters, cylinders...

## Short description:
The code shows how to obtain number of cylinders, tracks, sectors and clusters for a given device like HD, floppy or CD.  
***  


## Before you begin:
The code shows how to obtain number of cylinders, tracks, sectors and clusters for a given device like HD, floppy or CD.  

See also:

* [Displaying the drive type value](sample_012.md)  
* [Basic Volume information](sample_098.md)  
* [Setting the volume label](sample_151.md)  
* [Disk in drive A:](sample_319.md)  
  
***  


## Code:
```foxpro  
DO decl
DO GetDeviceInfo_1
DO GetDeviceInfo_2
* end of main

PROCEDURE GetDeviceInfo_1
	STORE 0 TO nSectorsPerCluster, nBytesPerSector,;
		nFreeClusters, nTotalClusters

	LOCAL lcRootName, nTotalSize
	lcRootName = "C:\"
	*lcRootName = "A:\"  && a way to test if a disk inserted

	= GetDiskFreeSpace(lcRootName, @nSectorsPerCluster,;
		@nBytesPerSector, @nFreeClusters, @nTotalClusters)

	?
	? "*** Returned by GetDiskFreeSpace:"
	? "Device name:", lcRootName
	? "Total clusters:", nTotalClusters
	? "Free clusters:", nFreeClusters
	? "Sectors per cluster:", nSectorsPerCluster
	? "Bytes per sector:", nBytesPerSector

	nTotalSize = nTotalClusters * nSectorsPerCluster * nBytesPerSector
	? "Total size: ", TRANSFORM(nTotalSize, "999,999,999,999")

PROCEDURE GetDeviceInfo_2
#DEFINE FILE_SHARE_READ   1
#DEFINE FILE_SHARE_WRITE  2
#DEFINE OPEN_EXISTING     3
#DEFINE INVALID_HANDLE_VALUE -1
#DEFINE IOCTL_DISK_GET_DRIVE_GEOMETRY 0x70000
#DEFINE ERROR_INSUFFICIENT_BUFFER 122
#DEFINE MAX_DWORD 0x100000000

	LOCAL cDrive, hDevice
	cDrive = "\\.\PhysicalDrive0"
*	cDrive = "\\.\c:"

	hDevice = CreateFile(m.cDrive, 0,;
		BITOR(FILE_SHARE_READ, FILE_SHARE_WRITE),;
		0, OPEN_EXISTING, 0, 0)

	IF hDevice = INVALID_HANDLE_VALUE
		? "Error: INVALID_HANDLE_VALUE"
		RETURN
	ENDIF

*|typedef struct _DISK_GEOMETRY {
*|  LARGE_INTEGER Cylinders;  0:8
*|  MEDIA_TYPE MediaType;     8:4
*|  DWORD TracksPerCylinder; 12:4
*|  DWORD SectorsPerTrack;   16:4
*|  DWORD BytesPerSector;    20:4
*|} DISK_GEOMETRY; total bytes: 24
#DEFINE DISK_GEOMETRY_SIZE 24

	LOCAL cBuffer, nBufsize, nCylinders, nMediaType, nTracksPerCyl,;
		nSecPerTrack, nBytesPerSec, nTotalSize
	cBuffer = REPLICATE(CHR(0), DISK_GEOMETRY_SIZE)
	nBufsize=0
	
	= DeviceIoControl(m.hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY,;
		Null, 0, @cBuffer, LEN(cBuffer), @nBufsize, 0)

	nCylinders = GetLongInt(SUBSTR(cBuffer,1,4), SUBSTR(cBuffer,5,4))
	nMediaType = buf2dword(SUBSTR(cBuffer,9,4))
	nTracksPerCyl = buf2dword(SUBSTR(cBuffer,13,4))
	nSecPerTrack =  buf2dword(SUBSTR(cBuffer,17,4))
	nBytesPerSec = buf2dword(SUBSTR(cBuffer,21,4))
	?
	? "*** Returned by DeviceIoControl:"
	? "Device name:", cDrive
	? "Cylinders:", nCylinders
	? "Media Type:", nMediaType
	? "Tracks per cylinder:", nTracksPerCyl
	? "Sector per track:", nSecPerTrack
	? "Bytes per sector:", nBytesPerSec

	nTotalSize = nCylinders * nTracksPerCyl * nSecPerTrack *;
		nBytesPerSec
	? "Total size:", TRANSFORM(nTotalSize, "999,999,999,999")

	= CloseHandle(hDevice)

PROCEDURE decl
	DECLARE INTEGER GetDiskFreeSpace IN kernel32;
		STRING lpRootPathName, INTEGER @lpSectorsPerCluster,;
		INTEGER @lpBytesPerSector, INTEGER @lpNumberOfFreeClusters,;
		INTEGER @lpTotalNumberOfClusters

	DECLARE INTEGER DeviceIoControl IN kernel32;
		INTEGER hDevice, INTEGER dwIoControlCode, STRING @lpInBuffer,;
		INTEGER nInBufferSize, STRING @lpOutBuffer, INTEGER nOutBufferSize,;
		INTEGER @lpBytesReturned, INTEGER lpOverlapped

	DECLARE INTEGER CreateFile IN kernel32;
		STRING lpFileName, INTEGER dwAccess, INTEGER dwShareMode,;
		INTEGER lpSecurityAttr, INTEGER dwCreationDisp,;
		INTEGER dwFlagsAndAttr, INTEGER hTemplateFile

	DECLARE INTEGER CloseHandle IN kernel32 INTEGER hObject
	DECLARE INTEGER GetLastError IN kernel32

FUNCTION GetLongInt(Lo, Hi)
#DEFINE MAX_DWORD 0x100000000
	IF VARTYPE(m.Lo)="C"
		Lo = buf2dword(m.Lo)
	ENDIF
	IF VARTYPE(m.Hi) = "C"
		Hi = buf2dword(m.Hi)
	ENDIF
RETURN m.Hi * MAX_DWORD + m.Lo

FUNCTION buf2dword(lcBuffer)
RETURN Asc(SUBSTR(lcBuffer, 1,1)) + ;
	BitLShift(Asc(SUBSTR(lcBuffer, 2,1)),  8) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 3,1)), 16) +;
	BitLShift(Asc(SUBSTR(lcBuffer, 4,1)), 24)  
```  
***  


## Listed functions:
[CloseHandle](../libraries/kernel32/CloseHandle.md)  
[CreateFile](../libraries/kernel32/CreateFile.md)  
[DeviceIoControl](../libraries/kernel32/DeviceIoControl.md)  
[GetDiskFreeSpace](../libraries/kernel32/GetDiskFreeSpace.md)  
[GetLastError](../libraries/kernel32/GetLastError.md)  
