[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioWrite
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### Writes a specified number of bytes to a file opened by using the mmioOpen function.

***  


## Code examples:
[Class for sound recording](../../samples/sample_420.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Adding supplementary data to AVI files](../../samples/sample_481.md)  

## Declaration:
```foxpro  
LONG mmioWrite(
	HMMIO hmmio,
	char _huge* pch,
	LONG cch
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG mmioWrite IN winmm;
	INTEGER hmmio,;
	STRING  pch,;
	LONG    cch
  
```  
***  


## Parameters:
hmmio
File handle of the file.

pch
Pointer to the buffer to be written to the file.

cch
Number of bytes to write to the file.
  
***  


## Return value:
Returns the number of bytes actually written. If there is an error writing to the file, the return value is -1.  
***  

