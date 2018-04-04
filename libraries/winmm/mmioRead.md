[<img src="../../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

## Function name : mmioRead
Group: [Windows Multimedia](../../functions_group.md#Windows_Multimedia)  -  Library: [winmm](../../Libraries.md#winmm)  
***  


#### The mmioRead function reads a specified number of bytes from a file opened by using the mmioOpen function.
***  


## Code examples:
[WAV file player](../../samples/sample_417.md)  
[Changing pitch and speed of a wave file](../../samples/sample_422.md)  
[Playing WAV sounds simultaneously](../../samples/sample_523.md)  

## Declaration:
```foxpro  
LONG mmioRead(
  HMMIO hmmio,
  HPSTR pch,
  LONG cch
);  
```  
***  


## FoxPro declaration:
```foxpro  
DECLARE LONG mmioRead IN winmm;
	INTEGER   hmmio,;
	STRING  @ pch,;
	INTEGER   cch  
```  
***  


## Parameters:
hmmio 
File handle of the file to be read. 

pch 
Pointer to a buffer to contain the data read from the file. 

cch 
Number of bytes to read from the file.   
***  


## Return value:
Returns the number of bytes actually read. If the end of the file has been reached and no more bytes can be read, the return value is 0. If there is an error reading from the file, the return value is 1.  
***  

