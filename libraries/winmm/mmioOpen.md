[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioOpen
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioOpen function opens a file for unbuffered or buffered I/O. The file can be a standard file, a memory file, or an element of a custom storage system.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
HMMIO mmioOpen(
  LPSTR szFilename,
  LPMMIOINFO lpmmioinfo,
  DWORD dwOpenFlags
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioOpen IN winmm;
	STRING   szFilename,;
	STRING @ lpmmioinfo,;
	INTEGER  dwOpenFlags
  
```  
***  


## Parameters:
szFilename 
Pointer to a string containing the filename of the file to open. 

lpmmioinfo 
Pointer to an MMIOINFO structure containing extra parameters used by mmioOpen.

dwOpenFlags 
Flags for the open operation.
  
***  


## Return value:
Returns a handle of the opened file. If the file cannot be opened, the return value is NULL.  
***  


## Comments:
The handle returned by mmioOpen is not a standard file handle. Do not use it with any file I/O functions other than multimedia file I/O functions.  
  
***  

