[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioFlush
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioFlush function writes the I/O buffer of a file to disk if the buffer has been written to.
***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  

## Declaration:
```foxpro  
MMRESULT mmioFlush(
  HMMIO hmmio,
  UINT fuFlush
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE INTEGER mmioFlush IN winmm;
	INTEGER hmmio,;
	INTEGER fuFlush  
```  
***  


## Parameters:
hmmio
File handle of a file opened by using the mmioOpen function.

fuFlush
Flag determining how the flush is carried out. It can be zero or the following.
  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

