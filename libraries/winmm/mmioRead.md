<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mmioRead
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmmio
File handle of the file to be read.

pch
Pointer to a buffer to contain the data read from the file.

cch
Number of bytes to read from the file.  
```  
***  


## Return value:
Returns the number of bytes actually read. If the end of the file has been reached and no more bytes can be read, the return value is 0. If there is an error reading from the file, the return value is 1.  
***  

