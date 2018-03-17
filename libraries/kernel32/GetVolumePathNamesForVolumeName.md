<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : GetVolumePathNamesForVolumeName
Group: File System - Library: kernel32    
***  


#### Retrieves a list of path names for the specified volume name.

***  


## Code examples:
[Enumerating Volumes and Volume Mounting Points (NTFS)](../../samples/sample_087.md)  

## Declaration:
```foxpro  
BOOL GetVolumePathNamesForVolumeName(
	LPCTSTR lpszVolumeName,
	LPTSTR lpszVolumePathNames,
	DWORD cchBufferLength,
	PDWORD lpcchReturnLength
);
  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER GetVolumePathNamesForVolumeName IN kernel32;
	STRING lpszVolumeName,;
	STRING @lpszVolumePathNames,;
	LONG cchBufferLength,;
	LONG @lpcchReturnLength  
```  
***  


## Parameters:
```txt  
lpszVolumeName
[in] Pointer to a string that specifies the volume name.

lpszVolumePathNames
[out] Pointer to a buffer that receives the list of null-terminated volume path names.

cchBufferLength
[in] Length of the lpszVolumePathNames buffer, in TCHARs.

lpcchReturnLength
[out] If the call is successful, this parameter is the number of TCHARs copied to the lpszVolumePathNames buffer.  
```  
***  


## Return value:
If the function succeeds, the return value is nonzero.  
***  


## Comments:
<Em>lpcchReturnLength</Em> -- allocate large buffer and rely on AT(Chr(0)+Chr(0), cBuffer) rather than on this parameter.  
  
<div class=precode>nBufsize=0  
cBuffer = REPLICATE(CHR(0), 0x4000)  
  
GetVolumePathNamesForVolumeName(;  
	"\\?\Volume{9da9a070-8130-11d6-bb8f-806d6172696f}\",;  
	@cBuffer, LEN(cBuffer), @nBufsize)  
  
cBuffer = SUBSTR(cBuffer, 1, AT(CHR(0)+CHR(0), cBuffer))  
* returns "A:\"  
</div>  
  
***  

