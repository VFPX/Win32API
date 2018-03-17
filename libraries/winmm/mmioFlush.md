<link rel="stylesheet" type="text/css" href="../../css/win32api.css">  
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">

## Functionname : mmioFlush
Group: Windows Multimedia - Library: winmm    
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
```txt  
hmmio
File handle of a file opened by using the mmioOpen function.

fuFlush
Flag determining how the flush is carried out. It can be zero or the following.
  
```  
***  


## Return value:
Returns zero if successful or an error otherwise.  
***  

